#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int maxn = 8;

int T;
int N;
int K;//최대 가능한 공사깊이
int map[maxn][maxn] = { 0, };// (y,x) 위치에 높이 h가 담겨져 있음
int highest;

struct node {
	int y, x;
	int h;
	int len;
	bool used;
};
int maxLength = 0;//정답변수
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
	//printf("highest Height: %d\n", highest);
}
inline int max(int a, int b) {
	return a > b ? a : b;
}
inline int abs(int a) {
	return a > 0 ? a : -a;
}
void printVisited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
}
void DFS(node cur,int depth) {
	for (int i = 0; i < depth; i++) {
	//	printf(">");
	}
	//printf("(%d, %d)%d\n", cur.y, cur.x,cur.h);
	visited[cur.y][cur.x] = true;// 행과 열에 둘다 [cur.y][cur.y] 를 넣는 실수를 범함ㅠㅠ
	//printVisited();
	if (cur.len > maxLength) {
		//printf("길이갱신 %d \n",cur.len);
		maxLength = cur.len;
	}

	for (int i = 0; i < 4; i++) {
		node next;
		next.y = cur.y + dy[i];
		next.x = cur.x + dx[i];
		next.h = map[next.y][next.x];
		next.len = cur.len + 1;
		next.used = cur.used;//cur의 사용기록을 그대로
		bool isBound = (next.y >= 0 && next.y < N && next.x >= 0 && next.x < N);
		if (!isBound)
			continue;
		if ( !visited[next.y][next.x]) { //DFS 재귀호출 영역 - 문제의 조건에 따라 if-else문으로 처리
			if (next.h < cur.h)
			{
				DFS(next,  depth + 1);
			}
			else if (cur.used == false && (next.h - K) < cur.h) {
				next.h = cur.h - 1;
				next.used = true;
				//printf("공사진행함\n");
				DFS(next, depth + 1);
			}
		}
	}
	//DFS를 마쳤다면 자신이 방문한 cur 노드의 방문기록을 지워준다.
	visited[cur.y][cur.x] = false;// ★★★★★가장 중요한듯....

}
void solve() {

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {

			if (map[i][j] == highest) {

				node start = { i,j, map[i][j], 1, false };
				DFS(start, 1);
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
		printf("#%d %d\n", i + 1, maxLength);
	}
	return 0;
}
