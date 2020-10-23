/*
** EPITECH PROJECT, 2019
** my_sort_int_in_order
** File description:
** Sort an integer array in ascending order.
*/

void swap(int *array, int index, int *count)
{
    int a = 0;

    a = array[index];
    array[index] = array[index + 1];
    array[index + 1] = a;
    *count = 0;
}

void my_sort_int_array(int *array, int size)
{
    int index = 0;
    int mis = 1;
    int count = 0;

    while (mis == 1) {
        while (index < size) {
            if (array[index] > array[index + 1])
                swap(array, index, &count);
            if (array[index] < array[index + 1])
                count = count +1;
            if (count == (size - 1))
                mis = 0;
            index = index + 1;
        }
        index = 0; }
}
