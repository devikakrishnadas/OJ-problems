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

/*int k[4][10000001]={0};
int v[5]={0,1,2,5};
int knap()
{
    for(int i=1;i<=10000000;i++)
    {
        k[1][i]=i;
    }
    for(int i=2;i<=3;i++)
    {
        for(int j=1;j<=10000000;j++)
        {
            a[i][j]=min(a[i-1][j],(j/v[i])+a[i-1][j%v[i]]);
        }
    }
}*/
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
        int mi=INT_MAX;
        vi a(n,0),b(n,0),c(n,0),d(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mi=min(mi,a[i]);
        }
        cout<<"done"<<endl;
        ll ans1=0;
        
        for(int i=0;i<=1000;i++)
        {
            ll tans=0;
            if(mi-i<0)
                break;
            for(int j=0;j<n;j++)
            {
                ll t=a[j]-i;
                tans+=(t/5 + (t%5)/2 + (t%5)%2 );
            }
            if(i)
                ans1=min(ans1,tans);
            else ans1=tans;
        }
        cout<<ans1<<endl;
    }
	return 0;
}

