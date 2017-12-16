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

map<ll,ll>val;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll n;
	cin>>n;
    vll a(n);
    vll s,ns;
    vll sqs;
    for(ll i=0;i*i<=10000000000;i++)
    {
        val[i*i]=1;
        sqs.pb(i*i);
    }

    ll z=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0) z++;

        if(val.find(a[i])!=val.end())
        {
            s.pb(a[i]);
        }
        else
            ns.pb(a[i]);
    }
    ll cnt = abs(n/2 - s.size());
    ll nz = s.size()-z;
//    cerr<<s.size()<<" "<<ns.size()<<endl;
    // if squares are greater in number
    // all numbers except 0 can be converted to a non square with just one operation
    // if it is 0, we need 2 operations to make it non square
    // so if we have cnt number of non zeroes, we can convert them to squares and cost = cnt
    // else take how much ever non zeroes we have, and substitute rest (cnt - nonzeroes) with with zeroes
    if(s.size() > ns.size())
    {
        cnt = (n/2) - ns.size();
        if(nz >= cnt)
        {
            cout<<cnt<<endl;
            return 0;
        }
        else
        {
            ll ans = nz + abs(cnt - nz)*2;
            cout<<ans<<endl;
            return 0;
        }
    }
    // if ns > s, then take the cost for converting the ns to the square greater than it, and less than it, and the min of both
    // and take the first cnt minimum values.
    else if(ns.size() > s.size())
    {
        vll ans;
        for(int i=0;i<ns.size();i++)
        {
            ll u = *lower_bound(all(sqs),ns[i]);
            ll l;
            if(u==0)
            {
                l=0;
            }
            else l = *(lower_bound(all(sqs),ns[i])-1);
            ans.pb(min(abs(ns[i]-l),abs(ns[i]-u)));
//            cerr<<ns[i]<<" "<<l<<" "<<u<<endl;
        }
        sort(all(ans));
        ll fans=0;
        for(int i=0;i<cnt;i++)
        {
            fans+=ans[i];
        }
        cout<<fans<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    return 0;
}

