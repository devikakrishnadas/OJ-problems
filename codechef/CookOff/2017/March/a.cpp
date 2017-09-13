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
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		string s;
		cin>>s;
		int mu=0,ml=0,mr=0,md=0;
		int x=0,y=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='L')
			{
				x--;
			}
			else if(s[i]=='R')
			{
				x++;
			}
			else if(s[i]=='U')
			{
				y++;
			}
			else y--;
			if(x<0)
			{
				ml=max(ml,abs(x));
			}
			else mr=max(mr,x);
			if(y<0)
			{
				md=max(md,abs(y));
			}
			else mu=max(mu,y);
		}
		x=mr+ml+1;
		y=mu+md+1;
//		cout<<x<<" "<<y<<"="<<n<<" "<<m<<endl;
		if(x>m || y>n)
		{
			cout<<"unsafe"<<endl;
		}
		else cout<<"safe"<<endl;
	}
	return 0;
}

