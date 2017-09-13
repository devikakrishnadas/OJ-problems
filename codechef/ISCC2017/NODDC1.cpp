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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector< vi >A(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        A[x].pb(y);
        A[y].pb(x);
    }
    dfs(A,1,-1,vis);
	return 0;
}

