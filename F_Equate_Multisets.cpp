#include <bits/stdc++.h>
using namespace std;

void calculate() {
    int n;
    cin >> n;

    int a[n];

    int temp;
    unordered_map<int, int> numbers;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        while (temp % 2 == 0) temp /= 2;
        a[i] = temp;

        if (numbers.count(temp)) numbers[temp]++;
        else numbers[temp] = 1;
    }

    int b[n];
    for (int i = 0; i < n; i++) cin >> b[i];

    bool flag;

    for (int i = 0; i < n; i++) {
        temp = b[i];
        flag = false;

        while (temp != 0) {
            if (numbers.count(temp)) {
                // decrement and remove
                if (--numbers[temp] == 0) {
                    numbers.erase(temp);
                }

                flag = true;
                break;
            }
            temp /= 2;
        }

        if (!flag) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    return;
}

int main() {
    int t; cin >> t;
    while (t--) calculate();
}