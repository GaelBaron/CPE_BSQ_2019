/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** ez
*/

void my_sort_int_array(int *array, int size)
{
    int min_pos = 0;
    int max_pos = 0;
    int min_value = array[0];
    int max_value = 0;

    for (int start = 0; start < size - 1; start++) {
        for (int i = start; i < size; i++) {
            if (array[i] < min_value) {
                min_value = array[i];
                min_pos = i;
            }
            else if (array[i] > max_value){
                max_value = array[i];
                max_pos = i;
            }
        }
        array[min_pos] = array[start];
        array[start] = min_value;
        min_value = max_value;
    }
}
