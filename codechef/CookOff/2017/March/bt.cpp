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
		for(int i=0;i<n;i++)
		{
			vi temp(2501,0);
			for(int j=0;j<n;j++)
			{
				cin>>A[i][j];
//				cout<<temp[A[i][j]]<<"*"<<endl;
				if(!temp[A[i][j]] && A[i][j]!=0)
				{
					color[i]++;
				}
				temp[A[i][j]]++;
			}
		//	cout<<"+"<<color[i]<<endl;
		}
		bool enter=1;
		//cout<<color[1]<<endl;
		while(enter)
		{
			enter=0;
			for(int i=0;i<n;i++)
			{
				if(color[i]==1)
				{
					//cout<<i<<endl;
					
					enter=1;
					for(int j=0;j<n;j++)
						color[j]--;
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
