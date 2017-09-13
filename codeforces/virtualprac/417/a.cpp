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
	int A[10][10]={0};
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>A[i][j];
		}
	}
	for(int i=0;i<4;i++)
	{
		if(A[i][3]==1)
		{
			if(A[(i+3)%4][2] || A[(i+1)%4][0] ||A[(i+2)%4][1] || A[i][1] || A[i][2] || A[i][0])
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}

