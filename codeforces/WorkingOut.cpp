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
ll tl[1002][1002]={0},tr[1002][1002]={0},bl[1002][1002]={0},br[1002][1002]={0};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//ll tl[1002][1002]={0},tr[1002][1002]={0},bl[1002][1002]={0},br[1002][1002]={0};
	//cout<<"abc"<<endl;
	/*
	starts from :
	Top Left tl
	Top Right tr
	Bottom Left bl
	Bottom Right br
	To the opposite corner
	*/
	ll n,m;
	cin>>n>>m;
	ll A[1002][1002]={0};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cin>>A[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			tl[i][j]=max(tl[i-1][j],tl[i][j-1])+A[i][j];
		}
	}
	for(int i=1;i<=n;i++)
        {
                for(int j=m;j>=1;j--)
                {
                        tr[i][j]=max(tr[i-1][j],tr[i][j+1])+A[i][j];
                }
        }
	for(int i=n;i>=1;i--)
        {
                for(int j=1;j<=m;j++)
                {
                        bl[i][j]=max(bl[i+1][j],bl[i][j-1])+A[i][j];
                }
        }
	for(int i=n;i>=1;i--)
        {
                for(int j=m;j>=1;j--)
                {
                        br[i][j]=max(br[i+1][j],br[i][j+1])+A[i][j];
                }
        }
	ll ans=0;
	for(int i=2;i<=n-1;i++)
	{
		for(int j=2;j<=m-1;j++)
		{
			ll a1=bl[i][j-1]+tl[i-1][j]+tr[i][j+1]+br[i+1][j];
			ll a2=bl[i+1][j]+tl[i][j-1]+tr[i-1][j]+br[i][j+1];
			ans=max(ans,max(a1,a2));
			//cout<<max(a1,a2)<<" ";
		}
		//cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

