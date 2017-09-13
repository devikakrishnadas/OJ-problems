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

int func(string a)
{
	int k=0;
	int re=1;
	for(int i=1;i<a.length();i++)
	{
		if(a[i]==a[0])
		{
			bool enter =0;
			for(int j=1;j<re;j++)
			{
				if(a[i+j]!=a[j])
				{
					re=i+j;
					enter=1;
					break;
				}
			}
			if(!enter)
				i=i+re-1;
		}
		else
		{
			re=i+1;
			k=0;
		}
		//cout<<re<<endl;
	}
	return re;
}

int factors(int a)
{
	int cnt=0;
	for(int i=1;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			cnt++;
			if(i!=(a/i))
			{
				cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b;
	cin>>a>>b;
	int mina=func(a);
//	cout<<endl<<endl;
	int minb=func(b);
	if(mina!=minb)
	{
		cout<<0<<endl;
		return 0;
	}
//	cout<<mina<<" "<<minb<<endl;
	{
		for(int i=0;i<mina;i++)
		{
			if(a[i]!=b[i])
			{
				cout<<0<<endl;
				return 0;
			}
		}
		mina=a.length()/mina;
		minb=b.length()/minb;
		int ans=__gcd(mina,minb);
		
		cout<<factors(ans)<<endl;
	}
	
	return 0;
}

