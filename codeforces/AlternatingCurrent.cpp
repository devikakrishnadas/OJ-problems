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
	string s;
	cin>>s;
	int n=s.length();
	if(n%2)
	{
		cout<<"No"<<endl;
		return 0;
	}
	int cnt=1;
	int prev=-1,cur=0;
	vi a(n,-1);
	for(int i=0;i<n;i+=2)
	{
		if(s[i]=='+') a[i]=1;
		else a[i]=0;
	}
	for(int i=1;i<n;i+=2)
	{
		if(s[i]=='+')
			a[i]=0;
		else a[i]=1;
	}
	stack<int>bef,af;
	for(int i=0;i<n;i++)
	{
		bef.push(a[i]);
	}
	while(!bef.empty())
	{
		int t=bef.top();
                bef.pop();
                af.push(t);
		while(!bef.empty() && !af.empty())
		{
			if(af.top()==1-bef.top())
			{
				af.pop();
				bef.pop();
			}
			else break;
		}
	}
	if(af.size()==0)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}

