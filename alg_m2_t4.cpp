#include<vector>
#include<cstdio>
#include <cstring>

/*
Даны неотрицательные целые числа n,k и массив целых чисел из [0..10^9] размера n. 
Требуется  найти k­ю порядковую статистику. т.е. напечатать число, которое бы стояло на позиции с индексом k  (0..n­1) в отсортированном массиве. 
Напишите нерекурсивный алгоритм.  Требования к дополнительной памяти: O(n). Требуемое среднее время работы: O(n).  
Функцию Partition следует реализовывать методом прохода двумя итераторами в одном  направлении.
Реализуйте стратегию выбора опорного элемента “медиана трёх”. Функцию Partition реализуйте  методом прохода двумя итераторами от конца массива к началу.  
*/
int median(std::vector<int>&data, int begin, int end) {
	if(data[begin] < data[(begin + end) / 2]) {
		std::swap(data[begin], data[end]);
	}
	if (data[begin] < data[end]) {
		std::swap(data[begin], data[end]);
	}
	if (data[(begin + end) / 2] > data[end]) {
		std::swap(data[(begin + end) / 2], data[end]);
	}
	return data[end];
}
int partition(std::vector<int>&data, int begin, int end){
	int pivot = median(data, begin, end-1 );	
	int i=end-2, j=end-2;
	while (i>=begin&&j>=begin&&i <= j) {
		if (data[i] <= pivot){
			--i;
		}else{
			std::swap(data[i], data[j]);
			--j;
			--i;
		}
	}
	std::swap(data[j+1], data[end - 1]);
	return j+1;

}
int statis(std::vector<int>& data, size_t size, int k) {
	int begin = 0, end = size;
	while (true) {
		int pos=partition(data,begin,end);
		if (pos == k) {
			return data[k];
		}
		if (pos > k) { 
			end = pos;
		}
		else {
			begin = pos + 1;
		}
	}
}
int main() {	
	int n = 0, k = 0;
	scanf("%d", &n);
	scanf("%d",&k);
	std::vector<int> data(n,0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &data[i]);
	}
	printf("%d",statis(data, n, k));
	system("pause");
	return 0;
 }