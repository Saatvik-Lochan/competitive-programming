#include <bits/stdc++.h>
using namespace std;

void calculate();
bool test(int value, int h[], int n);

int main(){
    int t;
    cin >> t;
    while (t--) calculate();
}

void calculate(){
    int n;
    cin >> n;
    int h[n];

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int l, u;
    l = 0;
    u = h[n-1];

    int mid, prev_correct = 0;

    while (l <= u) {
        mid = (l + u) / 2;

        if (test(mid, h, n)) {
            l = mid + 1;
            prev_correct = mid;
        } else {
            u = mid - 1;
        }
    }

    cout << prev_correct << endl;
}

// Not sure what is wrong here
bool test(int value, int h[], int n) {
    int stones[n];
    copy(h, h+n, stones);
    int d;

    for (int i = n-1; i >= 2; i--) {
        d = min(stones[i] - value, h[i]) / 3;
        if (d < 0) return false;

        stones[i] -= 3 * d;
        stones[i-1] += d;
        stones[i-2] += 2 * d;
    }

    if (stones[0] >= value && stones[1] >= value) {
        return true;
    } else {
        return false;
    }
}

/* Attempt 1
bool test(int value, int h[], int n) {
    int stones[n];
    copy(h, h+n, stones);
    int d;
    
    for (int i = 0; i < n - 2; i++) {
        if (stones[i] >= value) continue;

        d = ceil((value - stones[i]) / 2.0);

        if (3*d > stones[i + 2]) return false;

        stones[i] += 2 * d;
        stones[i+1] += d;
        stones[i+2] -= 3 * d;
    }

    if (d < value) {
        d = ceil((value - stones[n-2]));
        if (3*d > stones[n-1]) return false;

        stones[n-2] += d;
        stones[n-1] -= 3*d;
    }


    return stones[n-1] >= value;
}
*/

