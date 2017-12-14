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
#define PI 3.14159265358979323

using namespace std;
int MAGIC;
pair<pair<ll,ll>,ll>center;
ll check(vector<pair<pair<ll,ll>,ll> >&a,pair<pair<ll,ll>,ll>X,pair<pair<ll,ll>,ll>Y)
{
    ll bm=0,rm=0,bp=0,rp=0;
    ll x1 = X.ff.ff, x2 = Y.ff.ff;
    ll y1 = X.ff.ss, y2 = Y.ff.ss;
    for(int i=0;i<a.size();i++)
    {
        ll x = a[i].ff.ff;
        ll y = a[i].ff.ss;
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
int func(vector<pair<pair<ll,ll>,ll> >&a,ll n,ll m)
{
    ll ans=INT_MAX;
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a.size();j++)
        {

            ans=min(ans,check(a,a[i],a[j]));
        }
    }
    return ans;
}
double findVal(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
{
    ll x1 = a.ff.ff - center.ff.ff;
    ll x2 = a.ff.ss - center.ff.ss;
    ll y1 = b.ff.ff-center.ff.ff;
    ll y2 = b.ff.ss - center.ff.ss;
    return x2*y1 - x1*y2 >= 0;
    
}
ll calcError(vector<pair<pair<ll,ll>,ll> >&val,ll n,ll m)
{
    int j=0;
    ll red=0,blue=0;
    int sz = val.size();
    ll ans=INT_MAX;
    for(int i=0;i<3*val.size();i++)
    {
        if(val[i%sz]==center) continue;
//        cout<<i<<" "<<j<<" "<<findVal(val[i%sz],val[j%sz])<<" "<<((j - i + 1) <=val.size())<<endl;
        while(findVal(val[i%sz],val[j%sz]) && (j - i + 1) <=val.size())
        {
            if(val[j%sz]==center) 
            {j++;continue;}
//            cout<<i%sz<<" "<<j%sz<<endl;
            if(val[j%sz].ss==0) red++;
            else blue++;
            j++;
        }
        
        ans = min(ans,min(red + m - blue, blue + n - red));
        if(val[i%sz].ss == 0) red--;
        else blue--;
    }
    return ans;
}
bool Less(pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll> b)
{
    if (a.ff.ff - center.ff.ff >= 0 && b.ff.ff - center.ff.ff < 0)
        return true;
    if (a.ff.ff - center.ff.ff < 0 && b.ff.ff - center.ff.ff >= 0)
        return false;
    if (a.ff.ff - center.ff.ff == 0 && b.ff.ff - center.ff.ff == 0) 
    {
        if (a.ff.ss - center.ff.ss >= 0 || b.ff.ss - center.ff.ss >= 0)
            return a.ff.ss > b.ff.ss;
        return b.ff.ss > a.ff.ss;
    }

    ll det = (a.ff.ff - center.ff.ff) * (b.ff.ss - center.ff.ss) - (b.ff.ff - center.ff.ff) * (a.ff.ss - center.ff.ss);
    
    if (det < 0)
        return true;
    
    if (det > 0)
        return false;

    ll d1 = (a.ff.ff - center.ff.ff) * (a.ff.ff - center.ff.ff) + (a.ff.ss - center.ff.ss) * (a.ff.ss - center.ff.ss);
    ll d2 = (b.ff.ff - center.ff.ff) * (b.ff.ff - center.ff.ff) + (b.ff.ss - center.ff.ss) * (b.ff.ss - center.ff.ss);
    return d1 > d2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll t;
    cin>>t;
    MAGIC = 3;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<pair<pair<ll,ll>,ll> >pts,pts1;
        for(int i=0;i<n;i++)
        {
            ll x,y;
            cin>>x>>y;
            pts.pb(mp(mp(x,y),0));
        }
        for(int i=0;i<m;i++)
        {
            ll x,y;
            cin>>x>>y;
            pts.pb(mp(mp(x,y),1));
        }
        //        cout<<n<<m<<endl;
        if(n+m<=3)// || n==1 || m==1)
        {
            cout<<0<<endl;
            continue;
        }
		if(n+m <=1500)
        {
            cout<<func(pts,n,m)<<endl;
            continue;
        }
		
//        sort(all(pts));
        ll ans=INT_MAX;
//        cout<<pts.size()<<endl;
        pts1=pts;
        for(int i=0;i<pts.size();i++)
        {
            //cout<<i<<endl;
			center=pts1[i];
            sort(all(pts),Less);
//            cout<<pts.size()<<endl;
//            cout<<"center is ("<<center.ff.ff<<","<<center.ff.ss<<")"<<endl;
//            for(int j=0;j<pts.size();j++)
  //          {
    //            cout<<"("<<pts[j].ff.ff<<","<<pts[j].ff.ss<<" sign "<<pts[j].ss<<"), ";
      //      }
        //    cout<<endl<<endl;
            ans=min(ans,calcError(pts,n,m));
        }
        cout<<ans<<endl;
                //cout<<val2<<endl;
    }
	return 0;
}

