#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	int n = atoi(argv[1]);
	int x = atoi(argv[2]);
	int y = atoi(argv[3]);
	if (x < y) swap(x, y);
	cout << n << endl;
	for (int i = 1; i <= n; i++) {
		cout << i + x << " " << i + y << endl;
	}
	return 0;
}
