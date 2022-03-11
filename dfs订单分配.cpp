#include<iostream>
#include<vector>
using namespace std;
int maxs = 0;
int st[10] = { 0 };
vector<int> res;
vector<int> result;
vector<int> item;
vector<int> out;
void dfs(int x, vector<vector<int>>& score) {
    int n = score.size();
    if (x > n - 1) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += res[i];
        }
        if (sum > maxs) {
            maxs = sum;
            result = res;
            out = item;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (st[i] == 0) {
            st[i] = 1;
            res[x] = score[x][i];
            item[x] = i;
            dfs(x + 1, score);
            st[i] = 0;
        }
    }
}
vector<int> orderAllocation(vector<vector<int>>& score) {
    // write your code here
    int m = score.size();
    res.resize(m,0);
    item.resize(m, 0);
    dfs(0, score);
    return out;
}
int main()
{
    vector<vector<int>> s{ {1, 2, 4},{7, 11, 16},{37, 29, 22} };
    vector<int> v=orderAllocation(s);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }

	return 0;
}