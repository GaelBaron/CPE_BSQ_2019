/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** cpy n char of a str
*/

int my_strlenncpy(char const *src)
{
    int i = 0;

    while (src[i] != '\0')
        i++;
    return (i);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i <= n + 1) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
