#include<stdio.h>

struct Stack {
	int data[100];
	int len;
	int capacity;
	void create(int y) {
		capacity = y;
		len = 0;
	}
	void push(int y) {
		if (len >= capacity) {
			printf("Stack Overflow\n");
			return;
		}
		data[len++] = y;
	}
	void pop() {
		if (len <= 0) {
			printf("Stack underflow\n");
			return;
		}
		data[len - 1] = 0;
		len--;
	}
	int top() {
		if (len == 0)
			return -1;
		return data[len - 1];
	}
	int size() {
		return len;
	}
};



int main() {
	Stack s1;
	s1.create(5);
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.push(7);
	printf("%d\n", s1.top()); // 5
	s1.pop();
	printf("%d\n", s1.top()); //4

	s1.push(6);
	s1.push(7);//overflow
	printf("%d\n", s1.top()); //6

	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();

	s1.pop();//underflow

	printf("%d\n", s1.size());





	return 0;
}
