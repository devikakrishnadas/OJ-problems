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
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)

using namespace std;
ll n,q;
ll const maxn=100001;
vll a(maxn);
ll const K=50;
vector<vll > MST(3*maxn);

void merge(int l,int r,int c)
{
    MST[c].clear();
/*    priority_queue<int>b;
    for(int x : MST[l])
        b.push(x);
    for(int x: MST[r])
        b.push(x);
    while(MST[c].size()<K and !b.empty())
    {
        MST[c].pb(b.top());
        b.pop();
    }
*/
    int i=0,j=0;
    while(i<MST[l].size() or j<MST[r].size())
    {
        int lv=-1;
        int rv=-1;
        if(i<MST[l].size())
        {
            lv = MST[l][i];
        }
        if(j<MST[r].size())
        {
            rv = MST[r][j];
        }
        if(lv>rv)
        {
            i++;
        }
        else j++;
        MST[c].pb(max(lv,rv));
        if(MST[c].size()==K)
            break;
    }
}
void makeTree(int s,int e,int tp)
{
    if(s==e)
    {
        MST[tp].pb(a[s]);
        return;
    }
    int mid=(s+e)/2;
    makeTree(s,mid,2*tp+1);
    makeTree(mid+1,e,2*tp+2);
    merge(2*tp+1,2*tp+2,tp);
}
void updVal(int s,int e,int tp,int pos,int val)
{
    if(pos>e or pos < s)
        return;
    if(s==e and s==pos)
    {
        MST[tp].clear();
        MST[tp].pb(val);
        return;
    }
    int mid=(s+e)/2;
    updVal(s,mid,2*tp+1,pos,val);
    updVal(mid+1,e,2*tp+2,pos,val);
    merge(2*tp+1,2*tp+2,tp);
}

void merge2(vll &v, vll &mst)
{
/*    priority_queue<ll>b;
    for(int x:v)
        b.push(x);
    for(int x: mst)
        b.push(x);
    v.clear();
    while(v.size()<K and !b.empty())
    {
        v.pb(b.top());
        b.pop();
    }
*/
    int i=0,j=0;
    vll p;
    while(i<v.size() or j<mst.size())
    {
        int vv=-1;
        int mstv=-1;
        if(i<v.size())
            vv=v[i];
        if(j<mst.size())
            mstv=mst[j];
        if(vv>mstv)
            i++;
        else j++;
        p.pb(max(vv,mstv));
        if(p.size()==K)
            break;
    }
    swap(v,p);
}
void findElem(int s,int e,int qs,int qe,int tp,vll &v)
{
    if(e<qs or s > qe)
        return;
    if(s >= qs and e <=qe)
    {
        merge2(v,MST[tp]);
        return;
    }
    int mid=(s+e)/2;
    findElem(s,mid,qs,qe,2*tp+1,v);
    findElem(mid+1,e,qs,qe,2*tp+2,v);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>q;
    REP(i,n) cin>>a[i];

    makeTree(0,n-1,0);
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int pos,val;
            cin>>pos>>val;
            updVal(0,n-1,0,pos-1,val);
        }
        else
        {
            vll v;
            int l,r;
            cin>>l>>r;
            /*if(r-l < 3)
            {
                cout<<0<<endl;
                continue;
            }*/
            findElem(0,n-1,l-1,r-1,0,v);
            bool enter=0;
            for(int i=0;i+2<v.size();i++)
            {
                if(v[i] < v[i+1] + v[i+2])
                {
                    enter=1;
                    cout<<v[i]+v[i+1]+v[i+2]<<endl;
                    break;
                }
            }
            if(!enter)
                cout<<0<<endl;
        }
    }
	return 0;
}

