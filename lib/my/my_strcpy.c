/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** str copy
*/

char *my_strcpy(char *dest, char const *src)
{
    int ination = 0;

    while (src[ination] != '\0') {
        dest[ination] = src[ination];
        ination++;
    }
    dest[ination] = '\0';
    return (dest);
}
