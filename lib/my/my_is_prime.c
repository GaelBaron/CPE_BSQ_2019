/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** prime bitch
*/

int my_is_prime(int nb)
{
    if (nb <= 1)
        return (0);
    if ((nb % nb) == 0) {
        for (int i = 2; i <= nb; i++) {
            if ((nb % i) == 0 && i != nb) {
                return (0);
            }
        }
    }
    return (1);
}
