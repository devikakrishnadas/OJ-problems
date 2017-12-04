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

int main()
{
    freopen("munich.in","r",stdin);
    freopen("munich.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll n,k,m;
    ll p1,p2,p3,q1,q2,q3;
    cin>>m>>n>>k;
    cin>>p1>>p2>>p3>>q1>>q2>>q3;

    q1=min(q1,k*p1);
    q2=min(min(q2,k*p2),q1);
    q3=min(q3,k*p3);
    ll ans=INT_MAX;
    for(ll i=0;i<=m;i++)
    {
        for(ll j=0;j<=n;j++)
        {
            ll sum=i*q1 + j*q2;
            sum+=((((m-i)*2 + (n-j) + 9)/10)*q3);
            ans=min(ans,sum);
        }
    }
    cout<<ans<<endl;
	return 0;
}

