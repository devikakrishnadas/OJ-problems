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
	int n,x;
	cin>>n>>x;
	int t;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		sum+=t;
	}
	sum=abs(sum);
	int ans=0;
	if(sum%x!=0) ans++;
	ans=ans+sum/x;
	cout<<ans<<endl;
	return 0;
}

