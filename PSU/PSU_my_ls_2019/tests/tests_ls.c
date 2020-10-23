/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** tests_ls.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ls.h"

Test(my_ls, functional_without_flags)
{
    char *av[] = {"./tests_run", "src"};

    cr_redirect_stdout();
    my_ls(2, av);
    cr_assert_stdout_eq_str("option_ls_t.c\noption_ls_l.c\n"
    "general_function.c\naccess_right.c\noptions.c\noption_ls_r.c\n"
    "my_ls.c\noption_ls.c\ninit_struct.c\n");
}

Test(my_ls, wrong_path)
{
    char *av[] = {"./tests_run", "azerty"};

    cr_redirect_stdout();
    my_ls(2, av);
    cr_assert_stdout_eq_str("my_ls: cannot access azerty: No such file or "
    "directory\n");
}

Test(my_ls, flag_l)
{
    char *av[] = {"./tests_run", "-l", "src"};

    cr_redirect_stdout();
    my_ls(3, av);
    cr_assert_stdout_eq_str("total 36\n"
    "-rw-r-xr-- 1 dimitry dimitry 1374 Jan 10 02:27 option_ls_t.c\n"
    "-rw-r-xr-- 1 dimitry dimitry 1426 Jan 10 12:10 option_ls_l.c\n"
    "-rw-r-xr-- 1 dimitry dimitry 1107 Jan 10 12:06 general_function.c\n"
    "-rw-r-xr-- 1 dimitry dimitry 1233 Jan 10 01:28 access_right.c\n"
    "-rw-r-xr-- 1 dimitry dimitry 1582 Jan 10 04:41 options.c\n"
    "-rw-r-xr-- 1 dimitry dimitry 2095 Jan 10 12:32 option_ls_r.c\n"
    "-rw-r-xr-- 1 dimitry dimitry 1585 Jan 10 05:29 my_ls.c\n"
    "-rw-r-xr-- 1 dimitry dimitry 665 Jan 10 05:23 option_ls.c\n"
    "-rw-r-xr-- 1 dimitry dimitry 1611 Jan 10 01:48 init_struct.c\n");
}

Test(my_ls, flag_d)
{
    char *av[] = {"./tests_run", "-d", "src"};

    cr_redirect_stdout();
    my_ls(3, av);
    cr_assert_stdout_eq_str("src\n");
}

Test(my_ls, flag_t)
{
    char *av[] = {"./tests_run", "-t", "src"};

    cr_redirect_stdout();
    my_ls(3, av);
    cr_assert_stdout_eq_str("option_ls_r.c\n"
    "option_ls_l.c\n"
    "general_function.c\n"
    "my_ls.c\n"
    "option_ls.c\n"
    "options.c\n"
    "option_ls_t.c\n"
    "init_struct.c\n"
    "access_right.c\n");
}

Test(my_ls, flag_r)
{
    char *av[] = {"./tests_run", "-r", "src"};

    cr_redirect_stdout();
    my_ls(3, av);
    cr_assert_stdout_eq_str("init_struct.c\n"
    "option_ls.c\n"
    "my_ls.c\n"
    "option_ls_r.c\n"
    "options.c\n"
    "access_right.c\n"
    "general_function.c\n"
    "option_ls_l.c\n"
    "option_ls_t.c\n");
}

Test(my_ls, flag_R)
{
    char *av[] = {"./tests_run", "-R", "src"};

    cr_redirect_stdout();
    my_ls(3, av);
    cr_assert_stdout_eq_str("src:\n"
    "option_ls_t.c\n"
    "option_ls_l.c\n"
    "general_function.c\n"
    "access_right.c\n"
    "options.c\n"
    "option_ls_r.c\n"
    "my_ls.c\n"
    "option_ls.c\n"
    "init_struct.c\n\n");
}

Test(my_ls, flag_ld)
{
    char *av[] = {"./tests_run", "-ld", "tests/tmp"};

    cr_redirect_stdout();
    my_ls(3, av);
    cr_assert_stdout_eq_str("drwxr-xr-x 2 dimitry dimitry "
    "4096 Jan 10 06:10 tests/tmp\n");
}