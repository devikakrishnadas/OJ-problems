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

void minTime(stack<pair<int,int> > s,int a[100][100])
{
    int t=0;
    while(!s.empty())
    {
        t+=a[s.top().ff][s.top().ss];
        s.pop();
    }
    miPT=min(miPT,t);
}
void dfs1(int x,int y,int n,int m,int vis[100][100],int a[100][100],stack<pair<int,int> > &s,int val,int pt[100][100])
{
    if(x>=n || y>=m || x<0 || y<0)
    {
        return;
    }
    if(vis[x][y]==1)
        return;
    vis[x][y]=1;
    s.push(mp(x,y));
    val+=a[x][y];
    if(x==n-1 && y==m-1)
    {
        if(val<=miPF)
        {
            if(val<miPF)
                miPT=INT_MAX;
            miPF=val;
            minTime(s,pt);
        }
        s.pop();
        return;
    }
    //vis[x][y]=1;
    //s.push(mp(x,y));
    int A,B,C,D;
    A=B=C=D=INT_MAX;
    if(x+1<n)
        A=a[x+1][y];
    if(x>0) 
        B=a[x-1][y];
    if(y>0) 
        D=a[x][y-1];
    if(y+1<m) 
        C=a[x][y+1];
    
    cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
    if(A<B && A<C && A<D) 
        dfs1(x+1,y,n,m,vis,a,s,val,pt);
    if(B<A && B<C && B<D)
        dfs1(x-1,y,n,m,vis,a,s,val,pt);
    if(C<A && C<B && C<D)
        dfs1(x,y+1,n,m,vis,a,s,val,pt);
    if(D<A && D<B && D<C)
        dfs1(x,y-1,n,m,vis,a,s,val,pt);
    s.pop();
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
        stack<pair<int,int> > s;
        dfs1(0,0,n,m,vis,pf,s,0,pt);
        cout<<miPF<<" "<<miPT<<endl;
    }
	return 0;
}

