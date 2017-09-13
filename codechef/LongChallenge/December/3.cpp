#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end
#define MOD 18446744073709551557
using namespace std;

long long int ModE(long long int A,long long int M,long long int P)
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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		if(n==0)
			cout<<"INFINITY"<<endl;
		else
		{
			ll ans= n-(n/2) + 1;
			for(ll i=3;i<=n;i++)
			{	
				ll x=ModE(i,MOD,floor((double)log(n)/log(i)));
				cout<<x<<endl;
				if(x<=n && n<2*x)
					ans++;
				else break;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

