/*
** EPITECH PROJECT, 2019
** display_sections.hpp
** File description:
** display_sections class
*/

#include "nm.h"
#include "flags.h"

void SEC(ARCH)(void *buf,
        C_STRUCT_ARCH_S(ARCH) *sections,
        const char *sec_nm,
        unsigned int i)
{
    char printable[DUMP_SIZE + 1];
    char *iterator = buf + sections[i].sh_offset;
    char *sc_end = buf + sections[i].sh_offset + sections[i].sh_size;

    printf("Contents of section %s:\n", &sec_nm[sections[i].sh_name]);
    for (C_STRUCT_ARCH_S(ARCH) *off =
            (C_STRUCT_ARCH_S(ARCH) *)(sections[i].sh_addr);
    iterator != sc_end; off = (void *)off + DUMP_SIZE) {
        memset(printable, ' ', DUMP_SIZE);
        printable[DUMP_SIZE] = 0;
        printf(" %.4lx ", (unsigned long)off);
        iterator = display_hex_values(iterator, printable, sc_end);
    }
}

void INF(ARCH)(void *buf,
        C_STRUCT_ARCH_E(ARCH) *elf,
        C_STRUCT_ARCH_S(ARCH) *sec,
        const char *av)
{
    const char *sec_nm = buf + (&sec[elf->e_shstrndx])->sh_offset;

#if ARCH == 32
    printf("\n%s:     file format elf32-i386\n", av);
    printf("architecture: i386, flags ");
    HEAD(ARCH)(buf, sec, elf);
    printf("start address 0x%.8lx\n\n", (unsigned long)elf->e_entry);
#elif ARCH == 64
    printf("\n%s:     file format elf64-x86-64\n", av);
    printf("architecture: i386:x86-64, flags ");
    HEAD(ARCH)(buf, sec, elf);
    printf("start address 0x%.16lx\n\n", (unsigned long)elf->e_entry);
#endif
    for (unsigned int i = 0; i < elf->e_shnum; i++)
        if (sec_nm[sec[i].sh_name] &&
        strcmp(&sec_nm[sec[i].sh_name], ".bss") &&
        strcmp(&sec_nm[sec[i].sh_name], ".shstrtab") &&
        strcmp(&sec_nm[sec[i].sh_name], ".symtab") &&
        strcmp(&sec_nm[sec[i].sh_name], ".strtab"))
            SEC(ARCH)(buf, sec, sec_nm, i);
}

char PRINT_TYPE_NEXT(ARCH)
                (C_STRUCT_ARCH_Y(ARCH) *sym,
                C_STRUCT_ARCH_S(ARCH) *sh,
                char c)
{
    c = ((sh[sym->st_shndx].sh_type == SHT_PROGBITS ||
    sh[sym->st_shndx].sh_type == SHT_DYNAMIC) && c == 0 &&
    sh[sym->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE)) ? 'D' : c;
    c = (sh[sym->st_shndx].sh_type == SHT_PROGBITS && c == 0 &&
    sh[sym->st_shndx].sh_flags == SHF_ALLOC) ? 'R' : c;
    c = (sh[sym->st_shndx].sh_type == SHT_NOBITS && c == 0 &&
    sh[sym->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE)) ? 'B' : c;
    c = (sh[sym->st_shndx].sh_type == SHT_PROGBITS && c == 0 &&
    sh[sym->st_shndx].sh_flags == 0) ? 'N' : c;
    c = c == 0 ? '?' : c;
    c += ELF_ST_BIND(ARCH)(sym->st_info) == STB_LOCAL && c != '?' ? 32 : 0;
    return (c);
}

void *GET_TABLE_TYPE(ARCH)(void *buf, C_STRUCT_ARCH_S(ARCH) *sections,
        C_STRUCT_ARCH_E(ARCH) *elf, unsigned int type)
{
    for (unsigned int i = 0; i < elf->e_shnum; i++)
        if (sections[i].sh_type == type)
            return (buf + sections[i].sh_offset);
    return (NULL);
}

void HEAD(ARCH)(void *buf, C_STRUCT_ARCH_S(ARCH) *sections,
        C_STRUCT_ARCH_E(ARCH) *elf)
{
    unsigned int flags_hex = BFD_NO_FLAGS;

    flags_hex |= GET_TABLE_TYPE(ARCH)(buf, sections, elf, SHT_RELA) ?
                HAS_RELOC : 0;
    flags_hex |= elf->e_type == ET_EXEC ? EXEC_P : 0;
    flags_hex |= GET_TABLE(ARCH)(buf, sections, elf, ".symtab") ?
                HAS_SYMS : 0;
    flags_hex |= (flags_hex & EXEC_P) && (flags_hex & HAS_SYMS) ?
                D_PAGED : 0;
    flags_hex |= GET_TABLE_TYPE(ARCH)(buf, sections, elf, SHT_DYNSYM) &&
                !(flags_hex & D_PAGED) ? DYNAMIC : 0;
    printf("0x%.8x:\n", flags_hex);
    display_flags(flags_hex);
}