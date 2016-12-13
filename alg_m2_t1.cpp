/*Напишите программу, печатающую набор строк в лексикографическом порядке.  
Строки разделяются символом перевода строки '\n'. 
Если последний символ в потоке ввода '\n',                           
считать,что после него нет пустой строки. Максимальная длина строки 255 символов. Написать свою 
функцию сравнения строк.  

in  	out  
4		ab
caba    aba
abba    abba
ab      caba
aba        
*/

#include <cstdio>
#include <vector>
#include<cstring>

bool my_less(const char*str1, const char*str2) {
	int i = 0;
	while (str1[i] != '\0'){
		if (str2[i] == '\0') return false;
		if (str1[i] < str2[i]) { 
			return true; }
		else if (str1[i] > str2[i]) return false;	
		++i;
	}
	return true;
}

typedef char* data_t;
template <typename less_t>
void insertion_sort(data_t *begin,size_t size, less_t &less) {
	for (int i = 1; i < size; i++) {
		char* temp = new char[255];
		temp=begin[i];
		int j = i;
		for (; j > 0&&less(temp,begin[j-1]); --j) {			
				begin[j]=begin[j - 1];			
		}
		begin[j]=temp;	
	}
}

int main() {	
	int n;
	scanf("%d", &n);
	std::vector<data_t> data;	
	for (int i = 0; i < n; i++) {
		char * temp = new char[255];
		scanf("%s", temp);		
		data.push_back(temp);
	}
	insertion_sort(&data[0], n, my_less);
	for (int i = 0; i < n; i++) {
		printf("%s\n", data[i]);
	}
	system("pause");
	return 0;
}