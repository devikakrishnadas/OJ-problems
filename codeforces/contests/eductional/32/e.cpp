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
void findSubset(vll &first, ll bitmask, vll &half1,ll m)
{
    for(int i=0;i<=bitmask;i++)
    {
        ll tt=i;
        ll ind=0;
        ll sum=0;
        while(tt)
        {
            if(tt%2)
            {
                sum+=half1[ind];
                sum=sum%m;
            }
            ind++;
            tt=tt/2;
        }
        sum=sum%m;
        first.pb(sum);
    }
}
ll b_s(vll &sec,ll n,ll key)
{
    ll s=0;
    ll e=n-1;
    ll ans=0;
    while(s<=e)
    {
        ll mid=(s+e)/2;
        if(sec[mid]<key)
        {
            ans=sec[mid];
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll n,m;
    cin>>n>>m;
    vll a(n,0),half1,half2;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i<=(n/2)) half1.pb(a[i]);
        else half2.pb(a[i]);
    }
    ll bitmask=1<<(half1.size());
    vll first,sec;
    findSubset(first,bitmask,half1,m);
    bitmask=1<<(half2.size());
    findSubset(sec,bitmask,half2,m);
    sort(all(sec));
    ll ans=0;
    for(int i=0;i<first.size();i++)
    {
        ll key=m-1-first[i];
        ans=max(ans,(b_s(sec,sec.size(),key)+first[i])%m);
        key=2*m-1-first[i]
        ans=max(ans,(b_s(sec,sec.size(),key)+first[i])%m)
    }
    cout<<ans<<endl;
	return 0;
}

