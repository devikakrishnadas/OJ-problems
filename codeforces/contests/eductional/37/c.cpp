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
    vi a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    string s;
    cin>>s;
    int mi = INT_MAX;
    bool no=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]<mi)
            mi = a[i];
        else if(s[i] == '0')
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
	return 0;
}

