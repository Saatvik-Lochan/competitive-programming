#include <bits/stdc++.h>
using namespace std;

int max_subarray(vector<int>& vect);
void calculate();

int main() {
    int t; cin >> t;

    while (t--) calculate();
}

void calculate() {
    int n;
    cin >> n;

    vector<int> temp_v;
    int temp, max_value = 1;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        
        if (temp == 0) {
            max_value = max(max_subarray(temp_v), max_value);
            temp_v = {};
        } else {
            temp_v.push_back(temp);
        }
    }

    cout << max_value << endl;
}

int max_subarray(vector<int>& vect) {
    if (vect.empty()) return 1;

    int min_neg, min_pos, max_neg, max_pos;
    max_neg = max_pos = 1;
    min_neg = -5000000;
    int running_total = 1;

    for (int element : vect) {
        running_total *= element;

        if (running_total < 0) {
            min_neg = max(min_neg, running_total);
            max_neg = min(max_neg, running_total);
        } else {
            max_pos = max(max_pos, running_total);
        }
    }

    // return what you should delete - redo when you get time
    return max(max_pos, max_neg / min_neg);
}