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

void dfs(vector< vector<pair<ll,ll> > >&tree,ll a,ll prev,vi &l,vi &r,vi &eulerWalk,vi &vis,ll &cnt,vll &tree1)
{
    
    l[a]=eulerWalk.size()-1;
    vis[a]=cnt;
    cnt=cnt+1;
    tree1[a]=prev;
    for(int i=0;i<tree[a].size();i++)
    {
        if(tree[a][i].ff!=prev)
        {
            eulerWalk.pb(tree[a][i].ss);
            dfs(tree,tree[a][i].ff,a,l,r,eulerWalk,vis,cnt,tree1);
            eulerWalk.pb(tree[a][i].ss);
        }
    }
    r[a]=eulerWalk.size();
}
void merge(vector<pair<ll,ll> > &f, vector<pair<ll,ll> > &s,vector<pair<ll,ll> > &m)
{
    ll i=0;
    ll j=0;
    ll xo=0;
    while(1)
    {
        if(f.size()==i && s.size()==j)
            break;
        ll a=LLONG_MAX,b=LLONG_MAX;
        if(f.size()>i)
        {
            a=f[i].ff;
        }
        if(s.size()>j)
        {
            b=s[j].ff;
        }
        if(a<b)
        {
            xo=xo^a;
            m.pb(mp(a,xo));
            i++;
        }
        else if(b!=LLONG_MAX)
        {
            xo=xo^b;
            m.pb(mp(b,xo));
            j++;
        }
    }
}
void createMST(ll l,ll r,ll tp,vector<vector<pair<ll,ll> > >&MST,vi &eulerWalk)
{
    if(l==r)
    {
        MST[tp].pb(mp(eulerWalk[l],eulerWalk[l]));
        return ;
    }
    ll m=(l+r)/2;
    createMST(l,m,2*tp+1,MST,eulerWalk);
    createMST(m+1,r,2*tp+2,MST,eulerWalk);
    merge(MST[2*tp+1],MST[2*tp+2],MST[tp]);
}
void createMSTUtil(vector<vector<pair<ll,ll> > >&MST, vi &eulerWalk)
{
    createMST(0,eulerWalk.size()-1,0,MST,eulerWalk);
}

ll b_s(vector<pair<ll,ll> > &t,ll k)
{
    ll l=0;
    ll r=t.size()-1;
    ll ans=0;
    while(l<=r)
    {
        ll m=(l+r)/2;
        if(t[m].ff<=k)
        {
            ans=t[m].ss;
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
    return ans;
}
ll queryMST(vector<vector<pair<ll,ll> > >&MST,ll k,ll l,ll r,ll ql,ll qr,ll tp)
{
    //cout<<l<<" "<<r<<endl;
    if(r<ql || l>qr)
        return 0;
    if(l==r)
    {
        if(MST[tp][0].ss<=k)
            return MST[tp][0].ss;
        else return 0;
    }
    if(l>=ql && r<=qr)
    {
        return b_s(MST[tp],k);
    }
    ll m=(l+r)/2;
    return queryMST(MST,k,l,m,ql,qr,2*tp+1)^queryMST(MST,k,m+1,r,ql,qr,2*tp+2);
}
ll queryMSTUtil(vector<vector<pair<ll,ll> > >&MST,ll k,ll ql,ll qr,ll n)
{
    return queryMST(MST,k,0,n-1,ql,qr,0);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n;
        vector< vector<pair<ll,ll> > >tree(n+1);
        vi tree1(n+1,0);
        for(ll i=1;i<n;i++)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            tree[x].pb(mp(y,z));
            tree[y].pb(mp(x,z));
        }
        cin>>m;
        //sort(all(request));
        vi l(n+1,-1);
        vi r(n+1,-1);
        vi eulerWalk;
        eulerWalk.pb(0);
        vi vis(n+1,0);
        ll cnttt=1;
        dfs(tree,1,-1,l,r,eulerWalk,vis,cnttt,tree1);
        eulerWalk.pb(0);
        /*for(int i=0;i<eulerWalk.size();i++)
        {
            cout<<eulerWalk[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<l[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<r[i]<<" ";
        }
        cout<<endl;*/
        //cout<<"r1"<<endl;
        vector<vector<pair<ll,ll> > >MST(10*n);
        //cout<<"EulerWalkSize :"<<eulerWalk.size()<<endl;
        createMSTUtil(MST,eulerWalk);
        //cout<<"r2"<<endl;
        
        for(ll i=0;i<m;i++)
        {
            ll u,v,k;
            cin>>u>>v>>k;
            ll a,b,c,d;
            a=l[u];b=l[v];c=r[u];d=r[v];
            //cout<<"visit order "<<vis[u]<<" "<<vis[v]<<endl;
            //cout<<l[request[i].ss.ff]<<" "<<r[request[i].ss.ss]<<endl;
            if(c<=d)
            {
                cout<<queryMSTUtil(MST,k,c,d-1,eulerWalk.size())<<endl;
            }
            else if(d<=a)
            {
                cout<<queryMSTUtil(MST,k,d,a,eulerWalk.size())<<endl;
            }
            else
            {
                cout<<queryMSTUtil(MST,k,a,b,eulerWalk.size())<<endl;
            }
        }
    }
	return 0;
}

