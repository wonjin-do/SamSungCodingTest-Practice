#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

const int maxn = 115;
#define BLOCK_NUMBER 6
#define DIRECTION 4

int map[maxn][maxn];
int wormholePos[5][2];
int ans;
int T, N;

const int dy[4] = { 0,0,1,-1 };
const int dx[4] = { 1,-1,0,0 };
const int changeDirection[BLOCK_NUMBER][DIRECTION] = {
	{0,1,2,3}
	,{1,3,0,2}
	,{1,2,3,0}
	,{2,0,3,1}
	,{3,0,1,2}
	,{1,0,3,2}
};
void read() {
	scanf("%d", &N);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;j++)
			scanf("%d", &map[i][j]);
}

void setupThewall() {
	for (int i = 0; i <= N + 1; ++i)
		map[i][0] = map[i][N + 1] = map[0][i] = map[N + 1][i] = 5;
}

void wormhole(int& ny, int& nx, int wormhole_number) {
	for(int i=1;i<=N;++i)
		for (int j = 1; j <= N; j++) {
			if ((ny != i || nx != j) && map[i][j] == wormhole_number) {
				ny = i; nx = j;
				return;
			}
		}
}

void simulate(int sy, int sx, int d) {
	int y = sy;
	int x = sx;
	int cnt = 0;
	while (1) {
		int ny = y + dy[d];
		int nx = x + dx[d];
		if ((nx == sx && ny == sy) || map[ny][nx] == -1) {
			if (ans < cnt) ans = cnt;
			return;
		}
		if (map[ny][nx]) {
			if (map[ny][nx] < 6) {
				d = changeDirection[map[ny][nx]][d];
				cnt++;
			}
			else
				wormhole(ny, nx, map[ny][nx]);
		}
		x = nx;
		y = ny;
	}
}

void solve() {
	ans = 0;
	for(int i=1;i<=N;++i)
		for (int j = 1; j <= N; ++j) {
			if (map[i][j])continue;
			for (int d = 0; d < DIRECTION; ++d)
				simulate(i, j, d);
		}
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t < T; ++t) {
		read();
		setupThewall();
		solve();
		printf("#%d %d\n", t, ans);
	}
}
