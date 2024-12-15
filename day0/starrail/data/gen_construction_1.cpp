#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	int n = atoi(argv[1]);
	cout << n << endl;
	int x = 1e7, y = 1e7;
	for (int i = 1; i <= n; i++) {
		cout << x << " " << y << endl;
		x++;
		y--;
	}
	return 0;
}
