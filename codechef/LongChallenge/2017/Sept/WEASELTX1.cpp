
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
 
 
vll cntElements(2000000);
vll val(2000000);
vector< vi >A(2000000);
queue<ll>Q;
vll lans(4000000,-1);
 
int main()
{
//  ios_base::sync_with_stdio(false);
//  cin.tie(0);
//  cout.tie(0);
    ll n,q;
    //cin>>n>>q;
    //sf("%lld%lld",&n,&q);
    n=100000;
    q=100000;
    //vector< vi >A(n+1);
    
    for(int i=1;i<n;i++)
    {
        ll x,y;
        //cin>>x>>y;
        //sf("%lld%lld",&x,&y);
        x=i-1;
        y=i;
        A[x].pb(y);
        A[y].pb(x);
    }
    //vll val(n);
    for(int i=0;i<n;i++)
    {
        //cin>>val[i];
        //sf("%lld",&val[i]);
        val[i]=i+1;
    }
///    queue<ll>Q;
    Q.push(0);
    vi p(n+1,0);
    ll level=1;
    p[0]=1;
    cntElements[1]^=val[0];
    while(!Q.empty())
    {
        ll a=Q.front();
        Q.pop();
        
//        cout<<a<<" ";
     //   cout<<"Parent"<<a<<endl;
        for(int i=0;i<A[a].size();i++)
        {
            //cout<<"Parent"<<a<<endl;
            if(!p[A[a][i]])
            {
       //         cout<<"child"<<A[a][i]<<endl;
                p[A[a][i]]=p[a]+1;
                cntElements[p[A[a][i]]]^=(val[A[a][i]]);
                Q.push(A[a][i]);
                level=max(level,p[a]+1);
            }
        }
    }
    ll rep=log2(level);
    rep=pow(2,rep);
    if(level%rep)
        rep=rep*2;
    vll pow2(262145,0);
    ll v=1;
    for(int i=1;i<=rep;i++)
    {
        pow2[i]=v;
        if(i==2*v)
            v=2*v;
    }
    pow2[1]=0;
    ll tt=1;
    while(q--)
    {
        ll d;
        //cin>>d;
        //sf("%lld",&d);
        d=tt;
        tt++;
        d=d%rep;
        if(d==0) d=rep;
        ll ans=0;
        if(lans[d]!=-1)
        {
 
            pf("%lld\n",lans[d]);
            continue;
        }
        //cout<<"r1"<<endl;
        ll skip=pow2[d];
        
        for(int i=2;i<=level;i++)
        {
            
            if(!((i-1)&(d-1)))
            {
 
                ans^=cntElements[i];
            }
            ttt++;
            cout<<ttt<<endl;
            if(skip)
            if(i%(2*skip)==skip)
            {
                i=i+skip;
            }
        } 
        cout<<endl;
        ans=ans^cntElements[1];
        lans[d]=ans;
        pf("%lld\n",ans);
    }
    return 0;
}
