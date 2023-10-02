#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int x,y;
    cin>>x>>y;
    int a=x-(y%x);
    cout<<a<<endl;
    return 0;
}