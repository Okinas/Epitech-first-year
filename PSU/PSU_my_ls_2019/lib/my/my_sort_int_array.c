/*
** EPITECH PROJECT, 2019
** my_sort_int_in_order
** File description:
** Sort an integer array in ascending order.
*/

static void swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int j = 0;

    while (i < size) {
        i += 1;
        while (j < size - 1 - i) {
            j += 1;
            swap(&array[j], &array[j + 1]);
        }
    }
}