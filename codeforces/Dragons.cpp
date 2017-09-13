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
	vector<pair<int,int> >A;
	int s,n;
	cin>>s>>n;
	int x,y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		A.pb(mp(x,y));
	}
	sort(A.begin(),A.end());
	for(int i=0;i<n;i++)
	{
		if(s>A[i].first)
		{
			s=s+A[i].second;
		}
		else 
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}

