#include <bits/stdc++.h>
using namespace std;

#define ll long long

void calculate();

int main(){
    int t;
    cin >> t;
    while (t--) calculate();
}

void calculate(){
    int n;
    cin >> n;

    ll int a[n];
    cin >> a[0];
    ll int sum = 0, final_val, previous_val;
    final_val = previous_val = a[0];
    ll int difference;

    for (int i = 1; i < n; i++) {
        cin >> a[i];
        difference = a[i] - previous_val;
        sum += abs(difference);

        previous_val = a[i];
        if (difference < 0) {
            final_val += difference;
        }
    }

    sum += abs(final_val);
    cout << sum << endl;
}