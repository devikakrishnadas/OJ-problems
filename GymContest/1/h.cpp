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
    int cnt=0;
    while(t--)
    {
        cnt++;
        int n,m;
        cin>>n>>m;
        int A[1001][1001]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>A[i][j];
            }
        }
        for(int j=1;j<m;j++)
        {
            A[0][j]+=A[0][j-1];
        }
        for(int i=1;i<n;i++)
        {
            A[i][0]+=A[i-1][0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                A[i][j]+=max(A[i-1][j],A[i][j-1]);
            }
        }
        cout<<"Case "<<cnt<<": "<<A[n-1][m-1]<<endl;
    }
	return 0;
}

