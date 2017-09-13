
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
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
    ll n,q;
    //cin>>n>>q;
    //sf("%lld%lld",&n,&q);
    //vector< vi >A(n+1);
    n=200000;
    q=200000;
    for(int i=1;i<n;i++)
    {
        ll x,y;
        //cin>>x>>y;
        //sf("%lld%lld",&x,&y);
        A[i-1].pb(i);
        A[i].pb(i-1);
    }
    //vll val(n);
    for(int i=0;i<n;i++)
    {
        //cin>>val[i];
        //sf("%lld",&val[i]);
        val[i]=i;
    }
///    queue<ll>Q;
    Q.push(0);
    Q.push(-1);
    vi p(n+1,0);
    ll level=1;
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
  //  cout<<"R1"<<endl;    
    ll rep=log2(level);
    rep=pow(2,rep);
    if(level%rep)
        rep=rep*2;
    vector<vll>days(level+1);
    days[level-1].pb(cntElements[level-1]);
//    cout<<level<<endl;
    ll curpow=2;
    ll Count=0;
    for(int i=level-2;i>=1;i--)
    {
    //    cout<<i<<endl;
        if(curpow==level-i)
            curpow*=2;
        days[i].pb(cntElements[i]);
        for(int j=1;j<curpow;j++)
        {
            //cout<<Count<<endl;
            Count++;
  //          cout<<'j'<<j<<endl;
            days[i].pb(days[i][j-1]^days[i+1][j%days[i+1].size()]);
        }
        cout<<days[i].size()<<endl;
    }
    /*while(q--)
    {
        ll d;
        //cin>>d;
        //sf("%lld",&d);
        d=rand()%1000000000;
        
        ll ans=days[1][d%days[1].size()];
        pf("%lld\n",ans);
    }*/
	return 0;
}

