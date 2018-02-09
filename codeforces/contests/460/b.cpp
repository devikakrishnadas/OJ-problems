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

int sum(int a)
{
    int ans=0;
    while(a)
    {
        ans+=a%10;
        a=a/10;
    }
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    vi ans;
    REP(i,100000000)
    {
        int a = sum(i);
        if(a==10)
        {
            ans.pb(i);
        }
    }
    cerr<<ans.size()<<endl;
    int k;
    cin>>k;
    cout<<ans[k-1]<<endl;
	return 0;
}

