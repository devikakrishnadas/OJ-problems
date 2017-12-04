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

int leaf=0;

void dfs(int a,int p,vector<vi>&A)
{
    if(A[a].size()==1)
    {
        leaf++;
        return;
    }
    for(int i=0;i<A[a].size();i++)
    {
        if(A[a][i]!=p)
        {
            dfs(A[a][i],a,A);
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vector< vi >A(n+1);
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        A[x].pb(y);
        A[y].pb(x);
    }
    dfs(1,-1,A);
    vi pow2(100025,1);
    for(int i=1;i<=100000;i++)
    {
        pow2[i]=(pow2[i-1]*2)%M;
    }
    cout<<pow2[n-leaf]<<endl;
	return 0;
}

