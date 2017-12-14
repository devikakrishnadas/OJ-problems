#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

const int MAX = 500;
int cnt=0;

// isAvailable[i] == -1 if job available, otherwise stores the index of the person who took the job
bool bipartiteMatching(bool G[MAX][MAX],vi &vis, int u,int isAvailable[MAX],int n)
{
    for(int i=0;i<n;i++)
    {
        
        if(G[i][u] && !vis[i])
        {
            cnt++;
            vis[i]=1;
            if(isAvailable[i] == -1)             
            {
                isAvailable[i] = u;
                return true;
            }
            else if( bipartiteMatching(G,vis,isAvailable[i],isAvailable,n))
            {
                isAvailable[i] = u;
                return true;
            }
            vis[i]=0;
            isAvailable[i]=-1;
        }
    }
    return false;
}

int maxMatching(bool G[MAX][MAX],int n)
{
    int isAvailable[MAX];
    int ans=0;
     for(int j=0;j<n;j++)
         isAvailable[j]=-1;
    for(int i=0;i<n;i++)
    {
        vi vis(MAX,0);   
        if(bipartiteMatching(G,vis,i,isAvailable,n))
        {
            ans++;
        }
    }
    return ans;
}

double dist(pair<int,int>a,pair<int,int>b)
{   
    double x1=a.ff,x2=b.ff;
    double y1=a.ss,y2=b.ss;
    double val = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    val = sqrt(val);
    return val;
}
void fill(long double mid,bool G[MAX][MAX],vector<pair<int,int> >&cat,vector<pair<int,int> >&mouse)
{
    for(int i=0;i<cat.size();i++)
    {
        for(int j=0;j<mouse.size();j++)
        {
            if(dist(cat[i],mouse[j]) > mid)
            {
                G[i][j]=1;
            }
            else G[i][j]=0;
        }
    }
}
long double func(vector<pair<int,int> >&cat,vector<pair<int,int> >&mouse,int n, int k)
{
    long double s=0.0;
    long double e=1e14;
    bool G[MAX][MAX]={0};
    int t=200;
    while(t--)
    {
        cnt=0;
        long double mid = (s + e)*(0.5);
        int M = 0;
        fill(mid, G, cat, mouse);
        
        M= maxMatching(G,n);

//        cout<<s<<" "<<e<<" "<<mid<<" "<<M<<" "<<cnt<<endl;
        if(2*n - M >= k)
        {
            e = mid;
        }
        else
        {
            s = mid;
        }
    }
    return e;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<pair<int,int> >cat,mouse;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        cat.pb(mp(x,y));
    }
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        mouse.pb(mp(x,y));
    }
    double s=0,e=1e14,mid;
    int t=200;
    while(t--)
    {
        mid = (s + e)/2.0;
        if(func(mid))
            e = mid;
        else s=mid;
    }
    cout<<fixed<<setprecision(15)<<func(cat,mouse,n,k)<<endl;
	return 0;
}

