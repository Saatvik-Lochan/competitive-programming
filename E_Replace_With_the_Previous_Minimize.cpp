#include <bits/stdc++.h>
using namespace std;

void calculate();

int main() {
    int t;
    cin >> t;

    while (t--) {
        calculate();
    }
}

void calculate() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int s_arr[n];
    int greatest = 0, stop_index = 0;

    for (int i = 0; i < n; i++) {
        s_arr[i] = s[i] - 97;
    }

    while (s_arr[stop_index] <= k) {
        if (s_arr[stop_index] > greatest) {
            greatest = s_arr[stop_index];
            
        }
        stop_index++;
    }


    int lower_value, upper_value, remaining;
    remaining = k - greatest;

    upper_value = s_arr[stop_index];
    lower_value = upper_value - remaining;

    int out[n];
    for (int i = 0; i < n; i++) {
        if (s_arr[i] <= greatest) out[i] = 0;
        else if (lower_value < s_arr[i] && s_arr[i] <= upper_value) {
            out[i] = lower_value; 
        } else {
            out[i] = s_arr[i];
        }
    }

    string out_str;
    for (char ele : out) {
        out_str += char(ele+97);
    }

    cout << out_str << endl;
}

/* Attempt 1
void calculate(){
    int n, k;
    cin >> n >> k;

    string s, out;
    cin >> s;

    for (int i = 0; i < n; i++) {
        out += char(max(int(s[i]-k), 97));
    }

    cout << out << endl;

}
*/