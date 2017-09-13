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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int a,n;
		cin>>a>>n;
		int lose=0;
		for(int i=0;i<n;i++)
		{
			int x;
			if(a<=0 && !lose) lose=i;
			
			cin>>x;
			if(x==1)
			{
				a=a+2;
			}
			else a=a-1;
		}
		if(lose)
		{
			cout<<"No "<<lose<<endl;
		}
		else
		{
			cout<<"Yes "<<a<<endl;
		}
	}
	return 0;
}

