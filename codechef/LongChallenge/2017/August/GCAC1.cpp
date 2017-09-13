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
        for(ll i=1;i<=n;i++)
        {
            ll ms;
            cin>>ms;
            minSalary.pb(mp(ms,i));
        }
        vector<pair<ll,ll> >job(m+1);// < offered salary,maxJobOffers >
        for(ll i=1;i<=m;i++)
        {
            ll offeredSalary,maxJobOffer;
            cin>>offeredSalary>>maxJobOffer;
            job[i]=mp(offeredSalary,maxJobOffer);
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
        ll cnt=0;
        ll totSalary=0;
        ll compHired[10002]={0};
        for(ll i=0;i<minSalary.size();i++)
        {
            ll ma=-1;
            for(ll j=1;j<=m;j++)
            {
                if(job[j].ss==0)
                    continue;
                if(qual[minSalary[i].ss][j] && job[j].ff>=minSalary[i].ff)
                {
                    if(ma==-1)
                    {
                        ma=j;
                    }
                    else if(job[ma].ff<job[j].ff)
                    {
                        ma=j;
                    }
                }
            }
            if(ma!=-1)
            {
                compHired[ma]=1;
                job[ma].ss--;
                cnt++;
                totSalary+=job[ma].ff;
            }
        }
        cout<<cnt<<" "<<totSalary<<" ";
        cnt=0;
        for(ll i=1;i<=m;i++)
        {
            if(!compHired[i])
                cnt++;
        }
        cout<<cnt<<endl;
    }
	return 0;
}

