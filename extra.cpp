#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return source == destination;
        }
        vector<pair<int, int>> p;
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            p.emplace_back(u, v);
        }

        for (int i = 0; i < p.size(); i++) {
            if ((p[i].first == source && p[i].second == destination) || (p[i].first == destination && p[i].second == source)) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    Solution solution;
    
    // Example usage
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    int source = 0;
    int destination = 4;
    
    bool result = solution.validPath(n, edges, source, destination);
    
    if (result) {
        cout << "There is a valid path from " << source << " to " << destination << "." << endl;
    } else {
        cout << "There is no valid path from " << source << " to " << destination << "." << endl;
    }
    
    return 0;
}
