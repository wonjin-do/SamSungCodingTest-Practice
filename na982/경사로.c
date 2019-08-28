#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<iostream>

using namespace std;
#define MAX_N 20

int map[MAX_N][MAX_N];
int height[MAX_N]; // map의 행이나 열의 높이를 저장

int N, X;//맵사이즈, 경사로높이
int aggbs(int a) {
	return a > 0 ? a : -a;
}

bool isFlatBetween(int s, int e) {
	if(s < 0 || N <= e) {
		return false;
	}
	for (int i = s; i < e; i++) {
		if (height[i] != height[i + 1]) {
			return false;
		}
	}
	return true;
}

bool canRunway() {
	for (int i = 0; i < N - 1; i++) {
		if (abs(height[i] - height[i + 1]) >= 2) {
			return false;
		}
	}
	bool* upSlope = new bool[N];// 오른쪽으로 올라가는 경사로가 배치되어 있는지 확인하는 배열
	bool* downSlope = new bool[N];// 오른쪽으로 내려가는 경사로가 배치되어 있는지 확인하는 배열

	for (int i = 0; i < N; i++) {
		upSlope[i] = downSlope[i] = false;
	}
	for (int i = 0; i < N - 1; i++) {
		if (height[i] + 1 == height[i + 1]) {//i번째 지형이 낮은 경우 경사로가 i번째부터 왼쪽으로 X개 설치되므로 시작은 i-X+1, 끝은 i가 됨
			int s = i - X + 1;
			int e = i;
			if (isFlatBetween(s, e)) {
				for (int j = s; j <= e; j++) {
					upSlope[j] = true;
				}
			}
			else {
				return false;
			}
		}
		else if (height[i] - 1 == height[i + 1]) {
			int s = i + 1;
			int e = i + X;
			if (isFlatBetween(s, e)) {
				for (int j = s; j <= e; j++) {
					downSlope[j] = true;
				}
			}
			else {
				return false;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (upSlope[i] && downSlope[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &N, &X);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		int rowCnt, colCnt;
		rowCnt = colCnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				height[j] = map[i][j];
			}
			if (canRunway()) {
				rowCnt++;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				height[j] = map[j][i];
			}
			if (canRunway()) {
				colCnt++;
			}
		}
		printf("#%d %d\n", tc, rowCnt + colCnt);
	}
	return 0;
}
