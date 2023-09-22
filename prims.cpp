#include<bits/stdc++.h>
using namespace std;

int prims(vector<vector<pair<int, int>>>& adj, int s) 
{
    int n = adj.size();
    vector<bool> vis(n, false);
    int cnt = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int ans = 0;
    pq.push({0, s});
    while (!pq.empty() && cnt != n) {
        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) 
        {
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
    int ans = prims(adj, s);
    cout << ans << endl;
    return 0;
}
/*

6 9
1 2 2
1 4 3
1 5 4
2 6 7
2 3 3
2 4 3
4 5 9
3 4 5
3 6 8
1
*/
//ans will be 17
