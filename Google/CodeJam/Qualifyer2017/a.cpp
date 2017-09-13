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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		int k;
		cin>>s>>k;
		vi a;
		int ans=0;
		if(s[0]=='-') a.pb(0);
		int cnt=1;
		for(int i=1;i<s.length();i++)
		{
			if(a[i]!=a[i-1])
			{
				a.pb(cnt);
				cnt=1;
			}
			else cnt++;
		}
		a.pb(cnt);
		for(int i=1;i<a.length();i+=2)
		{	
			ans=ans+a[i]/k;
			a[i]=a[i]%k;
			
		}
		
	}
	return 0;
}

