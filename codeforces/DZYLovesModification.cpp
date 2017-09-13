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

int A[1002][1002];
int rowsort[2000023]={0},colsort[2000023]={0};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,p;
	cin>>n>>m>>k>>p;
	int rows[1002]={0};
	int cols[1002]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>A[i][j];
			rows[i+1000000]+=A[i][j];
			cols[j+1000000]+=A[i][j];
		}
		
	}
	for(int i=0;i<n;i++)
	{
		rowsort[rows[i]]++;
		
	}
	for(int i=0;i<m;i++)
	{
		colsort[cols[i]]++;
	}
	sort(rows,rows+n);
	sort(cols,cols+m);
	int i=2000000;
	int ans=0;
	int rowsub=0,colsub=0;
	while(i-- && k)
	{
		while((rowsort[i] || colsort[i]) && k)
		{
			if(rowsort[i] && colsort[i])
			{
				if(i-rowsub>i-colsub)
				{
					ans+=(i-rowsub-1000000);
					colsub+=p;
					rowsort[i]--;
					rowsort[i-rowsub]++;
				}
				else
				{
					ans+=(i-colsub-1000000);
					rowsub+=p;
					colsort[i]--;
					colsort[i-colsub]++;
				}
			}
			else if(rowsort[i])
			{
				ans+=(i-rowsub);
                                colsub+=p;
                                rowsort[i]--;

			}
			else
			{
				ans+=(i-colsub);
                                rowsub+=p;
                                colsort[i]--;
			}
			k--;
			
			cout<<ans<<" "<<rowsub<<" "<<colsub<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}

