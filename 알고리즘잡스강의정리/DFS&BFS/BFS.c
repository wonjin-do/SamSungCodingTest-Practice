/*
	너비우선 탐색(BFS)
	1 ----- 2  ------ 6
	 \	   / \		 /	
	  \	  /   4 --- 5
	   \ /   / \
	    3 - 7 - 8 - 9
*/
/*
9 12
1 2
1 3
2 3
2 4
2 6
3 7
4 5
4 7
4 8
5 6
7 8
8 9
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int n, m;
const int MAX = 100;
vector<int> myGraph[MAX];

void BFS() {
	bool check[MAX] = { 0, };
	queue<int> Queue;

	//1. 시작점을 큐에 push	//2. 방문체크
	Queue.push(1);
	check[1] = true;// 자! 원칙을 정하자. 방문체크 check[ ] = true 하고 queue에 Push!!
	
	//BFS 시작!
	while (Queue.empty() == false) {
		//3. 큐에서 pop
		int curr = Queue.front(); Queue.pop();

		printf("%d ", curr);//원하는 기능을 넣는곳 

		//4. 인접한 모든 정점에게 방문했는지 묻기
		for (int i = 0; i < myGraph[curr].size(); i++) {
			int next = myGraph[curr][i];
			if (check[next] == false) {
				check[next] = true;
				Queue.push(next);// 자! 원칙을 정하자. 방문체크 check[ ] = true 하고 queue에 Push!!
			}
		}

		//5. 모두 완료했다면 다시 3. 으로 돌아가기
	}
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		myGraph[a].push_back(b);
		myGraph[b].push_back(a);
	}
	BFS();
	return 0;
}
