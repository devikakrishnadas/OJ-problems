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
		int n;
		cin>>n;
		int x;
		vector<vector<int> >fact(100023);
		int B[100023]={0};
		vi A;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			B[x]++;
			A.pb(x);
			for(int j=1;j<=sqrt(x);j++)
			{
				if(x%j==0)
					fact[j].pb(x);
				if(j!=(x/j))
				{
					fact[x/j].pb(x);
				}
			}
		}
		int ma=0;
		for(int i=2;i<=100000;i++)
		{
//			cout<<i<<" "<<fact[i].size()<<endl;	
			if(B[i])
				ma=max(ma,(int)fact[i].size());
		}
//		cout<<ma<<endl;
		if(ma==n)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
