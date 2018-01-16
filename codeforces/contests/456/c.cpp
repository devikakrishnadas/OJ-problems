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
    ll n,m,r,k;
    cin>>n>>m>>r>>k;
    ll r1=r,r2=r;
    ll movh = n - (r-1);
    ll movv = m - (r-1);
    ll maxh = min(r,(n-(r-1)));
    ll maxv = min(r,(m-(r-1)));
    map<ll,ll>hcnt,vcnt;
    for(int i=1;i<=maxh;i++)
    {
        if(i==maxh)
        {
            hcnt[i]+=(n-2*(i-1));
        }
        else
        {
            hcnt[i]+=2;
        }
    }
    for(int i=1;i<=maxv;i++)
    {
        if(i==maxv)
        {
            vcnt[i]+=(m-2*(i-1));
        }
        else
        {
            vcnt[i]+=2;
        }
    }
    int tt=0;
    priority_queue<pair<long double,pair<int,int> > > bb;
    bb.push(mp(maxh*maxv,mp(maxh,maxv)));
    int cnt=0;
    double ans=0;
    set<pair<long double,pair<int,int> > >added;
    vector<pair<int,int> >A = {{0,1},{1,0},{1,1}};
    while(k)
    {
        cerr<<"r3"<<endl;
        pair<long double,pair<int,int> > t = bb.top();
        bb.pop();
        maxh = t.ss.ff;
        maxv = t.ss.ss;
        ll f = hcnt[maxh]*vcnt[maxv];
        if(added.find(t) != added.end())
            continue;
        added.insert(t);
        ans += (t.ff * min(f,k));
        cerr<<k<<" "<<f<<" "<<maxh<<" "<<maxv<<endl;
        k -= min(k,f);
        for(int j=0;j<3;j++)
        {
            cerr<<"r1"<<endl;
            ll F = maxh-A[j].ff, S = maxv-A[j].ss;
            if(F==0 || S==0) continue;
            if(added.find(mp(F*S,mp(F,S))) == added.end())
            {
                bb.push(mp(F*S,mp(F,S)));
            }
        }
        cerr<<"r2"<<endl;
    }
    cerr<<"ans "<<ans<<endl;
    ans = ans/(1.0*movh*movv);
    cout<<fixed<<setprecision(10)<<ans<<endl;
	return 0;
}

