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
	vector<pair<int,int> >A,B;
	int a,b;
	int n;
	cin>>n;
	bool rated=0;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		A.pb(mp(a,b));
		B.pb(mp(a,b));
		if(a!=b)
		{
			rated=1;
		}
	}
	if(rated)
	{
		cout<<"rated"<<endl;
		return 0;
	}
	sort(all(B));
	reverse(all(B));
	for(int i=0;i<n;i++)
	{
		if(A[i]!=B[i])
		{
			cout<<"unrated"<<endl;
			return 0;
		}
	}
	cout<<"maybe"<<endl;
	return 0;
}

