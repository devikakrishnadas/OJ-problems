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
    string s;
    cin>>s;
    int n=s.length();
    vector < vi > A(300);
    for(int i=0;i<300;i++)
    {
        A[i].pb(0);
    }
    for(int i=0;i<n;i++)
    {
        A[s[i]].pb(i+1);
    }
    for(int i=0;i<300;i++)
    {
        A[i].pb(n+1);
    }
    int ans=INT_MAX;

    for(int i=0;i<300;i++)
    {
        int tans=0;
        for(int j=1;j<A[i].size();j++)
        {
            tans=max(tans,A[i][j]-A[i][j-1]);
        }
        ans=min(ans,tans);
    }
    cout<<ans<<endl;
	return 0;
}

