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
#define REP(i,n) FOR(i,0,n)
ll bign = 1 << 22 ;
ll totv = 77;
ll base = 160;
ll prime = 25 * bign + 1;
using namespace std;

ll ModE(ll a,ll mo,ll b)
{
    if(b==0)
        return 1;
    else if(b==1)
        return a%mo;
    
        return (a*ModE(a*a,mo,b/2))%mo;
    else return (ModE(a*a,mo,b/2))%mo;
}
void arrange(vll &p, ll n,vll &q, vll &r)
{
    for(int i=0;i<n;i++)
    {
        if(i%2 == 0) q.pb(p[i]);
        else r.pb(p[i]);
    }
}


vll FFT(vll p, ll n, ll w)
{
    if(n <= 1)
        return p;
    vll q,r;
    arrange(p,n,q,r);

    q = FFT(q, n/2, (w*w)%prime);

    r = FFT(r, n/2, (w*w)%prime);
    ll w_ = 1;
    REP(i,n/2)
    {
         p[i] = (q[i] + (w_*r[i])%prime)%prime;
         p[i+n/2] = ((q[i] - (w_*r[i])%prime)%prime + prime)%prime;
         w_ = (w_*w)%prime;
    }
    return p;
}



double val[200][200][200] = {0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    vll p(bign);
    ll w = ModE(3,prime,25);
    cout<<prime<<endl;
    REP(i,4)
    {
        cin>>p[i];
    }
    p = FFT(p,bign,w);
    cout<<"hello"<<endl;

    p = FFT(p,bign,ModE(w,prime,prime-2));
    ll inv = ModE(bign,prime,prime-2);
    cout<<"inverse : "<<inv<<endl;
    REP(i,4)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    return 0;
}

