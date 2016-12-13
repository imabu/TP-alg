/*​Даны два массива целых чисел одинаковой длины A[0..n­1] и B[0..n­1]. Необходимо найти первую пару
индексов i0 и j0, i0 ≤ j0, такую что A[i0] + B[j0] = max {A[i] + B[j], где 0 <= i < n, 0 <= j < n, i <= j}. Время работы ­ O(n)*/

#include <iostream>
using namespace std;
void maxSumm(int *a, int *b, int n, int *  result) {
	int max_a = 0, index_a = 0, index_b = 0;
	for (int i = 0; i<n; i++) {
		if (a[i]>a[max_a]) max_a = i;
		if (a[index_a] + b[index_b]<b[i] + a[max_a]) {
			index_a = max_a;
			index_b = i;
		}
	}
	result[0] = index_a;
	result[1] = index_b;
}
int main() {
	int n = 0;
	cin >> n;
	int * a = new int[n], *b = new int[n];
	for (int i = 0; i<n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i<n; i++) {
		cin >> b[i];
	}
	int* result = new int[2];
	maxSumm(a, b, n, result);
	cout << result[0] << ' ' << result[1];	
	return 0;
}