#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<queue>

using namespace std;
/*
*/
int N, M; //지도의 행,열
const int maxL = 20;
int T;
int R, C, L;
const int maxSize = 50;
int map[maxSize][maxSize];
struct node {
	int y, x;
	int time;
};

const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
const int tunnel[8][4] = {
	{0,0,0,0}
	,{1,1,1,1}
	,{1,0,1,0}
	,{0,1,0,1}
	,{1,1,0,0}
	,{0,1,1,0}
	,{0,0,1,1}
	,{1,0,0,1}
};
bool visited[maxSize][maxSize] = { false, };
int cnt = 0;
void printVisited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
}
void DFS(node curr) {
	/*
		for (int i = 0; i < t; i++) {
			printf(">");
		}
	*/
	visited[curr.y][curr.x] = true;
	cnt++;
	//printf("%d초\n", curr.time);
	//printVisited();
	//printf("\n");

	for (int dir = 0; dir < 4; dir++) {
		node next = curr;
		if (tunnel[map[curr.y][curr.x]][dir]) {
			next.y += dy[dir];
			next.x += dx[dir];
			next.time++;
			if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M)
				continue;
			if (tunnel[map[next.y][next.x]][(dir + 2) % 4]
				&& !visited[next.y][next.x]
				&& next.time <= L) {
				DFS(next);
			}
		}
	}
}

void BFS(node start) {
	queue<node> Queue;
	visited[start.y][start.x] = true;
	cnt++;
	Queue.push(start);

	while (!Queue.empty()) {
		node curr = Queue.front(); Queue.pop();
	//	printf("%d초 (%d %d)\n", curr.time,curr.y,curr.x);
	//	printVisited();
	//	printf("\n");
		

		for (int dir = 0; dir < 4; dir++) {
			node next = curr;
			if (tunnel[map[curr.y][curr.x]][dir]) {
				next.y += dy[dir];
				next.x += dx[dir];
				next.time++;
				if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M)
					continue;
				if (!visited[next.y][next.x] && next.time <= L && tunnel[map[next.y][next.x]][(dir + 2) % 4]) {
					visited[next.y][next.x] = true;//반드시 push할때 같이 visited체크해줄것. pop을 한 이후에 visited를 체크하게 되면 오류 이유: 큐에서 pop되기 전까지 visited가 안된 상태가 되며, 이후 push되는 값들에 영향을 미침
					cnt++;
				//	printf("%d개\n",cnt);
					Queue.push(next);
				}
			}
		}


	}
}


void read() {
	scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
void init() {
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}
}

void solve() {
	node curr = { R,C,1 };
	//BFS(curr);
	DFS(curr);
}

int main() {

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		read();
		init();
		solve();
		printf("#%d %d\n", i + 1, cnt);
	}

	return 0;
}
