#include "testlib.h"
#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int C = atoi(argv[2]);
    int g = atoi(argv[3]);
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int aa, bb;
        do {
            double x = rnd.next(1.0 * n);
            double y = rnd.next(1.0 * n);
            aa = C / x;
            bb = C / y;
            aa = max(min(aa, C), 1);
            bb = max(min(bb, C), 1);
            if (g == 1) {
                bb = 0;
            } else if (g == 2) {
                aa = bb;
            }
        } while (aa < bb);
        a[i] = aa;
        b[i] = bb;
    }
//    for (int A = 1; A <= C; A += C / 20) {
//        for (int B = 1; B <= C; B += C / 20) {
//            long long sum = 0;
//            for (int i = 0; i < n; i++) {
//                if (A <= a[i]) {
//                    sum += A;
//                } else if (B <= b[i]) {
//                    sum += B;
//                }
//            }
//            cout << sum << " ";
//        }
//        cout << "\n";
//    }
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << b[i] << endl;
    }
    return 0;
}
