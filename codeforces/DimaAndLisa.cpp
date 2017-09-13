#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

vi pr(10000007,1);
vi p;

void sieve()
{
	for(int i=2;i<=10000000;i++)
	{
		if(pr[i])
		{
			for(int j=2;i*j<=10000000;j++)
			{
				pr[i*j]=0;
			}
			p.pb(i);	
		}
	}
}

bool isPrime(int a)
{
	for(int i=0;p[i]*p[i]<=a;i++)
	{
		if(a%p[i]==0)
			return 0;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	sieve();
	if(n<=10000000)
	{
		if(pr[n])
		{
			cout<<1<<endl;
			cout<<n<<endl;
			return 0;
		}
	}
	else
	{
		if(isPrime(n))
		{
			cout<<1<<endl;
			cout<<n<<endl;
			return 0;
		}
	}
	
	for(int i=0;i<=min((int)p.size()-1,n);i++)
	{
		int n1=n-p[i];
		if(n1<=1) continue;
		if(n1<=1000000)
		{
			if(pr[n1])
			{
				cout<<2<<endl;
				cout<<p[i]<<" "<<n1<<endl;
				return 0;
			}
		}
		else
		{
			if(isPrime(n1))
			{
				cout<<2<<endl;
				cout<<n1<<" "<<p[i]<<endl;
				return 0;
			}
		}
		for(int j=0;j<=min((int)p.size()-1,n1);j++)
		{
			int n2=n1-p[j];
			if(n2<=1) continue;
			if(n2<=1000000)
			{
				if(pr[n2])
				{
					cout<<3<<endl;
					cout<<p[i]<<" "<<p[j]<<" "<<n2<<endl;
					return 0;
				}
			}
			else
			{
				//cout<<"r1"<<" "<<n2<<endl;
				if(isPrime(n2))
				{
					cout<<3<<endl;
					cout<<p[i]<<" "<<p[j]<<" "<<n2<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

