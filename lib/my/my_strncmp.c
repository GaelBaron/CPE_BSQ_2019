/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** str n cmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int j = 0;

    for (int x = 0; s1[x] != '\0' && x < n; x++)
        i = s1[x] + i;
    for (int x = 0; s2[x] != '\0' && x < n; x++)
        j = s2[x] + j;
    if (i == j)
        return (0);
    if (i > j)
        return (1);
    if (i < j)
        return (-1);
}
