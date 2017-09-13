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
        ll n,m;
        cin>>n>>m;
        vector<pair<ll,ll> >minSalary;
        vll minSal(n+1);
        for(ll i=1;i<=n;i++)
        {
            ll ms;
            cin>>ms;
            minSalary.pb(mp(ms,i));
            minSal[i]=ms;
        }
        vector<pair<ll,ll> >job(m+1);// < offered salary,maxJobOffers >
        for(ll i=1;i<=m;i++)
        {
            ll offeredSalary,maxJobOffer;
            cin>>offeredSalary>>maxJobOffer;
            job[i]=(mp(offeredSalary,maxJobOffer));
        }
        ll qual[1001][1001]={0};
        char c;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            {
                cin>>c;
                qual[i][j]=c-'0';
            }
        }
        int ma=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(qual[i][j])
                {
                    
                }
            }
        }
    }
	return 0;
}

