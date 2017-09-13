#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define ss second
#define ff first
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<pair<int,int> >A;
	for(int i=0;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		A.pb(mp(x,y));
	}
	int cnt=0;
	for(int i=1;i<n-1;i++)
	{
		int x1=A[i-1].ff;
		int y1=A[i-1].ss;
		int x2=A[i+1].ff;
		int y2=A[i+1].ss;
		int x=A[i].ff;
		int y=A[i].ss;
		
		int ans=(x2-x1)*(y-y1)-(y2-y1)*(x-x1);
		if(ans<0) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}

