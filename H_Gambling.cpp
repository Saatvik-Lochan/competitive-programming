#include <bits/stdc++.h>
using namespace std;

void calculate() {
    int n;
    cin >> n;

    map<int, int> index;
    vector<int> start, last, current;    
    int running_count = 0;

    int roll;
    int to_minus;
    int curr_i;

    int a, l, r;
    int greatest = 0;

    for (int i = 1; i <= n; i++) {
        cin >> roll;

        if (index.count(roll)) {
            curr_i = index[roll];
            to_minus = i - last[curr_i] - 2;
            current[curr_i] -= to_minus;

            last[curr_i] = i;

            if (current[curr_i] <= 0) {
                start[curr_i] = i;
                current[curr_i] = 1;
            }
        } else {
            start.push_back(i);
            last.push_back(i);
            current.push_back(1);
            index[roll] = running_count++;
        }

        if (current[index[roll]] > greatest) {
            a = roll;
            l = start[index[roll]];
            r = i;
            greatest = current[index[roll]];
        }
    }

    cout << a << " " << l << " " << r << endl;
}

int main() {
    int t; cin >> t;
    while (t--) calculate();
}