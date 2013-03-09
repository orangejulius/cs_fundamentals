#ifndef SORT_H
#define SORT_H

void bubble_sort(int data[], int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size - i; j++) {
			if (data[j] < data[j-1]) {
				int temp = data[j];
				data[j] = data[j-1];
				data[j-1] = temp;
			}
		}
	}
}

void naive_bubble_sort(int data[], int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size ; j++) {
			if (data[j] < data[j-1]) {
				int temp = data[j];
				data[j] = data[j-1];
				data[j-1] = temp;
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

#endif // SORT_H
