/*
12 18
1 2
2 3
2 4
3 1
3 7
3 9
4 6
4 11
5 4
6 5
7 8
7 9
8 10
8 12
9 10
10 7
11 12
12 11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 100;
vector <int> List[MAX];
vector <int> reverseList[MAX];
int n, m;//정점,간선

int time[MAX], clock = 1;
int order[MAX], order_len = 0;//빠져나올 때마다 노드의 번호를 저장할것
int group[MAX], group_cnt = 1;//group[i]: 정점i가 속한 그룹번호
bool check[MAX], check2[MAX];
void get_time(int node) {
	//node부터 시작해서 DFS를 하면서, 빠져나오는 순서대로 시간을 기록
	check[node] = true;
	for (int i = 0;i < List[node].size();i++) {
		int node2 = List[node][i];
		//node -> node2
		if (!check[node2]) {
			get_time(node2);
		}
	}
	//방문 완료

	time[node] = clock;
	clock++;
	order[order_len++] = node;//빠져나오는 순서대로 오더가 저장됨
}

void get_my_group(int node) {
	//node에서부터 DFS 단, 거꾸로된 그래프에 대해서.
	
	check2[node] = true;
	group[node] = group_cnt;

	for (int i = 0;i < reverseList[node].size();i++) {
		int node2 = reverseList[node][i];
		if (!check2[node2]) {
			get_my_group(node2);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0;i < m;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		//a -> b
		List[a].push_back(b);
		reverseList[b].push_back(a);
	}

	//DFS를 하면서 빠져나오는 시간을 기록
	for (int i = 1;i <= n;i++) {
		if (!check[i]) {
			get_time(i);
		}
	}
	//빠져나오는 순서대로 시간이 기록됨.

	// 뒤집은 그래프에 대해서, 빠져나오는 시간이 큰 노드부터 순회
	// 이때 만나는 노드들이 모두 같은 그룹임.
	for (int i = order_len-1;i >= 0;i--) {
		int node = order[i];
		if (!check2[node]) {
			get_my_group(node);
			group_cnt++;
		}
		
	}
	for (int i = 1;i <= n;i++) {
		printf("%d : %d\n", i, group[i]);
	}
	printf("%d\n", group_cnt-1);
	return 0;
}





