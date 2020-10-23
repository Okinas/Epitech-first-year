/*
** EPITECH PROJECT, 2019
** tmp
** File description:
** tests_103.c
*/

#include "103cipher.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(cipher, functional)
{
    char *key = "Homer S";
    char *str = "Just because I don't care doesn't mean I don't understand.";

    cr_redirect_stdout();
    crypting(str, key);
    cr_assert_stdout_eq_str("Key matrix:\n"
    "\t72\t111\t109\n"
    "\t101\t114\t32\n"
    "\t83\t0\t0\n"
    "\nEncrypted message:\n"
    "26690 21552 11810 19718 16524 13668 25322 22497 14177 28422 26097 16433 "
    "12333 11874 5824 27541 23754 14452 17180 17553 7963 26387 22047 13895 "
    "18804 14859 12033 27738 23835 15331 21487 16656 13238 21696 15978 6976 "
    "20750 23307 14093 16788 11751 8981 22339 24861 15619 21295 16524 13668 "
    "26403 23610 15190 29451 25764 16106 26394 23307 14093 3312 5106 5014");
}