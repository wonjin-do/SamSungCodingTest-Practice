#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int maxN = 20;
int N;
int map[maxN][maxN];

const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

struct shark {
	int y, x;
	int size;
	int prey;
	int time;
};
shark baby = { 0,0,2,0,0 };

void read() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				map[i][j] = 0;
				baby.y = i;
				baby.x = j;
			}
		}
}
void BFS() {
	queue<shark> Queue;
	bool visited[maxN][maxN] = { false, };
	//visited
	Queue.push(baby);
	visited[baby.y][baby.x] = true;
	shark ans = { N - 1,N - 1,0,0,0 };
	while (!Queue.empty()) {
		shark curr = Queue.front(); Queue.pop();
		for (int d = 0; d < 4; d++) {
			shark next = curr;
			next.y = curr.y + dy[d];
			next.x = curr.x + dx[d];
			next.time = curr.time + 1;
			bool bound = (next.y >= 0 && next.y < N && next.x >= 0 && next.x < N);
			if (bound && !visited[next.y][next.x]) {
				if (baby.size >= map[next.y][next.x]) {
					Queue.push(next);
				}
				else if( (next.y <= ans.y) && ( next.x < ans.x )) {
					next = ans;
				}
			}
		}
	}
}
void solve() {
	while (1) {
		
	}
}
