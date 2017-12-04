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
    int si=1;
    for(int i=2;i<=n;i++)
    {
        if(A[i].size()<A[si].size())
        {
            si=i;
        }
    }
    vi a(n+1,1);
    //cout<<si<<endl;
    a[si]=0;
    for(int i=0;i<A[si].size();i++)
    {
        a[A[si][i]]=0;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
	return 0;
}

