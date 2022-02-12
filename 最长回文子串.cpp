#include <iostream>
#include<string>
using namespace std;
string longestPalindrome(string s) {
    int max = 1, start = 0;
    for (int i = 1; i < s.length(); i++) {
        int j = 1, num = 1;
        while (j <= i && i + j < s.length()) {
            if (s[i - j] == s[i + j]) {
                num += 2;
                j++;
            }
            else break;
        }
        if (num > max) {
            max = num;
            start = i - j + 1;
        }
        if (s[i] == s[i - 1]) {
            int k = 1, num2 = 2;
            while (k <= i - 1 && i + k < s.length()) {
                if (s[i - 1 - k] == s[i + k]) {
                    num2 += 2;
                    k++;
                }
                else break;
            }
            if (num2 > max) {
                max = num2;
                start = i - k;
            }
        }
    }
    return s.substr(start, max);
}
int main()
{
    // 请在此输入您的代码
    cout << longestPalindrome("cbbd");

    system("pause");
    return 0;
}