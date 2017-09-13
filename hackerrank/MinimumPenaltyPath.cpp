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
int ans=0,n,m,a,b;
int A[1003][1003]={0};
void dfs(int a,int mcv)
{
	
}
int main()
{
	int n,m;
	cin>>n>>m;
	
	int x,y;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>z;
		if(A[x][y])
		{
			A[x][y]=min(A[x][y],z);
			A[x][y]=min(Ax][y],z);	
		}
		A[x][y]=z;
		A[y][x]=z	
	}
	return 0;
}

