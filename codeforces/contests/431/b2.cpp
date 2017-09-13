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
set<int>B[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vi a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    vector<pair<pair<int,int>,int > >slope(1001);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            int x=j-i;
            int y=a[j]-a[i];
            int g=1;
            if(y)
                g=__gcd(x,y);
            else x=1;
            x=x/g;
            y=y/g;
            if(y<0 && x>0)
            {
                y=-1*y;
                x=-1*x;
            }
            slope[i].pb(mp(mp(x,y),j));
        }
        sort(all(slope[i]));
        int cnt=0;
        vector<vector<int> >tt(n+1);
        tt[cnt].pb(slope[i][1].ss);
        for(int j=2;slope[i].size();j++)
        {
            if(slope[i][j].ff!=slope[i][j-1].ff)
                cnt++;
            tt[cnt].pb(slope[i][j].ss);
        }
        for(int j=0;j<=cnt;j++)
        {
            if(tt[j].size()>=(n/2 + n%2))
            {
                sort(all(tt[j]));
                int pt=1;
                vector<pair<int,int> > t;
                for(int k=0;k<tt.size();k++)
                {
                    while(pt<tt[k])
                    {
                        t.pb(mp(a[pt],pt));
                        pt++;
                    }
                }
                
            }
        }
    }
	return 0;
}

