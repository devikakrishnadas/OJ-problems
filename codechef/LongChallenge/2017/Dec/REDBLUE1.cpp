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


struct per
{
    ll cl;
    double x, y, b;
};

ll misclass(per w, per p[3000], ll n, per &sum)
{
    ll cnt=0;
    sum.x=0;
    sum.y=0;
    sum.b=0;
    for(int i=0;i<n;i++)
    {
        ll val = p[i].x*w.x + p[i].y*w.y + p[i].b*w.b;
        ll del=1;
        if(val<=0) del = -1;
        if((val > 0 && p[i].cl == 0) || (val <= 0 && p[i].cl == 1))
        {
            //sum.x+=(del * p[i].x);
            //sum.y+=(del * p[i].y);
            //sum.b+=(del * p[i].b);
            w.x-=(del * p[i].x);
            w.y-=(del * p[i].y);
            w.b-=(del * p[i].b);
            cnt++;
        }
    }
    return cnt;
}
ll perceptron(per w,per p[3000],ll n, ll m)
{
    ll tt=150000;
    ll misc;
    ll mi=LLONG_MAX;
    double alp=0.1;
    do
    {
        per sum;
        misc = misclass(w,p,n+m,sum);
        w.x-=(alp*sum.x);
        w.y-=(alp*sum.y);
        w.b-=(alp*sum.b);
        mi=min(mi,misc);
//        cout<<misc<<endl;
    }while(tt-- && misc);
//    cout<<mi<<" "<<w.x<<" "<<w.y<<" "<<w.b<<endl;
    return mi;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{   
        per p[3000];
        ll n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>p[i].x>>p[i].y;
            p[i].cl=0;
            p[i].b=1;
        }
        for(int i=0;i<m;i++)
        {
            cin>>p[i+n].x>>p[i+n].y;
            p[i+n].cl=1;
            p[i+n].b=1;
        }
        per w;
        w.b=1;
        w.x=1;
        w.y=1;
        cout<<perceptron(w,p,n,m)<<endl;
	}
	return 0;
}

