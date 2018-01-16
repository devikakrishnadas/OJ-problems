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
    ll a,b;
    cin>>a>>b;
    ll x,y,z;
    cin>>x>>y>>z;
    ll yellow = 2*x + y;
    ll blue = 3*z + y;
    cout<<max((ll)0,yellow-a) + max((ll)0,blue-b)<<endl;
	return 0;
}

