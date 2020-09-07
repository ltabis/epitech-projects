/*
** EPITECH PROJECT, 2019
** shared_func_2.hpp
** File description:
** shared_func_2 class
*/

#include "nm.h"
#include "flags.h"

bool load_file_in_memory(const char *program, const char *av, int ac)
{
    int fd = open(av, O_RDONLY);
    void *buf = NULL;
    struct stat s;
    bool ret = FALSE;
    char get = 0;

    if (fd != -1 && fstat(fd, &s) != -1) {
        buf = mmap(NULL, (size_t)s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
        get = check_file_header(buf, program, av, fd);
        if (get == 0)
            ret = display_symbols_32(buf, program, av, ac);
        else if (get == 1)
            ret = display_symbols_64(buf, program, av, ac);
        close(fd);
        return (ret);
    }
    close(fd);
    return (disp_error(program, av, "No such file", TRUE));
}

bool check_file_format(int ac, const char * const *av)
{
    if (ac == 1) {
        if (open("./a.out", O_RDONLY) == -1) {
            return (disp_error(av[0], "a.out", "No such file", TRUE));
        } else
            load_file_in_memory(av[0], "a.out", ac);
    }
    for (int i = 1; i < ac; i++)
        load_file_in_memory(av[0], av[i], ac);
    return (TRUE);
}

char *display_hex_values(char *iterator, char *printable, char *sc_end)
{
    unsigned int i = 0;

    for (; i < DUMP_SIZE && iterator != sc_end; i++, iterator++) {
        printable[i] = !isprint(iterator[0]) ? '.' : iterator[0];
        printf("%02x", iterator[0] & 0xff);
        if ((i + 1) % (DUMP_SIZE / 4) == 0)
            putchar(' ');
    }
    for (; i < DUMP_SIZE; i++)
        (i + 1) % (DUMP_SIZE / 4) == 0 ? printf("   ") : printf("  ");
    printf(" %s\n", printable);
    return (iterator);
}

char check_file_header(void *buf,
        const char *program,
        const char *av,
        int fd)
{
    Elf64_Ehdr *elf = (Elf64_Ehdr *)buf;
    Elf32_Ehdr *elf_min = (Elf32_Ehdr *)buf;

    if (buf == (void *)-1 ||
    elf->e_ident[EI_MAG0] != ELFMAG0 || elf->e_ident[EI_MAG1] != ELFMAG1 ||
    elf->e_ident[EI_MAG2] != ELFMAG2 || elf->e_ident[EI_MAG3] != ELFMAG3 ||
    elf->e_ident[EI_CLASS] == ELFCLASSNONE ||
    elf->e_ident[EI_DATA] == ELFDATANONE ||
    elf->e_ident[EI_VERSION] == EV_NONE || elf->e_type == ET_NONE) {
        disp_error(program, av, "File format not recognized", FALSE);
        return (2);
    }
    if ((unsigned int)(elf->e_shoff + (elf->e_shentsize * elf->e_shnum)) !=
    lseek(fd, 0, SEEK_END) && (unsigned int)(elf_min->e_shoff +
    (elf_min->e_shentsize * elf_min->e_shnum)) != lseek(fd, 0, SEEK_END)) {
        disp_error(program, av, "File truncated", FALSE);
        return (2);
    } else if (elf->e_ident[EI_CLASS] == ELFCLASS32)
        return (0);
    return (elf->e_ident[EI_CLASS] == ELFCLASS64 ? 1 : 2);
}
