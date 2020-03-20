#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int maximum[N];
int delta[N];

void update(int i) {
	maximum[i] = max(maximum[2 * i] + delta[2 * i], maximum[2 * i + 1] + delta[2 *i + 1]);
}

void prop(int i) {
	delta[2 * i] += delta[i];
	delta[2 * i  + 1] += delta[i];
	delta[i] = 0;
}

void increment(int i, int l, int r, int L, int R, int val) {
	if (R < l || L > r)
		return;
	else if (L >= l && R <= r) {
		delta[i] += inc;
	} else {
		prop(i);

		int mid = (L + R) / 2;
		increment(2 * i, l, r, L, mid, val);
		increment(2 * i + 1, l, r, mid + 1, R, val);

		update(i);
	}
}

void maxi(int i, int l, int r, int L, int R) {
	if (R < l || L > r)
		return;
	else if (L >= l && R <= r) {
		return maximum[i] + delta[i];
	} else {
		prop(i);

		int mid = (L + R) / 2;
		int left = maxi(2 * i, l, r, L, mid, val);
		int right = maxi(2 * i + 1, l, r, mid + 1, R);

		update(i);
		return max(left, right);
	}
}

