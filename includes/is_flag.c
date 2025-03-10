/*
** EPITECH PROJECT, 2023
** IS_FLAG
** File description:
** Returns 1 if av[i] is a flag, 0 in other case
*/

int is_flag(char *av)
{
    char flag[] = "alRdrt";
    int j;

    for (int i = 1; av[i] != '\0'; i++) {
        for (j = 0; av[i] != flag[j] && flag[j] != '\0'; j++) {
        }
        if (av[i] != flag[j])
            return (0);
    }
    return (1);
}
