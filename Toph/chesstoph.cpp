#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x,y;
};
double dis(const point& p1, const point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
double pairdis(vector<point>&x)
{
	
} 
int main()
{
	int n;
	cin>>n;
	vector<point>x(n);
	for(int i=0;i<n;i++)
	{
		cin>>x[i].x>>x[i].y;
	}
	double ans=pairdis(x);
	cout<<ans<<endl;
	return 0;
}