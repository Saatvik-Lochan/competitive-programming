#include <bits/stdc++.h>
using namespace std;

void calculate();

int main() {
    int t;
    cin >> t;

    while (t--) calculate();
}



/* Attempt 1
void calculate() {  
    int n;
    cin >> n;

    int p[n];
    int index[n+1];
    int less_than[n+1][n] = {};

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        index[p[i]] = i;

        for (int j = 1; j <= n; j++) {
            if (i == 0) {
                if (j < p[i]) less_than[j][i] = 0;
                else less_than[j][i] = 1;
            } else {
                if (j < p[i]) {
                    less_than[j][i] = less_than[j][i-1];
                } else {
                    less_than[j][i] = less_than[j][i] + 1;
                }
            }
        }
    }

    int total;
    // just realised the idea was bad
}
*/