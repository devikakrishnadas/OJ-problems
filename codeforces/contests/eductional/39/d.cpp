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

const int maxx=510;
int dp[maxx][maxx]={0}, mn[maxx][maxx]={0};
int n,m,k;
vector<string>a(maxx);

int find_hours(int day,int hours)
{
    int j=0;
    int sum=0;
    int ans = INT_MAX;
    for(int i=0;i<=m;i++)
    {
        //if(a[day][i]=='1')
        
            j = max(i,j);
            while(sum < hours and j<m)
            {
                //cout<<"i :"<<i<<" sum : "<<sum<<" hours : "<<hours<<endl;
                if(a[day][j] == '1')
                {
                    sum++;
                    //cout<<"update sum"<<endl;
                }
                j++;
            }
        
        if(sum == hours)
        {
            ans = min(ans,j-i);
        }
        if(a[day][i]=='1')
            sum--;
    }
    return ans;
}
void precalc()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            mn[i][j] = find_hours(i,j+1);
            cout<<mn[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m>>k;
    REP(i,n)
    {
        cin>>a[i];
    }
    precalc();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                for(int l=0;j+l<m;l++)
                {
                    dp[i+1][j+l] += dp[i][j] + mn[i][l];
                    cout<<mn[i][l]<<" "<<i<<" "<<l<<endl;
                }
            }
        }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"ans "<<dp[n-1][k]<<endl;
	return 0;
}

