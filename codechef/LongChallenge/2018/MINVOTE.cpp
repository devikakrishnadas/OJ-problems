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
        vi a(n);
        REP(i,n) cin>>a[i];
        int j=n-2;
        int sum=a[n-1];
        vector<pair<int,int> > votes_till(n,mp(0,0));
        for(int i=n-1;i>=0;i--)
        {
            sum-=a[i];
            while(sum < a[i] and j>=0)
            {
                sum+=a[j];
                votes_till[i].ff=j;
                j--;
            }
        }
        sum=a[0];
        j=1;
        for(int i=0;i<n;i++)
        {
            sum-=a[i];
            while(sum<a[i] and j<n)
            {
                cout<<a[i]<<" votes for "<<a[j]<<endl;
                sum+=a[j];
                votes_till[i].ss=j;
                j++;
            }
        }
        
    }
	return 0;
}

