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
        vi a(n),b(n);
        REP(i,n) cin>>a[i];
        REP(i,n) cin>>b[i];
        sort(all(a));
        sort(all(b));
        int suma=0,sumb=0;
        REP(i,n-1) suma+=a[i];
        REP(i,n-1) sumb+=b[i];
        if(suma<sumb)
        {
            cout<<"Alice"<<endl;
        }
        else if(sumb<suma)
        {
            cout<<"Bob"<<endl;
        }
        else cout<<"Draw"<<endl;
    }
	return 0;
}

