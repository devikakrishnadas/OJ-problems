#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;
int ans=0;
int dp[1023][1023]={0};
int n;
int dp1[1023][1023]={0};
void func(int s,int e)
{
	if(s==e)
	{
		ans++;
		return;
	}
	else
	{
		for(int i=n;i>=0;i++)
		{
			if(dp[s][s+i]>=0)
			{
				func(s+i+1,e);
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	char A[1023];
	cin>>A;
	vi al(30,0);
	for(int i=0;i<26;i++)
	{
		cin>>al[i];
	}
	
	for(int l=0;l<n;l++)
	{
		for(int i=0,j=l;i<n-l;i++,j++)
		{
			if(l==0)
			{
				dp[i][j]=A[i]-1;
			}
			else
			{
				dp[i][j]=min(dp[i][j-1],dp[i+1][j])-1;
			}
		}
	}
	for(int l=0;l<n;l++)
        {
                for(int i=0,j=l;i<n-l;i++,j++)
                {
                        if(l==0)
                        {
                                dp[i][j]=0;
                        }
			else if(l==1)
			{
				dp[i][j]=1;
			}
                        else
                        {
				if(dp[i][j]>=0)
				{
					dp[i][j]=pow(2,j-i+1);
				}
				else
                                dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i-1][j-1];
                        }
                }
        }
	cout<<dp[n-1][0]<<endl;
	return 0;
}

