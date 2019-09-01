#include<stdio.h>
const int MAX = 100;
/*
	노드번호
			1
	     2     3
	   4  5   6  7
*/

/*
	값
			1
		 3     7
	   4  8   9  10
	 2(추가)
*/

/*
	값
			1
		 3     7
	   2  8   9  10
	 4  
*/

/*
	값
			1
		 2     7
	   3  8   9  10
	 4
*/

struct priorityQueue {
	int data[MAX];
	int len = 1;//새로운 데이터의 위치

	void push(int x) {
		data[len++] = x;
		int idx = len - 1;// 새로운 데이터의 위치정보를 수시로 이 변수에 업뎃할것임
		while (idx > 1) { // 루트노드가 아닐때만
			if (data[idx] < data[idx / 2]) {
				int temp = data[idx];
				data[idx] = data[idx / 2];
				data[idx / 2] = temp;
				idx = idx / 2; // 자리바꾸면 업뎃!
			}
			else 
				break;
		}
	}

	void pop() {
		data[1] = data[len - 1];// len은 newData가 저장될 위치를 미리 가르키는 것임. 따라서 data[]의 마지막 데이터는 len-1에 있음.
		data[len - 1] = 0;
		len--;

		int idx = 1;
		while (1) {
			int pIdx = -1;// 우선순위가 높은 친구의 노드번호
			
			//0. (중요) 왼쪽, 오른쪽 자식들중에 존재하는 것
			
			//(A) 자식이 모두 없는 경우
			if (idx * 2 >= len)
				break;
			//(B) 왼쪽만 존재 && 오른쪽자신은 없는 경우
			else if (idx * 2 >= 1 && idx * 2 < len && idx * 2 + 1 >= len)
			{
				pIdx = idx * 2;
			}
			//(C) 자식이 모두 있는 경우
			else {
				//양쪽 중 우선순위가 높은 친구를 알아내야 함.	
				if (data[idx * 2] < data[idx * 2 + 1])
					pIdx = idx * 2;
				else
					pIdx = idx * 2 + 1;       
			}
			//부모(idx)의 자식노드 번호가 pIdx에 저장됨..
			
			//2. 나와 그 우선순위가 높은 친구를 비교해서 자리를 바꾸어야함.
			if (data[idx] > data[pIdx]) {
				int temp = data[idx];
				data[idx] = data[pIdx];
				data[pIdx] = temp;
				idx = pIdx;
			}
			else {
				break;
			}
		}
	}

	int top() {
		return data[1];
	}

};

int main() {
	priorityQueue myPQ;
	
	myPQ.push(3);
	myPQ.push(89);
	myPQ.push(7);

	printf("%d\n", myPQ.top());
	myPQ.pop();

	printf("%d\n", myPQ.top());
	myPQ.pop();

	printf("%d\n", myPQ.top());
	myPQ.pop();
	return 0;
}
