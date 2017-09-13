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

int lcs(string a,string b,int n,int m,int tot)
{
	int c[1002][1002]={0};
	int d=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==b[0]) 
		{
			d=1;
			e[i][0]=1;
		}
		c[i][0]=d;
		//e[i][0]=c[i][0];
	}
	for(int j=0;j<m;j++)
	{
		if(a[0]==b[j])
		{
			d=1;
			e[0][j]=1;
		}
		c[0][j]=d;
		//e[0][j]=c[0][j];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(a[i]==b[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				e[i][j]=e[i-1][j-1]+1;
			}
			else
			{	
				if(e[i-1][j]>=tot)
				{
					c[i][j]=c[i-1][j];
					e[i][j]=0;
				}
				if(e[i][j-1]>=tot )
				{
					c[i][j]=max(c[i][j],c[i][j-1]);
				}
			}
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	return c[n-1][m-1];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	while(1)
//	{
		int k;
		cin>>k;
//		if(!k)
//		{
//			return 0;
//		}
		string a,b;
		cin>>a>>b;
		cout<<lcs(a,b,a.length(),b.length(),k)<<endl;
//	}
	return 0;
}

