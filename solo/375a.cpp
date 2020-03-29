#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string arr[] = {"1869", "1968", "9186", "6198", "8691", "1986", "1896"};
	string s;
	cin >> s;

	long long count[10];
	memset(count, 0, sizeof(count));

	for (char x : s)
		count[x - '0']++;

	count[1]--;count[6]--;count[9]--;count[8]--;
	string res = "";
	// placing all the values
	for (int i = 9; i >= 1; i--) {
		for (int j = 0; j < count[i]; j++)
			res += ('0' + i);
	}

	string str = res;
	res += "0000";

	int mod = res[0] - '0';
	for (int i = 1; i < res.length(); i++) {
		mod = (mod * 10 + (res[i] - '0')) % 7;
	}


	if (mod != 0)
		mod = 7 - mod;

	str += arr[mod];

	// let us fill the zeroes
	for (int i = 0; i < count[0]; i++)
		str += '0';

	cout << str;
	return 0;
}

