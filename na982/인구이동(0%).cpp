
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int n, l, r;

int map[50][50];

struct POSI {
	int y, x;
	int num;
};
int ret = 0;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

int main() {

	scanf("%d %d %d", &n, &l, &r);

	for (int y = 0;y < n;y++) {
		for (int x = 0;x < n;x++) {
			scanf("%d", &map[y][x]);
		}
	}

	bool is_update = true;

	while (is_update) {
		is_update = false;

		int assign[50][50] = { 0, };
		int neigh_idx = 0;
		int neigh_tot[2501] = { 0, };
		int neigh_count[2501] = { 0, };

		for (int y = 0;y < n;y++) {
			for (int x = 0;x < n;x++) {
				if (assign[y][x] == 0) {
					neigh_idx++;
					
					int check[50][50] = { 0, };//방문기록
					queue<POSI> q;
					POSI start;
					start.y = y;
					start.x = x;
					check[y][x] = 1;
					q.push(start);

					assign[y][x] = neigh_idx;
					neigh_tot[neigh_idx] += map[y][x];
					neigh_count[neigh_idx] ++;

					start.num = map[y][x];

					while (!q.empty()) {
						POSI curr = q.front(); q.pop();

						for (int d = 0;d < 4;d++) {
							POSI next = curr;
							next.y += dy[d];
							next.x += dx[d];
							next.num = map[next.y][next.x];
							if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n)
								continue;
							int delta = abs(curr.num - next.num);
							if (delta >= l && delta <= r && !check[next.y][next.x]) {
								check[next.y][next.x] = 1;
								
								assign[next.y][next.x] = neigh_idx;
								neigh_count[neigh_idx] ++;
								neigh_tot[neigh_idx] += map[next.y][next.x];
								
								q.push(next);
							}


						}

					}
				}
			}
		}

		for (int y = 0;y < n;y++) {
			for (int x = 0;x < n;x++) {
				int idx = assign[y][x];
				int avg = neigh_tot[idx] / neigh_count[idx];
				if (map[y][x] != avg) {
					map[y][x] = avg;
					is_update = true;

				}
			}
		}

		if (is_update)
			ret++;

	}

	printf("%d\n", ret);

	return 0;
}
