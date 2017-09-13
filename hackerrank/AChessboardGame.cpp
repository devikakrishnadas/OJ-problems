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

int ans=0;
void dfs(int x,int y,int l)
{
	if(x<1 || y<1 || x>15 || y>15) return;
	l++;
	ans=max(ans,l);
	dfs(x-2,y+1,l);
	dfs(x-2,y-1,l);
	dfs(x+1,y-2,l);
	dfs(x-1,y-2,l);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		ans=0;
		dfs(x,y,0);
		if(ans%2) cout<<1<<endl;
		else cout<<2<<endl;
	}
	return 0;
}

