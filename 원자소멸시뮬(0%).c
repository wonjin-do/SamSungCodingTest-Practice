#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>

const int MapSize = 4000;

bool map[MapSize][MapSize][4] = { false, };
int cnt[MapSize][MapSize] = { 0, };
const int dir[][2] = {
	{-1,0}
	,{1,0}
	,{0,1}
	,{0,-1}
};
int N; //원자갯수 1000

struct ATOM {
	int y;
	int x;
	int d;//방향
	int k;//보유에너지
	bool state;
}atom[1000];

int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int totEnergy = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			int row, col;
			scanf("%d %d", &row, &col);
			atom[i].y = 2 * row + (MapSize / 2), atom[i].x = 2 * col + (MapSize / 2);
			scanf("%d %d", &atom[i].d, &atom[i].k);

			atom[i].state = true;
			map[atom[i].y][atom[i].x][i] = true;//i번쨰 원자의 위치를 map에 기록
			cnt[atom[i].y][atom[i].x]++;
		}
		bool isAtLeastInBound = true;
		while (isAtLeastInBound) {

			for (int i = 0; i < N; i++) {
				if (atom[i].state) {
					map[atom[i].y][atom[i].x][i] = false;
					cnt[atom[i].y][atom[i].x]--;
					
					atom[i].y += dir[atom[i].d][0];
					atom[i].x += dir[atom[i].d][1];
					if (atom[i].y < 0 || atom[i].y >= MapSize || atom[i].x < 0 || atom[i].x >= MapSize)
					{
						atom[i].state = false;
						continue;
					}
					map[atom[i].y][atom[i].x][i] = true;
					cnt[atom[i].y][atom[i].x]++;
					if (cnt[atom[i].y][atom[i].x] >= 2) {
						totEnergy += atom[i].k;

					}

				}
			}

			for (int i = 0; i < MapSize; i++) {
				for (int j = 0; j < MapSize; j++) {
					

				}
			}


		}


	}



	return 0;
}
