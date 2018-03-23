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
    ll n;
    cin>>n;
    vll a(n),b(n),t(n);
    REP(i,n)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    ll s=0;
    REP(i,n)
    {
        cin>>t[i];
        if(i)
            b[i]+=s;
        s+=t[i];
    }
    priority_queue<ll,vector<ll>,greater<ll> >q;
    ll sum=0;
    ll ans=0;
    vll aa;
    for(int i=0;i<n;i++)
    {
        ans=0;
        q.push(b[i]);
        sum+=t[i];
        if(!q.empty())
        while(q.top()<=sum)
        {
            ans+=(q.top()-(sum-t[i]));
            q.pop();
            if(q.empty())
                break;
        }
        ans+=(q.size()*t[i]);
        aa.pb(ans);
    }
    for(ll x:aa)
        cout<<x<<" ";
    cout<<endl;
	return 0;
}

