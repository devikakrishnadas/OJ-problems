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

void calcpp(vcd &p,vcd &pp,int a,int b)
{
    int j=1;
    for(int x:p)
    {
        while(j<x)
        {
            pp[a*j+b] = cd(0,0);
            j++;
        }
        pp[a*j + b] = cd(1,0);
        j++;
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cd w = {cos((2*M_PI)/n),sin((2*M_PI)/n)};
        //vcd ans = FFT(p,n,w);
        //p = iFFT(ans,n,w);
        int n;
        vi p1,p2,p3; // points;
        int offset = 1000000;
        int y1=0,y2=0,y3=0;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            if(x==1) 
            {
                p1.pb(y);
                y1 = max(y1,y);
            }
            else if(x==2) 
            {
                p2.pb(y);
                y2 = max(y2,y);
            }
            else 
            {
                p3.pb(y);
                y3 = max(y3,y);
            }
        }

        int j=1;
        int value = pow(2,12);
        vcd pp1(value),pp2(2*value),pp3(value); // coeff of polynomial
        calcpp(p1,pp1,1,0);
        calcpp(p2,pp2,-2,offset);
        calcpp(p3,pp3,1,0);
        vcd f1 = FFT(pp1,value,w);
        vcd f2 = FFT(pp2,value,w);
        vcd f3 = FFT(pp3,value,w);
        vcd f(4*value);
        for(int i=0;i<value;i++)
        {
            f[i] = f1[i]*f2[i]*f3[i];
        }
        vi ans = iFFT(f,value,w);

    }
	return 0;
}

