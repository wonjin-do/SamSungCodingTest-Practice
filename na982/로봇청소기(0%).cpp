
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int N, M;
int r, c, d;
int map[50][50];
bool clean[50][50];
int tot = 0;
int isStop = false;



void search() {
	int sc_y, sc_x;
	int k;
	cout << "r,c : " << r << ", " << c <<"d: "<<d<< endl;

	for (k = 0;k < 4;k++) { 
		
		int dir = (d + 3 * (k+1))%4;
		cout << "dir: " << dir << endl;
		sc_y = r + dy[dir]; //현재 방향기준 왼쪽
		sc_x = c + dx[dir];
		cout << "k: " << k << endl << "탐색 (y,x): " << sc_y << ", " << sc_x << endl;
		

		if (sc_y < 0 || sc_y >= N || sc_x < 0 || sc_x >= M) {
			cout << "영역 밖" << endl;
			continue;
		}
		if (map[sc_y][sc_x] != 1) { // 벽 X
			if (clean[sc_y][sc_x] == false)
			{
				cout << "벽도 아니고 청소안된 부분 찾음." << endl;
				d = dir;
				r = sc_y;
				c = sc_x;
				return;
			}
			else {
				cout << "청소되있는 부분" << endl;
				continue;
			}
				
		}
		else {//벽 인경우
			cout << "벽" << endl;
			continue;
		}
	}

	if (k == 4) {
		int dir = (d + 2) % 4;
		int y = r + dy[dir];
		int x = c + dx[dir];
		cout << "k==4인 경우 : (y,x) : (" << y << ", " << x << ")" << endl;
		if (map[y][x] != 1) {//뒤 쪽이 벽이 아닌 경우
			cout << "뒤 쪽이 벽이 아닌 경우" << endl;
			r = y;
			c = x;
			return;
		}
		else {
			cout << "뒤 쪽이 벽" << endl;
			isStop = true;
			return;
		}
	}

	

}

int main() {

	cin >> N >> M;

	cin >> r >> c >> d;
	r;
	c;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		cout << "로봇청소기의 위치: (" << r << ", " << c << ")" << endl;
		clean[r][c] = true;
		tot++;
		search();
		if (isStop) {
			break;
		}
	}
	cout << tot << endl;

	return 0;
}
