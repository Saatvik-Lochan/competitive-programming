#include <bits/stdc++.h>
using namespace std;
 
#define ull unsigned long long

void calculate();
 
ull int MOD = 1000000007;
 
int main(){
    int t; cin >> t;
    while (t--) calculate();
}
 
void calculate() {
    int n; cin >> n;
    ull int loc[n], temp;
 
    for (int i = 0; i < n; i++) {
        cin >> temp;
        loc[temp] = i;
    }
 
    ull int left, right;
    left = right = loc[0];
 
    ull int total = 1;
 
    for (int i = 1; i < n; i++) {
        if (loc[i] > right) {
            right = loc[i];
        } else if (loc[i] < left) {
            left = loc[i];
        } else {
            total *= (right - left + 1ULL - i);
            total %= MOD;
        }
    }
 
    cout << total << endl;
} 