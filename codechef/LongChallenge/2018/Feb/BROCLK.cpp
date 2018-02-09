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
#define PI 3.14159265
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        ll l,d,t;
        cin>>l>>d>>t;
        double x = 1.0*d/l;
        double theta = a cos(abs(x));
        if(x < 0)
        {
            theta = PI - theta;
        }
        theta = (x*t)%(2*PI);

    }
	return 0;
}

