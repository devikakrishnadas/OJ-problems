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

int mans=0;
int c[1002][1002]={0};
int e[1002][1002]={0};
int k;
int lcs(vc a,vc b, int n,int m)
{
	
	for(int i=0,d=0;i<n;i++) 
	{
		if(a[i]==b[0]) d=1;
		c[i][0]=d;
	}
	for(int j=0,d=0;j<m;j++)
	{
		if(a[0]==b[j])
		{
			d=1;
		}
		c[0][j]=d;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			c[i][j]=max(c[i-1][j],c[i][j-1]);
			if(a[i]==b[j])
			{
				e[i][j]=1+e[i-1][j-1];
			}
			else e[i][j]=0;
			if(e[i][j]>=k)
			{
				for(int p=k;p<=e[i][j];p++)
				{
					c[i][j]=max(c[i-p][j-p]+p,c[i][j]);
				}
			}
//			cout<<c[i][j]<<"-"<<e[i][j]<<" ";
		}
//		cout<<endl;
	}
	return c[n-1][m-1];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
//		int k;
		cin>>k;
		if(!k) return 0;
		string a,b;
		cin>>a>>b;
		vc A,B;
		A.pb('0');
		B.pb('1');
		for(int i=0;i<a.size();i++)
		{
			A.pb(a[i]);
		}
		for(int j=0;j<b.size();j++)
		{
			B.pb(b[j]);
		}
		cout<<lcs(A,B,A.size(),B.size())<<endl;
		
	}
	return 0;
}

