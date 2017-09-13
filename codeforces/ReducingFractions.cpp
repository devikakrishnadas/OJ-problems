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
	ll n,m;
	cin>>n>>m;
	vll num(n),den(m);
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	for(int i=0;i<m;i++)
		cin>>den[i];
	map<ll,ll>A,B;
	for(int i=0;i<n;i++)
	{
		ll k=num[i];
		for(int j=2;j<=sqrt(num[i]);j++)
		{
			while(k%j==0)
			{
				A[j]++;
				k/=j;
			}
		}
		if(k!=1)
			A[k]++;
	}
	for(int i=0;i<m;i++)
	{
		ll k=den[i];
		for(int j=2;j<=sqrt(den[i]);j++)
		{
			while(k%j==0)
			{
				k=k/j;
				B[j]++;	
			}
		}
		if(k!=1) B[k]++;
	}
	vll ansn,ansd;
	ansn.pb(1);
	ansd.pb(1);
	for(int i=2;i<=sqrt(10000000);i++)
	{
		ll t=min(A[i],B[i]);
		A[i]-=t;
		B[i]-=t;
		ll jk=1;
		while(jk)
		{
			int pp=10;
			ansn.pb(pow(i,pp));
			A[i]-=pp;
		}
		if(A[i]) ansn.pb(pow(i,A[i]));
		
	
		
		while(B[i]>10)
		{
			int pp=10;
			ansd.pb(pow(i,B[i]));
			B[i]-=10;
		}
		if(B[i]) ansd.pb(pow(i,B[i]));
		
	}
	cout<<ansn.size()<<" "<<ansd.size()<<endl;
	for(int i=0;i<ansn.size();i++)
	{
		cout<<ansn[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<ansd.size();i++)
	{
		cout<<ansd[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}

