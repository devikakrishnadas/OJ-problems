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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int> >a;
    vector<double>b;
    for(int i=0;i<n;i++)
    {
        double x,y;
        cin>>x>>y;
        a.pb(mp(x,y));
        b.pb(atan2(y,x)*57.2957795131);
    }
    sort(all(b));
    double ans = 0.0;
    for(int i=1;i<=2*n;i++)
    {
        double f = b[i%n];
        double s = b[(i-1)%n];
        if(f<s)
            f = f + 360.0;
        ans = max(ans, (f-s));
    }
    double ans2 = (b[n-1] - b[0]);
    cout<<fixed<<setprecision(15)<<min(360.0 - ans,ans2)<<endl;
	return 0;
}

