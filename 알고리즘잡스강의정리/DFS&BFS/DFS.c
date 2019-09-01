/*
	너비우선 탐색(BFS)
	1 ----- 2  ------ 6
	 \	   / \		 /	
	  \	  /   4 --- 5
	   \ /   / \
	    3 - 7 - 8 - 9
*/
/*
9 12
1 2
1 3
2 3
2 4
2 6
3 7
4 5
4 7
4 8
5 6
7 8
8 9
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
using namespace std;
const int MAX = 100;

int n, m;
vector<int> myGraph[MAX];
bool visited[MAX];
/*
	DFS(v, visited)
	1. v를 방문했다고 처리
	2. v와 인접한 모든 w에 대하여 다음을 반복
	3. 만약 w를 아직 방문하지 않았다면, 
	4. DFS(w, visited)
	5. 방문순서 반환
*/
void DFS(int x) {	
	//0. Graph와 visited[]는 전역변수로 만들어 parameter로 쓰는 번거로움을 해결한다.
	//1. 방문기록을 남긴다.
	visited[x] = true;

	//문제로직
	printf("%d ", x);

	//2. myGraph[x]에 들어 있는 정보로 순회
	for (int i = 0; i < myGraph[x].size(); i++) {
		int y = myGraph[x][i];
		if (visited[y] == false) {
			DFS(y);
		}
	}

}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		myGraph[a].push_back(b);
		myGraph[b].push_back(a);
	}
	DFS(1);
	return 0;
}
