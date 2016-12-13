/*Во всех задачах из следующего списка следует написать структуру данных, обрабатывающую команды
push* и pop*.
Формат входных данных.
В первой строке количество команд n. n ≤ 1000000.
Каждая команда задаётся как 2 целых числа: a b.
a = 1 ­ push front
a = 2 ­ pop front
a = 3 ­ push back
a = 4 ­ pop back
Для очереди используются команды 2 и 3. Для дека используются все четыре команды.
Если дана команда pop*, то число b ­ ожидаемое значение.Если команда pop вызвана для пустой структуры
данных, то ожидается “­1”.
Формат выходных данных.
Требуется напечатать YES ­ если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не
оправдалось, то напечатать NO.
​Реализовать очередь с помощью двух стеков. Использовать стек, реализованный с помощью
динамического буфера.*/

#include <iostream>;
#include <assert.h> 
using std::cout;
using std::cin;
class stack {
private:
	int buffSize;	
	int* buff;	
public:
	int top;
	explicit stack(int size=1) {
		top = -1;
		buffSize = size;
		buff = new int[buffSize];
	}
	~stack() {
		delete[] buff;
	}
	void push(int elem) {
		if (top+1 == buffSize){		
			int newbuffSize = buffSize*2;			
			int* tempBuff = new int[newbuffSize];
			for (int i = 0; i < buffSize; i++) tempBuff[i] = buff[i];
			delete[] buff;
			buffSize = newbuffSize;
			buff = tempBuff;			
		}
		++top;
		buff[top] = elem;

	}
	int pop() {
		assert(top != -1);
		return buff[top--];
	}
};
class queue {
private:
	stack initial;
	stack final;
public:
	void push(int elem) {
		initial.push(elem);
	}
	int pop() {
		int n = initial.top;
		for (int i = 0; i <=n; i++) {
			final.push(initial.pop());
		}
		int elem = final.pop();
		for (int i = 0; i <n; i++) {
			initial.push(final.pop());
		}
		return elem;
	}
	bool isEmpty() {
		if (initial.top == -1) return true;
		else return false;
	}
};

bool expectedValue(int n) {
	queue a;
	int command = 0, value = 0, realValue=0;
	for (int i = 0; i < n; ++i) {
		cin >> command >> value;
		if (command == 3) {
			a.push(value);
		}
		else {
			if (a.isEmpty()) realValue=-1;		
			else realValue= a.pop();
			if (realValue != value) return false;
		}
	}
	return true;
}

int main() {		
	int n = 0;
	cin >> n;
	if (expectedValue(n)) cout << "YES";
	else cout << "NO";
	system("pause");
	return 0;
}