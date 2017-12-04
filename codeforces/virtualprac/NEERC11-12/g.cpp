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

long double eps= 1e-13;
using namespace std;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ll n;
    cin>>n;
    while(n--)
    {
        long long k,m;
        cin>>k>>m;
        long double den= 4.0*m - k;
        long double num= 2.0*m - k;
        if(abs(den) <= eps)
        {
            den=eps;
        }
        printf("%.20lf\n",(double)(num/den));
    }
	return 0;
}

