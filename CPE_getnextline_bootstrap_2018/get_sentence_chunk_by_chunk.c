/*
** EPITECH PROJECT, 2018
** get_sentence_chunk_by_chunk.c
** File description:
** function that get a sentence chunk by chunk of 5 bytes
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char *get_sentence_chunk_by_chunk(void)
{
	char *arr = malloc(sizeof(char) * 6);
	char sentence[] = "Hello my name is Chucky, Do you want to be my friend?";
	static int decal = 0;

	for (int i = 0; i != 5 ;i++, decal++)
		arr[i] = sentence[decal];
	arr[5] = '\0';
	return (arr);
}
