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

ll dp[1000023]={0};

int main()
{
    freopen("express.in","r",stdin);
freopen("express.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    ll n,k;
    cin>>n>>k;
    if(n<4)
    {
        cout<<0<<endl;
        return 0;
    }
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<=n;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2])%k;
    }
    ll ans=((dp[n]-dp[n-4]+k)%k - (n+1)%k+ k)%k;
    cout<< ans<<endl;    
	return 0;
}

