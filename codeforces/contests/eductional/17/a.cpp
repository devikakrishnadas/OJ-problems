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
	vll A;
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			A.pb(i);
		}
		if(i!=(n/i) && n%i==0)
		{
			A.pb(n/i);
		}
	}
	sort(A.begin(),A.end());
	if((k)>(ll)A.size())
	{
		cout<<-1<<endl;
	}
	else
	cout<<A[k-1]<<endl;
	return 0;
}

