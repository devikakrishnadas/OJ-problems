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
	int A[101]={0};
	int B[101]={0};
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
		B[i]=1-A[i];
		if(i)
		{
			A[i]=A[i]+A[i-1];
			B[i]=B[i]+B[i-1];
		}
//		cout<<B[i]<<" ";
		
	}
//	cout<<endl;
	int  ans=0;
//	cout<<A[n]<<endl;	
	for(int i=1;i<=n;i++)
	{
		
		for(int j=i;j<=n;j++)
		{
			int val=A[i-1]+(B[j]-B[i-1])+(A[n]-A[j]);
			//cout<<val<<endl;
			ans=max(ans,val);
		}
	}
//	cout<<ans<<endl;
	if(ans==A[n])
	{
		ans=abs(ans-1);
	}
	cout<<ans<<endl;
	return 0;
}

