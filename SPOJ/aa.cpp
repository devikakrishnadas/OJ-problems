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

ll E_GCD(ll a,ll b,ll &x,ll &y)
  {   
      if(a==0)
      {
          x=0;
          y=1;
  
          return b;
       
      }
      ll X1,Y1;
      ll gcd = E_GCD(b%a,a,X1,Y1);
      x=Y1-(b/a)*X1;
      y=X1;
  
      
      return gcd;
   
  }

 ll inv(ll n, ll mod)
  {   
      ll x,y;
      E_GCD(n,mod,x,y);
      while(x<0) x=x+mod;
      return x;
  }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll t;
    cin>>t;
    cout<<inv(t,(ll)500000002)<<endl;
	return 0;
}

