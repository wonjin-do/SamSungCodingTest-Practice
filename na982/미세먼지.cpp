#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;


int R, C, T; // T초가 지난 후 방에 남아있는 미세먼지의 양을 구하여라
struct node {
	int y, x;
};

int map[50][50];
int t = 0;

int main() {

	scanf("%d %d %d", &R, &C, &T);
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			scanf("%d", &map[i][j]);//-1 로봇청소기 (2대) , 미세먼지의 양
		}
	}

	while (1) {

		





		t++;
		if (t == T)
			break;

	}
	


	return 0;
}
