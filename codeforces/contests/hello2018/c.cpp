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
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)

using namespace std;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll n,l;
    cin>>n>>l;
    vll c(n);
    rep(i,n)
        cin>>c[i];
    vll dp(n,0);
    dp[0] = c[0];
    for(int i=1;i<n;i++)
    {
        dp[i] = min(c[i],2*dp[i-1]);
	}
    ll tl = l;
    ll ans=0;
    for(ll p=0, i = 1;p<n;p++,i*=2)
    {
        if( i & tl )
        {
            ans += (dp[p]*(tl/i));
            tl -= (tl/i)*i;
        }
        else if(tl<=0)
        {
            ans = min(ans,dp[p]);
        }
    }
    cout<<ans<<endl;
    return 0;
}

