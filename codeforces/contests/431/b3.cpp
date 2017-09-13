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


set<pair<int,int> >A[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<pair<pair<int,int> ,pair<int,int> > >slope;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int x=j-i;
            int y=a[j]-a[i];
            int g=1;
            if(y)
                g=__gcd(y,x);
            y=y/g;
            x=x/g;
            if(y==0) x=1;
            slope.pb(mp(mp(x,y),mp(i,j)));
        }
    }
    sort(all(slope));
    int cnt=0;
    A[cnt].insert(mp(a[slope[0].ss.ff],slope[0].ss.ff));
    A[cnt].insert(mp(a[slope[0].ss.ss],slope[0].ss.ss));
    for(int i=1;i<slope.size();i++)
    {
        if(slope[i].ff!=slope[i-1].ff)
            cnt++;
        A[cnt].insert(mp(a[slope[i].ss.ff],slope[i].ss.ff));
        A[cnt].insert(mp(a[slope[i].ss.ss],slope[i].ss.ss));
    }
    for(int i=0;i<=cnt;i++)
    {
        if(A[i].size()>=n-1)
        {
            vector<pair<int,int> >t;
            int inv=0;
            set<pair<int,int> >::iterator it1=A[i].begin(),it=A[i].begin();
            it1++;
            int x=it1->ss-it->ss;
            int y=it1->ff-it->ff;
            int g=1;
            if(x && y)
            g=__gcd(x,y);
            x=x/g;
            y=y/g;
            it1++;
            for(;it1!=A.end();it1++)
            {
                
            }
            
        }
    }
	return 0;
}

