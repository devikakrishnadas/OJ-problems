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
			if(i>=1000 && i<10000)
			if(((i%100)/10) != 0 && ((i%1000)/100) !=0 )
			{
				int a=(i%100)/10;
				a=a%2;
				int b=(i%1000)/100;
				b=b%2;
				int c=i/1000;
				c=c%2;	
				int cnt=0;
				if(a==0) cnt++;
				if(b==0)cnt++;
				if(c==0) cnt++;
				if(cnt<=1)
                        		primes.pb(i);
			}
                }
        }
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	s();
	cout<<primes.size()<<endl;
	return 0;
}

