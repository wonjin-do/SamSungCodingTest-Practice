
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

		int status[50][50] = { 0, };
		int area_idx = 0;
		int sum[2501] = { 0, };
		int count[2501] = { 0, };

		for (int y = 0;y < n;y++) {
			for (int x = 0;x < n;x++) {
				if (status[y][x] == 0) {
					area_idx++;
					
					int visited[50][50] = { 0, };//방문기록
					queue<POSI> q;
					POSI head;
					head.y = y;
					head.x = x;
					visited[y][x] = 1;
					head.num = map[y][x];
					q.push(head);

					status[y][x] = area_idx;
					sum[area_idx] += map[y][x];
					count[area_idx] ++;
					
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
							if (delta >= l && delta <= r && !visited[next.y][next.x]) {
								visited[next.y][next.x] = 1;
								
								status[next.y][next.x] = area_idx;
								count[area_idx] ++;
								sum[area_idx] += map[next.y][next.x];
								
								q.push(next);
							}


						}

					}
				}
			}
		}

		for (int y = 0;y < n;y++) {
			for (int x = 0;x < n;x++) {
				int idx = status[y][x];
				int avg = sum[idx] / count[idx];
				if (map[y][x] != avg) {
					map[y][x] = avg;
					is_update = true;

				}
			}
		}

		if (is_update)
			ret++;

	}

	printf("%d\n",ret);

	return 0;
}
