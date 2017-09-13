#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define M 100000000
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int A[201][101][3]={0};//A[n1][n2][identifier]
int func(int n1,int n2,int k1,int k2,int o)
{
	if(o==1 && n1==1)
	{
		if(n2<=k2)
			return 1;
		return 0;
	}
	if(o==2 && n2==1)
	{
		if(n1<=k1)
			return 1;
		return 0;
	}
	if(n2==0 && o==1)
	{
		if(n1<=k1)
			return 1;
		return 0;
	}
	if(n1==0 && o==2)
	{
		if(n2<=k2)
			return 1;
		return 0;
	}
	if(n1==0 && o==1) 
		return 0;
	if(n2==0 && o==2)
		return 0;

	if(A[n1][n2][o]!=-1)
		return A[n1][n2][o];
	A[n1][n2][o]=0;
	if(o==2)
	{
		for(int i=1;i<=min(n2,k2);i++)
		{
			A[n1][n2-i][1]=func(n1,n2-i,k1,k2,1);
			A[n1][n2][2]=(A[n1][n2][2]+A[n1][n2-i][1])%M;
		}
	}
	else
	{
		for(int i=1;i<=min(n1,k1);i++)
		{
			A[n1-i][n2][2]=func(n1-i,n2,k1,k2,2);
			A[n1][n2][1]=(A[n1][n2][1]+A[n1-i][n2][2])%M;
		}
	}
	return A[n1][n2][o];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n1,n2,k1,k2;
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			A[i][j][1]=-1;
			A[i][j][2]=-1;
		}
	}
	cin>>n1>>n2>>k1>>k2;
	cout<<(func(n1,n2,k1,k2,2)+func(n1,n2,k1,k2,1))%M<<endl;
	return 0;
}

