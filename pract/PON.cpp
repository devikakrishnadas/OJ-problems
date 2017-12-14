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

//vector<bool> prime(1000000001,1);
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
    return res%M;
    
}
int pTest(ll n)
{
    ll cnt=0;
//    cout<<"for "<<n<<endl;
    for(int i=1;i<=min((ll)100000,n-1);i++)
    {
        ll tt=ModE(i,n,n-1);
        if(tt%n==1)
        {
            cnt++;
        }
        else return 0;
        if(cnt==100000) return 1;
    }
    if(cnt==n-1) return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        
        if(pTest(n) && n>1)
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
