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

int main()
{
	int n;
	int x,y;
	int my=0,mix=INT_MAX;
	cin>>n;
	vector<pair<int,int> >A;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		A.pb(mp(x,y));
		mix=min(mix,x);
		my=max(my,y);
	}

	for(int i=0;i<n;i++)
	{
		if(A[i].first==mix && A[i].second==my)
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}

