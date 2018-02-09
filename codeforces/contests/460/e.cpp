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


ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll a,b,p,x;
    cin>>a>>b>>p>>x;
    ll x,y;
    FOR(i,1,p)
    {
        ll x,y;
        
    }
    return 0;
}

