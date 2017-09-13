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

int main()
{
	s();
	vll A;
	ll cnt=0;
	for(ll i=10;i<=10000000000;i++)
	{
		ll a=i;
		ll cntr=0;
		if(i<100000)
		if(sieve[i]==0)
		{
			cnt=0;
			continue;
		}
		for(int j=0;primes[j]<=sqrt(i);j++)
		{
			if(a%primes[j]==0)
			{	
				while(a%primes[j]==0)
				{
					a=a/primes[j];
				}
				cntr++;	
			}
		}
		
		if(a!=1)
		{
			cntr++;
		}
		
		if(cntr==4)
		{
			cout<<i<<endl;
			cnt++;
		}
		else if(cntr!=4)
		{
			cnt=0;
		}
		if(cnt>=4)
		{
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
