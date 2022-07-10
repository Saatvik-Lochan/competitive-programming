#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int 

ull gcd(ull a, ull b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

ull lcm(ull a, ull b){
    return a*b/gcd(a, b);
}

void calculate() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<bool> visited(n+1, false);
    string temp; 
    int next;
    int p[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<string> loops;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        temp = "";
        next = i;

        do {
            temp += s[next-1];
            visited[next] = true;
            next = p[next];
        } while (next != i);

        loops.push_back(temp);
    }

    ull count;
    string new_str;

    vector<ull> nums;

    for (string loop : loops) {
        count = 0;

        do {
            count++;
            new_str = loop.substr(count, n-count); 
            new_str += loop.substr(0, count);
        } while (new_str != loop);

        nums.push_back(count);
    }
    
    ull total = 1;
    for (auto element: nums){
        total = lcm(total, element);
    } 

    cout << total << endl;
}

int main() {
    int t; cin >> t;
    while (t--) calculate();
}