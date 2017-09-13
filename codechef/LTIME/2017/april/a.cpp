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
	int t;	
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int cnt=0;
		bool enter=0;
		bool oneEnd=0;
		bool no=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='1')
			{
				cnt++;
				if(!enter)
					enter=1;
				if(oneEnd)
				{
					no=1;
				}
			}
			else if(enter)
			{
				oneEnd=1;
			}
		}
		if(no)
		{
			cout<<"NO"<<endl;
		}
		else if(!enter)
		{
			cout<<"NO"<<endl;
		}
		else cout<<"YES"<<endl;
	}
	return 0;
}

