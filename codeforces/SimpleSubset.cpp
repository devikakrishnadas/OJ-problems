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

vector<bool> sieve (2000023,0);
int x;
void s()
{
	for(int i=2;i<=2000002;i++)
	{
		if(!sieve[i])
		{
			for(int j=2;i*j<=2000002;j++)
			{
				sieve[i*j]=1;
			}
		}
	}
}

vi B(1000023,0);

int main()
{
	int n;
	cin>>n;
	vi A;
	s();
	
	vi B(1000023,0);
	int one=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x==1)
		{
			one++;
			continue;
		}
		if(!B[x])
		{
			A.pb(x);
			B[x]++;
		}	
	}
	ll ans=one;

	if(one)
	{
		bool enter=0;
		for(int i=0;i<A.size();i++)
		{
			if(!sieve[A[i]+1])
			{
				cout<<ans+1<<endl;
				cout<<A[i];
				cout<<" ";
				enter=1;
				break;
			}
		}
		if(!enter && one>1) cout<<one<<endl;
		if(one!=1 || enter)
		for(int i=0;i<one;i++)
		{
			cout<<1;
			if(i!=one-1) cout<<" ";
			else {cout<<endl;
			return 0;}
		}
	}
	
	for(int i=0;i<A.size();i++)
	{
		for(int j=i+1;j<A.size();j++)
		{
			if(!sieve[A[i]+A[j]])
			{
				cout<<2<<endl;
				cout<<A[i]<<" "<<A[j]<<endl;
				return 0;
			}
		}
	}
	for(int i=0;i<A.size();i++)
	{
		if(!sieve[A[i]])
		{
			cout<<1<<endl;
			cout<<A[i]<<endl;
			return 0;
		}
	}
	cout<<1<<endl;
	if(A.size()==0 && one ==1)
	{
		cout<<1<<endl;
	}
	else
	cout<<A[0]<<endl;
	return 0;
}
