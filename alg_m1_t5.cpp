/*Скобочная последовательность.

Дан фрагмент последовательности скобок, состоящей из символов (){}[].

Требуется определить, возможно ли продолжить фрагмент в обе стороны, получив корректную

последовательность.

Длина исходной последовательности ≤ 200000.

Формат входных данных. Строка, содержащая символы (){}[] и, возможно, перевод строки.

Формат выходных данных. Если возможно ­ вывести минимальную корректную последовательность, иначе ­

напечатать "IMPOSSIBLE​".

*/

#include <iostream>
#include <assert.h> 
#include <string>

using std::cout;
using std::cin;

class stack {
private:
	int buffSize;
	char* buff;
public:
	int top;
	explicit stack(int size = 1) {
		top = -1;
		buffSize = size;
		buff = new char[buffSize];
	}
	~stack() {
		delete[] buff;
	}
	void push(char elem) {
		if (top + 1 == buffSize) {
			int newbuffSize=buffSize *2;
			char* tempBuff = new char[newbuffSize];
			for (int i = 0; i < buffSize; i++) tempBuff[i] = buff[i];
			delete[] buff;
			buffSize = newbuffSize;
			buff = tempBuff;			
		}
		++top;
		buff[top] = elem;

	}
	char pop() {
		assert(top != -1);
		return buff[top--];
	}
	bool isEmpty() {
		if (top == -1) return true;
		else return false;
	}
	int size() {
		return top+1;
	}
	
};

bool checkChain(std::string chain, stack *open, stack *close) {
	int n = chain.length();
	char temp;
	for (int i = 0; i < n; ++i) {
		if (chain[i] == '{' || chain[i] == '[' || chain[i] == '(') {
			switch (chain[i]) {
			case '{':
				close->push('}');
				break;
			case '(':
				close->push(')');
				break;
			case '[':
				close->push(']');
				break;
			}
		}
		else {
			if (close->isEmpty()) {
				switch (chain[i]) {
				case '}':
					open->push('{');
					break;
				case ')':
					open->push('(');
					break;
				case ']':
					open->push('[');
					break;
				}
			}
			else {
				temp = close->pop();
				if (temp != chain[i]) {					
					return false;
				}
			}
		}
	}
	return true;
}

void print(stack* st) {
	int n = st->size();
	for (int i = 0; i < n; i++) {
		cout << st->pop();
	}
}
void print(std::string st) {
	int n = st.length();
	for (int i = 0; i < n; i++) {
		cout << st[i];
	}
}
int main() {
	std::string chain;
	stack open, close;
	cin >> chain;
	if (checkChain(chain,&open,&close)) {
		print(&open);
		print(chain);
		print(&close);
	}
	else cout << "IMPOSSIBLE";
	system("pause");
	return 0;
}