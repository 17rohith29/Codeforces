#include <bits/stdc++.h>
using namespace std;

pair<int, int> ount(int k, string x) {
	string y = "";
	for (int i =0; i <4; i++) {
		y += ('0' + (k % 10));
		k = k / 10;
	}
	reverse(y.begin(), y.end());

	// checking if y is a bad string
	for (char c: y) {
		if (count(y.begin(), y.end(), c) > 1)
			return {-1, -1};
	}
	int b= 0, c = 0;

	for (int i = 0; i < 4; i++) {
		if (x[i] == y[i]) b++;
		else {
			char cur = y[i];
			if (count(x.begin(), x.end(), cur) > 0)
				c++;
		}
	}

	return {b, c};
}
int main() {
	int n;
	cin >> n;
	int arr[10000];
	int count = 10000;
	memset(arr, 1, sizeof(arr));

	for (int i = 0; i < n; ++i) {
		string x;
		int b, c;
		cin >> x >> b >> c;

		for (int j = 0; j < 10000; j++) {
			auto bc = ount(j, x);
			if (arr[j] == 0) continue;
			if (bc.first != b || bc.second != c) {
				arr[j] = 0;
				count--;
			}
		}
	}


	if (count == 1) {
		int i = 0;
		while (arr[i] == 0)
			i++;
		printf("%04d", i);
	} else if (count < 1) {
		cout << "Incorrect data";
	} else {
		cout << "Need more data";
	}
}
