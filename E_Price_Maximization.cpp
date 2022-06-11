#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

void calculate() {
    int n, k;
    cin >> n >> k;

    ll int total = 0;
    int remainders[k] = {0};

    int a;

    for (int i = 0; i < n; i++) {
        cin >> a;
        total += a;
        remainders[a % k] += 1;
    }

    int compare, sub;

    for (int i = 0; i < k; i++) {
        if (!remainders[i]) continue;

        for (int c = 0; c < k; c++) {
            compare = (k - i + c) % k;
            if (i == compare) {
                sub = remainders[i] / 2;
            } else {
                sub = min(remainders[i], remainders[compare]);          
            }

            total -= c * sub;

            remainders[i] -= sub;
            remainders[compare] -= sub;

            if (!remainders[i]) break;
        }
    }

    cout << total / k << endl;
}

int main(){
    int t;
    cin >> t;

    while (t--) {
        calculate();
    }
}

/* Attempt 1 - got some logic wrong
void calculate(){
    int n, k;
    cin >> n >> k;

    int total = 0;
    unordered_map<int, int> remainders;

    int a;

    for (int i = 0; i < n; i++) {
        cin >> a;
        total += a;
        remainders[a % k] += 1;
    }

    int temp_sum;

    for (int i = 0; i < k/2; i++) {
        temp_sum = remainders[i] - remainders[k-i];

        if (temp_sum >= 0) {
            total -= i * temp_sum;
        } else {
            total -= (i-k) * temp_sum;
        }
    }

    int mid;

    if (k % 2 == 0) {
        mid = k / 2; 
        total -= mid * (remainders[mid] % 2);
    }

    cout << total / k << endl;
}
*/
