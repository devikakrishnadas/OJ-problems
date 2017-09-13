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


void sieve(int n,vector<bool>&A)
{
	for(int i=2;i<=n+1;i++)
	{
		if(A[i]==0)
		{
			for(int j=2;i*j<=n+1;j++)
			{
				A[i*j]=1;
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	vector<bool>A(n,0);
	sieve(n,A);
	if(n<=2)
	{
		cout<<1<<endl;
		for(int i=0;i<n;i++)
			cout<<1<<" ";
	}
	else
	{
		cout<<2<<endl;
		for(int i=2;i<=n+1;i++)
		{
			if(A[i]==0) cout<<2<<" ";
			else
				cout<<1<<" ";
		}
	}
	cout<<endl;
	return 0;
}

