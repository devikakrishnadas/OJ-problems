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
#define MOD 10004
using namespace std;

int ans=0;
bool A[MOD]={0};
void sieve()
{

	for(int i=2;i<MOD-3;i++)
	{
		if(!A[i])
		for(int j=2;i*j<MOD-3;j++)
		{
			A[i*j]=1;
		}
	}
}
int main()
{
	int t;
	cin>>t;
	cout<<"def"<<endl;
	sieve();
	int x;
	while(t--)
	{
		int n;
		cin>>n;
		vi B;
		int C[MOD]={0};
		int maxe=0;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			int maxe=max(maxe,x);
			B.pb(x);
			if(A[x]==0)
				A[x]=1;
			C[x]++;
		}	
		cout<<"abc"<<endl;
		int D[MOD];
		vi E;
		for(int i=0;i<=maxe;i++) D[MOD]=1;
		cout<<'g'<<endl;
		for(int i=2;i<=maxe;i++)
		{
			if(!A[i]) {E.pb(i);D[i]=0;}
		}
		cout<<'h'<<endl;
		for(int i=0;i<n;i++)
			E.pb(B[i]);
		int ans=0;
		for(int i=0;i<E.size();i++)
		{
			int c=E[i]+1;
			for(int j=2;B[i]*j<=maxe;j++)
			{
				if(C[B[i]*j])
				{
					D[B[i]*j]=max(c,D[B[i]*j]);
					c=D[B[i]*j]+1;
					ans=max(ans,c);
				}
				
			}
			C[B[i]]--;
		}
	
		cout<<ans<<endl;
	}
	
	return 0;
}

