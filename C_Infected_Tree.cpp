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
    vector<int> tree[n+1];

    int node1, node2;

    for (int i = 0; i < n - 1; i++) {
        cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }

    queue<pair<int, int>> pending;
    pair<int, int> temp;

    bool visited[n+1] = { false };

    pending.push(make_pair(1, 0));
    int current_node, current_depth, next_node_count;

    while (!pending.empty()) {
        tie(current_node, current_depth) = pending.front();
        pending.pop();

        visited[current_node] = true;

        next_node_count = 0;
        for (int next_node : tree[current_node]) {
            if (!visited[next_node]) {
                pending.push(make_pair(next_node, current_depth + 1));
                next_node_count++;
            }
        }

        if (next_node_count < 2) break;
    }
    
    while (!pending.empty()) {
        temp = pending.front();
        pending.pop();

        if (temp.second == current_depth) {
            if (tree[temp.first].size() <= 1) next_node_count = 0;
        } else {
            break;
        }
    }

    int blocked_nodes, infected_nodes, saved_nodes;

    blocked_nodes = current_depth + next_node_count;
    infected_nodes = current_depth + 1;

    saved_nodes = n - (blocked_nodes + infected_nodes);

    cout << saved_nodes << "\n";
}