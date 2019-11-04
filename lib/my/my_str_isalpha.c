/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** is str alpha full ?
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            i++;
        else if (str[i] < 'a'  && str[i] > 'A' || str[i] < 'A' || str[i] > 'Z')
            return (0);
        else
            i++;
    }
    return (1);
}
