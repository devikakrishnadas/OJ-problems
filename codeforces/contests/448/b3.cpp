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
#define MAX 1
#define MIN 0
using namespace std;

int b_s(bool val,ll x,ll k,vi &a,int ind)
{
    int s=0;
    int e=a.size()-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        int midv=a[mid]/x-(a[ind]-1)/x;
        if(midv>k)
        {
            e=mid-1;
        }
        else if(midv<k)
        {
            s=mid+1;
        }
        else
        {
            if(a[mid] >= a[ind])
                ans=mid;
            if(val)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
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
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(all(a));
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        int j1=b_s(MAX,x,k,a,i);
        if(j1==-1) break;
        int j2=b_s(MIN,x,k,a,i);
        if(j2==-1) j2=j1;
//        cout<<j1<<" "<<j2<<endl;
        ans+=(j1-j2+1);
    }
    cout<<ans<<endl;
	return 0;
}

