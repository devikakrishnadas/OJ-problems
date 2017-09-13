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

void dfs(vector < vi >&A,int a,int &cnt)
{
	cnt++;
	for(int i=0;i<A[a].size();i++)
	{
		
		dfs(A,A[a][i],cnt);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;	
	int x;
	vector< vi >A(n+22),B(n+22);
	for(int i=1;i<n;i++)
	{
		cin>>x;
		if(x==1)
		{
			A[i].pb(i+1);
			B[i+1].pb(i);
		}
		else 
		{
			A[i+1].pb(i);
			B[i].pb(i+1);
		}
	}
	int q;
	cin>>q;
	bool ua=1;
	while(q--)
	{
		char c;
		cin>>c;
		if(c=='U')
		{
			ua=1-ua;
		}
		else
		{
			int t;
			cin>>t;
			int cnt=0;
			if(ua==1)
			{
				dfs(A,t,cnt);
			}
			else dfs(B,t,cnt);
			cout<<cnt<<endl;
		}
	}
	return 0;
}

