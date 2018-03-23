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
    ll n;
    cin>>n;
    vll a(n),b(n);
    ll suma = 0,sumb=0;
    REP(i,n)
    {
        cin>>a[i];
        suma+=a[i];
    }
    REP(i,n)
    {
        cin>>b[i];
        sumb+=b[i];
    }
    ll ba,bb;
    ba = bb = 0;
    ll v=1;
    REP(i,20)
    {
        REP(j,n)
        {
            if(a[j] & v)
            {
                ba |= v;
            }
            if(b[j] & v)
            {
                bb |= v;
            }
        }
        v = v*2;
    }

    if(suma - ba > sumb - bb)
    {
        cout<<"1 "<< suma - ba - (sumb - bb)<<endl;
    }
    else if( suma - ba < sumb - bb)
    {
        cout<<"2 "<<sumb - bb - ( suma - ba )<<endl;
    }
    else
        cout<<-1<<endl;
	return 0;
}

