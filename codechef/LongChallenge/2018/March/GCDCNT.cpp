#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int n,q;
int const maxn=50001;
vi a(maxn);
vector<set<int> >val(2*maxn);
vi squareFree(maxn*10,1);
vi sf;
void sieve()
{
    for(ll i=2;i<maxn*2;i++)
    {
        if(squareFree[i])
        {
            for(ll j=1;i*i*j<maxn*2;j++)
            {
                squareFree[i*i*j]=0;
            }
            sf.pb(i);
        }
    }
}
void addAt(int ind,bool v)
{
    for(int i=2;i<=sqrt(a[ind]);i++)
    {
        if(a[ind]%i==0)
        {
            if(v)
                val[i].insert(ind);
            else val[i].erase(ind);
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    REP(i,n) cin>>a[i];
    sieve();
//    cout<<sf.size()<<endl;
    for(int i=0;i<n;i++)
    {
        addAt(i,1);
    }
    cin>>q;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x,y;
            cin>>x>>y;
            addAt(x-1,0);
            a[x-1]=y;
            addAt(x-1,1);
        }
        else
        {
            int l,r,g;
            cin>>l>>r>>g;
            vi fact;
            for(int i=2;i<=sqrt(g);i++)
            {
                if(g%i==0) fact.pb(g);
                while(g%i==0) g=g/i;
            }
            if(g!=1)
            {
                fact.pb(g);
            }
            int nn=fact.size();
            int lim = pow(2,nn);
            ll ans=0;
            for(int i=1;i<lim;i++)
            {
                int ti=i;
                int cnt=0;
                int value=1;
                int j=0;
                while(ti)
                {
                    if(ti%2)
                    {
                        cnt++;
                        value=value*fact[j];
                    }
                    ti=ti/2;
                    j++;
                }
                if(cnt%2==0)
                    ans += (distance(val[value].upper_bound(r-1))-1-distance(val[value].lower_bound(l-1))); 
                else
                    ans -= (distance(val[value].upper_bound(r-1))-1-distance(val[value].lower_bound(l-1))); 
            }
            cout<<ans<<endl;
        }
    }
	return 0;
}
