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

int dp[101][101][30];
int ch[101][101];
int n,m;

int dfs(int x,int y,int c)
{
    if(dp[x][y][c] != -1)
    {
        return dp[x][y][c];
    }

    for(int i=1;i<=n;i++)
    {
        if(ch[x][i] >= c and dfs(y,i,ch[x][i]) == 0)
        {
            dp[x][y][c] = 1;
        }
    }
    if(dp[x][y][c]==-1)
        dp[x][y][c]=0;
    return dp[x][y][c];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    memset(ch,-1,sizeof(ch));
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<m;i++)
    {
        int x,y;
        char z;
        cin>>x>>y>>z;
        ch[x][y] = (int) z-'a'+1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dfs(i,j,0);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dp[i][j][0])
                cout<<'A';
            else cout<<'B';
        }
        cout<<endl;
    }
	return 0;
}

