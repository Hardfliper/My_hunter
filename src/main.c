/*
** EPITECH PROJECT, 2018
** main
** File description:
** main that call the other functions
*/

int error(int ac, char **av);

int main(int ac, char **av)
{
    if (error(ac, av) == 1)
        return (84);
    else
        return (0);
}
