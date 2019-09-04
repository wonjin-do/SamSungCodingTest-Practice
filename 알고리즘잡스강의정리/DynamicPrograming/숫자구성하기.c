#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


const int MAX = 100;
int Table[MAX];
int N,M;
/*
	1~M까지의 숫자들을 중복하여 더해 숫자 N을 만들 수 있는 순서쌍의 갯수를 구하여라
*/

int main() { 

	scanf("%d %d", &N, &M);
	/*
	예)
	M = 4
	Table[1] = 1
	Table[2] = Table[1] + 1
	Table[3] = Table[2] + Table[1] + 1
	Table[4] = Table[3] + Table[2] + Table[1] + 1

	Table[5] = Table[4] + Table[3] + Table[2] + Table[1] + 1
	*/

	/*
	1~4까지 기저조건
	for (int i = 1; i <= M; i++) { // i가 증가할 때마다 매번 j 가 1 부터 시작하며 더하는 번거로움을 반복하고 있다.
		int sum = 0;
		for (int j = 1; j <= i - 1; j++)
			sum += Table[j];
		Table[i] = sum + 1;
	}
	*/ 

	//이중for문없이 채울수 있는 좋은 방법!!
	Table[1] = 1;
	int sum = 0;
	for (int i = 2; i <= M; i++) {
		sum += Table[i - 1];
		Table[i] = sum + 1;
	}

	for (int i = M + 1; i<= N; i++) {
		for (int j = i - M; j < i - 1; j++) {
			Table[i] += Table[j];
		}
	}
	printf("%d\n", Table[N]);
	return 0;
}
