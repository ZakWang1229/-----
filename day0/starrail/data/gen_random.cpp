#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]);
	int C = atoi(argv[2]);
	int g = atoi(argv[3]);
	cout << n << endl;
	for (int i = 0; i < n; i++) {
	    int a, b;
	    do {
		    a = rnd.next(1, C);
    		b = rnd.next(1, C);
    		if (g == 1) {
    		    b = 0;
    		} else if (g == 2) {
    		    a = b;
    		}
	    } while (a < b); 
		cout << a << " " << b << endl;
	}
	return 0;
}
