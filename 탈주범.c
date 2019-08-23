#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
*/
int N, M; //지도의 행,열
const int maxL = 20;
int T;
int R, C, L;
const int size = 50;
int map[size][size];
struct node {
	int y, x;
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
bool visited[size][size] = { false, };
int cnt = 0;
void DFS(node curr, int t) {
	printf("(%d, %d) ", curr.y, curr.x);
	visited[curr.y][curr.x] = true;
	cnt++;
	node next = curr;
	
	for (int i = 0; i < 4; i++) {
		if (tunnel[map[curr.y][curr.x]][i]) {
			printf("\n(i: %d) ", i);
			next.y += dy[i];
			next.x += dx[i];
			if(map[next.y][next.x] && !visited[next.y][next.x] && t<L)
				DFS(next, t + 1);
		}
	}
}

void read() {
	scanf("%d%d%d%d%d", &N, &M, &R, &C, &L);
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
	node curr = { R,C, };
	DFS(curr, 1);
}

int main() {

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		read();
		init();
		solve();
		printf("\n%d\n", cnt);
	}

	return 0;
}
