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

void print(int c[1002][1002],int e[1002][1002],int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<c[i][j]<<"_"<<e[i][j]<<" ";
		}
		cout<<endl;
	}
}
int lcs(string a,string b,int n,int m,int tot)
{
	int c[1002][1002]={0};
	int e[1002][1002]={0};
	int d=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==b[0]) 
		{
			e[i][0]=1;
			d=1;
		}
		c[i][0]=d;	
	}
	d=0;
	for(int j=0;j<m;j++)
	{
		if(a[0]==b[j])
		{
			e[0][j]=1;
			d=1;
		}
		c[0][j]=d;
	}
	int ans=0;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(a[i]==b[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				for(int k=j-1;k>=0;k--)
				{
					if(e[i-1][j-1]>=tot)
					{
						val=max(val,e[i-1][j-1]);
					}
				}
				if(val>=tot) ans+=val;
				e[i][j]=val+1;
			}
			else
			{
				if(c[i][j-1]>c[i-1][j])
				{
					if(e[i][j-1]>=tot)
					{
						c[i][j]=c[i][j-1];
					}
					/*else if(i-tot<0 || j-1-tot<0)
					{
						c[i][j]=c[i][j-1];
					}*/
					else if(e[i-1][j]>=tot)
					{
						c[i][j]=c[i-1][j];
					}
					/*else if(i-1-tot<0 || j-tot<0)
					{
						c[i][j]=c[i-1][j];
					}*/
				}
				else
				{
					if(e[i-1][j]>=tot)
                                        {
                                                c[i][j]=c[i-1][j];
                                        }
                                        /*else if(i-1-tot<0 || j-tot<0)
                                        {
                                                c[i][j]=c[i-1][j];
                                        }*/
					else if(e[i][j-1]>=tot)
                                        {
                                                c[i][j]=c[i][j-1];
                                        }
                                        /*else if(i-tot<0 || j-1-tot<0)
                                        {
                                                c[i][j]=c[i][j-1];
                                        }*/
				}
			}
//			cout<<c[i][j]<<" ";
		}
//		cout<<endl;
	}	
	print(c,e,n,m);
	return c[n-1][m-1];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
		int k;
		cin>>k;
		if(!k)
		{
			return 0;
		}
		string a,b;
		cin>>a>>b;
		cout<<lcs(a,b,a.length(),b.length(),k)<<endl;
	}
	return 0;
}

