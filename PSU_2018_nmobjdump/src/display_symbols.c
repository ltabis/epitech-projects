/*
** EPITECH PROJECT, 2019
** display_symbols.c
** File description:
** display_symbols file
*/

#include "nm.h"

char PRINT_TYPE(ARCH)(C_STRUCT_ARCH_Y(ARCH) *sym,
                        C_STRUCT_ARCH_S(ARCH) *sh)
{
    char c = (ELF_ST_BIND(ARCH)(sym->st_info) == STB_GNU_UNIQUE) ? 'u' : 0;

    c = (ELF_ST_BIND(ARCH)(sym->st_info) == STB_WEAK && c == 0) ?
        sym->st_shndx == SHN_UNDEF ? 'w' : 'W' : c;
    c = (ELF_ST_BIND(ARCH)(sym->st_info) == STB_WEAK &&
    ELF_ST_TYPE(ARCH)(sym->st_info) == STT_OBJECT && c == 0) ?
        sym->st_shndx == SHN_UNDEF ? 'v' : 'V' : c;
    c = (sym->st_shndx == SHN_UNDEF && c == 0) ? 'U' : c;
    c = (sym->st_shndx == SHN_ABS && c == 0) ? 'A' : c;
    c = (sym->st_shndx == SHN_COMMON && c == 0) ? 'C' : c;
    c = (((sh[sym->st_shndx].sh_type == SHT_PROGBITS &&
    sh[sym->st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR)) ||
    sh[sym->st_shndx].sh_type == 14 || sh[sym->st_shndx].sh_type == 15) &&
            c == 0) ? 'T' : c;
    return (PRINT_TYPE_NEXT(ARCH)(sym, sh, c));
}

void *GET_TABLE(ARCH)(void *buf, C_STRUCT_ARCH_S(ARCH) *sections,
        C_STRUCT_ARCH_E(ARCH) *elf, const char *table)
{
    C_STRUCT_ARCH_S(ARCH) *sh_strtab = &sections[elf->e_shstrndx];
    const char *const sec_names = buf + sh_strtab->sh_offset;

    for (unsigned int i = 0; i < elf->e_shnum; i++)
        if (strcmp(&sec_names[sections[i].sh_name], table) == 0)
            return (buf + sections[i].sh_offset);
    return (NULL);
}

void DISPLAY_FORMATED_LINE(ARCH)(char *str_tab,
        C_STRUCT_ARCH_Y(ARCH) *sym, C_STRUCT_ARCH_S(ARCH) *sh)
{
    if (!sym->st_name || ELF_ST_TYPE(ARCH)(sym->st_info) == STT_FILE)
        return;
    if (!(sym->st_size == 0 && sym->st_value == 0)) {
#if ARCH == 32
        printf("%.8x ", sym->st_value);
#elif ARCH == 64
        printf("%.16lx ", sym->st_value);
#endif
    } else
#if ARCH == 32
        printf("         ");
#elif ARCH == 64
        printf("                 ");
#endif
    printf("%c ", PRINT_TYPE(ARCH)(sym, sh));
    printf("%s\n", str_tab + sym->st_name);
}

void ORDER(ARCH)(C_STRUCT_ARCH_S(ARCH) *sections,
        C_STRUCT_ARCH_S(ARCH) *sh,
        C_STRUCT_ARCH_Y(ARCH) *sym, char *str_tab)
{
    size_t len = sections->sh_size / sections->sh_entsize;
    char displayed[len];
    int sml_idx = 0;

    memset(displayed, 0, len);
    while ((sml_idx = get_unused_name(displayed, len)) != -1) {
        for (int i = 0; i < (int)len; i++) {
            sml_idx = (str_tab + sym[i].st_name)[0] &&
            strcmpchar(str_tab + sym[i].st_name,
            str_tab + sym[sml_idx].st_name) &&
            !displayed[i] ? i : sml_idx;
        }
        displayed[sml_idx] = 1;
        DISPLAY_FORMATED_LINE(ARCH)(str_tab, &sym[sml_idx], sh);
    }
}

bool DISPLAY_SYMBOLS(ARCH)(void *buf,
        const char *program,
        const char *av,
        int ac)
{
    C_STRUCT_ARCH_E(ARCH) *elf = (C_STRUCT_ARCH_E(ARCH) *)buf;
    C_STRUCT_ARCH_S(ARCH) *sections = NULL;
    C_STRUCT_ARCH_Y(ARCH) *sym = NULL;
    char *str_tab = NULL;
    unsigned int idx_sym = 0;

    if (!elf->e_shoff)
        return (FALSE);
    sections = (C_STRUCT_ARCH_S(ARCH) *)(buf + elf->e_shoff);
    sym = (C_STRUCT_ARCH_Y(ARCH) *)GET_TABLE(ARCH)(buf,
            sections, elf, ".symtab");
    str_tab = (char *)GET_TABLE(ARCH)(buf, sections, elf, ".strtab");
    for (; idx_sym < elf->e_shnum &&
    sections[idx_sym].sh_type != SHT_SYMTAB; idx_sym++);
    if (!strcmp(program + 2, "my_nm")) {
        if (ac > 2)
            printf("\n%s:\n", av);
        ORDER(ARCH)(&sections[idx_sym], sections, sym, str_tab);
    } else
        INF(ARCH)(buf, elf, sections, av);
    return (TRUE);
}
