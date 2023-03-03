#include <iostream>
#include <time.h>
using namespace std;
void quick_sort(float arr[], int first, int last) {
	float mid, tmp;
	int f = first, l = last;
	mid = arr[(f + l) / 2]; //pivont
	while (f < l) {
		while (arr[f] < mid) { f++; }
		while (arr[l] > mid) { l--; }
		if (f <= l) {
			tmp = arr[f];
			arr[f] = arr[l];
			arr[l] = tmp;
			f++;
			l--;
		}
	}
	if (first < l) quick_sort(arr, first, l);
	if (f < last) quick_sort(arr, f, last);
}
void fill_array_random(float arr[], int size) {
	srand(time(NULL));
	for (int i = 0, sign; i < size; i++) {
		sign = rand() % 2;
		if (sign == 0) {
			arr[i] = rand() % 10000 + 1;
			arr[i] /= 100;
		}
		else {
			arr[i] = -(rand() % 10000 + 1);
			arr[i] /= 100;
		}
	}
}
void fill_array_increasing(float arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
}
void fill_array_decreasing(float arr[], int size) {
	for (int i = size - 1, j = 0; i >= 0; i--, j++) {
		arr[j] = i;
	}
}
void print_array(float arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ")" << arr[i] << endl;
	}
}
void bubble_sort(float arr[], int size) {
	float k;
link:
	int j = 0;
	for (int i = 1; i < size; i++) {
		if (arr[i - 1] > arr[i]) {
			k = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = k;
			j++;
		}
	}
	size--;
	if (j != 0) {
		goto link;
	}
}
void select_sort(float arr[], int size) {
	while (size != 0) {
		float d = arr[0], tmp;
		int key = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i] > d) {
				d = arr[i];
				key = i;
			}
		}
		size--;
		tmp = arr[size];
		arr[size] = arr[key];
		arr[key] = tmp;
	}
}
void insertion_sort(float arr[], int size) {
	float tmp;
	int seat;
	for (signed int i = 0; i < size - 1;)
	{
		seat = i;
		if (arr[i] > arr[i + 1]) {
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i--;
			if (i < 0) { i = seat; }
		}
		else { i = seat + 1; }
	}
}
void check_the_sorting(float arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			cout << "ќбнаружена ошибка" << endl;
		}
	}
}
void shaker_sort(float arr[], int size) {
	float tmp;
	int first = 0;
link:
	int j = 0;
	for (int i = first + 1; i < size; i++) {
		if (arr[i - 1] > arr[i]) {
			tmp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = tmp;
			j++;
		}
	}
	size--;
	for (int i = size; i > first; i--) {
		if (arr[i - 1] > arr[i]) {
			tmp = arr[i - 1];
			arr[i - 1] = arr[i];
			arr[i] = tmp;
			j++;
		}
	}
	first++;
	if (j != 0) { goto link; }
}
void gnome_sort(float arr[], int size) {
	float tmp;
	for (signed int i = 0; i < size - 1;) {
		if (arr[i] > arr[i + 1]) {
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i--;
			if (i < 0) { i = 1; }
		}
		else { i++; }
	}
}
void stupid_sort(float arr[], int size) {
	float tmp;
	for (int i = 1; i < size; i++) {
		if (arr[i - 1] > arr[i]) {
			tmp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = tmp;
			i = 0;
		}
	}
}
void comb_sort(float arr[], int size) {
	int step = size - 1;
	float tmp;
	while (step > 0) {
		for (int i = 0; i + step < size; i++) {
			if (arr[i] > arr[i + step]) {
				tmp = arr[i];
				arr[i] = arr[i + step];
				arr[i + step] = tmp;
			}
		}
		step--;
	}
}
void Shell_sort(float arr[], int size) {
	int step = size / 2;
	int tmp, j;
	while (step > 0) {
		for (int i = 0; i < size - step; i++) {
			j = i;
			while ((j >= 0) && (arr[j] > arr[j + step])) {
				tmp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = tmp;
				j--;
			}
		}
		step /= 2;
	}
}
void fill_array_myself(float arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("¬ведите элемент массива под номером %d  ", i + 1);
		cin >> arr[i];
	}
}