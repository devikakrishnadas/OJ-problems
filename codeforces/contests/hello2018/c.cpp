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

bool compare(pair<int,int>a,pair<int,int>b)
{
    if(a.ff < b.ff)
        return 1;
    else if(a.ff == b.ff)
    {
        if(a.ss > b.ss)
            return 1;
    }
    return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll n,l;
    cin>>n>>l;
    vector<pair<ll,ll> > a;
    for(int i=0;i<n;i++)
    {
        ll t;
        cin>>t;
        a.pb(mp(t,i));
    }
    vll pow2;
    //sort(all(a[i]),compare);
    ll t = 1;
    for(int i=0;i<32;i++)
    {
        pow2.pb(t);
        t = t<<1;
    }
    //int A[100][100];
    vector<pair<double,ll> >costperlitre;
    for(int i=0;i<n;i++)
    {
        costperlitre.pb(mp((1.0*a[i].ff)/pow2[i],i));
    }
    sort(all(costperlitre));
    ll ans = 0;
    ll fans=LLONG_MAX;
    for(int i=0;i<costperlitre.size();i++)
    {
        ll f = a[costperlitre[i].ss].ff;
        ll s = pow2[costperlitre[i].ss];
        cerr<<f<<" "<<s;
        while(l > s)
        {
            //cerr<<l<<" "<<ans<<endl;
            ans += f;
            l-=s;
        }
        if(l - s <= 0)
        {
            fans = min(fans,ans + f);
        }
        cerr<<" ans "<<ans<<endl;

    }
    cout<<fans<<endl;
	return 0;
}

