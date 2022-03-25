//题目描述
//班里 N 个小朋友，每个人都有自己最崇拜的一个小朋友（也可以是自己）。
//
//在一个游戏中，需要小朋友坐一个圈，每个小朋友都有自己最崇拜的小朋友在他的右手边。
//
//求满足条件的圈最大多少人？
//
//小朋友编号为 1, 2, 3, ?N。
//
//输入描述
//输入第一行，一个整数 N（3 < N < 10 ^ 5）。
//
//接下来一行 N 个整数，由空格分开。
//
//输出描述
//要求输出一个整数，表示满足条件的最大圈的人数。

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n;
    cin >> n;
    vector<int> ans(1e5 + 1, 0);
    vector<int> st(1e5 + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> ans[i];
    }
    int maxres = 0;
    for (int i = 1; i <= n; i++) {
        if (st[i] == 1)continue;
        vector<int> temp;
        int j = i, cnt = 0;
        while (find(temp.begin(), temp.end(), j) == temp.end()) {
            temp.push_back(j);
            st[j] = 1;
            j = ans[j];
            cnt++;
        }
        maxres = max(maxres, cnt - (find(temp.begin(), temp.end(), j) - temp.begin()));
    }
    cout << maxres << endl;
    return 0;
}