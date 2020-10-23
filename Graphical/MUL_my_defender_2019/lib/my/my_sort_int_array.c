/*
** EPITECH PROJECT, 2019
** my_sort_in_array
** File description:
** Task06
*/

int my_swap_that(int *array, int i, int *check)
{
    int a = 0;

    a = array[i];
    array[i] = array[i + 1];
    array[i + 1] = a;
    *check = 0;
    return (0);
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int range = 1;
    int check = 0;
    int check_size = size - 1;

    while (range == 1) {
        while (i < size) {
            if (array[i] > array[i + 1]) {
                my_swap_that(array, i, &check); }
            if (array[i] < array[i + 1]) {
                check = check + 1; }
            if (check == check_size)
                range = 0;
            i = i + 1; }
        i = 0;
    }
}
