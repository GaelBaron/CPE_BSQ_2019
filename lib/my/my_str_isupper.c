/*
** EPITECH PROJECT, 2019
** my_str_isupper
** File description:
** is my_ str upper ?
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            i++;
        else if (str[i] < 'a'  && str[i] > 'z')
            return (0);
        else
            i++;
    }
    return (1);
}
