#include<stdio.h>

struct Queue {
	int data[100];
	int f, r;
	int capacity;
	//     0 1 2 3 4 5 6 7
	//data 1 2 3 4
	//     f       r
	void create(int y) {
		//     0 1 2 3 4 5 6 7
		//data 0 0 0 0 0 0 0 0	
		//     f
		//     r
		capacity = y;
		f= 0;
		r= 0;
	}

	void push(int y) {
		//     0 1 2 3 4 5 6 7
		//data 1 0 0 0 0 0 0 0	
		//	   f
		//       r

		//     0 1 2 3 4 5 6 7
		//data 1 2 0 0 0 0 0 0	
		//	   f
		//         r
		if (r - f >= capacity)
			printf("Queue overflow\n");
		else
			data[r++] = y;
	}

	void pop() {
		if (r - f<= 0)
			printf("Queue underflow\n");
		else
		{
			data[f] = 0;
			f++;
		}
	}

	int front() {
		if (r- f<= 0) {
			return -1;
		}
		return data[f];
	}
	int size() {
		return r - f;
	}
};

int main(void) {
	Queue q;
	q.create(3);

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	printf("%d\n", q.front());
	//1 2 3
	q.pop();
	q.pop();

	//3
	printf("%d\n", q.front());
	printf("%d\n", q.size());

	q.pop();
	q.pop();//underflow

	printf("%d\n", q.size());

	return 0;
}
