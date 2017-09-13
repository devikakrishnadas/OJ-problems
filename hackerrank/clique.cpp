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

int n,m;
int func(int r)
{
	int _m=((r-1)*n*n)/(2*r);
	if(_m<m)
	{
		while(((r-1)*n*n)/(2*r)<=m)
		{
			r++;
		}
		return r;
	}
//	else if(_m==m)
//		return r;
	return func(r-1);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		cin>>n>>m;
		cout<<func(n)<<endl;
	}
	return 0;
}

