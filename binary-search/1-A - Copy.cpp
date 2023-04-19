// A. Binary Search
// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            // arr[lo] <= x, arr[hi] > x
            int lo = -1, hi = n;
            while (lo + 1 < hi) {
                auto mid = lo + (hi - lo) / 2;
                if (arr[mid] <= x) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            if (lo >= 0 && arr[lo] == x) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
