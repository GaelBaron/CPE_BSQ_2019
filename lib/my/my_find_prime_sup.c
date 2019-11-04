/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** find prime sup
*/

int is_prime_orno(int nb)
{
    if ((nb % nb) == 0) {
        for (int i = 2; i <= nb; i++) {
            if ((nb % i) == 0 && i != nb) {
                return (0);
            }
        }
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    int nb_fir = nb;

    if (nb <= 2)
        return (2);
    if ((nb % nb) == 0) {
        while (is_prime_orno(nb_fir) == 0)
            nb_fir++;
    }
    return (nb_fir);
}
