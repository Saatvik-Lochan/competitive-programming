#include <bits/stdc++.h>
using namespace std;

void calculate();

int main() {
    int t; cin >> t;
    while (t--) {
        calculate();
    }
}

void calculate() {
    int n; cin >> n;

    int parent[n+1];
    bool visited[n+1];
    list<int> graph[n+1];

    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
        graph[parent[i]].push_back(i);
    }

    int lower[n+1], upper[n+1];
    int current[n+1] = { 0 };

    for (int i = 1; i <= n; i++) {
        cin >> lower[i] >> upper[i];
    }

    queue<int> pending;
    pending.push(1);

    int current_node;
    int in_order[n];

    int r_count = n-1;

    while (!pending.empty()) {
        current_node = pending.front();
        pending.pop();

        in_order[r_count] = current_node;
        r_count--;

        for (int next_node : graph[current_node]) {
            pending.push(next_node);
        }
    }

    int node, count = 0, curr_parent;
    for (int i = 0; i < n; i++) {
        node = in_order[i];
        if (current[node] < lower[node]) {
            count++;
            current[node] = upper[node];
        }

        if (node == 1) continue;

        curr_parent = parent[node];

        current[curr_parent] += current[node];
        current[curr_parent] = min(current[curr_parent], upper[curr_parent]);
    }

    cout << count << endl;
}

/* Attempt 2 - Incorrect ordering of nodes
void calculate() {
    int n; cin >> n;

    int parent[n+1];
    bool visited[n+1];
    vector<bool> leaf(n+1, true);

    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
        leaf[parent[i]] = false;
    }

    int lower[n+1], upper[n+1];
    int current[n+1] = { 0 };

    for (int i = 1; i <= n; i++) {
        cin >> lower[i] >> upper[i];
    }

    queue<int> pending;

    for (int i = 1; i <= n; i++) {
        if (leaf[i]) {
            pending.push(i);
            visited[i] = true;
        }
    }

    int node, count = 0, curr_parent, increase;
    while (!pending.empty()) {
        node = pending.front();
        pending.pop();

        if (current[node] < lower[node]) {
            count++;
            current[node] = upper[node];
        }

        if (node == 1) continue;

        curr_parent = parent[node];

        current[curr_parent] += current[node];
        current[curr_parent] = min(current[curr_parent], upper[curr_parent]);

        if (!visited[curr_parent]) {
            pending.push(curr_parent);
            visited[curr_parent] = true;
        }
    }    

    cout << count << endl;
}
*/

/** Attempt 1 - TLE on Test 31 :(
void calculate() {
    int n; cin >> n;
    list<int> graph[n+1];
    int reverse[n+1];

    int parent;
    for (int i = 2; i <= n; i++) {
        cin >> parent;
        graph[parent].push_back(i);
        reverse[i] = parent;
    }

    reverse[1] = 0;

    int lower_bound[n+1], upper_bound[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> lower_bound[i] >> upper_bound[i];
    }

    queue<int> pending;
    pending.push(1);

    int current_node;
    int in_order[n];

    int r_count = n-1;

    while (!pending.empty()) {
        current_node = pending.front();
        pending.pop();

        in_order[r_count] = current_node;
        r_count--;

        for (int next_node : graph[current_node]) {
            pending.push(next_node);
        }
    }

    int current_value[n+1] = { 0 };
    int uncertainty, max_possible;
    int count = 0, node;

    for (int i = 0; i < n; i++) {
        node = in_order[i];
        if (current_value[node] >= lower_bound[node]) {
            continue;
        }
    
        uncertainty = INT_MAX;
        count++;

        for (current_node = node; 
            current_node != 0; 
            current_node = reverse[current_node]) 
        {
            max_possible = upper_bound[current_node] - current_value[current_node];
            uncertainty = min(uncertainty, max_possible);

            if (!uncertainty) break;

            current_value[current_node] += uncertainty;
        }
    }

    cout << count << "\n";
}
**/