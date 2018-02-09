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

using namespace std;
typedef complex<double> cd ;
typedef vector< cd > vcd;
void arrange(vcd &p, int n,vcd &q, vcd &r)
{
    for(int i=0;i<n;i++)
    {
        if(i%2 == 0) q.pb(p[i]);
        else r.pb(p[i]);
    }
}


vcd FFT(vcd p, int n, cd w)
{

    if(n <= 1)
        return p;
    vcd q,r;
    arrange(p,n,q,r);

    q = FFT(q, n/2, w*w);

    r = FFT(r, n/2, w*w);
    cd w_ = 1;
    REP(i,n/2)
    {
         p[i] = q[i] + w_*r[i];
         p[i+n/2] = q[i] - w_*r[i];
        w_ *= w;
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
    vcd p(bign),p_(bign);
    cd w = {cos((2*M_PI)/bign),sin((2*M_PI)/bign)};
    REP(i,n)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        ll t1 = x*base*base + y*base + z;
        ll t2 = (totv - x)*base*base + (totv - y)*base + totv-z;
        p[t1] = cd(1,0);
        p_[t2] = cd(1,0);
    }
    p = FFT(p,bign,w);
    p_= FFT(p_,bign,w);
    REP(i,bign)
        p[i]*=p_[i];
    p = FFT(p,bign,cd(1,0)/w);
    REP(i,bign)
    {
        p[i]=p[i]/cd(bign,0);
    }
    FOR(i,-totv,totv+1)
    {
        FOR(j,-totv,totv+1)
        {
            FOR(k,-totv,totv+1)
            {
                if(i==0 and j==0 and k==0) continue;
                ll vv = (p[(i+totv)*base*base + (j+totv)*base + k+totv].real()) + 0.5;
                double den = sqrt(pow(i,4) + pow(j,4) + pow(k,4));
                val[i+totv][j+totv][k+totv] += (vv/den);
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
                }
            }
        }
        double nn = n*1ll*(n-1);
        ans = ans/nn;
        cout<<fixed<<setprecision(20)<<ans<<endl;
    }

    return 0;
}

