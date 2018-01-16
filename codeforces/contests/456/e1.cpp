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
const ll magic = 4;
void func(vll &p, set<ll>&f)
{
    cerr<<"enter"<<endl;
    priority_queue<ll,vll,greater<ll> >a;
    a.push(1);
    while(f.size() < k)
    {
        ll temp = a.top();
        a.pop();
        if(f.find(temp) != f.end())
            continue;

        cerr<<"temp "<<temp<<" f.size() "<<f.size()<<endl;
        f.insert(temp);
        for(int i=0;i<p.size();i++)
        {
            if(f.find(temp*p[i]) == f.end())
                a.push(temp * p[i]);
        }
    }
}

bool present;
ll calc(set<ll>&a, set<ll>&b, ll val)
{
    ll cnt = 0;
    auto j = b.begin();
    for(auto i=a.begin(); i!= a.end(); i++)
    {
        while((*i) * (*j) < val and j!=b.end())
        {
            cnt++;
            j++;
        }
        if((*i) * (*j) == val)
            present = 1;
    }
    return cnt;
}

ll b_s(set<ll>&a,set<ll>&b)
{
    ll hi = 1000;
    ll lo = 0;
    ll ans = 0;
    while(lo<hi)
    {
        ll mid = (hi+lo)/2;
        ll val = calc(a,b,mid);
        cerr<<" lo hi val k present "<<lo<<" "<<hi<<" "<<val<<" "<<k<<" "<<present<<endl;
        if(val < k)
        {
            lo = mid+1;
        }
        else if(val > k)
        {
            hi = mid;
        }
        else
        {
            ans = mid;
            break;
        }
    }
    for(int i=0;i<100;i++)
    {
        ll val = calc(a,b,ans+i),val_=0;
        if(val > k)
            break;
        else if(val == k and present)
        {
            return ans + i;
        }
    }
    for(int i=0;i<100;i++)
    {
        ll val = calc(a,b,ans-i);
        if(val<k)
            break;
        else if(val == k and present)
        {
            return ans - i;
        }
    }

    return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    vll p(n);
    vll a,b;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        if(i%2)
            a.pb(p[i]);
        else b.pb(p[i]);
    }
    cin>>k;
    //k = k-1;
    set<ll>aa,bb;
    func(a,aa);
    cerr<<"r1"<<endl;
    func(b,bb);
    cerr<<"aa"<<endl;
    set<ll>cc;
    for(auto i = aa.begin();i!=aa.end();i++)
    {
        cerr<<*i<<" ";
        cc.insert(*i);
    }
    cerr<<endl;
    cerr<<"bb"<<endl;
    for(auto i = bb.begin();i!=bb.end();i++)
    {
        cerr<<*i<<" ";
        cc.insert(*i);
    }
    cerr<<endl;
    for(auto i = aa.begin();i!=aa.end();i++)
    {
        for(auto j = bb.begin();i!=bb.end();i++)
        {
            cc.insert(*i * *j);
        }
    }
    vll pp;
    for(auto i = cc.begin();i!=cc.end();i++)
    {
        pp.pb(*i);
    }
    cout<<pp[k-1]<<endl;
	return 0;
}

