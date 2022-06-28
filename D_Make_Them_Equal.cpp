#include <bits/stdc++.h>
using namespace std;

void calculate();

int main() {
    int t; cin >> t;

    while (t--) calculate();
}

/* Attempt 1 at cost
int cost(int b) {
    int one_count = 0, overall_count = 0;
    while (b > 0) {
        if (b & 1 != 0) one_count++;
        b = b >> 1;
        overall_count++;
    }

    return overall_count + one_count - 2;
}
*/

int cost(int b) {
    int from = 1, count = 0, temp;

    while (from != b) {
            count++;
            if (from <= b / 2) from <<= 1;

            else {
                temp = from / (b - from);
                if (from + from / temp > b) {
                    from += from / (temp + 1);
                } else {
                    from += from / temp;
                }
            }
        }

    return count;
}

void calculate() {
    int n, k;
    cin >> n >> k;


    int b[n], c[n];

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }


    if (k == 0) {
        cout << 0 << endl;
        return;
    }

    vector<int> non_zero_cost;
    vector<int> non_zero_return;
    int valid_numbers = 0;
    int result, zero_total = 0;

    for (int i = 0; i < n; i++) {
        result = cost(b[i]);

        if (result == 0) {
            zero_total += c[i];
        } else {
            non_zero_cost.push_back(result);
            non_zero_return.push_back(c[i]);
            valid_numbers++;
        }
    }

    int answer[valid_numbers][k+1];
    int max_value, compare;

    for (int i = 0; i < valid_numbers; i++) {
        for (int j = 1; j <= k; j++) {
            if (j < non_zero_cost[i]) {
                answer[i][j] = 0;
            } else if (j == non_zero_cost[i]) {
                answer[i][j] = non_zero_return[i];
            } else {
                max_value = answer[i][j-1];
                for (int m = 0; m < i; m++) {
                    compare = answer[i-m-1][j-non_zero_cost[i]] + non_zero_return[i];
                    max_value = max(max_value, compare);
                }
                answer[i][j] = max_value;
            }
        }
    } 

    max_value = 0;
    for (int i = 0; i < valid_numbers; i++) {
        max_value = max(max_value, answer[i][k]);
    }

    cout << max_value + zero_total << endl;
}