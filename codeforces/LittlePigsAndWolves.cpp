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
	char A[100][100];
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(A[i][j]=='W')
			{
				if(A[i-1][j]=='P' && i)
				{	
					ans++;
				}
				else if(A[i+1][j]=='P' && i<n-1)
				{
					ans++;
				}
				else if(A[i][j-1]=='P' && j)
				{
					ans++;
				}
				else if(A[i][j+1]=='P' && j<m-1)
				{
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

