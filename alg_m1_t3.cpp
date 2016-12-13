/* ?Дан отсортированный массив различных целых чисел A[0..n­1] и массив целых чисел B[0..m­1]. Для
каждого элемента массива B[i] найдите минимальный индекс элемента массива A[k], ближайшего по
значению к B[i]. Время работы поиска для каждого элемента B[i]: O(log(k)).
n ? 110000, m ? 1000.*/ 

#include <iostream>
#define min(x,y)(x<y?x:y)
using namespace std;

int search(int *a, int n, int value) {
	int left = 0, right = 0;	
	for (int i = 1; i < n; i *= 2) {		
		if (value <= a[i]) {
			left = i / 2;
			right = i;
			break;
		}
		if (2 * i > n - 1) {
			left = (n - 1)/2;
			right = n - 1;
			break;
		}
	}	
	int mid = 0;
	for (; right-left>1;) {
		mid = left + (right - left) / 2;
		if (a[mid] < value) left = mid;
		else right = mid;
	}
	if (a[right] - value < value - a[left]) return right;
	else return left;
	
}


int main() {
	int n = 0;
	cin >> n;	
	int*a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m = 0;
	cin >> m;
	int*b = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < m; i++) {
		cout << search(a, n, b[i]) << " ";
	}
	system("pause");
	return 0;
}