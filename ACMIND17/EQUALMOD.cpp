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
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<pair<ll,ll> >a(n,mp(0,0));
    
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            a[i].ff=x;
        }
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            a[i].ss=x;
            a[i].ff%=a[i].ss;
        }

        sort(all(a));
        ll minb=a[0].ff;
        vll toZero(n,0);
        for(int i=0;i<n;i++)
        {
            toZero[i]=(a[i].ss-a[i].ff);
            toZero[i]+=toZero[i-1];
        }
        ll ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,a[i].ff*(n)+toZero[n-1]-toZero[i]);
        }
        cout<<ans<<endl;
    }
	return 0;
}

