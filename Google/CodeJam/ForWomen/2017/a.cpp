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
	int t;
	ifstream fin;
	ofstream fout;
	fin.open("A-large.txt");
	fout.open("op.txt");
	
	fin>>t;
	int j=0;
	while(t--)
	{
		j++;
		//vector< vi >A(n);
		int n,s;
		fin>>n>>s;
		int A[101][101]={0};
		int x,y;
		for(int i=0;i<n;i++)
		{
			fin>>x>>y;
			A[x][y]=A[y][x]=1;
		}
		int ans=0;
		for(int i=1;i<=s;i++)
		{
			int cnt=0;
			for(int j=1;j<=s;j++)
			{
				if(A[i][j]) cnt++;
			}
			ans=max(ans,cnt);
		}
	fout<<"Case #"<<j<<": "<<ans<<endl;
	}
	
	return 0;
}

