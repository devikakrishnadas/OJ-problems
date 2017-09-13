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
	/*ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/
	int n;
	cin>>n;
	double A[100023]={0};
	
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	if(n==1)
	{
		cout<<setprecision(9)<<fixed<<A[0]<<endl;
		return 0;
	}
	
	sort(A,A+n);
	double ans[100023]={0};
	for(int l=0;l<n;l++)
	{
		double val;
		for(int i=l;i<n;i++)
		{
			val=A[i];
			for(int j=l;j<n;j++)
			{
				if(i==j)
					continue;
				val=val*(1.000000000-A[j]);
			}
			ans[l]+=val;
		}
	}
	sort(ans,ans+n);
	cout<<setprecision(12)<<fixed;
	cout<<ans[n-1]<<endl;
	return 0;
}

