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
    ll n;
    cin>>n;
    ll d = (n/10) *10;
    ll u = ((n/10) + 1)*10;
    if(n - d < u - n)
    {
        cout<<d<<endl;
    }
    else  cout<<u<<endl;
	return 0;
}
