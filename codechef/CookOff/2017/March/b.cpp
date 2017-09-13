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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;	
	cin>>t;
	while(t--)
	{
		int A[51][51]={0};
		int n;
		cin>>n;
		int cnt=n;
		vi color(n,0);	
		int col[51][2501]={0};
		for(int i=0;i<n;i++)
		{
			vi temp(2501,0);
			for(int j=0;j<n;j++)
			{
				cin>>A[i][j];
				if(!temp[A[i][j]] && A[i][j])
				{
					color[i]++;
					
				}
				
				col[i][A[i][j]]++;
				temp[A[i][j]]++;
			}
		}
		bool enter=1;
		while(enter)
		{
			enter=0;
			for(int i=0;i<n;i++)
			{
				if(color[i]==1)
				{
					color[i]=0;
					int remcolor=0;
					for(int j=0;j<n;j++)
					{
						if(A[i][j])
						{
							remcolor=A[i][j];
							
						}
						A[i][j]=A[j][i]=0;
					}
					col[i][remcolor]=0;
					for(int j=0;j<n;j++)
					{
						col[j][remcolor]--;
						if(col[j][remcolor]==0)
						{
							if(color[j]>1) color[j]--;
						}
					}
				}
			}
		}
		cnt=0;
		for(int i=0;i<n;i++)
		{
			if(color[i]>1)
				cnt++;
		}
		if(cnt<=2) cnt=0;
		cout<<cnt<<endl;
	}
	return 0;
}

