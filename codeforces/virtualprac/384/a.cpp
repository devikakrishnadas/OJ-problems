#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,a,b;
	string s;
	cin>>n>>a>>b;
	cin>>s;
	if(s[a-1]==s[b-1])
	{
		cout<<0<<endl;
	}
	else
	{
		cout<<1<<endl;
	}
	return 0;
}

