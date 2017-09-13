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

int dp[160][160]={0};

int dpFunction(int i,int j)
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
    int cnt=0;
    for(int k=1;k<=min(i,j);k++)
    {
        dp[j-k][k]=dpFunction(j-k,k);
        cnt+=dp[j-k][k];
    }
    dp[i][j]=cnt+1;
    return dp[i][j];
}

void copyArr(int a[160][160],int b[160][160],int n,int m)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            a[i][j]=b[i][j];
        }
    }
}

void fillArr(int a[160][160],int n,int m,int item)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            a[i][j]=item;
        }
    }
}
int func(vi &a)
{
    int tt[160][160]={0},bb[160][160]={0};
    vector<pair<int,int> >t,b;
    b.pb(mp(a[1],a[2]));
    //cout<<a.size()<<endl;
    for(int i=2;i<a.size()-1;i++)
    {
        t.clear();
        fillArr(tt,150,150,0);
        for(int j=0;j<b.size();j++)
        {
            //b[j].ss+=a[i];
            int mi=min(b[j].ff,b[j].ss);
            //cout<<"mi "<<mi<<endl;
            for(int k=0;k<=mi;k++)
            {
                if(tt[b[j].ss-k][k+a[i+1]]==0)
                    t.pb(mp(b[j].ss-k,k+a[i+1]));
                tt[b[j].ss-k][k+a[i+1]]+=1;
            }
        }
        b.clear();
        b=t;
        //***copyArr(bb,tt,150,150);
        //***fillArr(bb,150,150,0);
//        cout<<b.size()<<" "<<t.size()<<endl;
    }
    int ans=0;
  //  cout<<b.size()<<endl;
    for(int i=0;i<b.size();i++)
    {
        ans+=dp[t[i].ff][t[i].ss+a[a.size()-1]];
        ans=ans%M;
    //    cout<<dp[t[i].ff][t[i].ss+a[a.size()-1]]<<" dpval"<<endl;
         
    }
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    /*
    for(int i=0;i<200;i++)
    {
        for(int j=0;j<200;j++)
        {
            dp[i][j]=-1;
        }
    }
    */
    fillArr(dp,150,150,-1);
    for(int i=0;i<=150;i++)
    {
        for(int j=0;j<=150;j++)
        {
            dpFunction(i,j);
        }
    }
    /*int x,y;
    cin>>x>>y;
    cout<<dp[x][y]<<endl;
    */
    int t;
    cout<<dp[2][3]<<endl;
    cin>>t;
    while(t--)
    {
        cin>>n; 
        int cnt=0;
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
        int mm=0;
        //cout<<dp[1][4]<<" "<<dp[2][3]<<" "<<1<<endl;
        int ans=func(a)%M;
        if(ans<=0)
            ans=1;
        cout<<ans<<endl;

    }
    return 0;
}
