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
    ll k,t;
    ll d;
    cin>>k>>d>>t;
    d = (k/d)*d + (k%d ? d : 0);
    double cookperd = k + (d-k)/2.0;
    double ontime = k;
    double offtime = (d-k);
    ll x = (2*t)/(2*cookperd);
    ontime*=x;
    offtime*=x;
    double rem = t - x*cookperd;
    ontime += min(rem,1.0*k);
    rem = rem - min(rem,1.0*k);
    offtime += (2.0*rem);
    cout<<fixed<<setprecision(14)<<ontime + offtime<<endl;
    return 0;
}

