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

int check(vector<pair<double,double> >&a,vector<pair<double,double> >&b)
{
    
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<double,double> >blue,red;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            blue.pb(mp(x,y));
        }
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            red.pb(mp(x,y));
        }
        int a=check(blue,red);
        int b=check(red,blue);
        cout<<min(a,b)<<endl;
    }
	return 0;
}

