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
	ll n;
	cin>>n;
	int  h=0;
//	cout<<n<<endl;
	while(n>1)
	{
		n=n+n%2;
		n=n/2;
		h++;
	}
	cout<<h<<endl;
	return 0;
}

