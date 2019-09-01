#include<stdio.h>

struct Queue {
	int data[100];
	int f, r;
	int capacity;
	int len;
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
		len = 0;
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
		if (len >= capacity)
			printf("Queue overflow\n");
		else {
			data[r++] = y;
			r = r % capacity;
			len++;
		}
			
	}

	void pop() {
		if (len<= 0)
			printf("Queue underflow\n");
		else
		{
			data[f] = 0;
			f++;
			f = f % capacity;
			len--;
		}
	}

	int front() {
		if (len<= 0) {
			return -1;
		}
		return data[f];
	}
	int size() {
		return len;
	}
};

int main(void) {
	Queue q;
	q.create(4);

	for (int i = 0; i < 4; i++) {
		q.push(i+1);
		q.push(i+2);
		q.push(i+3);
		q.push(i+4);

		q.pop();
		q.pop();
		q.pop();
		q.pop();
	}

	q.push(1);
	q.push(2);

	printf("%d\n", q.front());//1 예상
	q.pop();
	printf("%d\n", q.front());//2 예상
	q.pop();
	
	return 0;
}
