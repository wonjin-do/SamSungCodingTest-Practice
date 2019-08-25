#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
#define  MAXL 352

struct data_type {
	int status;
	int LP, NP;
};

int T, N, M, K;
data_type Map[2][MAXL][MAXL];
int dir[4][2] = {
	{0,-1}
	,{0,1}
	,{1,0}
	,{-1,0} };
int main() {
	setbuf(stdout, NULL);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> K;
		for (int i = 0; i < N + K + 2; i++) {
			for (int j = 0; j < M + K + 2; j++) {
				Map[0][i][j].status = 0;
				Map[1][i][j].status = 0;
			}
		}
		for(int i=0+K/2+1;i<N+K/2+1;i++)
			for (int j = 0 + K / 2 + 1; j < M + K / 2 + 1; j++) {
				cin >> Map[0][i][j].LP;
				if (Map[0][i][j].LP > 0) {
					Map[0][i][j].status = 1;
					Map[0][i][j].NP = 0;
				}
			}
		N = N + K + 2;
		M = M + K + 2;
		int CurMap = 0;
		for (int k = 0; k < K; k++) {
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++) {
					if (Map[CurMap][i][j].status == 3) {
						Map[1 - CurMap][i][j].status = Map[CurMap][i][j].status;
						continue;
					}
					else if (Map[CurMap][i][j].status == 1) {
						Map[1 - CurMap][i][j].NP = Map[CurMap][i][j].NP + 1;
						Map[1 - CurMap][i][j].LP = Map[CurMap][i][j].LP;
						if (Map[1 - CurMap][i][j].NP == Map[1 - CurMap][i][j].LP)
							Map[1 - CurMap][i][j].status = 2;
						else
							Map[1 - CurMap][i][j].status = 1;
					}
					else if (Map[CurMap][i][j].status == 2) {
						if (Map[CurMap][i][j].NP == Map[CurMap][i][j].LP) {
							for (int d = 0; d < 4; d++) {
								int i2, j2;
								j2 = j + dir[d][0];
								j2 = j + dir[d][1];
								if (Map[CurMap][i2][j2].status == 0) {
									if ((Map[1 - CurMap][i2][j2].status == 0)) {
										Map[1 - CurMap][i2][j2].status = 1;
										Map[1 - CurMap][i2][j2].LP = Map[CurMap][i][j].LP;
										Map[1 - CurMap][i2][j2].NP = 0;
									}
									else if (Map[1 - CurMap][i2][j2].status == 1 && Map[1 - CurMap][i2][j2].LP < Map[CurMap][i][j].LP)
										Map[1 - CurMap][i2][j2].LP = Map[CurMap][i][j].LP;
								}
							}
						}
						Map[1 - CurMap][i][j].NP = Map[CurMap][i][j].NP - 1;
						if (Map[1 - CurMap][i][j].NP == 0)
							Map[1 - CurMap][i][j].status = 3;
						else
							Map[1 - CurMap][i][j].status = 2;
					}
				}
			CurMap = 1 - CurMap;
		}
		int Answer = 0;
		for(int i=0;i<N;i++)
			for (int j = 0; j < M; j++) {
				if (Map[CurMap][i][j].status == 1 || Map[CurMap][i][j].status == 2)
					Answer++;
			}
		cout << "#" << tc << " " << Answer << endl;
	}
	return 0;
}
