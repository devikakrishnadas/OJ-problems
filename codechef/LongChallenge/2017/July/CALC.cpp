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
        int x=n/(2*b);
        int y=(n/b)-x;
        int z=n%b;
        cout<<max(x*z + x*b*y, y*z + x*b*y)<<endl;
    }
	return 0;
}

