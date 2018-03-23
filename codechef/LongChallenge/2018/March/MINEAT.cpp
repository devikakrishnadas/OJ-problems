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


ll calc(int mid, vi &a)
{
    ll n=a.size();
    ll ans =0 ;
    REP(i,n)
    {
        ans += ((a[i]/mid)+(a[i]%mid ? 1 : 0));
    }
    return ans;
}
ll b_s(vi &a,int h)
{
    ll s=1;
    ll e=1000000234;
    ll ans=-1;
    while(s<=e)
    {
        ll mid = (s+e)/2;// mid gives the rate per which minion eats banana
        if(mid == 0)
        {
            break; 
        }
        ll ht = calc(mid,a);// ht has the number of hours it takes with mid banana/hour
        if(ht <= h)
        {
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
        if(ht<=h)
            ans=mid;
    }
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,h;
        cin>>n>>h;
        vi a(n);
        REP(i,n) cin>>a[i];
        cout<<b_s(a,h)<<endl;
    }
	return 0;
}

