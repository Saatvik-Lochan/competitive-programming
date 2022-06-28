#include <bits/stdc++.h>
using namespace std;

void calculate();

int main() {
    int t;
    cin >> t;

    while (t--) calculate();
}

void calculate() {
    int a, b;
    cin >> a >> b;

    int height = 0;

    while (1 << height <= b) height++;
    height--;

    int mask;
    bool a_bit, b_bit;
    bool flag = false;
    int final_value = 0;

    for (int i = height; i >= 0; i--) {
        mask = 1 << i;
        a_bit = a & mask;
        b_bit = b & mask;

        if (a_bit && !b_bit) {
            flag = true;
        }



        if (flag) {
            final_value += a_bit << i; 
        } else {
            final_value += b_bit << i;
        }
    }

    int test1 = final_value - b + 1;
    int test2 = b - a;

    int test3;

    if (!flag) test3 = 1;
    else {
        for (int i = height; i >= 0; i--) {
            mask = 1 << i;
            b_bit = b & mask;

            if (b_bit) {
                if (mask > a) final_value = mask;
                else continue;
            }
        }
        test3 = final_value - a + 1;
    }

    cout << min(test1, min(test2, test3)) << endl;
}