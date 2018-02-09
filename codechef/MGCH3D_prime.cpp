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
    ll t = ModE(a*a,mo,b/2);
    
    if(b%2)
        t = t*a;
    return t;
}
void arrange(vll &p, int n,vll &q, vll &r)
{
    for(int i=0;i<n;i++)
    {
        if(i%2 == 0) q.pb(p[i]);
        else r.pb(p[i]);
    }
}


vll FFT(vll p, int n, ll w)
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
         p[i+n/2] = (q[i] - (w_*r[i])%prime + prime)%prime;
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
    ll n,q;
    cin>>n>>q;
    vll p(bign),p_(bign);
    ll w = ModE(3,prime,25);
    REP(i,n)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        ll t1 = x*base*base + y*base + z;
        ll t2 = (totv - x)*base*base + (totv - y)*base + totv-z;
        p[t1] = 1;
        p_[t2] = 1;
    }
    p = FFT(p,bign,w);
    p_= FFT(p_,bign,w);
    REP(i,bign)
        p[i]=(p[i]*p_[i])%prime;
    p = FFT(p,bign,ModE(w,prime,prime-2));
    REP(i,bign)
    {
        p[i]=(p[i]*ModE(bign,prime,prime-2))%prime;
    }
    FOR(i,-totv,totv+1)
    {
        FOR(j,-totv,totv+1)
        {
            FOR(k,-totv,totv+1)
            {
                if(i==0 and j==0 and k==0) continue;
                ll vv = (p[(i+totv)*base*base + (j+totv)*base + k+totv]) + 0.5;
                double den = sqrt(pow(i,4) + pow(j,4) + pow(k,4));
                val[i+totv][j+totv][k+totv] += (1.0*vv/den);
            }
        }
    }
    while(q--)
    {
        ll A,B,C,D;
        cin>>A>>B>>C>>D;
        double ans=0.0;
        FOR(i,-totv,totv+1)
        {
            FOR(j,-totv,totv+1)
            {
                FOR(k,-totv,totv+1)
                {
                    if(i==0 and j==0 and k==0) continue;
                    ans += val[i+totv][j+totv][k+totv]*abs(A*i + B*j + C*k + D);
                    //cout<<val[i+totv][j+totv][k+totv]<<endl;
                }
            }
        }
        double nn = n*1ll*(n-1);
        ans = ans/nn;
        cout<<fixed<<setprecision(20)<<ans<<endl;
    }

    return 0;
}

