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

long long int E_GCD(long long int a,long long int b,long long  int&x,long long int &y)
{
    if(a==0)
    {
        x=0;
        y=1;
        
        return b;
        
    }
    long long int X1,Y1;
    long long int gcd = E_GCD(b%a,a,X1,Y1);
    x=Y1-(b/a)*X1;
    y=X1;
    
    
    return gcd;
    
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
    ll n,q,m;
    //cin>>n>>q>>m;
    sf("%lld%lld%lld",&n,&q,&m);
    vll a(n+1),f(n+2,1),b(n+2,1);

	for(int i=1;i<=n;i++)
    {
        //cin>>a[i];
        sf("%lld",&a[i]);
        f[i] = (f[i-1] * a[i])%m;
        //cerr<<f[i]<<" ";
    }
    //cerr<<endl;
    for(int i=n;i>=1;i--)
    {
        b[i] = (b[i+1] * a[i])%m;
        //cerr<<b[i]<<" ";
    }
    //cerr<<endl;
    while(q--)
    {
        int ind;
        cin>>ind;
        //cerr<<"f : "<<f[ind-1]<<" b : "<<b[ind+1]<<endl;
        ll ans = (f[ind-1]*b[ind+1])%m;
        //cout<<ans<<endl;
        pf("%lld\n",ans);
    }
    return 0;
}

