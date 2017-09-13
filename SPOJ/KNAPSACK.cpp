#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int dp[50][2000001]={0};
int main()
{
	vector<pair<int,int> >A,item;
        int n;
        int val,wt;
        //cin>>n;
        int totwt;
        //totwt=200002;
        cin>>n;
        for(int i=0;i<n;i++)
        {
                cin>>wt>>val;
		totwt+=
                A.pb(mp(wt,val));
        }
 //       int dp[2000][2000]={0};
        sort(all(A));
        for(int i=0;i<=totwt;i++)
        {
                if(i<A[0].first)
                {
                        dp[0][i]=0;
                }
                else
                {
                        dp[0][i]=A[0].second;
                }
        }
        for(int i=1;i<n;i++)
        {
                for(int j=1;j<=totwt;j++)
                {
                        if(j<A[i].first)
                        {
				if(i%2)
                                dp[i%2][j]=dp[(i-1)%2][j];
				else dp[i%2][j]=dp[(i+1)%2][j];
                        }
                        else
                        {
				if(i%2)
                                dp[i%2][j]=max(A[i].second+dp[(i-1)%2][j-A[i].first],dp[(i-1)%2][j]);
				else
				dp[i%2][j]=max(A[i].second+dp[(i+1)%2][j-A[i].first],dp[(i+1)%2][j]);
                        }
                }
        }
        for(int i=1;i<=totwt;i++)
	{
	}

	return 0;
}

