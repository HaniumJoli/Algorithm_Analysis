#include<bits/stdc++.h>
using namespace std;
bool vis[1000000];
void dfs(vector<vector<pair<int,int>>>&graph, int node) {
    vis[node] = true;
    cout << node<< " ";
    int cost=0;
    for (auto neighbor : graph[node]) {
    int i = neighbor.first;
    int edge_cost = neighbor.second;

    

    if (!vis[i]) {
        dfs(graph, i);
        cost += edge_cost; 


    }
}

}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>graph(n+1);

    cout << "Enter the edges (node1 node2 cost):\n";
    for (int i = 0; i < m; ++i) {
        int node1, node2,c;
        cin >> node1 >> node2>>c;
        graph[node1].push_back({node2,c});
        graph[node2].push_back({node1,c});
    }

    int node;
    cin>>node;

   
    dfs(graph, node);
    cout << endl;

    return 0;
}