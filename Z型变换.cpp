#include<iostream>
#include<string>
using namespace std;
string convert(string s, int numRows) {
	string v[1000];
	int index = 0, direction = -1;
	for (int i = 0; i < s.length(); i++) {
		if (numRows == 1)return s;
		if (i % (numRows - 1) == 0)direction *= -1;
		v[index].push_back(s[i]);
		index += direction;
	}
	string res = v[0];
	for (int i = 1; i < numRows; i++) {
		res += v[i];
	}
	return res;
}
int main() {
	/*char name[105],ant[105];
	int lenans = 0, n, len;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name;
		len = strlen(name);
		if (len > lenans) {
			lenans = len;
			strcpy_s(ant, name);
		}
	}
	cout << ant<< endl;*/
	system("pause");
	return 0;

}