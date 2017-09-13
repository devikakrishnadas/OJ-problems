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

bool A[1000000001]={0};

bool is_prime(int a)
{
	for(int i=2;i<=sqrt(a);i++)
	{
		if(a%i==0) return 1;
	}
	return 0;
}
int main()
{
	int n,m;
	cin>>n>>m;
	if(n%2==0)
		n=n+1;
	if(m%2==0)
		m=m-1;
	vi primes;
	for(int i=n;i<=m;i+=2)
	{
		if(!is_prime(i))
		{
			primes.pb(i);
		}
	}
	int ans=0;
	for(int i=1;i<primes.size();i++)
	{
		if(primes[i]-primes[i-1]==2)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}

