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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,b;
        cin>>n>>b;
        ll val=0;
        if(b>=n)
        {
            cout<<0<<endl;
            continue;
        }
        else if((n/2)<=b)
        {
            cout<<(n-b)<<endl;
            continue;
        }
        for(ll i=min((ll)1,(n/2)-500);i<=(n/2)+500;i++)
        {
            val=max(val,i*((n-i)/b));
        }
        cout<<val<<endl;
    }
	return 0;
}

