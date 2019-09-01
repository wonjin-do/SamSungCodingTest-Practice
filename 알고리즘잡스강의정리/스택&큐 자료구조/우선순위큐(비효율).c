#include<stdio.h>
const int MAX = 100;
//주의. Stack Overflow와 underflow를 고려하지 않음
struct priorityQueue {
	//		0 1 2 3 4 5 6 7
	//data  1 4 5 7 6 2 1 3
	//data  1 4 5 6 2 1 3
	//data  1 4 5 2 1 3
	//data  1 4 2 1 3
	//data  1 2 1 3
	//data  1 2 1 
	//data  1 1
	int data[MAX];
	int len = 0;//새로운 데이터의 위치idx

	void push(int x) {
		data[len++] = x;
	}
	void pop() {
		//1.우선순위가 가장높은 원소를 찾는다.(찾는 방법은 선형탐색for문)
		//2. 그 원소를 제거하고, 그 뒤의 원소를 앞으로 당긴다.
		int myMax = -987987987, myMaxIdx = -1;
		for (int i = 0; i < len; i++) {
			if (data[i] > myMax) {
				myMax = data[i];
				myMaxIdx = i;
			}
		}
		for (int i = myMaxIdx; i < len; i++) {
			data[i] = data[i + 1];
		}
		len--;
	}
	int top() {
		int myMax = -987987987;
		for (int i = 0; i < len; i++) {
			if (data[i] > myMax) {
				myMax = data[i];
			}
		}
		return myMax;
	}
};

int main() {
	priorityQueue myPQ;

	myPQ.push(1);
	myPQ.push(8);
	myPQ.push(7);
	myPQ.push(5);

	printf("%d\n", myPQ.top());
	myPQ.pop();
	printf("%d\n", myPQ.top());
	myPQ.pop();
	printf("%d\n", myPQ.top());
	myPQ.pop();
	printf("%d\n", myPQ.top());
	myPQ.pop();

	return 0;
}
