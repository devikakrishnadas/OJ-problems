#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;


double bs(vll &x, vll &v,ll n)
{
	double l=0;
	double h=DBL_MAX;
	double ma=0.0,m=0.0;
	///cout<<"r1"<<endl;
	double ans=DBL_MAX;
	while(h-l>0.000001)
	{
		//cout<<"r2"<<endl;
		ma=0.0;
		double Max=0.0;
		m=(l+h)/2;
//		cout<<l<<" "<<h<<" "<<m<<endl;
		for(int i=0;i<n;i++)
		{
			if(abs(ma)<abs((x[i]-m)/v[i]))
			{
				ma=(x[i]-m)/v[i];
				Max=x[i];
			}
		}
		if(ma<=0)
		{
			h=m;
//			l=Max;
		}
		else 
		{
			l=m;
//			h=Max;
		}
		ans=min(ans,abs(ma));
	}
	return ans;
}

int main()
{
	ll n;
	cin>>n;
	vll x(n),v(n);
	for(int i=0;i<n;i++)
		cin>>x[i];
	for(int i=0;i<n;i++)
		cin>>v[i];
	pf("%0.6f\n",bs(x,v,n));
//	cout<<DBL_MAX<<endl;
	return 0;
}
