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
	int t;
	cin>>t;
	while(t--)
	{
		string a;
		cin>>a;
		bool no=0;
		bool c=0,e=0,s=0;
		for(int i=0;i<a.length();i++)
		{
			if(a[i]=='C' && (e==1 or s==1))
			{
				no=1;
				break;
			}
			else if(a[i]=='E' && s==1)
			{
				no=1;
				break;
			}
			if(a[i]=='C') c=1;
			else if(a[i]=='E') e=1;
			else if(a[i]=='S') s=1;
		}
		if(no) cout<<"no"<<endl;
		else cout<<"yes"<<endl;
	}
	
	return 0;
}

