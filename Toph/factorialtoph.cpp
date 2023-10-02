#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> dp; 

ll fact(int n)
{
    dp.resize(n + 1); 
    dp[0] = 1; 
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] * i; 
    }
    return dp[n];
}

int main()
{
    ll n;
    cin >> n;
    ll result = fact(n); 
    
    
    return 0;
}
