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
	int n,k;
	cin>>n>>k;
	int A[300023];
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
	}
	vi B(n+5,0);
	for(int i=1;i<=n;i++)
	{
		B[i]=B[i-1]+(1-A[i]);
	}
	int j=0,ans=0;
	int ansj=0,ansi=0;
	for(int i=1;i<=n;i++)
	{
	//	j=i;
		while(B[j]-B[i-1]<=k &&j<=n)
		{
			if(ans<j-(i-1))
			{
				ansj=j;
				ansi=i;
				ans=max(ans,j-(i-1));
			}
				j++;
		}
		if(j>n) j=n;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		if(i>=ansi && i<=ansj)
		{
			cout<<1;
		}
		else cout<<A[i];
		if(i!=n) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
