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
	int T;
	cin>>T;
	while(T--)
	{
		int A[10000]={0};
		int n;
		cin>>n;
		//int diff;
		//int x;
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		}
		ll ans=1;
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(A[j]==9)
				{
					goto a;
				}
				else
				{
					ans=ans+1;
				}
			}
		}
		a:cout<<ans<<endl;
	}

	return 0;
}

