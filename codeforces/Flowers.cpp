#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define M 1000000007
#define all(V) V.begin(),V.end()

using namespace std;
ll A[100023]={0};
void func(ll k,ll tot)
{
	for(int i=1;i<=tot;i++)
	{
		if(i>=k)
		{
			A[i]=A[i-k]+1;
		}
		A[i]=A[i-1]+1+A[i];
		A[i]=A[i]%M;
		//cout<<A[i]<<" ";
	}
	//cout<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t,k;
	cin>>t>>k;
	func(k,100000);
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		cout<<(A[b]-A[a-1]+M)%M<<endl;
	}
	return 0;
}

