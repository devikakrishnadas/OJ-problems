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
const double PI = 3.1415926536;

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

vcd iFFT(vcd p,int n, cd w)
{
    return FFT(p,n,cd(1,0)/w);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    cd w = {cos((2*M_PI)/n),sin((2*M_PI)/n)};
    vcd p(3*n+1);
    REP(i,n)
    {
        int x;
        cin>>x;
        p[i]= cd (x,0);
    }
    vcd ans = FFT(p,n,w);
    for(cd x : ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    p = iFFT(ans,n,w);
    for(cd x : p)
    {
        cout<<x/cd(n,0)<<" ";
    }
    cout<<endl;
	return 0;
}

