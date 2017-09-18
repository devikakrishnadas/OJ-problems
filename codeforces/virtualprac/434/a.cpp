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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll n,k;
    cin>>n>>k;
    ll n2=n;
    int cnt2=0,cnt5=0;
    while(n%2==0)
    {
        n=n/2;
        cnt2++;
    }
    while(n%5==0)
    {
        n=n/5;
        cnt5++;
    }
    while(cnt2<k)
    {
        n2=n2*2;
        cnt2++;
    }
    while(cnt5<k)
    {
        n2=n2*5;
        cnt5++;
    }
    cout<<n2<<endl;
	return 0;
}

