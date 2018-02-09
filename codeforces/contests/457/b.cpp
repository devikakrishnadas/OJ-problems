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
	ll n,k;
    cin>>n>>k;
    vll pow2(100,0);
    ll val = 1;
    map<ll,ll,greater<ll> >a;
    REP(i,64)
    {
        pow2[i] = val;
        val = val*2;
        if(n & pow2[i])
        {
            a[i]=1;
        }
    }
    k-=a.size();
    int cnt = 0;
    if(k<0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    while(k>0)
    {
        auto t = *a.begin();
        if(k >= t.ss)
        {
            a.erase(t.ff);
            a[t.ff-1] += 2*t.ss;
            k-=t.ss;
        }
        else
        {
            auto tt = *a.rbegin();
            a[tt.ff]-=1;
            a[tt.ff-1]+=2;
            k-=1;
            if(a[tt.ff]==0) a.erase(tt.ff);
        }
    }
    cout<<"Yes"<<endl;
    for(auto i:a)
    {
        REP(j,i.ss)
        {
            cout<<i.ff<<" ";
        }
    }
    cout<<endl;
    return 0;
}

