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
	vi A;
	int x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		A.pb(x);
	}
	if(n<=2)
	{
		cout<<n<<endl;
		return 0;
	}
	int f=A[0],s=A[1];
	int l=2;
	int ans=2;
	for(int i=2;i<n;i++)
	{
		if(A[i]==f+s)
		{
			l++;
			ans=max(ans,l);
		}
		else l=2;
		f=s;
		s=A[i];
	}
	cout<<ans<<endl;
	return 0;
}

