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
vector<vi>A(100023);
vi col(100023,0);
vi children(100023,-1);
ll ans=0;
int dfs(int a,int l,int p)
{
    l++;
    if(col[a])
    {
        children[a]=l;
        ans=ans+l;
        l=0;
    }
    for(int i=0;i<A[a].size();i++)
    {
        if(A[a][i]!=p)
        {
            dfs(A[a][i],l,a);
        }
        l=children[a];
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    //vector<vi>A(n+1);
    for(int i=0;i<n-1;i++)
    {
        int x;
        cin>>x;
        A[i+1].pb(x);
        A[x].pb(i+1);
    }   
    //vi col(n+1,0);
    int black=-1;
    for(int i=0;i<n;i++)
    {
        cin>>col[i];
        if(col[i]) black=i;
    }
    dfs(i,0);
    cout<<ans<<endl;
	return 0;
}

