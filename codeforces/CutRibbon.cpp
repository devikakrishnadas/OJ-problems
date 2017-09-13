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
int a,b,c,n;
int main()
{
	cin>>n>>a>>b>>c;
	int cnt=0;
	for(int i=0;i<=4000;i++)
	{
		for(int j=0;j<=4000;j++)
		{
			int ans=n-i*a-j*b;
			if(ans<0) continue;
			if(ans%c==0)
			{
				cnt=max(cnt,i+j+(ans/c));
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}

