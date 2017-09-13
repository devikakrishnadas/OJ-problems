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
	//vi a;
	int x,ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		ans= ans + x/k;
		if(x%k) ans++;
	}
	ans=ans/2 + ans%2;
	cout<<ans<<endl;
	
	return 0;
}

