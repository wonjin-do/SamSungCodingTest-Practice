//T[i] : 정점 i에 도달하는데 걸리는 최단거리
//for i = 0 ~ n

// (1) T[i] 중 최솟값을 정한다. 단, 지금까지 최솟값으로 뽑히지 않았던 값들 중.
// (2) .(1)에서 구한 idx i로 부터 뻗어나간다. T[i] + cost(edge) 의 값들을 참고하며
/*
input Data
 8 11 0 6
 0 1 3
 0 5 1
 1 2 4
 1 3 1
 1 5 1
 2 4 6
 2 6 9
 2 7 4
 3 4 2
 4 6 9
 6 7 3
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>	

using namespace std;

const int MAX = 100;

vector <int> graph[MAX];
vector <int> cost[MAX];

int n, m, start, last;
int Table[MAX];
bool Check[MAX]; // true : 이미 i는 최단거리가 확정됨. //false: 아직 i는 최단거리가 확정되지 않음.

int main() {
	scanf("%d %d %d %d", &n, &m, &start, &last);
	for (int i = 0; i < m; i++) {
		int a, b, c; //(노드 - 간선 - 노드 )의 정보
		scanf("%d %d %d", &a, &b, &c);

		graph[a].push_back(b);
		graph[b].push_back(a);

		cost[a].push_back(c);
		cost[b].push_back(c);

		/*
		graph[1] : 2 6 8 9
		cost[1]  : 1 1 3 4
		*/
	}

	for (int i = 0; i < n; i++)Table[i] = 987987987;
	Table[start] = 0;

	for (int i = 0; i < n; i++) {
		//(1) 최솟값을 구한다. 단, 지금까지 최단거리로 확정되지 않았던 정점에 대해서.
		int minValue = 987987987, minIndex = -1;
		for (int j = 0; j < n; j++) {
			if (!Check[j] && minValue > Table[j]) {
				minValue = Table[j];
				minIndex = j;
			}
		}
		
		Check[minIndex] = true;

		// (2) 그 최솟값을 갖는 노드로부터 뻗어나간다.
		for (int j = 0; j < graph[minIndex].size(); j++) {
			int Node2 = graph[minIndex][j];
			int Cost2 = cost[minIndex][j];

			// minIndex ----(Cost2) ---- Node2

			if (Table[Node2] > Table[minIndex] + Cost2) {
				Table[Node2] = Table[minIndex] + Cost2;
			}
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", Table[i]);
	return 0;
}

