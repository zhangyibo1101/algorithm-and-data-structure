//L 星球上的生物由蛋蓝质组成，每一种蛋蓝质由一类称为蓝肽的物资首尾连接成一条长链后折叠而成。
//
//生物学家小乔正在研究 L 星球上的蛋蓝质。她拿到两个蛋蓝质的蓝肽序列，想通过这两条蓝肽序列的共同特点来分析两种蛋蓝质的相似性。
//
//具体的，一个蓝肽可以使用 11 至 55 个英文字母表示，其中第一个字母大写，后面的字母小写。一个蛋蓝质的蓝肽序列可以用蓝肽的表示顺序拼接而成。
//
//在一条蓝肽序列中，如果选取其中的一些位置，把这些位置的蓝肽取出，并按照它们在原序列中的位置摆放，则称为这条蓝肽的一个子序列。蓝肽的子序列不一定在原序列中是连续的，中间可能间隔着一些未被取出的蓝肽。
//
//如果第一条蓝肽序列可以取出一个子序列与第二条蓝肽序列中取出的某个子序列相等，则称为一个公共蓝肽子序列。
//
//给定两条蓝肽序列，找出他们最长的那个公共蓝肽子序列的长度。
//输入描述
//输入两行，每行包含一个字符串，表示一个蓝肽序列。字符串中间没有空格等分隔字符。
//
//其中有 ，两个字符串的长度均不超过 1000。
//
//输出描述
//输出一个整数，表示最长的那个公共蓝肽子序列的长度
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> fn(string &s) {
    int cnt = 0;
    vector<string> v;
    for (int i = s.length() - 1; i >= 0; i--) {
        cnt++;
        if (s[i] >= 'A' && s[i] <= 'Z') {
            v.push_back(s.substr(i, cnt));
            cnt = 0;
        }
    }
    reverse(v.begin(), v.end());
    return v;
}
void myprint(vector<string>& v) {
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }
}
int main()
{
    // 请在此输入您的代码
    string s1, s2;
    vector<string> v1, v2;
    cin >> s1 >> s2;
    v1 = fn(s1);
    v2 = fn(s2);
    vector<vector<int>>dp(1005, vector<int>(1005, 0));
    for (int i = 1; i <= v1.size(); i++) {
        for (int j = 1; j <= v2.size(); j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (v1[i - 1] == v2[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= v1.size(); i++) {
        for (int j = 1; j <= v2.size(); j++) {
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans << endl;
    return 0;
}