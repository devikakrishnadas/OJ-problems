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
	cin>>n>>m;
	vector< vi > A(n);
	int x;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>x;
			A[i].pb(x);
		}
	}
	int B[n+5][m+5]={0};
	int C[100000]={0};
	for(int i=0;i<n;i++)
	{
		C[i]=i;
	}
	int s=0,e=0;
	for(int j=0;j<m;j++)
	{
		s=0,e=0;
		for(int i=0;i<n;i++)
		{
			if(!i)
			{
				B[i][j]=1;
			}
			else
			{
				if(A[i][j]>=A[i-1][j])
				{
					B[i][j]=B[i-1][j]+1;
					e=i;
					C[s]=max(C[s],e);
					
				}
				else {B[i][j]=1;s=i;e=i;}
			}
		}
	}
//	cout<<endl<<C[2]<<endl;
	for(int i=0;i<n;i++)
	{
		if(i)
		C[i]=max(C[i],C[i-1]);
//		cout<<C[i]<<" ";
	}
//	cout<<endl;
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		if(C[x]>=y)
		{
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}
	return 0;
}

