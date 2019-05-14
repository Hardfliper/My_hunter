/*
** EPITECH PROJECT, 2018
** chartoint
** File description:
** transform a *char to int
*/

int my_put_nbr(int nb);
char *my_revstr(char *str);

int number(char *str)
{
    int nb = 0;
    int i = 0;
    int multi = 1;
    my_revstr(str);

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb + (str[i] - 48) * multi;
            multi = multi * 10;
        }
        i = i + 1;
    }
    return (nb);
}
