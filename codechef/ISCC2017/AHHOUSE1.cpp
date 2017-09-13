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
 
void accept(int n,int m,int a[100][100])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
}
int miPF=INT_MAX;
int miPT=INT_MAX;
 
void dfs1(int x,int y,int n,int m,int vis[100][100],int a[100][100],int val,int pt[100][100],int val2)
{
    
    if(x>=n || y>=m || x<0 || y<0)
    {
        return;
    }
    if(vis[x][y]==1)
        return;
    //cout<<x<<" "<<y<<endl;
    vis[x][y]=1;
    val+=a[x][y];
    val2+=pt[x][y];
    if(x==n-1 && y==m-1)
    {
        if(val<miPF)
        {
            miPF=val;
            miPT=val2;
        }
        else if(val==miPF) miPT=min(miPT,val2);
        vis[x][y]=0;
        return;
    }
    //vis[x][y]=1;
    //s.push(mp(x,y));
    dfs1(x+1,y,n,m,vis,a,val,pt,val2);
    dfs1(x,y+1,n,m,vis,a,val,pt,val2);
    vis[x][y]=0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        miPF=miPT=INT_MAX;
        int pf[100][100]={0},pt[100][100]={0};
        int vis[100][100]={0};
        accept(n,m,pf);
        accept(n,m,pt);
        dfs1(0,0,n,m,vis,pf,0,pt,0);
        cout<<miPF<<" "<<miPT<<endl;
    }
    return 0;
}
