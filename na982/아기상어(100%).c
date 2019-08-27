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

int baby_size;
int baby_eat;

struct SHARK{
	int y, x;
	int time;
};
SHARK baby;

bool isFindEat = true;
void BFS() {
	queue<SHARK> Queue;
	bool visited[maxN][maxN] = { false, };
	//visited
	Queue.push(baby);
	visited[baby.y][baby.x] = true;
	SHARK proper;
	proper.y = 20, proper.time = -1;
	while (!Queue.empty()) {
		SHARK curr = Queue.front(); Queue.pop();
		if (proper.time != -1 && curr.time > proper.time)//적절한 먹이가 나타났고 && 시간이 오버된경우
			break;
		// 처음 curr.time = 0 , proper.time = -1  (baby.time = 0)
		// 중간 curr.time = 4 , proper.time = -1
		// 나중 curr.time = 5 , proper.time = 4
		if (map[curr.y][curr.x] > 0 && map[curr.y][curr.x] < baby_size)//
		{
			isFindEat = true;
			if (curr.y < proper.y || (curr.y == proper.y && curr.x < proper.x)) {
				proper = curr;
			}
		}
		//이동을 위한 코드
		for (int d = 0; d < 4; d++) {
			SHARK next = curr;
			next.y = curr.y + dy[d];
			next.x = curr.x + dx[d];
			next.time = curr.time + 1;
			bool bound = (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N);
			if (bound)
				continue;
			if (!visited[next.y][next.x] && baby_size >= map[next.y][next.x]) {
				visited[next.y][next.x] = true;
				Queue.push(next);
			}
		}
	}
	if (isFindEat) {
		baby = proper;
		baby_eat++;
		if (baby_size == baby_eat) {
			baby_size++;
			baby_eat = 0;
		}
		map[baby.y][baby.x] = 0;
	}

}
int main(){
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				map[i][j] = 0;
				baby.y = i;	baby.x = j;	baby.time = 0;
				baby_size = 2;  baby_eat = 0;
			}
		}
	while (isFindEat) {
		isFindEat = false;
		BFS();
	}
	printf("%d\n", baby.time);
}
