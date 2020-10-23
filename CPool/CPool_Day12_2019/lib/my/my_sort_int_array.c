/*
** EPITECH PROJECT, 2019
** my_sort_int_in_order
** File description:
** Sort an integer array in ascending order.
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

void my_sort_int_array(int *array, int size)
{
    int index;
    int index2;

    while (index < size)
    {
        index += 1;
        while (index2 < size - 1 - index) {
            index2 += 1;
            my_swap(&array[index2], &array[index2 + 1]);
        }
    }
}