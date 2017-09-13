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
	vector<pair<int,int> >ans;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;	
		int l=-1,r=-1;
		for(int j=0;j<m+2;j++)
		{
			A[i][j]=s[j]-'0';
			if(A[i][j])
			{
				r=j;
				if(l==-1)
				{
					l=j;
				}
			}
		}
		if(l!=-1 && r!=-1)
			ans.pb(mp(l,r));
	}
	
	return 0;
}

