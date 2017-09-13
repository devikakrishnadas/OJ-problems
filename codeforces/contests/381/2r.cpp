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
	int n,m;
	cin>>n>>m;
	int A[200];
	int M[500]={0};
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	int a,b;
	int ans=0;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		a--;
		b--;
		int anst=0;
		for(int j=a;j<=b;j++)
		{
			anst=anst+A[j];
		}
		
		ans=max(ans,ans+anst);
	}
//	map<int,int>::iterator it=M.begin();
	
	cout<<ans<<endl;
	return 0;
}

