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
    int n;
    cin>>n;
    map<int,int>a;
    vi val;
    REP(i,n)
    {
        int x;
        cin>>x;
        if(!a[x])
            val.pb(x);
        a[x]++;
    }
    if(val.size()==1)
    {
        cout<<n<<endl;
        REP(i,a[val[0]])
            cout<<val[0]<<" ";
        cout<<endl;
        return 0;
    }
    else if(val.size()==2)
    {
        cout<<n<<endl;
        REP(i,a[val[1]])
        {
            cout<<val[1]<<" ";
        }
        REP(i,a[val[0]])
        {
            cout<<val[0]<<" ";
        }
        cout<<endl;
        return 0;
    }
    sort(all(val));
    int ans1 = a[val[0]]+a[val[2]]+(a[val[1]]%2);
    int ans2 = a[val[1]] + abs(a[val[2]]-a[val[0]]);
    if(ans1<ans2)
    {
        cout<<ans1<<endl;
        a[val[0]]+=(a[val[1]]/2);
        a[val[2]]+=(a[val[1]]/2);
        REP(i,a[val[0]])
        {
            cout<<val[0]<<" ";
        }
        REP(i,a[val[2]])
        {
            cout<<val[2]<<" ";
        }
        if(a[val[1]]%2)
            cout<<val[1]<<" ";
        cout<<endl;
    }
    else
    {
        cout<<ans2<<endl;
        int mi = min(a[val[0]],a[val[2]]);
        a[val[1]]+=(2*mi);
        a[val[0]]-=mi;
        a[val[2]]-=mi;
        REP(i,a[val[0]])
        {
            cout<<val[0]<<" ";
        }
        REP(i,a[val[1]])
        {
            cout<<val[1]<<" ";
        }
        REP(i,a[val[2]])
        {
            cout<<val[2]<<" ";
        }
        cout<<endl;
    }
	return 0;
}

