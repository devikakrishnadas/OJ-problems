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
	vi A(200023,0);
	int n;
	cin>>n;
	ll cnt=0;
	int x;
	ll ans=0;
	for(int i=0;i<2*n;i++)
	{
		cin>>x;
		if(A[x])
		{
			A[x]=0;
			cnt--;
		}
		else
		{	
			A[x]=1;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}

