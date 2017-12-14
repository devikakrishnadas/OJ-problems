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

set<ll >S[2000000];
vll vals;
vector<pair<ll,pair<ll,ll> > >a;

void add(ll l,ll r,ll s,ll e,ll item,ll tp,ll x)
{
    //cerr<<"r5"<<endl;
    //cerr<<"tp : "<<tp<<endl;
//    cerr<<"l : "<<l<<", r : "<<r<<", s : "<<s<<", e : "<<e<<endl;
    if(e<l || s>r)
        return;
    if(e<=r && s>=l)
    {
        if(x)
        {
            S[tp].insert(item);
            //if(item==3)
                //cout<<"add 3"<<endl;
        }
        else
        {
            S[tp].erase(item);
            //if(item==3)
                //cout<<"erase 3 from "<<tp<<endl;
        }
 //       else cerr<<"bloody effin fool"<<endl;
        return;
    }
    ll mid = (s+e) / 2;
    add(l,r,s,mid,item,2*tp+1,x);
    add(l,r,mid+1,e,item,2*tp+2,x);
}

ll get(ll s,ll e,ll x,ll y)
{
//    cerr<<"r7"<<endl;
    ll tp=0;
    vll path;
    path.pb(0);
    while(s<e)
    {
        ll mid = (s+e)/2;
        //cerr<<" s e vals[mid] x: "<<s<<" "<<e<<" "<<vals[mid]<<" "<<x<<endl;
        if(vals[mid] >= x)
        {
            e=mid;
            tp = 2*tp + 1;
        }
        else if(vals[mid] < x)
        {
            s=mid+1;
            tp = 2*tp + 2;
        }
        path.pb(tp);
    }
    //cerr<<"path.size() : "<<path.size()<<endl;
    for(int i=0;i<path.size();i++)
    {
        for(auto p : S[path[i]])
        {
//            if(p==2)
  //          {
    //            cout<<"how the hell ?"<<endl;
      //      }
            //cerr<<"p : "<<p<<endl;
            ll x1 = a[p].ss.ff;
            ll y1 = a[p].ss.ss;
            ll dist = (x-x1)*(x-x1) + (y-y1)*(y-y1);
            ll rad = y1 * y1;
            if(dist < rad)// && (x > x1-y1 &&  x < x1+y1))
            {
                //cout<<"center of ans : "<<x1<<" "<<y1<<endl;
                return p+1; 
            }
        }
    }
    return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll t,x,y;
        cin>>t>>x>>y;
        a.pb(mp(t,mp(x,y)));
        if(t==1)
        {
            vals.pb(x-y+1);
            vals.pb(x+y-1);
        }
        else
            vals.pb(x);
    }
    //cerr<<"r1"<<endl;
    auto it = unique(all(vals));
    vals.resize(distance(vals.begin(),it));
    ll cnt = vals.size();
    sort(all(vals));
    //cerr<<"r2"<<endl;
    for(int i=0;i<n;i++)
    {
        ll t,x,y;
        t=a[i].ff;
        x=a[i].ss.ff;
        y=a[i].ss.ss;
        //cerr<<"r3"<<endl;
        if(t==1)
        {
            //cerr<<"r4"<<endl;
            ll l = lower_bound(all(vals),x-y+1) - vals.begin() ;
            ll r = lower_bound(all(vals),x+y-1) - vals.begin() ;
//            cout<<vals[l]<<" "<<vals[r]<<endl;
            add(l,r,0,cnt-1,i,0,1); // l, r, s, e, item, tp, add/remove
        }
        else
        {  
            //cerr<<"r6"<<endl;
            ll ind = get(0,cnt-1,x,y);
            //cerr<<"answer is :"<<endl;

            cout<<ind<<endl;
            if(ind != -1)
            {
                ind--;
                //cerr<<"r8"<<endl;
                ll x = a[ind].ss.ff;
                ll y = a[ind].ss.ss;
                ll l = lower_bound(all(vals),x-y+1) - vals.begin() ;
                ll r = lower_bound(all(vals),x+y-1) - vals.begin() ;
//                cout<<vals[l]<<" "<<vals[r]<<endl;
                add(l,r,0,cnt-1,ind,0,0);
            }
        }
    }
    return 0;
}

