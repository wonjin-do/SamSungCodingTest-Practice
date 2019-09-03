#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<queue>
//벽돌깨기

using namespace std;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

int N, W, H;
int map[15][12] = { 0, };
int testMap[15][12] = { 0, };
struct node {
	int y, x;
	int dis;
};
void read() {
	scanf("%d %d %d", &N, &W, &H);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

bool visited[15][12] = { 0, };

void initMap() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			testMap[i][j] = map[i][j];
		}
	}
	
}
void printVisted() {
	printf("방문기록\n");
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
}

void printTestMap() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			printf("%d ", testMap[i][j]);
		}
		printf("\n");
	}
}

void bomb(int col) {
	int row;
	int find = false;
	for (int r = 0; r < H; r++) {
		if (testMap[r][col] != 0) {
			row = r;//투하될 행
			find = true;
			break;
		}
	}
	if (!find)return;
	//(row,col) 에 투하됨.
	queue<node> Queue;
	visited[row][col] = true;
	node start = { row,col,testMap[row][col] };
	testMap[row][col] = 0;
	//printf("%d %d\n", row, col);
	Queue.push(start);
	
	while (!Queue.empty()) {
		
		node curr = Queue.front(); Queue.pop();
		//printf("%d %d %d\n", curr.y, curr.x, curr.dis);
		for (int dis = 1; dis < curr.dis; dis++) {
			//printf("test\n");
			for (int dir = 0; dir < 4; dir++) {
				node next = curr;
				next.y += dis * dy[dir];
				next.x += dis * dx[dir];
				next.dis = testMap[next.y][next.x];
				if (next.y < 0 || next.y >= H || next.x < 0 || next.x >= W || testMap[next.y][next.x] == 0) {
					continue;//영역 밖 이거나 벽돌이 없을 떄
				}
				if (!visited[next.y][next.x]) {
					visited[next.y][next.x] = true;
					testMap[next.y][next.x] = 0;
					Queue.push(next);
				}
			}
		}
	}
	//printVisted();
}

void arrange() {
	for (int x = 0; x < W; x++) {
		for (int y = H - 1; y >= 0; y--) {
			if (testMap[y][x] == 0) {
				for (int a = y-1; a >= 0; a--) {
					if (testMap[a][x] != 0) {
						testMap[y][x] = testMap[a][x];
						testMap[a][x] = 0;
						break;
					}
					
				}
			}
		}
	}
	//printTestMap();
}
int min(int a, int b) {
	
	return a > b ? b : a;
}

int countRemain() {
	int remain = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (testMap[i][j] != 0)
				remain++;
		}
	}
	return remain;
}
int main()
{
	/*
	5 3 10 10 0 0 0 0 0 0 0 0 0 0 1 0 1 0 1 0 0 0 0 0 1 0 3 0 1 1 0 0 0 1 1 1 1 0 1 2 0 0 0 9 1 1 4 0 1 1 0 0 1 1 1 1 4 1 1 1 2 1 1 1 1 1 5 1 1 1 1 2 1 1 1 1 6 1 1 1 1 1 2 1 1 1 1 1 1 1 1 1 1 5 1 1 7 1 1 1 1 1 1 1 2 9 10 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 1 1 0 1 1 1 0 1 0 1 1 0 1 1 1 0 1 0 1 1 1 1 1 1 1 1 0 1 1 3 1 6 1 1 1 1 1 1 1 1 1 1 1 1 1 3 6 7 1 1 0 0 0 0 1 1 0 0 1 0 1 1 0 0 4 0 4 1 0 0 1 0 1 5 1 0 1 6 1 2 8 1 1 6 1 1 1 9 2 1 4 4 15 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 0 5 0 1 1 1 0 1 1 1 9 1 1 1 1 1 6 1 2 1 1 1 5 1 1 1 1 2 1 1 2 4 12 15 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9
	*/
	int T;
	int B[4];
	
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int remain = 10000000;
		read();
		initMap();
		int x[4];
		for (B[0] = 0; B[0] < W; B[0]++) {
			for (B[1] = 0; B[1] < W; B[1]++) {
				for (B[2] = 0; B[2] < W; B[2]++) {
					for (B[3] = 0; B[3] < W; B[3]++) {
		//				printf("(%d %d %d %d)\n", B[0], B[1], B[2], B[3]);
						initMap();
						for (int r = 0; r < N; r++) {
							for (int i = 0; i < H; i++) {
								for (int j = 0; j < W; j++) {
									visited[i][j] = 0;
								}
							}
							bomb(B[r]);
							arrange();
						}
						if (remain > countRemain()) {
							x[0] = B[0], x[1] = B[1], x[2] = B[2], x[3] = B[3];
							remain = countRemain();
						}

						if (N < 4)break;
					}
					if (N < 3)	break;
				}
				if (N < 2) break;
			}
		}
		printf("#%d %d\n",t, remain);

	}
	return 0;
}
