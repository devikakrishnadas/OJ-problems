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
	int n,m;
	char A[100][100];
	int r[100]={0};
	int c[100]={0};
	int B[100][100]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>A[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(A[i][j]=='S')	
			{
				r[i]++;
				c[j]++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(!r[i])
		{
			for(int j=0;j<m;j++)
			{
				B[i][j]=1;
			}
		}
	}
	for(int j=0;j<m;j++)
	{
		if(!c[j])
		{
			for(int i=0;i<n;i++)
			{
				B[i][j]=1;
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			ans+=B[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}

