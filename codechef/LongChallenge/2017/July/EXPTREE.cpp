#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define N 1000000009
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;


long long int E_GCD(long long int a,long long int b,long long  int&x,long long int &y)
{
    if(a==0)
    {
        x=0;
        y=1;
        return b;                   
    }
    long long int X1,Y1;
    long long int gcd = E_GCD(b%a,a,X1,Y1);
    x=Y1-(b/a)*X1;
    y=X1;                                                                                                                                          return gcd;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n==1)
        {
            cout<<0<<" "<<0<<endl;
            continue;
        }
        n=n-2;
        ll P1=(((n+2)%M)*((n+1)%M))%M;
        ll P2=(((n+2)%N)*((n+1)%N))%N;
        ll Q1=2*(2*n+1);
        ll Q2=Q1;
        Q1=Q1%M;
        Q2=Q2%N;
        ll x,y;
        E_GCD(Q1,M,x,y);
        ll ans1=(P1*x)%M;
        E_GCD(Q2,N,x,y);
        ll ans2=(P2*x)%N;
        ans1=(ans1+M)%M;
        ans2=(ans2+N)%N;
        cout<<ans1<<" "<<ans2<<endl;
    }
	return 0;
}

