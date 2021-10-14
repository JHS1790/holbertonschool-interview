#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

void printa(int *left, int *right, size_t left_size, size_t right_size);
int worker_allocation(int *work_array, size_t size);
void printb(int *array, size_t size);
int *just_for_betty(int *array, size_t left_size, size_t right_size);

#endif /* SORT_H */
