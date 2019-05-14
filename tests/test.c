/*
** EPITECH PROJECT, 2018
** test
** File description:
** unit test for duck hunt
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include <unistd.h>
#include <stdlib.h>

int error(int ac, char **av);

void cr_redirect_all_output(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(error, wrong_flag, .init = cr_redirect_all_output)
{
    system("./my_hunter nope");
    cr_expect_stderr_eq_str("Did you meant -h ?\n");
    cr_log_warn("wrong_flag: test with another argument than -h\n");
}

Test(error, flag_success_help, .init = cr_redirect_all_output)
{
    system("./my_hunter -h");
    cr_expect_stdout_eq_str("Type ./my_hunter and shoot the duck !\n");
    cr_log_warn("flag_success_help : Flag -h\n");
}

Test(error, too_many_arg, .init = cr_redirect_all_output)
{
    system("./my_hunter too many arguments");
    cr_expect_stderr_eq_str("Too many arguments !\n");
    cr_log_warn("too_many_arg : too much arguments\n");
}
