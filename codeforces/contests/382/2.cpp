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
	int  n,n1,n2;
	cin>>n>>n1>>n2;
	int  A[100023];
	for(int i=0;i<n;i++)
		cin>>A[i];
	sort(A,A+n);
	reverse(A,A+n);
	double ans=0,ans1=0;
	if(n1>n2)
		swap(n1,n2);
	for(int i=0;i<n1;i++)
	{
		ans+=((1.0*A[i])/(1.0*n1));
	}
	
	//ans=(1.0*ans)/(1.0*n1);
	
	//cout<<ans<<" "<<min(n1,n2)<<endl;
	for(int i=n1;i<n1+n2;i++)
	{
	//	cout<<A[i]<<"-"<<i<<" ";
		ans1+=((1.0*A[i])/(1.0*n2));
	}
//	cout<<endl;
	//cout<<ans1<<endl;
	//ans1=(1.0*ans1)/(1.0*n2);
	//cout<<ans1<<endl;
//	pf("%.6f %.6f\n",ans,ans1);
	printf("%.6f\n",ans+ans1);
	return 0;
}

