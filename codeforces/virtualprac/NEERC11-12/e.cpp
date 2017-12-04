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

int main()
{
    freopen("domino.in","r",stdin);
    freopen("domino.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll n,r;
    cin>>n>>r;
    vector< pair<int,int> >a;
    vi b(2*r+1);
    int sum=0;
    map<pair<int,int>,int>cnt;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        cnt[mp(x,y)]+=1;
        sum+=(x+y);
    }
    
    for(int i=0;i<2*r;i++)
    {
        cin>>b[i];
    }
    for(auto p: cnt)
    {
        for(int i=0;i<2 && i<p.ss;i++)
        {
            a.pb(p.ff);
        }
    }
    int ans=-1;
    for(auto p: a)
    {
        if(p.ss == b[0] || p.ff == b[0])
        {
            ans=max(ans,p.ff + p.ss);
        }
        if(p.ss == b[2*r-1] || p.ff == b[2*r-1] )
        {
            ans=max(ans,p.ff + p.ss);
        }

    }
    bool one = ans == -1 ? 0 : 1;
    bool two=0;
    for(int i=0;i<a.size();i++)
    {
        for(int j=0; j<i ;j++)
        {
            auto p1=a[i], p2=a[j];
            if(p1.ff == p1.ss && p2.ff == p2.ss)
            {
                if((p1.ff==b[0] && p2.ff==b[2*r-1]) || (p1.ff==b[2*r-1] && p2.ss==b[0]))
                {
                    if(p1.ff*2 + p2.ff*2 >= ans)
                    {
                        two=1;
                    }
                    ans=max(ans,p1.ff*2 + p2.ff*2);
                    
                }
            }
        }
    }
    if(ans==sum &&( (one && n == 1) || (two && n==2 )))
    {
        cout<<-1<<endl;
    }
    else
    {
        if(ans==-1) ans=0;
        cout<<sum - ans<<endl;
    }
	return 0;
}

