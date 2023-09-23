#include<bits/stdc++.h>
using namespace std;

int prims(vector<vector<pair<int, int>>> adj, int s,int from,int to,int weight) {
    int n = adj.size();
    vector<bool> vis(n+1, false);
    int cnt = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int ans = weight;
    pq.push({0, from});
    pq.push({0, to});
    while (!pq.empty() && cnt != n) {
        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        ans += wt;
        cnt++;
        vis[u] = true;
        for (auto i : adj[u]) {
            int v = i.first;
            int w = i.second;
            if (!vis[v]) {
                pq.push({w, v});
            }
        }
    }
    return ans;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<pair<int, int>>> adj(v+1);

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int s;
    cin >> s;
    int from,to,weight;
    cin>>from>>to>>weight;
    int ans = prims(adj, s,from,to,weight);
    cout << ans << endl;
    // for(auto x:adj)
    // {
    //     for(auto y: x) cout<<y.first<<' '<<y.second<<"    ";
    //     cout<<endl;
    // }
    return 0;
}
/*
5 7
0 1 2
0 2 4
1 2 1
1 3 7
2 3 3
2 4 5
3 4 6
0
3 4 6
*/
//ans will be 12