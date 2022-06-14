#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> max_subarray(vector<int>& vect);
void calculate();

int main() {
    int t; cin >> t;

    while (t--) calculate();
}


void calculate() {
    int n;
    cin >> n;

    vector<int> temp_v;
    int temp, max_value = 0;
    int temp_lower, temp_upper, temp_max;
    int lower = n, upper = 0;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        
        if (temp == 0 || i == n - 1) {
            if (i == n - 1 && temp != 0) {
                temp_v.push_back(temp);
                i++;
            }
            if (temp_v.empty()) continue;
            tie(temp_lower, temp_upper, temp_max) = max_subarray(temp_v);
            
            if (temp_max > max_value) {
                max_value = temp_max;
                lower = (i - temp_v.size() + temp_lower);
                upper = n - (i - temp_v.size() + temp_upper) - 1;
            }

            temp_v = {};
        } else {
            temp_v.push_back(temp);
        }
    }

    cout << lower << " " << upper << endl;
}

tuple<int, int, int> max_subarray(vector<int>& vect) {
    bool first_neg_found = false;
    int first_neg, first_neg_index;
    int last_neg, last_neg_index;
    int max_pos = 0, max_pos_index = 0;
    int power_of_2 = 0;
    bool positive = true;

    for (int i = 0; i < vect.size(); i++){
        if (abs(vect[i]) == 2) power_of_2++;
        if (vect[i] < 0) positive = !positive;

        if (!positive) {
            last_neg = power_of_2;
            last_neg_index = i;

            if (!first_neg_found) {
                first_neg = power_of_2;
                first_neg_index = i;
                first_neg_found = true;
            }
        } else {
            max_pos = power_of_2;
            max_pos_index = i;
        }
    }


    if (first_neg_found) {
        if (max_pos > last_neg - first_neg) {
            return make_tuple(0, max_pos_index, max_pos);
        } else {
            return make_tuple(first_neg_index + 1, last_neg_index, last_neg - first_neg);
        }
    } else {
        return make_tuple(0, max_pos_index, max_pos);
    }
}

/* Attempt 1 - running total overflows no matter what
tuple<int, int, int> max_subarray(vector<int>& vect) {
    bool first_neg_found = false;
    int first_neg, first_neg_index;
    int last_neg, last_neg_index;
    int max_pos = 0, max_pos_index = 0;
    ull int running_total = 1;

    for (int i = 0; i < vect.size(); i++){
        running_total *= vect[i];

        if (running_total < 0) {
            last_neg = running_total;
            last_neg_index = i;

            if (!first_neg_found) {
                first_neg = running_total;
                first_neg_index = i;
                first_neg_found = true;
            }
        } else {
            max_pos = running_total;
            max_pos_index = i;
        }
    }


    if (first_neg_found) {
        if (max_pos > last_neg / first_neg) {
            return make_tuple(0, max_pos_index, max_pos);
        } else {
            return make_tuple(first_neg_index + 1, last_neg_index, last_neg / first_neg);
        }
    } else {
        return make_tuple(0, max_pos_index, max_pos);
    }
}
*/