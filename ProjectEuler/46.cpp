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
		}
	}
}
int main()
{
	s();
//	cout<<"abc"<<endl;
	for(int i=9;i<=100000;i+=2)
	{
		if(!sieve[i]) continue;
		bool enter=0;
		for(int j=i-1;j>=1;j--)
		{
			if(sieve[j]) continue;
			if((i-j)%2) continue;
			int t=(i-j)/2;
			int s=sqrt(t);
			if(s*s==t) { enter=1; break;}
		}
		if(!enter) cout<<i<<endl;
	}
	return 0;
}

