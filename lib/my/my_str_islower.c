/*
** EPITECH PROJECT, 2019
** my_str_islower
** File description:
** my str islower ?
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            i++;
        else if (str[i] < 'A'  && str[i] > 'Z')
            return (0);
        else
            i++;
    }
    return (1);
}
