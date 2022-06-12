#include <bits/stdc++.h>
using namespace std;

void calculate();

int main() {
    int t;
    cin >> t;
    while (t--) calculate();
}

void calculate() {
    string s;
    cin >> s;

    int n;
    n = s.length();
    
    int ones[n+1] = { 0 };
    int zeros[n+1] = { 0 };

    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0') {
            zeros[i] = zeros[i-1] + 1;
            ones[i] = ones[i-1];
        } else {
            ones[i] = ones[i-1] + 1;
            zeros[i] = zeros[i-1];
        }
    }

    int minimum = n + 1;

    int lower, upper, mid;
    int zeros_left, ones_removed, score;

    for (int start = 0; start <= n; start++) {
        lower = start;
        upper = n;

        while (lower <= upper) {
            mid = (lower + upper) / 2;

            zeros_left = zeros[mid] - zeros[start];
            ones_removed = ones[n] - (ones[mid] - ones[start]);
            score = max(zeros_left, ones_removed);

            minimum = min(minimum, score);

            if (zeros_left == ones_removed) break;
            if (zeros_left < ones_removed) {
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }
    }

    cout << minimum << endl;
}