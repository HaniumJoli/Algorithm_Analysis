#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1000][1000];
int ways(int arr[],int n,int sum)
{
    if(sum==0)
    {
        return 1;
    }
    if(n<=0)
    {
       return 0;
    }
    if(dp[n][sum]!=-1)
    {
        return dp[n][sum];
    }
    int exclude=ways(arr,n-1,sum);
    int include=0;
    if(arr[n-1]<=sum)
    {
     include=ways(arr,n-1,sum-arr[n-1]);
    }
    return dp[n][sum]=exclude+include;

}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    cout<<ways(arr,n,sum)<<endl;
    return 0;
}
/*
7
2 3 5 8 12 13 15
20
*/
