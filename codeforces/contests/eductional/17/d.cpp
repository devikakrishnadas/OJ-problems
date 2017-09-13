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
ll fans=0;
void dfs(int x,int y,ll ans)
{
	if(x<0 || x>3 || y<0 || y>n-1)
		return ;
	dfs(x+1,y,ans+A[x+1][y]);
	dfs(x-1,y,ans+A[x-1][y]);
}
int main()
{
	
	return 0;
}

