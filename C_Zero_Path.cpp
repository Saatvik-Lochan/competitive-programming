#include <bits/stdc++.h>
using namespace std;

void calculate();

int main(){
    int t; cin >> t;
    while (t--) calculate();
}

void add_set(unordered_set<int>& base_set, unordered_set<int>& to_insert, int shift, int cap) {
    int temp;
    for (int element : to_insert) {
        temp = element + shift;
        if (abs(temp) <= cap) {
            base_set.insert(temp);
        }
    }
}

void calculate() {
    int n, m;
    cin >> n >> m;

    int cap = (m + n - 1) / 2;

    int a[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    if ((n + m) % 2 == 0) {
        cout << "NO\n";
        return;
    }

    bitset<1000> possible_sums[n][m];
    if (a[0][0] == 1) {
        possible_sums[0][0][1] = 1;
    } else {
        possible_sums[0][0][0] = 1;
    }

    int i, j, num;

    for (int d = 0; d < m + n - 1; d++) {
        i = min(d, n-1);
        j = d - i;
        while (i < n && j < m && i >= 0 && j >= 0) {
            if (i + 1 < n) {
                if (a[i+1][j] ==  1) {
                    possible_sums[i+1][j] |= (possible_sums[i][j] << 1);
                } else {
                    possible_sums[i+1][j] |= possible_sums[i][j];
                }
            }
            if (j + 1 < m) {
                if (a[i][j+1] ==  1) {
                    possible_sums[i][j+1] |= (possible_sums[i][j] << 1);
                } else {
                    possible_sums[i][j+1] |= possible_sums[i][j];
                }
            }

            // increment for next cycle
            i--; j++;
        }
    }    

    if (possible_sums[n-1][m-1][cap]) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    cout << "\n";
}

/* Attempt 1
void calculate() {
    int n, m;
    cin >> n >> m;

    int cap = (m + n - 1) / 2;

    int a[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    if ((n + m) % 2 == 0) {
        cout << "NO\n";
        return;
    }

    unordered_set<int> possible_sums[n][m];
    possible_sums[0][0].insert(a[0][0]);

    int i, j, num;

    for (int d = 0; d < m + n - 1; d++) {
        i = min(d, n-1);
        j = d - i;
        while (i < n && j < m && i >= 0 && j >= 0) {
            if (i + 1 < n) {
                add_set(possible_sums[i+1][j], possible_sums[i][j], a[i+1][j], cap);
            }
            if (j + 1 < m) {
                add_set(possible_sums[i][j+1], possible_sums[i][j], a[i][j+1], cap);
            }

            if (i != n-1 && j != m-1) possible_sums[i][j].clear();
            // increment for next cycle
            i--; j++;
        }
    }    

    if (possible_sums[n-1][m-1].count(0)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    cout << "\n";
}
*/