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
        int n,k;
        cin>>n>>k;
        int s=1;
        vi a(n+1,-1);
        int nu = k;
        REP(i,k)
        {
            int x;
            cin>>x;
            a[x]=s;
        }
        while(nu<n)
        {
            s++;
            FOR(i,2,n+1)
            {
                if(a[i-1]!= -1 and a[i] == -1 and a[i-1] != s)
                {
                    a[i]=s;
                    nu++;
                }
            }
            for(int i=n-1;i>=1;i--)
            {
                if(a[i+1] != -1 and a[i]==-1 and a[i+1] != s)
                {
                    a[i]=s;
                    nu++;
                }
            }
        }
        cout<<s<<endl;
    }

	return 0;
}

