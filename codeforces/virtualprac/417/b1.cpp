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
	int n,m;
	cin>>n>>m;
	int A[200][200]={0};
	vector<pair<int,int> >cnt;
	for(int i=0;i<n;i++)
	{
		int s=-1,e=-1;
		for(int j=0;j<m+2;j++)
		{
			cin>>A[i][j];
			if(A[i][j])
			{
				e=j;
				if(s==-1) s=j;
			}
		}
		cnt.pb(mp(s,e));
	}
	int prev=1;// 1-->means previous exit through right;
	int ans=A[0].s
	return 0;
}

