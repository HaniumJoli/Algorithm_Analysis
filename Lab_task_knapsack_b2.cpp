#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &weight, vector<int> &value,vector<int> &volume, int n, int maxWeight,int maxVolume) {
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(maxWeight+1, vector<int>(maxVolume+1, 0)));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= maxWeight; w++) {
          for(int v=1;v<=maxVolume;v++)
          {
              int include=0;
              if(weight[i-1]<=w && volume[i-1]<=v)
              {
                  include=value[i-1]+dp[i-1][w-weight[i-1]][v-volume[i-1]];
              }
              int exclude=dp[i-1][w][v];
              dp[i][w][v]=max(include,exclude);
          }
        }
    }
    return dp[n][maxWeight][maxVolume];
}
int main() {
    int n;
    int maxWeight;
    int maxVolume;
    cin >>n;
    cin >>maxWeight;
    cin>>maxVolume;
    vector<int> weight(n);
    vector<int> value(n);
    vector<int>volume(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
     for (int i = 0; i < n; i++) {
        cin >> volume[i];
    }
    int result = knapsack(weight, value,volume, n, maxWeight,maxVolume);
    cout << result << endl;
    return 0;
}