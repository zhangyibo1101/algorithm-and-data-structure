#include <iostream>
#include<string>
using namespace std;
bool isexceed(vector<int>& v1) {
    vector<int> v2;
    int max = 2E31 - 1;
    while (max) {
        v2.push_back(max % 10);
        max /= 10;
    }
    int i = 0;
    while (i < 10) {
        if (v2[9 - i] > v1[i]) {
            return true;
        }
        else if (v2[9 - i] == v1[i]) {
            i++;
        }
        else {
            return false;
        }
    }
    return false;

}
int link(vector<int>& v) {
    int res = 0, index = 1;
    for (int i = 0; i < v.size(); i++) {
        res += index * v[i];
        index *= 10;
    }
    return res;
}
int reverse(int x) {
    if (x == 0 || x == -2e31)return 0;
    vector<int> v;
    if (x > 0) {
        while (x) {
            v.push_back(x % 10);
            x /= 10;
        }
        if (v.size() == 10 && isexceed(v)) {
            return 0;
        }
        else {
            return link(v);
        }
    }
    if (x < 0) {
        x = -x;
        while (x) {
            v.push_back(x % 10);
            x /= 10;
        }if (v.size() == 10 && isexceed(v)) {
            return 0;
        }
        else {
            return -link(v);
        }

    }
int main()
{
    cout << reverse(123) << endl;

    system("pause");
    return 0;
}