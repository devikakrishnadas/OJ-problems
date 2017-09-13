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
int max_k=0;
void dfs(vector < vi >&A, int par, int gpar,vi &col)
{
	int k=0;
//	cout<<"r3"<<endl;
	for(int i=0;i<A[par].size();i++)
	{
		
		if(!col[A[par][i]])
		{
			k++;
			while(k==col[par] || k==col[gpar])
				k++;
			col[A[par][i]]=k;
			dfs(A,A[par][i],par,col);
			
		}
	//	k++;
	}
	max_k=max(max_k,k);
}

int main()
{
	int n;
	cin>>n;
	vector< vi >A(200023);
	int x,y;
//	cout<<"r1"<<endl;
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		A[x].pb(y);
		A[y].pb(x);
	}
	vi col(n+1,0);
	x=1;
	col[x]=1;
//	cout<<"r2"<<endl;
	dfs(A,x,0,col);
	for(int i=1;i<=n;i++)
		max_k=max(max_k,col[i]);
	cout<<max_k<<endl;
	for(int i=1;i<=n;i++)
		cout<<col[i]<<" ";
	cout<<endl;
	return 0;
}

