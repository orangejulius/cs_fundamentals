#ifndef SORT_H
#define SORT_H

#include <stdbool.h>
#include "shuffle.h"

void bubble_sort(int data[], int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size - i; j++) {
			if (data[j] < data[j-1]) {
				swap(data, j, j - 1);
			}
		}
	}
}

void naive_bubble_sort(int data[], int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size ; j++) {
			if (data[j] < data[j-1]) {
				swap(data, j, j - 1);
			}
		}
	}
}

void insertion_sort(int data[], int size) {
	for(int i = 1; i < size; i++) {
		int temp = data[i];
		int j = i - 1;
		while(temp < data[j] && j >= 0) {
			data[j + 1] = data[j];
			j = j - 1;
		}
		data[j + 1] = temp;
	}
}

int partition(int data[], int l, int r)
{
	int i = l - 1;
	int j = r;
	int v = data[r];
	while(1) {
		while (data[++i] < v) {};
		while (v < data[--j]) {
			if (j == l) break;
		}
		if (i >= j) break;
		swap(data, i, j);
	}
	swap(data, i, r);
	return i;
}

void quicksort_internal(int data[], int l, int r)
{
	if (r <= l) {
		return;
	}
	int i = partition(data, l, r);
	quicksort_internal(data, l, i - 1);
	quicksort_internal(data, i + 1, r);
}

void quicksort(int data[], int size)
{
	quicksort_internal(data, 0, size - 1);
}

bool is_sorted(int data[], int size) {
	for (int i = 1; i < size; i++) {
		if (data[i-1] > data[i]) {
			return false;
		}
	}
	return true;
}

void bogo_sort(int data[], int size) {
	while (is_sorted(data, size) == false) {
		shuffle(data, size);
	}
}

#endif // SORT_H
