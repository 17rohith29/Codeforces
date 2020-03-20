#include <bits/stdc++.h>
using namespace std;

const int N = 300000 + 5;

int maximum[4 * N];
int delta[4 * N];
int p[N], q[N], rev[N];

// updates the maxmimum value at i
void update(int i) {
	maximum[i] = max(maximum[2 * i] + delta[2 * i], maximum[2 * i + 1] + delta[2 * i + 1]);
}

// moves down the delta
void propagate(int i) {
	delta[2 * i] += delta[i];
	delta[2 * i + 1] += delta[i];
	delta[i] = 0;
}

/* function that updates delta value in range */
void increment(int v, int l, int r, int inc, int L = 1, int R = N) {
	// the current range L, R stics out of given range l, r
	if (R < l || L > r) // completely outside
		return;
	else if (l <= L && r >= R) { // completely in range
		delta[v] += inc;
	} else {
		propagate(v); // the increment is pushed down

		int mid = (L + R) / 2;
		increment(2 * v, l, r, inc, L, mid);
		increment(2 * v + 1, l, r, inc, mid + 1, R);

		update(v); // update as the change is propageted down
	}
}

int max_value(int v, int l, int r, int L = 1, int R = N) {
	if (R < l || L > r)
		return -1000;
	else if (l <= L && r >= R) {
		return maximum[v] + delta[v];
	} else {
		propagate(v); // the increment is pushed down

		int mid = (L + R) / 2;
		int left = max_value(2 * v, l, r, L, mid);
		int right = max_value(2 * v + 1, l, r, mid + 1, R);

		update(v); // update as the change is propageted down
		return max(left, right);
	}
}

int main() {
	memset(maximum, 0, sizeof(maximum));
	memset(delta, 0, sizeof(delta));

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		rev[p[i]] = i;
	}

	for (int i = 1; i <= n; i++)
		cin >> q[i];

	int ans = n;
	increment(1, 1, rev[ans], 1);

	for(int i = 1; i < n + 1; i++) {
		while (max_value(1, 1, n) <= 0) {
			ans--;
			increment(1, 1, rev[ans], 1);
		}

		increment(1, 1, q[i], -1);
		if (i != 1) cout << " ";
		cout << ans;
	}

	fflush(stdin);
	return 0;
}

