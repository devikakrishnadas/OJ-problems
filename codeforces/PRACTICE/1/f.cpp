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
    ll n;
    cin>>n;
    vll a(n+2,0);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    ll mi=0;
    ll ma=0;
    ll ans=0;
    for(int i=1;i<=n+1;i++)
    {
        if(a[i]>a[i-1])
        {
            ma=a[i];
        }
        else
        {
            ans+=(ma-mi);
            mi=a[i];
            ma=a[i];
        }
    }
    cout<<ans<<endl;
	return 0;
}

