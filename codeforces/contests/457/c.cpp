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

vi prime(10000023,1);
vi p;
void ps()
{
    for(int i=2;i<10000000;i++)
    {
        if(prime[i])
        {
            
            for(int j=i;j<10000000/i;j++)
            {
                prime[i*j] = 0;
            }
            p.pb(i);
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,m;
    ps();
    cin>>n>>m;
    vector<pair<pair<int,int>,int> >ans;
    ans.pb(mp(mp(1,n),2));
    cerr<<ans.size()<<endl;
    for(int i=n-1;i>=3;i--)
    {
        ans.pb(mp(mp(1,i),1));
    }
    int cursum = 2 + n-3 ;
    int p1 = *upper_bound(all(p),cursum);
    if(n!=2)
    ans.pb(mp(mp(1,2),p1-cursum));
    cursum = p1;
    cout<<2<<" "<<p1<<endl;

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].ff.ff<<" "<<ans[i].ff.ss<<" "<<ans[i].ss<<endl;
    }
    m = m - ans.size();
    for(int i=2;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            
            if(m!=0)
                cout<<i<<" "<<j<<" "<<1000000000<<endl;
            else
                return 0;
            m--;
        }
    }
	return 0;
}

