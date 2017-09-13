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
	int n;
	int A[200];
	cin>>n;
	int o=0,e=0;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		if(A[i]%2)
			o++;
		else e++;
		sum+=A[i];
	}	
	int ans=0;
	if(sum%2)
	{
		ans=o;
		
	}
	else ans=e;
	cout<<ans<<endl;
	return 0;
}

