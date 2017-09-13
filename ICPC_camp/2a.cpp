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

vi path;
vi A[10000];
int no[4000]={0};
bool time=1;
int startp;
void dfs(int a,v[4000])
{
	path.pb(a);
	no[a]++;
	if(no[a]==2 && time)
	{
		time=0;
		startp=a;	
	}
	for(int i=0;i<A[a].size();i++)
	{
		if(!v[A[a][i]])
		{
			dfs(A[a][i]);
			
		}
	}
}
int l=0;
int sp[4000];
void shortestPath(int a,int l,int v[4000])
{
	sp[a]=min(sp[a],l);
	v[a]=1;
	for(int i=0;i<A[a].size();i++)
        {
                if(!v[A[a][i]])
                {
                        shortestPath(A[a][i],l+1,v);

                }
        }

}
int main()
{
	int n;
	int x,y;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		sp[i]=INT_MAX;
		cin>>x>>y;
		x--;
		y--;
		A[x].pb(y);
		A[y].pb(x);
	}
	int v[4000]={0};
	dfs(x,v);
	bool enter=0;
	for(int i=0;i<path.size();i++)
	{
		if(path[i]==startp)
		{
			if(enter==0)
				enter=1;
			else break;
		}
		if(enter)
		{
			int v[4000]={0};
			shortestPath(path[i],0,v);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(sp[i]==INT_MAX)
			cout<<0<<" ";
		else cout<<sp[i]<<" ";
	}
	cout<<endl;
	return 0;
}

