#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int main()
{
	int A[][5]={{0,0,0,0},{1,0,0,0},{2,0,0,0},{3,0,0,0},{2,3,2,0},{5,0,0,0},{3,5,0,0},{7,0,0,0},{7,2,2,2},{7,3,3,2},{7,5,2,1}};
	int n;
	cin>>n;
	string s;
	cin>>s;
	vi ans;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
		{
			ans.pb(A[s[i]-'0'][j]);
		}
	}
	sort(all(ans));
	reverse(all(ans));
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i]>1)
			cout<<ans[i];
	}
	cout<<endl;
	return 0;
}

