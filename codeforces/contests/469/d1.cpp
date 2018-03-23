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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll n,q;
    cin>>n>>q;
    while(q--)
    {
        ll x;
        cin>>x;
        if(x%2)
        {
            cout<<x/2 + 1<<endl;
        }
        else
        {
            ll val = n - x/2;
            ll ans = val;
            while(val%2 == 0)
            {
                val = val/2;
                ans = ans + val;
            }
            ans = ans+x;
            cout<<(ans+1)/2<<endl;
        }
    }
	return 0;
}

