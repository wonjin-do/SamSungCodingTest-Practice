#include <stdio.h>
#include <string.h>

struct shark {
    int s, d, z;
};

int r, c, m, sum=0;
shark a[100][100];
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};

void solve() {
    for (int t=0; t<c; t++) {
        shark b[100][100] = {0};
        
        for (int i=0; i<r; i++) {
            if (a[i][t].z) {
                sum += a[i][t].z;
                a[i][t] = {0, 0, 0};
                break;
            }
        }
        
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (a[i][j].z) {
                    if (a[i][j].d < 2) { // 위 아래  
                        int s = a[i][j].s % ((r-1)*2);
                        int d = a[i][j].d;
                        int ni = i;
                        while (s--) {
                            if (ni == 0 && d == 0) d = 1;
                            if (ni == r-1 && d == 1) d = 0;
                            ni += dx[d];
                        }
                        if (a[i][j].z > b[ni][j].z) b[ni][j] = {a[i][j].s, d, a[i][j].z};
                    } else { // 오른쪽 왼쪽  
                        int s = a[i][j].s % ((c-1)*2);
                        int d = a[i][j].d; 
                        int nj = j;
                        while (s--) {
                            if (nj == 0 && d == 3) d = 2;
                            if (nj == c-1 && d == 2) d = 3;
                            nj += dy[d];
                        }
                        if (a[i][j].z > b[i][nj].z) b[i][nj] = {a[i][j].s, d, a[i][j].z};
                    }
                    a[i][j] = {0, 0, 0};
                }
            }
        }
        memcpy(a, b, sizeof(b));
    }
}

int main() {
    scanf("%d %d %d", &r, &c, &m);
    for (int i=0; i<m; i++) {
        int x, y, s, d, z;
        scanf("%d %d %d %d %d", &x, &y, &s, &d, &z);
        a[x-1][y-1] = {s, d-1, z};
    }
    solve();
    printf("%d\n", sum);
    return 0;
}
[출처] SW역량테스트 2019년 낚시왕 문제풀이 (백준 알고리즘 17743번)|작성자 지젝
