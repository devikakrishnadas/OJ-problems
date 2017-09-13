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
	cin>>n;
	vector<pair<int,int> >A;
	int x,y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		A.pb(mp(x,y));
	}
	sort(A.begin(),A.end());
	for(int i=1;i<n;i++)
	{
		if(A[i-1].second>A[i].second)
		{
			cout<<"Happy Alex"<<endl;
			return 0;
		}
	}
	cout<<"Poor Alex"<<endl;
	
	return 0;
}

