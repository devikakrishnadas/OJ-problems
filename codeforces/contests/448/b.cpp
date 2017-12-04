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
    vll a(n+1,0);
    map<int,int>A;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        A[a[i]]++;
    }
    ll ans=0;
    sort(all(a));
    for(int i=1;i<=n;i++)
    {
        ll lb,ub;
        if(a[i]%x==0) 
        {
            lb=a[i]+(k-1)*x;
            ub=a[i]+k*x;
            if(k-1 < 0) continue;
        }
        else 
        {
            lb=(a[i]+k*x) - (a[i]+k*x)%2;
            ub=a[i]+(k+1)*x - (a[i]+(k+1)*x)%2 ;
        }
        ll j1=b_s(lb,a);
        ll j2=b_s(ub,a);
        if(j2==-1) j2=n+1;
        if(j1==-1) break;
        if( abs(( a[j1] - a[i] ) / x) == k )//&& abs(( a[j2] - a[i] ) / x) == k+1 )
        {
            
            ans=ans + j2 - max(j1,(ll)i) + A[max(j1,(ll)i)]-1;
        }
        
    }
    cout<<ans<<endl;
	return 0;
}

