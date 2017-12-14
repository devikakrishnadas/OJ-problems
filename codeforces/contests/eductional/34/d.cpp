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

vector<ll> vals(200023,0);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll n;
    ll ans=0;
    cin>>n;
    vll a(n+1,0);
    //map<ll,vector<ll> >c;
    set<ll>ab;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ab.insert(a[i]);
  //      c.pb(mp(a[i],i));
        if(i==1) continue;
        vals[i] = vals[i-1] + (i-2)*a[i-1] + a[i-1] - (i-1)*a[i];
        ans+=vals[i];
    }
    cout<<ans<<endl;
    int i=0;
    map<ll,ll>val;
    for(int i=1;i<=n;i++)
    {
        val[a[i]]++;
        ans=ans + val[a[i]-1];
        ans=ans - val[a[i]+1];
    }
    cout<<(ll)(((ll)-1)*ans)<<endl;
	return 0;
}

