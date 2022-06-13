#include <bits/stdc++.h>
using namespace std;

void calculate();

int main() {
    int t;
    cin >> t;

    while (t--) calculate();
}

void calculate() {
    int n;
    cin >> n;

    string temp_str;
    int a[n][n];
    int row_total[n];

    int temp_sum;

    for (int i = 0; i < n; i++) {
        temp_sum = 0;
        cin >> temp_str;

        for (int j= 0; j < n; j++) {
            temp_sum += int(temp_str[j]) - 48;
            a[i][j] = int(temp_str[j]) - 48;
        }

        row_total[i] = temp_sum;
    }

    int minimum = 5000000;
    int column;

    for (int pattern = 0; pattern < n; pattern++) {
        temp_sum = 0;

        for (int row = 0; row < n; row++) {
            column = (row + pattern) % n;
            if (a[row][column]) {
                temp_sum += (row_total[row] - 1);
            } else {
                temp_sum += (row_total[row] + 1);
            }
        }

        minimum = min(temp_sum, minimum);
    }

    cout << minimum << endl;
}