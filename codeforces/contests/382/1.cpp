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
	char A[300];
	cin>>A;
	int gp,tp;
	for(int i=0;i<n;i++)
	{
		if(A[i]=='G')
			gp=i;
		if(A[i]=='T')
			tp=i;
	}
//	cout<<gp<<" "<<tp<<endl;	
	for(int i=min(gp,tp);i<=max(gp,tp);i+=k)
	{
		if(A[i]=='#')
		{
			cout<<"NO"<<endl;
			return 0;
		}
		if(i==max(gp,tp))
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}

