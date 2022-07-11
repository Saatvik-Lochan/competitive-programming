#include <bits/stdc++.h>
using namespace std;

void calculate() {
    int n; cin >> n;

    string t;

    int letters[26] = { 0 };

    for (int i = 0; i < n * 2; i++) {
        cin >> t;
        for (char c : t) {
            letters[int(c)- 97]++;
        }
    }

    cin >> t;
    int final_l[26] = { 0 };
    for (char c : t) {
        final_l[int(c) - 97]++;
    }

    for (int i = 0; i < 26; i++) {
        if (letters[i] % 2 != final_l[i] % 2) {
            cout << char(i + 97) << endl;
            break;
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) calculate();
}