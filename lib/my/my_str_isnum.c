/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** is str num full ?
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            i++;
        else if (str[i] < '0'  && str[i] > '9' && str[i] != '-')
            return (0);
        else
            i++;
    }
    return (1);
}
