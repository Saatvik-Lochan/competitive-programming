#include <bits/stdc++.h>
using namespace std;

#define ll long long

void calculate() {
    int n, k;
    cin >> n >> k;

    vector<ll int> modified(n);
    ll int input, total = 0;

    for (ll int i = 0; i < n; i++) {
        cin >> input;
        modified[i] = -1LL * input + n - i - 1LL;
        total += input;
    }

    sort(modified.begin(), modified.end());

    for (ll int i = 0; i < k; i++) {
        total += modified[i];
        total -= i;
    }

    cout << total << endl;
}


int main() {
    int t; cin >> t;
    while (t--) calculate();
}