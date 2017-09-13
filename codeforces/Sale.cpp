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
	int ans=0;
	int A[1000]={0};
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	sort(A,A+n);
	for(int i=0;i<m;i++)
	{
		if(A[i]>0) break;
		if(A[i]==0) continue;
		ans+=A[i];
	}
	cout<<abs(ans)<<endl;
	return 0;
}

