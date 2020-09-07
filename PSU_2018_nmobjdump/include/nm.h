/*
** EPITECH PROJECT, 2019
** nm.hpp
** File description:
** nm header
*/

#ifndef NM_H
#define NM_H

#include <sys/mman.h>
#include <sys/stat.h>
#include <memory.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <elf.h>

#define DUMP_SIZE 16
#ifndef ARCH
    #define ARCH 64
#endif

typedef enum e_bool {TRUE, FALSE} bool;

int len_special(const char *);
bool disp_error(const char *, const char *, const char *, bool);
char strcmpchar(const char *, const char *);
int get_unused_name(const char *, size_t);
bool check_file_format(int, const char * const *);
char strcmpchar(const char *, const char *);
char *display_hex_values(char *, char *, char *);
char check_file_header(void *, const char *, const char *, int);
void display_flags(unsigned int);

#define CONCAT_STRINGS(str1, str2) str1 ## _ ## str2
#define CONCAT_THREE_STRINGS(str1, str2, str3) str1 ## str2 ## _ ## str3

#define C_STRUCT_ARCH_E(arch) CONCAT_THREE_STRINGS(Elf, arch, Ehdr)
#define C_STRUCT_ARCH_S(arch) CONCAT_THREE_STRINGS(Elf, arch, Shdr)
#define C_STRUCT_ARCH_Y(arch) CONCAT_THREE_STRINGS(Elf, arch, Sym)

#define ELF_ST_TYPE(arch) CONCAT_THREE_STRINGS(ELF, arch, ST_TYPE)
#define ELF_ST_BIND(arch) CONCAT_THREE_STRINGS(ELF, arch, ST_BIND)

#define GET_TABLE(arch) CONCAT_STRINGS(get_table, arch)
void *get_table_32(void *, Elf32_Shdr *, Elf32_Ehdr *, const char *);
void *get_table_64(void *, Elf64_Shdr *, Elf64_Ehdr *, const char *);

#define GET_TABLE_TYPE(arch) CONCAT_STRINGS(get_table_type, arch)
void *get_table_type_32(void *, Elf32_Shdr *, Elf32_Ehdr *, unsigned int);
void *get_table_type_64(void *, Elf64_Shdr *, Elf64_Ehdr *, unsigned int);

#define DISPLAY_FORMATED_LINE(arch) CONCAT_STRINGS(display_formated_line, arch)
void display_formated_line_32(char *, Elf32_Sym *, Elf32_Shdr *);
void display_formated_line_64(char *, Elf64_Sym *, Elf64_Shdr *);

#define ORDER(arch) CONCAT_STRINGS(display_symbols_by_order, arch)
void display_symbols_by_order_32(Elf32_Shdr *, Elf32_Shdr *,
        Elf32_Sym *, char *);
void display_symbols_by_order_64(Elf64_Shdr *, Elf64_Shdr *,
        Elf64_Sym *, char *);

#define DISPLAY_SYMBOLS(arch) CONCAT_STRINGS(display_symbols, arch)
bool display_symbols_32(void *, const char *, const char *, int);
bool display_symbols_64(void *, const char *, const char *, int);

#define PRINT_TYPE(arch) CONCAT_STRINGS(print_type, arch)
char print_type_32(Elf32_Sym *, Elf32_Shdr *);
char print_type_64(Elf64_Sym *, Elf64_Shdr *);

#define PRINT_TYPE_NEXT(arch) CONCAT_STRINGS(print_type_next, arch)
char print_type_next_32(Elf32_Sym *, Elf32_Shdr *, char);
char print_type_next_64(Elf64_Sym *, Elf64_Shdr *, char);

#define SEC(arch) CONCAT_STRINGS(display_current_section, arch)
void display_current_section_32(void *, Elf32_Shdr *,
        const char *, unsigned int);
void display_current_section_64(void *, Elf64_Shdr *,
        const char *, unsigned int);

#define INF(arch) CONCAT_STRINGS(display_sections_informations, arch)
void display_sections_informations_32(void *, Elf32_Ehdr *, Elf32_Shdr *,
        const char *);
void display_sections_informations_64(void *, Elf64_Ehdr *, Elf64_Shdr *,
        const char *);

#define HEAD(arch) CONCAT_STRINGS(get_header_flags, arch)
void get_header_flags_32(void *, Elf32_Shdr *, Elf32_Ehdr *);
void get_header_flags_64(void *, Elf64_Shdr *, Elf64_Ehdr *);

#endif /* !NM_H */
