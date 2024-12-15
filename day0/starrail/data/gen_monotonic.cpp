#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MX = 1000 * 1000 * 1000;
int main(int argc, char** argv) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]);
	vector<int> a;
	for (int i = 0; i < 2 * n; i++) {
		a.push_back(rnd.next(int(1e7), int(2e7)));
	}
	sort(a.begin(), a.end());
	cout << n << endl;
	for (int i = 0; i < n; i++) {
	    int x = a[n - i - 1], y = a[n + i];
		cout << y << " " << x << endl;
	}
	return 0;
}

