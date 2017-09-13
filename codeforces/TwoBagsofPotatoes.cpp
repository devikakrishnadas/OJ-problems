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
	ll y,k,n;
	cin>>y>>k>>n;
	if(y==n)
	{
		cout<<-1<<endl;
		return 0;
	}
	int a=n-n%k;
	vi ans;
	while(a>y)
	{
		ans.pb(a-y);
		a=a-k;
	}
	for(int i=ans.size()-1;i>=0;i--)
	{
		cout<<ans[i];
		if(i!=0) cout<<" ";
		else cout<<endl;
	}
	if(ans.size()==0) cout<<-1<<endl;
	return 0;
}

