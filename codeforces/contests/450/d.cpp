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

long long int ModE(long long int A,long long int P)
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

map<ll,ll>fval;
ll f(ll a)
{
    if(fval.find(a)!=fval.end())
        return fval[a];
    ll val=ModE(2,a-1)-1;
//    cout<<sqrt(a)<<endl;
    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
        {
            val=val - f(a/i);
            if(a/i != i)
                val = val - f(i);
            val = (val + 2*M)%M;
        }
    }
    val = (val+M)%M;
    fval[a]=val;
    return val;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll x,y;
    cin>>x>>y;
    if(y%x)
    {
        cout<<0<<endl;
    }
    else if(y==x)
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<f(y/x)<<endl;
    }
	return 0;
}

