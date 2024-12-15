#include "testlib.h"
#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define int64 long long

const int N = (int) 2e5 + 10;
const int B = 250;

int a[N], b[N], bucket[N], n;
vector< pair<int, int> > alla, allb;

struct t_bucket {
    int pos;
    vector<int> elems;
    vector< pair<int, int64> > data, lines;
    vector<int64> pts;

    void add_elem(int elem) {
        vector<int>::iterator pos = lower_bound(elems.begin(), elems.end(), elem);
        elems.insert(pos, elem);
    }

    int64 ceiling(int64 a, int64 b) {
        return (a + b - 1) / b;
    }

    void add(int value) {
        add_elem(value);
        lines.clear();
        data.clear();
        pts.clear();
        for (int i = 0; i < sz(elems); ++i) {
            if ((i == 0) || (elems[i] != elems[i - 1])) {
                lines.pb(mp(elems[i], elems[i] * (int64) (sz(elems) - i)));
            }
        }
        pts.pb(0);
        data.pb(lines[0]);
        for (int i = 1; i < sz(lines); ++i) {
            while (!data.empty() && (lines[i].fs * (int64) pts.back() + lines[i].sc >= data.back().fs * (int64) pts.back() + data.back().sc)) {
                data.pop_back();
                pts.pop_back();
            }
            pts.pb(data.empty() ? 0 : max(0LL, ceiling(data.back().sc - lines[i].sc, lines[i].fs - data.back().fs)));
            data.pb(lines[i]);
        }
        pos = 0;
    }

    int64 get_value(int pos, int size) {
        return data[pos].fs * (int64) size + data[pos].sc;
    }

    int64 get_best(int size) {
        if (data.empty()) {
            return 0;
        }
        while ((pos + 1 < sz(data)) && (get_value(pos + 1, size) >= get_value(pos, size))) {
            pos++;
        }
        return get_value(pos, size);
    }
} buckets[N / B + 1];

int64 get_answer() {
    int size = 0;
    int64 best = 0;
    for (int i = 0; i <= (n - 1) / B; ++i) {
        best = max(best, buckets[i].get_best(size));
        size += sz(buckets[i].elems);
    }
    return best;
}

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int c = atoi(argv[2]);
    int cc = 0;
    int64 ans = c;//(int64) c * 20;
    //cc = sqrt(ans);
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        a[i] = rnd.next(c / n) + 1;
        b[i] = rnd.next(c);
    }
    for (int i = 0; i < n; ++i) {
        alla.pb(mp(a[i], i));
        allb.pb(mp(b[i], i));
    }
    sort(alla.rbegin(), alla.rend());
    for (int i = 0; i < n; ++i) {
        bucket[alla[i].sc] = i / B;
    }

    sort(allb.begin(), allb.end());
    int64 best = 0;
    for (int i = 0; i < n; ++i) {
        int num = allb[i].sc;
        //get_answer() + (n - i) * (int64) b[num] == C;
        b[num] = (ans - get_answer()) / (n - i);
        b[num] = max(b[num], a[num]);
        b[num] = min(b[num], c);
        buckets[bucket[num]].add(a[num]);
    }

    swap(a, b);

//    int maxa = *max_element(a.begin(), a.end());
//    int maxb = *max_element(b.begin(), b.end());
//
//    for (int A = 1; A <= maxa; A += maxa / 20) {
//        for (int B = 1; B <= maxb; B += maxb / 20) {
//            long long sum = 0;
//            for (int i = 0; i < n; i++) {
//                if (A <= a[i]) {
//                    sum += A;
//                } else if (B <= b[i]) {
//                    sum += B;
//                }
//            }
//            cout << sum / 100000 << " ";
//        }
//        cout << "\n";
//    }
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << b[i] << endl;
    }
    return 0;
}
