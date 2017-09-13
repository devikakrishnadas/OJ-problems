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


bool substExist(int m,string a,string &b,vi &c)
{
	for(int i=0;i<m;i++)	
	{
		a[c[i]]='0';
	}
	int j=0;
	int i=0;

	for(i=0;i<b.length();i++)
	{
		while(b[i]!=a[j] && j<a.length())
		{
			j++;
		}
		if(j==a.length()) break;
		j++;
	}
	if(i==b.length())
	{
		return 1;
	}
	return 0;
}
int bs(string &a,string &b,vi &c)
{
	int s=1;
	int e=a.length();
	int ans=0;
	while(s<=e)
	{
		int m=(s+e)/2;
		//cout<<m<<endl;
		if(substExist(m,a,b,c))
		{
			//cout<<m<<endl;
			ans=m;
			s=m+1;
		}
		else e=m-1;
	}
	return ans;
}
	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b;
	cin>>a>>b;
	vi c(a.length()+1);
	for(int i=0;i<a.length();i++)
	{
		cin>>c[i];
		c[i]--;
	}
	cout<<bs(a,b,c)<<endl;
	return 0;
}

