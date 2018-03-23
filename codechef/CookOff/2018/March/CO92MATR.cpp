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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll A[101][101],mi[101][101]={0},ma[101][101]={0};
        REP(i,n)
            REP(j,m)
            { 
                cin>>A[i][j];
                ma[i][j]=2000000000;
                mi[i][j]=1;
            }
        bool noans=0;
        for(ll i=0;i<n;i++)
        {
            for(ll j=1;j<m;j++)
            {
                if(A[i][j]==-1)
                mi[i][j] = max(mi[i][j-1],A[i][j-1]);
                else if(A[i][j] < mi[i][j-1])
                {
                    noans=1;
                    break;
                }
            }
            for(ll j=m-2;j>=0;j--)
            {G
                if(A[i][j]==-1 and A[i][j+1]!=-1)
                    ma[i][j]=min(ma[i][j+1],A[i][j+1]);
                else if(A[i][j+1]==-1) ma[i][j]=ma[i][j+1];
                else if(A[i][j]>ma[i][j+1])
                {
                    noans=1;
                    break;
                }
            }
            if(noans) break;
        }
        for(ll j=0;j<m;j++)
        {
            for(ll i=1;i<n;i++)
            {
                if(A[i][j]==-1)
                {
                    mi[i][j] = max(max(mi[i-1][j],A[i-1][j]),mi[i][j]);
                }
                else if(A[i][j] < mi[i-1][j])
                {
                    noans=1;
                    break;
                }
            }
            for(ll i=n-2;i>=0;i--)
            {
                if(A[i][j]==-1 and A[i+1][j]!=-1)
                {
                    ma[i][j]=min(min(ma[i+1][j],A[i+1][j]),ma[i][j]);
                }
                else if(A[i+1][j]==-1)
                    ma[i][j]=ma[i+1][j];
                else if(A[i][j] > ma[i+1][j])
                {
                    noans=1;
                    break;
                }
            }
            if(noans) break;
        }
        if(noans)
            cout<<-1<<endl;
        else
        {
            for(ll i=0;i<n;i++)
            {
                for(ll j=0;j<m;j++)
                {
                    if(A[i][j]==-1)
                    {
                        cout<<mi[i][j]<<" ";
                    }
                    else cout<<A[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
	return 0;
}

