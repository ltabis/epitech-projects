/*
** EPITECH PROJECT, 2019
** run.hpp
** File description:
** run class
*/

#include <openssl/sha.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <unistd.h>
#include "chap.h"

/*
* create_key -> const char * -> const parameters_t *
* create a new set of data from the challenge
*/

char *create_key(const char *data, const parameters_t *parameters)
{
    unsigned char hash[SHA256_DIGEST_LENGTH] = {0};
    SHA256_CTX sha256;
    char *output_buffer;

    if (!(output_buffer =
    calloc(1, sizeof(char) * ((SHA256_DIGEST_LENGTH * 2) + 1))))
        return (NULL);
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Update(&sha256, parameters->password, strlen(parameters->password));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(output_buffer + (i * 2), "%02x", hash[i]);
    output_buffer[64] = 0;
    return (output_buffer);
}

/*
* setup_package -> char * -> parameters_t *
* get a package ready to be sent.
*/

char *setup_package(char *message, parameters_t *parameters)
{
    char *buffer = malloc(sizeof(char) * PCKT_LEN);

    if (!buffer)
        return (NULL);
    memset(buffer, 0, PCKT_LEN);
    create_ip_wrap(buffer, message, parameters);
    create_udp_wrap(buffer, message, parameters);
    return (buffer);
}

/*
* parse_response -> char * -> parameters_t *
* Check if the current packet is the challenge or not
*/

int parse_response(char *response, parameters_t *parameters)
{
    struct iphdr *ip = NULL;
    struct udphdr *udp = NULL;
    char *data = NULL;

    if (!response)
        return (EXIT_FAIL);
    data = response + sizeof(struct iphdr) + sizeof(struct udphdr);
    ip = (void *)response;
    udp = (void *)response + sizeof(struct iphdr);
    if (strlen(data) == 10)
        if (ip->saddr == inet_addr(parameters->target) &&
        udp->source == htons(parameters->port))
            return (EXIT_SUCCESS);
    return (EXIT_FAIL);
}

/*
* manipulate_challenge -> int -> parameters_t * -> char *
* get the challenge and modify it to send it to the server
*/

void manipulate_challenge(int socket, parameters_t *parameters, char *packet)
{
    char *response = NULL;
    char *data = NULL;
    char *output_buffer = NULL;

    while (parse_response(response, parameters) == EXIT_FAIL) {
        if (response)
            free(response);
        response = receive_package_from(socket, parameters);
    }
    data = response + sizeof(struct iphdr) + sizeof(struct udphdr);
    output_buffer = create_key(data, parameters);
    packet = setup_package(output_buffer, parameters);
    send_package_to(socket, output_buffer, packet, parameters);
    free(output_buffer);
    free(packet);
    free(response);
}

/*
* run_client -> parameters_t *
* runs the client.
*/

int run_client(parameters_t *parameters)
{
    int socket = create_raw_socket();
    char *response = NULL;
    char *packet = NULL;

    if (socket == -1 || set_socket(socket) == -1 ||
    bind_socket(socket, parameters->port) == EXIT_FAIL) {
        perror("Socket error");
        return (EXIT_FAIL);
    }
    if (!(packet = setup_package("client hello", parameters)))
        return (EXIT_FAIL);
    send_package_to(socket, "client hello", packet, parameters);
    free(packet);
    manipulate_challenge(socket, parameters, packet);
    response = catch_correct_packet(socket, parameters);
    display_result(response);
    close(socket);
    return (EXIT_SUCCESS);
}