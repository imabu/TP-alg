/* Дана последовательность целых чисел из диапазона (­10^9 .. 10^9). 
Длина последовательности не  больше 10^6. Числа записаны по одному в строке. 
Количество чисел не указано.   Пусть количество элементов n, и числа записаны в массиве a = a[i]: i из [0..n­1].  
Требуется напечатать количество таких пар индексов (i,j) из [0..n­1], что (i < j и a[i] > a[j]).  
Указание​ : количество инверсий может быть больше 4*10^9 ­ используйте int64_t.  
#include <stdint.h>  int64_t cnt = 0;  printf(“%ld”, cnt)
*/
#include <stdint.h>
#include <vector>
#include <cstring>
#include <iostream>

void merge(int *left, size_t sizeLeft, int *right, size_t sizeRight, int* result, int64_t& invers) {
	int i = 0, j = 0;
	/*for (; i < sizeLeft; ++i) {
		printf("%d",left[i]);
	}
	printf("\n");
	for (; j < sizeRight; ++j) {
		printf("%d",right[j]);
	}
	i = 0;
	j = 0;
	printf("\n");*/
	for (; i < sizeLeft&&j < sizeRight;) {
		if (left[i] <= right[j]) {
			result[i + j] = left[i];
			++i;
		}
		else {
			result[i + j] = right[j];
			invers+=sizeLeft-i;
			++j;
		}

	}

	for (; i < sizeLeft; ++i) {
		result[j + i] = left[i];
	}
	for (; j < sizeRight; ++j) {
		result[j + i] = right[j];
	}
	return;

}
void mergeSort(int* begin, size_t size, int* result, int64_t& invers) {
	if (size < 2) return;
	mergeSort(begin, size / 2, result, invers);
	mergeSort(&begin[size / 2], size - size / 2,result, invers);
	merge(begin, size / 2, &begin[size / 2], size - size / 2, result, invers);
	for (int i = 0; i < size; ++i) begin[i] = result[i];
}
int inversion(std::vector<int>&data) {
	int64_t cnp=0;
	return 0;
}
int main() {
	std::vector<int > data;
	int temp = 0;	
	while (scanf("%d", &temp)!= 1) {
		data.push_back(temp);
	}
	/*do
	{
		std::cin >> temp;
		data.push_back(temp);
	} while (!std::cin.eof());*/
	int64_t inv = 0;
	int * result = new int[data.size()];
	mergeSort(&data[0], data.size(),result , inv);
	printf("%ld", inv);
	system("pause");
	return 0;
}