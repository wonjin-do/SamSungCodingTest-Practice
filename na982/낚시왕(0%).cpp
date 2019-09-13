
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
int M;
const int MAX = 10000;
const int dy[] = { 0,-1,1,0,0 };
const int dx[] = { 0, 0,0,1,-1 };
int kingPos = -1;
int totSize = 0;

struct SHARK {
	int r,c;
	int s;
	int d;
	int z;
};

SHARK shark[101][101];

int main() {
	cin >> R >> C >> M;
	for (int i = 0;i < M;i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		r--;c--;
		shark[r][c].s = s;
		shark[r][c].d = d;
		shark[r][c].z = z;
	}
	
	while (1) {
		kingPos++;
		if (kingPos == C)
			break;
		for (int i = 0;i < C;i++) {
			if (shark[i][kingPos].z > 0) {
				totSize += shark[i][kingPos].z;
				shark[i][kingPos].z = 0;
				break;
			}
		
		}


	}


	return 0;
}
