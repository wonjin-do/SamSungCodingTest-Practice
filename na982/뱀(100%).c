#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
const int dy[] = { 0,1,0,-1 };
const int dx[] = { 1,0,-1,0 };

int map[101][101] = { 0, };// 뱀 1, 사과2
char cmd[10001];

//head의 자취배열 (시간에 따라)
int snake_y[10100 + 1];
int snake_x[10100 + 1];

//위의 head배열을 갱신하기 위해서는 변수를 이용하는 것이 편리함
int head_y = 1;
int head_x = 1;

//tail은 head의 배열을 하나씩 따라감, y x로 다룰 필요없음
int tail_idx = 0;
int time = 0;

int dir = 0;

int N, K;
int L;

void read() {
	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int x, y;
		scanf("%d %d", &y, &x);
		map[y][x] = 2;//사과는 2
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		int time,c;
		scanf("%d %c", &time,&c);
		cmd[time] = c;
	}
}

void init() {
	snake_y[time] = 1;
	snake_x[time] = 1;//첫 헤드
	map[1][1] = 1;
	
}

void printArr() {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1)
				printf("* ");
			else if (map[i][j] == 2)
				printf("A ");
			else
				printf("0 ");

		}
		printf("\n");
	}
	printf("time: %d 회전: %c\n", time, cmd[time]);
	printf("head_y, head_x (%d, %d) %d\n", head_y, head_x, map[head_y][head_x]);
}
int main(void) {
	read();
	init();

	while (1) {
		time++;

		head_y += dy[dir];
		head_x += dx[dir];

		//snake_y[time] = snake_y[time - 1] + dy[dir];
		
		if (head_y <1 || head_y >N || head_x <1 || head_x >N || map[head_y][head_x] == 1)
			break;
		snake_y[time] = head_y;
		snake_x[time] = head_x;
		if (map[head_y][head_x] == 0) {
			int tail_y = snake_y[tail_idx];
			int tail_x = snake_x[tail_idx];
			map[tail_y][tail_x] = 0;
			tail_idx++;
			
		}
		map[head_y][head_x] = 1;

		if (cmd[time] == 'D') {
			dir = (dir + 1) % 4;
		}
		if (cmd[time] == 'L') {
			dir = (dir + 3) % 4;
		}
			
		printArr();
		Sleep(900);
		system("cls");
		
	}
	printArr();
	Sleep(900);
	printf("%d\n", time);

	return 0;
}
