/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** power
*/

int my_compute_power_rec(int nb, int p)
{
    static int result = 1;

    if (p > 0) {
        if (nb > 2147483647 || nb < -2147483648)
            return (0);
        if ((nb * result) > 2147483647 || (nb * result) < -2147483648)
            return (0);
        result = nb * result;
        my_compute_power_rec(nb, p - 1);
        return (result);
    }
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
}
