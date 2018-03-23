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
    int l,r,a;
    cin>>l>>r>>a;
    if(l<r)
    {   
        while(a-(r-l) < 0)
        {
            r--;
        }
        a -= (r-l);
        l += (r-l);
    }
    else
    {
        while(a-(l-r) < 0)
        {
            l--;
        }
        a -= (l-r);
        r += (l-r);
    }
    l = l + a/2;
    r = r + a/2;
    cout<<l+r<<endl;
    return 0;
}

