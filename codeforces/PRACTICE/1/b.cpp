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
    int n;
    cin>>n;
    vector<pair<ll,pair<ll,ll> > >A;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        A.pb(mp(x-y,mp(x,y)));
    }
    sort(all(A));
    reverse(all(A));
    ll ans=0;
    ll cur=0;
    for(int i=0;i<n;i++)
    {
        if(cur<A[i].ss.ff)
        {
            ll t=A[i].ss.ff-cur;
            cur=cur+t;
            ans=ans+t;
            cur=cur-A[i].ss.ss;
        }
        else
            cur=cur-A[i].ss.ss;
        
    }
    cout<<ans<<endl;
	return 0;
}

