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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char A[10][10];
	for(int i=1;i<=4;i++)
	for(int j=1;j<=4;j++)
		cin>>A[i][j];
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			int cntw=0;
			int cntb=0;
			for(int m=i;m<=i+1;m++)
			{
				for(int n=j;n<=j+1;n++)
				{
					if(A[m][n]=='.') cntw++;
					else cntb++;
				}
			}
			if(cntw>=3 || cntb>=3)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}

