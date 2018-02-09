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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int> >l;
        //vector<pair<int,int> >ans;
        vi ans;
        REP(i,n)
        {
            int x,y;
            cin>>x>>y;
            l.pb(mp(x,y));
        }
        vi tea_time(6000,0);
        int j=0;
        FOR(time,1,5055)
        {
            while(l[j].ss < time and j<n)
            {
                ans.pb(0);
                j++;
            }
            if(j==n) break;
            if(time >= l[j].ff and time <= l[j].ss)
            {   
                ans.pb(time);
                j++;
            }
        }
        REP(i,n)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}

