#include<bits/stdc++.h>
#define ll long long
#define vi vector<ll>
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
 
ll dp[200][200]={0};
 
ll dpFunction(ll i,ll j)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==0 && j==0)
    {
        dp[i][j]=0;
        return dp[i][j];    
    }
    if(i==0 || j==0)
    {
        dp[i][j]=1;
        return dp[i][j];
    }
    ll cnt=0;
    for(ll k=1;k<=min(i,j);k++)
    {
        dp[j-k][k]=dpFunction(j-k,k);
        cnt+=dp[j-k][k];
    }
    dp[i][j]=cnt+1;
    return dp[i][j];
}
 
 
void fillArr(ll tt[200][200],ll n,ll m,ll item)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            tt[i][j]=item;
        }
    }
}
void copyArr(ll bb[200][200],ll tt[200][200],ll n,ll m)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            bb[i][j]=tt[i][j];
        }
    }
}
ll func(vi &a)
{
    vector<pair<ll,ll> >b,t;
    b.pb(mp(a[1],a[2]));
    //cout<<a.size()<<endl;
    ll tt[200][200]={0};
    ll bb[200][200]={0};
    bb[a[1]][a[2]]=1;
    for(int i=2;i<a.size()-1;i++)
    {
        t.clear();
        fillArr(tt,150,150,0);
        for(int j=0;j<b.size();j++)
        {
            //b[j].ss+=a[i];
            ll mi=min(b[j].ff,b[j].ss);
            //cout<<"mi "<<mi<<endl;
            for(int k=0;k<=mi;k++)
            {
                if(tt[b[j].ss-k][a[i+1]+k]==0)
                    t.pb(mp(b[j].ss-k,k+a[i+1]));
                tt[b[j].ss-k][k+a[i+1]]+=bb[b[j].ff][b[j].ss];
                tt[b[j].ss-k][k+a[i+1]]=tt[b[j].ss-k][k+a[i+1]]%M;
            }
        }
        b.clear();
        fillArr(bb,150,150,0);
        b=t;
        copyArr(bb,tt,150,150);
    //    cout<<b.size()<<" "<<t.size()<<endl;
    }
    ll ans=0;
  //  cout<<b.size()<<endl;
    for(int i=0;i<b.size();i++)
    {
        ans+=((dp[b[i].ff][b[i].ss])*bb[b[i].ff][b[i].ss]);
        ans=ans%M;
    //    cout<<b[i].ff<<" "<<b[i].ss<<" val"<<endl;
      //  cout<<bb[b[i].ff][b[i].ss]<<" bbval"<<endl;
         
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    for(int i=0;i<200;i++)
    {
        for(int j=0;j<200;j++)
        {
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<200;i++)
    {
        for(int j=0;j<200;j++)
        {
            dpFunction(i,j);
        }
    }
    /*int x,y;
    cin>>x>>y;
    cout<<dp[x][y]<<endl;
    */
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n; 
        ll cnt=0;
        vi a(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }   
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        else if(n==2)
        {
            cout<<dp[a[1]][a[2]]<<endl;
            continue;
        }
        ll mm=0;
        //cout<<dp[1][4]<<" "<<dp[2][3]<<" "<<1<<endl;
        ll ans=func(a)%M;
        if(ans<=0)
            ans=1;
        cout<<ans%M<<endl;
 
    }
    return 0;
}
