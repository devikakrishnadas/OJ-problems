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
#define mod 1000000007
using namespace std;


/*ll phi(ll n)
{    
    ll result = n;
    for (ll p=2; p*p<=n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}*/

ll  phi(ll x)
 {
   ll ret = 1,i,Pow;
   for (i = 2; x != 1; i++) 
   {
     Pow = 1;
     if(i>sqrt(x))break;
     while (!(x%i)) 
     {
       x /= i;
       Pow *= i;
     }
     ret *= (Pow - (Pow/i));
    }
    if(x!=1)ret*=(x-1);
    return ret;
}



int main()
{
	ll n,k;
	cin>>n>>k;
	ll p=k/2 + k%2;
	while(p--)
	{
		if(n==1)
			break;
		n=phi(n);
//		n=n%mod;
	}
	cout<<n%mod<<endl;
	return 0;
}

