#include<bits/stdc++.h>
#define ll unsigned long long
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
#define inf 1000000000000000001
using namespace std;
ll n,k;
void calc(vll p, vll &v)
{
    priority_queue<ll,vll,greater<ll> >a;
    a.push(1);
  //  cerr<<"Enter"<<endl;
    while(!a.empty())// and v.size() < 3*k)
    {
        ll t = a.top();
        a.pop();
//        cerr<<t<<endl;
        if(!binary_search(all(v),t))
        {
            v.pb(t);
            for(ll val : p)
                if(val <= inf/t)
                    a.push(val*t);
        }
    }
}

ll count(vll &a, vll&b,ll val)
{
    int j=b.size()-1;
    ll ans = 0;
    for(int i=0;i<a.size();i++)
    {
        while(j>=0 and a[i]>val/b[j])
            j--;
        ans = ans + j + 1;
    }
    return ans;
}
void print(vll &a)
{
    for(int i=0;i<10;i++)
        cerr<<a[i]<<" ";
    cerr<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    vll p(n),a,b;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        if(i%2) a.pb(p[i]);
        else b.pb(p[i]);
    }
    cin>>k;
    ll hi = LLONG_MAX;
    ll lo = 0;
    vll a1,b1;
    calc(a,a1);
    cerr<<"r1"<<endl;
    calc(b,b1);
    cerr<<"r2"<<endl;
    ll ans;
    while (hi - lo > 1) 
    {
		ll mid = (lo+hi)>>1;
		ll cnt = count(a1,b1,mid);
		if (cnt >= k) hi = mid;
		else lo = mid;
//        cout<<cnt<<" "<<k<<endl;
	}
	if(count(a1,b1,lo) >= k) ans = lo;
	else ans = hi;
	cout<<ans<<endl;
    return 0;
}

