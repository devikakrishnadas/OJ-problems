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
ll b_s(ll key,vll &a)
 {
     ll s=0;
     ll e=a.size()-1;
     ll ans=-1;
//     cout<<s<<" "<<e<<endl;
     while(s<=e)
     {
         ll mid=(s+e)/2;
         if(a[mid]>=key)
         {
             ans=mid;
             e=mid-1;
         }
         else
         {
             s=mid+1;
         }
     }
     return ans;
 }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll n,x,k;
    cin>>n>>x>>k;
    vll a(n);
    map<ll,ll>first,last;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(all(a));
    int j=0;
    int cnt=-1;
    int fans=0;
    bool enter=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int val=a[j]/x - a[i]/x;
        if(a[i]%x==0) val++;
        cout<<cnt<<" "<<val<<endl;
        if(val==k && cnt!=-1)
        {
            fans+=ans;
            continue;
        }
        cnt=val;
        enter=1;
        ans=0;
        while(j<n && cnt<=k)
        {
            cnt=a[j]/x - a[i]/x;
            if(a[i]%x==0) cnt++;

            if(cnt>k) break;
            if(cnt==k)
            {
                ans++;
                cout<<a[j]<<" - "<<a[i]<<" "<<cnt<<" "<<k<<endl;
            }
            j++;
        }
        if(j<n)
        {
            cnt=a[j-1]-a[i]/x;
            if(a[i]%x==0)
                cnt++;
        }
        fans+=ans;
    }
    cout<<fans<<endl;
	return 0;
}

