/*
** EPITECH PROJECT, 2019
** my_getnbr*
** File description:
** stfu.
*/

int error_gestion(char const *str)
{
    int i = 0;
    int nb_count = 0;

    while (str[i] != '\0') {
        if (str[i] <= '9' && str[i] >= '0') {
            nb_count++;
            i++;
        }
        else
            i++;
    }
    if (nb_count > 10)
        return (84);
    return (0);
}

int powernbr(int nb, int pow)
{
    int i = 0;
    int nb_base = nb;

    if (pow == 0)
        return (1);
    while (i + 1 < pow) {
        nb = nb_base * nb;
        i++;
    }
    return (nb);
}

int resultingnbr(char const *str, int i, int result)
{
    int min = i;
    int j = 0;

    while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0') {
        i++;
    }
    if (str[i] == '\0')
        i--;
    while (str[i] < '0' || str[i] > '9')
        i--;
    while (min <= i) {
        result = result + ((str[i] - 48) * (powernbr(10, j)));
        j++;
        i--;
    }
    return (result);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int result = 0;

    if (error_gestion(str) != 0)
        return (0);
    while (str[i] < '0' || str[i] > '9') {
        if (str[i] == '\0')
            return (0);
        i++;
    }
    if (i > 0 && str[i - 1] == '-')
        result = resultingnbr(str, i, result) * -1;
    else
        result = resultingnbr(str, i, result);
    return (result);
}
