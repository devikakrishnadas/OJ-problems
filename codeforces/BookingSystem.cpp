#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
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
	vector<pair<int,pair<int,int> > >A;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		A.pb(mp(x,mp(y,i+1)));
	}
	sort(all(a));
	int k;
	cin>>k;
	vector<pair<int,int> >r;
	for(int i=0;i<k;i++)
	{
		int x;
		cin>>x;
		r.pb(mp(x,i+1));
	}
	sort(all(r));
	int apos=0;
	
	return 0;
}

