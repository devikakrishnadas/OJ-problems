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

int main()
{
	ll n,l,r;
	cin>>n>>l>>r;
	ll tn=n;
	ll cnt=0;
	vi bal;
	while(tn>=4)
	{
		cnt++;
		bal.pb(cnt%2);
		tn=tn/2;
	}
	cnt--;
	reverse(bal.begin(),bal.end());
	
	return 0;
}

