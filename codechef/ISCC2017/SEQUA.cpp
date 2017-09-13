#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;


long long int ModE(ll A,ll M,ll P)
{
    long long int res = 1;     
  
    while (P > 0)
    {
       
        if (P & 1)
            res = (res*A)%M;
  
        
        P = P>>1; 
        A = (A*A)%M ;  
    }
    return res;
    
}


long long int _ModE(ll A,ll M,ll P)
{
    if(P==0) return 1;
    if(P==1) return A;
    ll ans=1;
    if(P%2)
    {
        ans= _ModE(A,M,P/2)*(1 + ModE(A,M,P/2)) + ModE(A,M,P);
    }
    else
    {
        ans=_ModE(A,M,P/2)*(1 + ModE(A,M,P/2)) ;
    }
    ans=ans%M;
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        
        ll n;
        ll m;
        ll ans=1;
        cin>>n>>m;
        for(ll i=1;i<=min(n,m-1);i++)
        {
            ll cnt=(n/m) + (n%m >=i ? 1 : 0);
            ll val1= ModE(i,m,i) ;
            if(cnt==1)
            {
                ans=ans+val1;
                ans=ans%m;
                continue;
            }
            ll val2=_ModE(ModE(i,m,m),m,cnt-1) ;
            val1%=m;
            val2%=m;
            ll val=val1*(1+val2);
            val=val%m;
            //cout<<i<<" "<<val1<<" "<<val2<<" ";
            val=val%m;
            ans=ans+val;
            ans=ans%m;
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
	return 0;
}

