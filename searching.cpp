#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;

void quick_sort(int arr[], int first, int last);
void print_array(int arr[], int size);
void fill_array_integer_random(int arr[], int size);
int line_search(int arr[], int size, int x);
int binery_search(int arr[], int x, int left, int right);
int interpol_search(int arr[], int x, int size);
void fill_array(int arr[], int size);

int main() {
	setlocale(LC_ALL, "ru");
	printf("Поиск\nx принадлежит [-10000,10000], x принадлежит Z\n");
	int x, SIZE, p, a, result;
	printf("Введите размер массива:");
	cin >> SIZE;
	int* arr = new int[SIZE];
	printf("Выберите способ заполнения массива:\n");
	cout << "1 — заполнить случайными значениями" << endl
		<< "2 — заполнить вручную" << endl;
	cin >> a;
	switch (a) {
	case 1:fill_array_integer_random(arr, SIZE);
		break;
	case 2:fill_array(arr, SIZE);
		break;
	}
	printf("Введите искомое число x:");
	cin >> x;
	printf("Выберите способ поиска:\n");
	cout << "1 — линейный поиск" << endl
		<< "2 — бинарный поиск" << endl
		<< "3 — интерполяционный поиск" << endl;
	cin >> p;
	auto start = chrono::high_resolution_clock::now();
	switch (p) {
	case 1:result = line_search(arr, SIZE, x);
		break;
	case 2:result = binery_search(arr, x, 0, SIZE - 1);
		break;
	case 3:result = interpol_search(arr, x, SIZE);
		break;
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	//print_array(arr, SIZE);
	if (result > -1) {
		cout << "Значение " << x << " находится в ячейке с индексом " << result << "." << endl
			<< result << ")" << arr[result] << endl;
	}
	else { cout << "Такого значения нет в массиве.\n"; }
	printf("Продолжительность поиска составила %.7f секунд.\n", duration.count());
	return 0;
}

void quick_sort(int arr[], int first, int last) {
	int mid, tmp;
	int f = first, l = last;
	mid = arr[(f + l) / 2];
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
void print_array(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << i << ")" << arr[i] << endl;
	}
}
void fill_array_integer_random(int arr[], int size) {
	srand(time(NULL));
	for (int i = 0, sign; i < size; i++) {
		sign = rand() % 2;
		if (sign == 0) {
			arr[i] = rand() * rand() % 10000 + 1;
		}
		else {
			arr[i] = -(rand() * rand() % 10000 + 1);
		}
	}
}
int line_search(int arr[], int size, int x) {
	for (int i = 0; i < size; i++) {
		if (x == arr[i]) {
			return i;
		}
	}
	return -1;
}
int binery_search(int arr[], int x, int left, int right) {
	quick_sort(arr, 0, right);
	int mid;
	int i = 1, r = right;
	while (r != 0) {
		r /= 2;
		i++;
	}
	while (i != 0) {
		mid = (left + right) / 2;
		if (x == arr[mid]) {
			return mid;
		}
		if (x < arr[mid]) right = mid;
		if (x > arr[mid]) left = mid + 1;
		i--;
	}
	return -1;
}
void fill_array(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("Введите элемент массива c индексом %d  ", i);
		cin >> arr[i];
	}
}
int interpol_search(int arr[], int x, int size) {
	quick_sort(arr, 0, size - 1);
	int left = 0, right = size - 1, mid;
	while ((arr[left] <= x) && (arr[right] >= x)) {
		mid = left + ((x - arr[left]) * (right - left)) / (arr[right] - arr[left]);
		if (arr[mid] < x) left = mid + 1;
		else if (arr[mid] > x) right = mid - 1;
		else return mid;
	}
	if (arr[left] == x) return left;
	else return -1;
}