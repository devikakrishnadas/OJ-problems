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
ll dp[20][262145]={0}; 
int main()
{
//  ios_base::sync_with_stdio(false);
//  cin.tie(0);
//  cout.tie(0);
    ll n,q;
    //cin>>n>>q;
    sf("%lld%lld",&n,&q);
    vector< vi >A(n+1);
    
    for(int i=1;i<n;i++)
    {
        ll x,y;
        //cin>>x>>y;
        sf("%lld%lld",&x,&y);
        A[x].pb(y);
        A[y].pb(x);
    }
    vll val(n);
    for(int i=0;i<n;i++)
    {
        //cin>>val[i];
        sf("%lld",&val[i]);
    }
    queue<ll>Q;
    Q.push(0);
    Q.push(-1);
    vi p(n+1,0);
    ll level=1;
    vll cntElements(n+1);
//    cout<<"ELEMENTS"<<endl;
    while(!Q.empty())
    {
        ll a=Q.front();
        Q.pop();
        if(a==-1)
        {
            level++;
//            cout<<endl;
            if(Q.size()!=0)
                Q.push(-1);
            continue;
        }
        p[a]=1;
//        cout<<a<<" ";
        cntElements[level]^=val[a];
        for(int i=0;i<A[a].size();i++)
        {
            if(!p[A[a][i]])
            {
                Q.push(A[a][i]);
            }
        }
    }
    cout<<"R1"<<endl; 
    ll rep=log2(level);
    rep=pow(2,rep+1);
    vll lans(rep+1,-1);
    vll pow2(rep+1);
    ll vali=1;
    for(int i=0;i<=rep;i++)
    {
        pow2[i]=vali;
        vali=vali*2; 
    }
    cout<<"R2"<<endl;
    //ll dp[200002][20]={0};
    for(int i=1;i<level;i++)
    {
        dp[0][i]=cntElements[i];
    }
    cout<<"R3"<<endl;
    for(int i=1;i<=18;i++)
    {
        //cout<<"i"<<i<<endl;
        for(int j=1;j<=rep;j++)
        {   
            cout<<"i"<<i<<"j"<<j<<endl;
            if(j&pow2[i-1])
                dp[i][j]=dp[i-1][j^pow2[i-1]];
            else
                dp[i][j]=dp[i-1][j]^dp[i-1][j^pow2[i-1]];
        }
    }
//    cout<<"LEVEL"<<level<<endl;
//    cout<<"REP"<<rep<<endl;
    cout<<dp[18][0]<<" "<<dp[18][1]<<" "<<dp[18][3]<<endl;
    /*while(q--)
    {
        ll d;
        //cin>>d;
        sf("%lld",&d);
        cout<<dp[18][(d-1)&&(level-1]<<endl;
        
    }*/
    return 0;
}
