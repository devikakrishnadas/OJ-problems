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


int lcs(string a,string b,int m,int n,int k)
{
	int c[1002][1002]={0};
	int aa=0;
	for(int i=0;i<n;i++) 
	{
		if(a[0]==b[i] )	
			aa=1;
		c[0][i]=aa;
	}
	aa=0;
	for(int i=0;i<m;i++) 
	{
		if(a[i]==b[0])
			aa=1;
		c[i][0]=aa;
	}
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(b[j]==a[i])
			{
				c[i][j]=c[i-1][j-1]+1;
			}
			else
			{
				if(c[i-1][j-1]<k)
					c[i][j]=0;
				else
					c[i][j]=min(c[i-1][j],c[i][j-1])+1;
			}
		}
	}
	int ans=0;
	for(int i=0;i<m;i++)
	{
		ans=max(ans,c[i][n-1]);
	}
	for(int j=0;j<n;j++)
	{
		ans=max(ans,c[m-1][j]);
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int k;
	cin>>k;
	
	string a,b;
	cin>>a>>b;
	int c[1002][1002]={0};
	cout<<lcs(a,b,a.length(),b.length(),k)<<endl;
	return 0;
}
