// Created by rutvik on 29/01/20.

#include "bits/stdc++.h"

#define ln long long
using namespace std;

void bfs(vector<int> adjacency_list[], int node) {
    bool visited[node + 1];
    // assign false value to all nodes
    memset(visited, false, sizeof(visited));
    queue<int> queue;
    // insert the first node where you want to start traversal
    queue.push(node);
    visited[node] = true;
    while (!queue.empty()) {
        int x = queue.front();
        cout << x << " "; // print traversal path
        queue.pop();
        // all adjacency nodes of current node
        for (int i = 0; i < adjacency_list[x].size(); i++) {
            int element = adjacency_list[x][i];
            if (!visited[element]) {
                queue.push(element);
                visited[element] = true;
            }
        }
    }
}

int main() {
    // Max value of node
    int node;
    cin >> node;
    // How many edges are there
    int edge;
    cin >> edge;
    // create adjacency list
    vector<int> adjacency_list[node + 1];
    int first, second;
    for (int i = 0; i < edge; i++) {
        cin >> first >> second;
        // for undirected graph
        adjacency_list[first].push_back(second);
        adjacency_list[second].push_back(first);
    }
    bfs(adjacency_list, node);
}
