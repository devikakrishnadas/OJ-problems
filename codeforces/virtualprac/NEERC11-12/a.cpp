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
    freopen("area.in","r",stdin);
    freopen("area.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    int a,b,c,d;
    vector<double> g;
    while(n--)
    {
        cin>>a>>b>>c>>d;
        int per=2*abs(c-a) + 2*abs(d-b);
        int area=abs(c-a)*abs(d-b);
        double val= (1.0*area)/(1.0*per);
        g.pb(val);
    }
    sort(all(g));
    reverse(all(g));
    cout<<fixed<<setprecision(10)<<g[0]<<endl;
	return 0;
}

