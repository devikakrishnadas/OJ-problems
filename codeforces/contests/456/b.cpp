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
    ll tn=n;
    ll val = 1;
    while(tn)
    {
        tn = tn / 2;
        val = val*2;
    }
    val = val/2;
//    cout<<(val & n)<<endl;
    if(k >= 2)
    {
        cout<<max(val*2-1,n)<<endl;
    }
    else
        cout<<max(val,n)<<endl;
	return 0;
}

