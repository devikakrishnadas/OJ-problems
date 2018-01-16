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

using namespace std;

ll n,k;

void func(set<ll>&fin,vll p)
{   
    priority_queue<ll, vll , greater<ll> >a;
    a.push(1);
    while(fin.size() < k)
    {
        ll v = a.top();
        fin.insert(v);
        a.pop();
        for(int i=0;i<p.size();i++)
        {
            if(fin.find(v*p[i]) == fin.end())
                a.push(v*p[i]);
        }
    }
}

bool isThere=0;
ll calc(set<ll> &a,set<ll> &b, ll v)
{
    auto i = a.begin();
    auto j = b.begin();
    ll cnt=0;
    for(; i!= a.end(); i++)
    {
        cerr<<"cnt "<<cnt<<endl;
        while( *i * *j < v and j!= b.end())
        {
            j++;
            cnt++;
            cerr<<" *i "<<*i<<" *j "<<*j<<" "<<v<<endl;
        }
    }
    cerr
    return cnt+1;
}


ll b_s(set<ll> a,set<ll> b)
{
    ll s= 0;
    ll e= LLONG_MAX;
    ll ans = -1;
    while(s<e)
    {
        isThere=0;
        ll mid = (s+e)/2;
        ll val = calc(a,b,mid);
        if(val < k)
        {
            s = mid+1;
        }
        else 
        {
            e = mid;
            if(val == k)
            {
                cerr<<" BS "<<e<<endl;
            }
        }
    }
    while(!isThere)
    {
        e++;
        calc(a,b,e);
    }
    return e;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    vll p(n); 
    vll aa,bb;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        if(i%2) aa.pb(p[i]);
        else bb.pb(p[i]);
    }
    cin>>k;
    set<ll>a,b;
    a.insert(1);
    b.insert(1);
    func(a,aa);
    func(b,bb);
    cout<<b_s(a,b)<<endl;
    return 0;
}

