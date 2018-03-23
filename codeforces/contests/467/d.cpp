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
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)

using namespace std;

vector<vector<int> >a(200023);
vi vis(200023,0);
stack<int>temp;
vi ans;
bool canDraw = 0;
bool canWin = 0;
void copy(stack<int>temp)
{
    while(!temp.empty())
    {
        ans.pb(temp.top());
        temp.pop();
    }
}
void dfs(int s,int d)
{
    if(canWin)
        return;
    vis[s]=1;
    temp.push(s);
    for(int x : a[s])
    {
        if(!vis[x])
            dfs(x,d+1);
        else
        {
            canDraw = 1;
        }
    }
    if(a[s].size()==0 && !canWin && !(d%2))
    {
        canWin = 1;
        copy(temp);

    }
    vis[s]=0;
    temp.pop();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,m;
    cin>>n>>m;
    FOR(i,1,n+1)
    {
        int x;
        cin>>x;
        REP(j,x)
        {
            int y;
            cin>>y;
            a[i].pb(y);
        }
    }
    int s;
    cin>>s;
    dfs(s,1);
    if(canWin)
    {
        cout<<"Win"<<endl;
        reverse(all(ans));
        for(int x : ans)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    else if(canDraw)
    {
        cout<<"Draw"<<endl;
    }
    else
    {
        cout<<"Lose"<<endl;
    }
	return 0;
}

