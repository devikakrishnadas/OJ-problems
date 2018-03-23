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
    int a,b;
    cin>>a>>b;
    int mid = (a+b)/2;
    int n1 = (mid - min(a,b));
    int n2 = (max(a,b) - mid);
    ll ans = (n1*(n1+1))/2 + (n2*(n2+1))/2;
    cout<<ans<<endl;
	return 0;
}

