#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	int n = atoi(argv[1]);
	int C = atoi(argv[2]);
	cout << n << endl;
	int x = rnd.next(1, C);
	for (int i = 1; i <= n; i++) {
		cout << x << " " << x << endl;
	}
	return 0;
}
