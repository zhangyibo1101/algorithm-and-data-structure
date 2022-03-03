#include <iostream>
using namespace std;
void irrigate(int i, int j, int c[101][101]) {
    int a[4] = { -1,-1,1,1 };
    int b[4] = { 1,-1,-1,1 };
    for (int k = 0; k < 4; k++) {
        if (c[i + a[k]][j + b[k]] == 1) {
            c[i + a[k]][j + b[k]] = 2;
        }
    }
}
int main()
{
    // 请在此输入您的代码
    int n, m, t;
    cin >> n >> m >> t;
    int c[101][101] = { 0 };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            c[i][j] = 1;
        }
    }
    for (int i = 1; i <= t; i++) {
        int r, s;
        cin >> r >> s;
        c[r][s] = 2;
    }
    int k;
    cin >> k;
    for (int l = 0; l < k; l++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (c[i][j] == 2) {
                    irrigate(i, j, c);
                }
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == 2) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}