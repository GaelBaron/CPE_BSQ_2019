/*
** EPITECH PROJECT, 2019
** my_atoi
** File description:
** atoi
*/

int my_strlen(char *str);

int checker(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9' || str[i] == '-')
            i++;
        else
            return (0);
    }
    return (1);
}

int power(int nb, int pow)
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

int my_atoi(char *str)
{
    int result = 0;
    int end = (my_strlen(str) - 1);
    int pui = 0;
    int neg = 0;

    if (str[0] == '-')
        neg++;
    while (end + 1 > 0 + neg) {
        result = result + (str[end] - 48) * power(10, pui);
        pui = pui + 1;
        end--;
    }
    if (str[0] == '-')
      return (result * (-1));
    return (result);
}
