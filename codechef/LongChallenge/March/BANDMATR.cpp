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
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		int A[505][505];
		int z=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>A[i][j];
				if(!A[i][j])
					z++;
			}
		}
		int tot=n*n-n;
		int ans=-1;
		for(int i=0;i<n;i++)
		{
			if(z>=tot)
			{
				ans=i;
				break;
			}
			tot=tot-2*(n-i-1);
		}
		if(ans==-1)
			cout<<n-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}

