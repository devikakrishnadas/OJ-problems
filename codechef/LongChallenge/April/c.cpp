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
		int n=s.length();
		ll cnt=0;
		ll ans=0;
		ll pos=0;
		bool changecnt=0;
		bool enter=0;
		ll ppo=n-1;
		if(s[n-1]=='1') {pos=1;}
		for(int i=n-2;i>=0;i--)
		{
			if(s[i]==s[i+1])
			{
				if(s[i]=='1')
				{
					pos++;
				}
			}
			else { ppo=i;break;}
		}
		//cout<<ppo<<endl;
		for(int i=ppo;i>=0;i--)
		{
			if(s[i]=='1')
			{
				enter=1;
				
				if(n-1-pos-i > 0)
				{
					if(changecnt)
					{
						changecnt=0;
						cnt++;
					}
					ans=ans+(n-1-pos)-i+1+cnt;
				}
				//cout<<ans<<endl;
				pos++;
			}
			else if(enter) changecnt=1;
			
		}
		cout<<ans<<endl;
	}
	return 0;
}

