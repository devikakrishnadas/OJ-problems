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

string s;
const int tot = 300023;
vector<vi>G(tot);
int a[tot][30];
vi indegree(tot);
vi vis(tot,0);
vi vis2(tot,0);
bool cycle=0;

void dfs(int u)
{
    if(vis2[u])
    {
        cycle=1;
        return;
    }
    if(vis[u])
    {
        return;
    }
    vis[u]=1;
    vis2[u]=1;
    for(int v:G[u])
    {
        dfs(v);
    }
    vis2[u]=0;
}

void copy(int aa[30],int bb[30])
{
    REP(i,30)
    {
        aa[i]+=bb[i];
    }
}
void print(int aa[30])
{
    REP(i,30)
    {
        cerr<<aa[i]<<" ";
    }
    cerr<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,m;
    cin>>n>>m;
    cin>>s;

    REP(i,m)
    {
        int x,y;
        cin>>x>>y;
        G[x].pb(y);
        indegree[y]++;
    }

    FOR(i,1,n+1)
    {
        if(!vis[i] and indegree[i]==0)
        {
            dfs(i);
        }
    }
    if(cycle)
    {
        cout<<-1<<endl;
        return 0;
    }
    queue<int>q;
    FOR(i,1,n+1)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            a[i][s[i-1]-'a']++;
        }
    }
    int ma = 0;
    vi vvis(n+1,0);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        

        cerr<<"t : "<<t<<endl;
        print(a[t]);
        ma = max(*max_element(a[t],a[t]+30),ma);
        for(int x:G[t])
        {
            
            //copy(a[x],a[t]);
            REP(i,30)
            {
                if(vvis[x])
                    a[x][i]=0;
                a[x][i]+=a[t][i];
            }
            cerr<<"done a["<<x<<"] = a["<<t<<"]"<<endl;
            cerr<<"a["<<x<<"] = "<<endl;
            REP(i,30)
            {
                cerr<<a[x][i]<<" ";
            }
            cerr<<endl;
            cerr<<"a["<<t<<"] = "<<endl;
            REP(i,30)
            {
                cerr<<a[t][i]<<" ";
            }
            cerr<<endl;
            a[x][s[x-1]-'a']++;
            indegree[x]--;
            if(indegree[x]==0 )
                q.push(x);
        }

        vvis[t]=1;
    }
    cout<<ma<<endl;
	return 0;
}

