/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** swap
*/

void my_swap(int *a, int *b)
{
    int k = *a;

    *a = *b;
    *b = k;
}
