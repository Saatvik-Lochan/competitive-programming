#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

void calculate();

int main() {
    int t; cin >> t;

    while (t--) calculate();
}

void calculate() {
    int n, x;
    cin >> n >> x;

    ull int temp, previous;
    ull int smaller_side, larger_side, minimum, maximum;

    ull int total = 0;

    cin >> temp;
    smaller_side = larger_side = minimum = maximum = temp;

    for (int i = 1; i < n; i++) {
        previous = temp;
        cin >> temp;
        maximum = max(temp, maximum);
        minimum = min(temp, minimum);

        if (previous > temp) total += (previous - temp);
        else total += (temp - previous);

        if (i == n - 1) {
            if (temp > smaller_side) larger_side = temp;
            else smaller_side = temp;
        }
    }

    if (minimum != 1) {
        total += min((minimum - 1) * 2, smaller_side - 1);
    }

    ull int middle_sum;

    if (x > maximum) {
        middle_sum = (x - maximum) * 2;
        total += min(middle_sum, x - larger_side);
    }

    cout << total << endl;
}