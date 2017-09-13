#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
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
	int n,m;
	cin>>n>>m;
	vi c(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	vector< vi >A(n+1);
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		A[x].pb(y);
		A[y].pb(x);
	}
	//cout<<"r1"<<endl;
	set<int>ans[100023];
	//cout<<"r2"<<endl;
	//sort(all(c));
	for(int i=1;i<=n;i++)
	{
		//cout<<"Size :"<<A[i].size()<<endl;
		for(int j=0;j<A[i].size();j++)
		{
			if(c[i]!=c[A[i][j]])
				ans[c[i]].insert(c[A[i][j]]);
			//cout<<i<<" "<<A[i][j]<<endl;
		}
	}
	//cout<<"r3"<<endl;
	int ma=-1;
	int mai=-1;
	sort(all(c));
	for(int i=1;i<=n;i++)
	{
		if((int)ans[c[i]].size()>ma)
		{
			mai=c[i];
			ma=(int)ans[c[i]].size();
		}
		
	}
	cout<<mai<<endl;
	return 0;
}

