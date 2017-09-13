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

vi grundy(pow(2,17),-1);
int func(vector <vi > &A,int x,int y)
{
	int k=0;
	int val=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			val=val+A[i][j]*pow(2,k);
			k++;
		}
	}
	vi mex;
	int n=log2(val);
	if(pow(2,n)==val)
	{
		grundy[val]=1;
		return grundy[val];
	}
	if(grundy[val]!=-1)
		return grundy[val];

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(A[i][j])
			{
				A[i][j]=0;
				int ttt=0;
				if(i && A[i-1][j] )
					ttt=1;
				if(i<3 && A[i+1][j]) ttt=1;
				if(j && A[i][j-1]) ttt=1;
				if(j<3 && A[i][j+1]) ttt=1;
				mex.pb(func(A,i,j));
				A[i][j]=1;
			}
		}
	}
	int temp=0;
	sort(mex.begin(),mex.end());
	int m=1;
	for(int i=0;i<mex.size();i++) 
	{
		if(mex[i]==m) m++;
	}
	grundy[val]=m;
	return grundy[val];
}
int main()
{
	vector< vi >A(4);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			A[i].pb(1);
		}
	}
	func(A,0,0);
	for(int i=0;i<10;i++)
		cout<<grundy[i]<<" ";
	cout<<endl;
	return 0;
}

