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

using namespace std;

void binary(ll val, vi &b)
{
    ll cnt=0;
    while(val)
    {
        b[cnt] = val%2;
        cnt++;
        val=val/2;
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll n,q;
    cin>>n>>q;
    vi a(n);
    vector<vi > bits(n);
    vector<vi > bitSum(n);
    REP(i,n) 
    {
        cin>>a[i];
        bits[i].resize(32,0);
        binary(a[i],bits[i]);
        bitSum[i].resize(32,0);
        bitSum[i] = bits[i];
    }
    REP(i,31)
    {
        REP(j,n)
        {
            if(j)
            {
                bitSum[j][i] = bitSum[j][i] + bitSum[j-1][i];
            }
        }
    }
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        ll tn = (r-l+1);
        vi t(32,0);
        for(ll i=0;i<31;i++)
        {
            t[i] = bitSum[r][i] - bitSum[l][i] + bits[l][i];
        }
        ll ans = 0;
        for(ll i=0, tval = 1;i<31;i++, tval*=2)
        {
            ll val = 0;
            if(tn-t[i] > t[i])
            {
                val = 1;
            }
            ans = ans + val*tval;
        }
        cout<<ans<<endl;
    }
	return 0;
}

