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

vi sieve(100023,0);
vi primes;
void s()
{
        for(int i=2;i<=100000;i++)
        {
                if(!sieve[i])
                {
                        for(int j=2;j*i<=100000;j++)
                        {
                                sieve[i*j]=1;
                        }
                        primes.pb(i);
                }
        }
}

void list_factors(ll m)
{
	for(int i=0;i<primes.size();i++)
	{
		if(m%primes[i]==0)	
		{
			while(m%primes[i]==0)
			{
				m=m/primes[i];
			}
			cout<<primes[i]<<" ";
		}
	}
	if(m!=1)
	{
		cout<<m<<endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	s();
	ll m;
	cin>>m;
	list_factors(m);
	return 0;
}

