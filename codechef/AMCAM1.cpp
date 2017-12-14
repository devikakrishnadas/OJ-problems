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

int n,k;
vector<pair<int,int> >cat,mouse;
vector< int >G[220];
int isAvail[220];
bool vis[220];
bool bipMatch(int p)
{
    for(auto x:G[p])
    {
        if(!vis[x])
        {
            vis[x]=1;
            if(isAvail[x]==-1 || bipMatch(isAvail[x]))
            {
                isAvail[x]=p;
                return 1;
            }
        }
    }
    return 0;
}
int maxMatching()
{
    int cnt=0;
    for(int i=0;i<n;i++) isAvail[i]=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) vis[j]=0;
        if(bipMatch(i))
        {
            cnt++;
        }
    }
    return cnt;
}
double dist(int i,int j)
{
    double val1 = (cat[i].ff-mouse[j].ff) ;
    double val2 = (cat[i].ss-mouse[j].ss) ;
    double val= val1*val1 + val2*val2;
    val = sqrt(val);
    return val;
}
bool func(double mid)
{
    for(int i=0;i<n;i++) G[i].clear();

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist(i,j) > mid)
            {
                cnt++;
                G[i].pb(j);
            }
        }
    }
    int M = maxMatching();
    if(2*n - M >= k)
    {
        return true;
    }
    return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>k;
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
    int t=200;
    double s=0.0;
    double e=1e14;
    while(t--)
    {
        double mid = (s+e)/2.0;
        if(func(mid))
        {
            e=mid;
        }
        else
        {
            s=mid;
        }
    }
    cout<<fixed<<setprecision(15)<<e<<endl;
	return 0;
}

