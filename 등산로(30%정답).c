#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int maxn = 8;

int T;
int N;
int K;//최대 깊이
int map[maxn][maxn] = { 0, };
int highest;

struct node{
	int y, x;
	int h;
	int used;
};
int maxLength = 0;
bool visited[maxn][maxn] = { false, };
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
void init() {
	maxLength = 0;
	highest = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visited[i][j] = false;
}
void read() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			highest = highest > map[i][j] ? highest : map[i][j];
		}
			
}
inline int max(int a, int b) {
	return a > b ? a : b;
}
inline int abs(int a) {
	return a > 0 ? a : -a;
}
bool used;//true 사용함, false 아직안사용(기본)

void DFS(node cur, int len,int depth) {
	for (int i = 0; i < depth; i++) {
		//printf(">");
	}
	//printf("(%d, %d)%d\n", cur.y, cur.x,cur.h);
	len++;
	visited[cur.y][cur.y] = true;
	maxLength = max(maxLength, len);
	for (int i = 0; i < 4; i++) {
		node next;
		next.y = cur.y + dy[i];
		next.x = cur.x + dx[i];
		next.h = map[next.y][next.x];
		next.used = false;
		bool isBound = (next.y >= 0 && next.y < N && next.x >= 0 && next.x < N);
		
		if (isBound && !visited[next.y][next.x]) {
			if (next.h < cur.h)
			{
				//printf("다음이 작다.");
				DFS(next, len, depth + 1);
				visited[next.y][next.x] = false;
			}
			else if (cur.used == false && (map[next.y][next.x] - K) < cur.h) {
				//printf("다음이 크다.");
				//printf("깍기신공");
				next.h = cur.h - 1;
				next.used = true;
				DFS(next, len,depth+1);
				visited[next.y][next.x] = false;
				
			}
		}
	}
}
void solve() {
	
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++) {
			
			if (map[i][j] == highest) {
				
				node start = { i,j, map[i][j], false };
				DFS(start, 0, 1);
			}
		}
}

int main(void) {
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		
		init();
		read();
		solve();
		printf("#%d %d\n",i+1,maxLength);
	}
	return 0;
}
