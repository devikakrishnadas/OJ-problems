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

int check(vector<pair<pair<int,int>,int> >&a,pair<pair<int,int>,int>X,pair<pair<int,int>,int>Y)
{
    int bm=0,rm=0,bp=0,rp=0;
    ll x1 = X.ff.ff, x2 = Y.ff.ff;
    ll y1 = X.ff.ss, y2 = Y.ff.ss;
    for(int i=0;i<a.size();i++)
    {
        int x = a[i].ff.ff;
        int y = a[i].ff.ss;
        ll d =(x-x1)*(y2-y1) - (y-y1)*(x2-x1);
        if(d>0)
        {
            if(a[i].ss == 0)
                rp++;
            else
                bp++;
        }
        else
        {
            if(a[i].ss==0)
                rm++;
            else bm++;
        }
//        cout<<d<<" "<<rm<<" "<<rp<<" "<<bm<<" "<<bp<<endl;
    }
    return min(rp+bm,rm+bp);
}
int func(vector<pair<pair<int,int>,int> >&a,int n,int m)
{
    int ans=INT_MAX;
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a.size();j++)
        {

            ans=min(ans,check(a,a[i],a[j]));
        }
    }
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<pair<int,int>,int> >a;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            a.pb(mp(mp(x,y),0));
        }
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            a.pb(mp(mp(x,y),1));
        }
        if(n+m<=3)
        {
            cout<<0<<endl;
            continue;
        }
        cout<<func(a,n,m)<<endl;
    }
	return 0;
}

