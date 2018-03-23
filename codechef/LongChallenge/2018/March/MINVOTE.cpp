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
        vll a(n);
        REP(i,n) cin>>a[i];
        vll ans(n,0);
        REP(i,n)
        {
            ll sum=0;
            ll ind = i+1;
            while(sum <= a[i] and ind < n)
            {
                ans[ind]++;
                sum+=a[ind];
                ind++;
            }
            sum=0;
            ind = i-1;
            while(sum<=a[i] and ind >=0)
            {
                ans[ind]++;
                sum+=a[ind];
                ind--;
            }
        }
        REP(i,n)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}

