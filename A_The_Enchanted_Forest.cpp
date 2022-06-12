#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

void calculate();
ull int total(ull int value);

int main() {
    int t;
    cin >> t;

    while (t--) calculate();
}

void calculate() {
    ull int n, k;
    cin >> n >> k;

    int a[n];
    ull int sub_total;
    sub_total = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i < k) sub_total += a[i];
    }

    ull int answer;

    if (k >= n) {
        answer = sub_total + k * n - total(n);
    } else {
        ull int greatest = sub_total;
        for (int i = 1; i <= n - k; i++) {
          sub_total -= a[i-1];
          sub_total += a[i + k - 1];

          if (sub_total > greatest) greatest = sub_total;
        }

        answer = greatest + total(k-1);
    }

    cout << answer << endl;
}

ull int total(ull int value) {  // to ensure no rounding error
    ull int sub_value;
    if (value % 2 == 0) {
        sub_value = value / 2;
        return sub_value * (value + 1);
    } else {
        sub_value = (value + 1) / 2;
        return sub_value * value;
    }
}