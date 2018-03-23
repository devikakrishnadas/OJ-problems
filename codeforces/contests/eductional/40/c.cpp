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
    int k=-1;
    REP(i,n) cin>>a[i];
    int maxrem=0;
    int maxdiv=0;
    FOR(i,1,n)
    {
        if(abs(a[i]-a[i-1])==1)
        {
            maxrem = max(
        }
        else if(a[i]-a[i-1]==0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else if(k==-1)
        {
            k=abs(a[i]-a[i-1]);
        }
        else if(abs(a[i]-a[i-1])!=k)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(k==-1) k=1;
    REP(i,n)
    {
        maxdiv=max(maxdiv,a[i]/k);
    }
    if(maxrem > k)
    {
        cout<<maxrem<<" "<<k<<endl;
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    cout<<maxdiv+1<<" "<<k<<endl;
	return 0;
}

