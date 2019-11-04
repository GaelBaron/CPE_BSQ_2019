/*
** EPITECH PROJECT, 2019
** my_str_is_printable
** File description:
** is my_ str printable ?
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            i++;
        else if (str[i] < '\0'  || str[i] > 127)
            return (0);
        else
            i++;
    }
    return (1);
}
