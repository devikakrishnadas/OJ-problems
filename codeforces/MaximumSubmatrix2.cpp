#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int A[5001][5001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,x;
	char z;
	cin>>n>>m;
	
	//int A[5001][5001]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>z;
			x=z-'0';
			A[i][j]=x;
		}
	}
	for(int i=0;i<n;i++)
	{
		int t=0;
		for(int j=m-1;j>=0;j--)
		{
			if(A[i][j]==1)
			{
				t++;
				A[i][j]=t;
			
			}
			else
			{
				t=0;
			}	
		}
	}
/*
	for(int i=0;i<n;i++)
        {
                for(int j=0;j<m;j++)
                {
                        cout<<A[i][j]<<" ";
                }
                cout<<endl;
        }
	
	cout<<"r3"<<endl;
*/	for(int i=0;i<m;i++)
	{
		int B[5001]={0};
		for(int j=0;j<n;j++)
		{
			B[A[j][i]]++;
/*			cout<<A[j][i]<<" "<<B[A[j][i]]<<endl;
*/		}
/*		cout<<endl;
*/		int k=0;
/*		cout<<"B****************"<<endl;
*/		vi temp;
		for(int t=0;t<=max(m,n);t++)
		{
			while(B[t]--)
			{
				temp.pb(t);
			}
		}
		for(int l=0;l<temp.size();l++)
		{
			
			A[l][i]=temp[l];
/*			cout<<A[l][i]<<" ";
*/		}
/*		cout<<endl;
		cout<<endl;
*/	}
/*	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
*/	int ans=0;
/*	cout<<"r5"<<endl;
*/	for(int i=n-1,k=1;i>=0;i--,k++)
	{
		for(int j=0;j<m;j++)
		{
			ans=max(ans,A[i][j]*k);
		}
	}
	cout<<ans<<endl;
	return 0;
}

