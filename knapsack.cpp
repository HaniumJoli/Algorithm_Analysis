#include<bits/stdc++.h>
using namespace std;
int knapsack(int c, int wt[], int p[], int n)
{
    vector<vector<int>> table(n + 1, vector<int>(c + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            if (i == 0 || j == 0)
            {
                table[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                table[i][j] = max(p[i - 1] + table[i - 1][j - wt[i - 1]], table[i - 1][j]);
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }
    return table[n][c];
}
int main()
{
    int weight[] = {1, 2, 3};
    int profit[] = {10, 15, 40};
    int capacity = 6;
    int n = sizeof(profit) / sizeof(profit[0]);
    int ans = knapsack(capacity, weight, profit, n);
    cout << ans << endl;
    return 0;
}
