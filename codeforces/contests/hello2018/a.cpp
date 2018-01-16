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
    ll n,m;
    cin>>n>>m;
    swap(m,n);
    ll val=0;
    vi b;
    while(n && m)
    {
        b.pb(n%2);
        n=n/2;
        m--;
    }
    ll t=1;
    ll ans = 0;
    for(int i=0;i<b.size();i++)
    {
        ans = ans + t*b[i];
        t = t*2;
    }
    cout<<ans<<endl;
	return 0;
}

