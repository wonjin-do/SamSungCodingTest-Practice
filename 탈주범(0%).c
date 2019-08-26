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
/*
	for (int i = 0; i < t; i++) {
		printf(">");
	}
*/
	
	/*
	5 6 2 1 3      
0 0 5 3 6 0
0 0 2 0 2 0
3 3 1 3 7 0
0 0 0 0 0 0
0 0 0 0 0 0
	*/
	visited[curr.y][curr.x] = true;
	cnt++;
	

	for (int dir = 0; dir < 4; dir++) {
		node next = curr;
		if (tunnel[map[curr.y][curr.x]][dir]) {
			next.y += dy[dir];
			next.x += dx[dir];
			if (tunnel[map[next.y][next.x]][(dir + 2) % 4] 
				&& !visited[next.y][next.x] 
				&& t < L
				&& next.y >= 0 && next.y < N && next.x >= 0 && next.x < M) {
					DFS(next, t + 1);
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
	node curr = { R,C };
	DFS(curr, 1);
}

int main() {

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		read();
		init();
		solve();
		printf("#%d %d\n",i+1, cnt);
	}

	return 0;
}
