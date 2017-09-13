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
#define xx first
#define yy second

using namespace std;

int main()
{
	vector<pair<int,int> >A;
	int x,y;
	set<pair<int,int> >ans;
	for(int i=0;i<3;i++)
	{
		cin>>x>>y;
		A.pb(mp(x,y));
	}
	ans.insert(mp(A[1].xx-A[0].xx+A[2].xx , A[1].yy-A[0].yy+A[2].yy));
	ans.insert(mp(A[1].xx-A[2].xx+A[0].xx , A[1].yy-A[2].yy+A[0].yy));
	ans.insert(mp(A[2].xx-A[0].xx+A[1].xx , A[2].yy-A[0].yy+A[1].yy));
	ans.insert(mp(A[0].xx-A[1].xx+A[2].xx , A[0].yy-A[1].yy+A[2].yy));
        ans.insert(mp(A[2].xx-A[1].xx+A[0].xx , A[2].yy-A[1].yy+A[0].yy));
        ans.insert(mp(A[0].xx-A[2].xx+A[1].xx , A[0].yy-A[2].yy+A[1].yy));
	
	cout<<ans.size()<<endl;
	set<pair<int,int> >::iterator it;
	for(it=ans.begin();it!=ans.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}

