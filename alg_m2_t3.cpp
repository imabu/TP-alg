#include <cstdio>
#include <vector>
#include <cstring>
/*
На числовой прямой окрасили ? N
?отрезков. Известны координаты левого и правого концов каждого  отрезка (?Li и Ri)
Найти сумму длин частей числовой прямой, окрашенных в один слой */

class data_t {
public:
	int value;
	int attribute;
	data_t(int _value=0,int _attribute=1) {
		value = _value;
		attribute = _attribute; // attribute = 1, если начало отрезка; -1, если конец отрезка
	}
	void putParam(int _value, int _attribute) {
		value = _value;
		attribute = _attribute;
	}
	bool operator ==(data_t val) {
		if ((*this).value == val.value && (*this).attribute == val.attribute) return true;
		return false;
	}
};

bool myLess(const data_t &val1, const data_t &val2) {
	if (val1.value<val2.value) return true;
	return false;
}
template<typename less_t>
void heapMake(std::vector <data_t> &data, size_t size, size_t head, less_t &less) {
	for (int i = head; 2 * i + 1 < size;) {
		i *= 2;
		i++;
		if (i + 1 <size && less(data[i], data[i + 1])) {
			i += 1;
		}
		if (less(data[(i - 1) / 2], data[i])) {
			std::swap(data[(i - 1) / 2], data[i]);
		}
	}
}
template<typename less_t>
void heapSiftUp(std::vector <data_t> &data,int index,less_t &less) {
	while (index > 0) {
		int parent = (index - 1) / 2;
		if (less( data[parent], data[index])) {
			std::swap(data[index], data[parent]);
			index = parent;
		}
		else break;
	}
}
template<typename less_t>
void sort(std::vector <data_t> &data, size_t size, less_t &less) {
	for (int i = 0; i < size; ++i) {
		std::swap(data[size-i - 1], data[0]);	
		heapMake(data,size-i-1,0,less);
	}	
}


int main() {	
	int n = 0;
	scanf("%d", &n);
	int size = 2 * n;
	std::vector<data_t> data(size,0);
	for (int i = 0; i < n; ++i) {
		int right = 0, left = 0;
		scanf("%d %d", &right, &left);
		data[2*i].putParam(right,1);
		data[2 * i+1].putParam(left, -1);
		heapSiftUp(data, 2 * i, myLess);
		heapSiftUp(data, 2 * i+1, myLess);
	}
	sort(data, size, myLess);
	int k=0, u=0;
	for (int i = 0;i<size;++i) {	
		u += data[i].attribute;
		if (u == 1) {
			 k += data[i+1].value - data[i].value;
		}
		printf("u=%d k=%d\n", u, k);
	}	
	system("pause");
	return 0;
}
