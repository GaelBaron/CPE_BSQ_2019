/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** str capitalize
*/

char *my_strcapitalize(char *str)
{
    int up_or_no = 0;
    char c;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 'z' && str[i] >= 'a' && up_or_no == 0) {
            c = str[i];
            up_or_no++;
            str[i] = c - 32;
        }
        if (str[i] == ' ')
            up_or_no = 0;
    }
    return (str);
}
