#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>


int N, L;
int map[100][100];
int tot = 0;
int abs(int a) {
	return a > 0 ? a : -a;
}

bool fun(int row, int from, int to) {
	if (from < 0 || to >= N)
		return false;
	int pivot = map[row][from];
	for (int i = from+1; i <= to; i++) {
		if (map[row][i] != pivot) {
			printf("%d 행의 (%d~%d)구간의 높이가 다름\n", row, from, to);
			return false;
		}
			
	}
	return true;
}


int main(void) {

	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; i++) {
			scanf("%d", &map[i][j]);
		}
	}
	bool flag;
	for (int row = 0; row < N; row++) {
		//map[row]의 배열을 순회
		flag = true;

		for (int col = 0; col < N - 1; col++) {
			if (abs(map[row][col] - map[row][col + 1]) == 0)
				continue;
			if (abs(map[row][col] - map[row][col + 1]) == 1) {
				if (map[row][col] < map[row][col + 1]) {
					bool res = fun(row, col - L + 1, col);//row, from,to 모두다 높이가 같은지
					if (res == false)
					{
						flag = false;
						break;
					}
				}
				else {
					bool res = fun(row, col, col+L);//row, from,to 모두다 높이가 같은지
					if (res == false)
					{
						flag = false;
						break;
					}
						
				}
			}
			else
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
			tot++;
		
	}
	


	return 0;
}
