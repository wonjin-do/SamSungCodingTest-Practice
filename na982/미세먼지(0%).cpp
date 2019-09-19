#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;


int R, C, T; // T초가 지난 후 방에 남아있는 미세먼지의 양을 구하여라
struct node {
	int y, x;
};
node cleaner[2];
int map[50][50];
int t = 0;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

int main() {

	scanf("%d %d %d", &R, &C, &T);
	int clean_idx = 0;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			int x;
			scanf("%d", &x);
			map[i][j] = x;
			if (x == -1)
				cleaner[clean_idx++] = { i,j };
		}
	}

	while (1) {
		int backup[50][50] = { 0, };

		for (int y = 0;y < R;y++) {
			for (int x = 0;x < C;x++) {
				if (map[y][x] != -1) {//미세먼지라면
					int posi_dir = 0;
					for (int d = 0;d < 4;d++) {
						int ty = y + dy[d];
						int tx = x + dx[d];
						if (map[ty][tx] == -1|| ty < 0 || ty >= R || tx < 0 || tx >= C)
							continue;
						backup[ty][tx] += map[y][x] / 5;
						posi_dir++;
					}
					backup[y][x] += (map[y][x] - (map[y][x] / 5) * posi_dir);
				}
			}
		}
		memcpy(map, backup, sizeof(backup));
		int backup[50][50] = { 0, };
		for (int y = 0;y < R;y++) {
			for (int x = 0;x < C;x++) {
				if (y == 0 && x != 0) {
					backup[y][x - 1] = map[y][x];
				}
				else if (x == 0 && (y < cleaner[0].y - 1)) {
					backup[y + 1][x] = map[y][x];
				}
				else if (y == cleaner[0].y && x != C) {
					backup[y][x + 1] = map[y][x];
				}
				else if (x == C && (y >= 1 && y <= cleaner[1].y)) {
					backup[y - 1][x] = map[y][x];
				}

				else if (y == cleaner[1].y && (x != 0 || x != C)) {

				}
			}
		}


		t++;
		if (t == T)
			break;

	}



	return 0;
}
