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
		map<string,int>A;
		string s;
		for(int i=0;i<8;i++)
		{
			cin>>s;
			A[s]++;
		}
		map<string,int>::iterator it;
		int cnt=0;
		for( it=A.begin();it!=A.end();it++)
		{
			if((it->second)>1) cnt++;
		}
		if(cnt>1)
		{
			cout<<"similar"<<endl;
		}
		else
		{
			cout<<"dissimilar"<<endl;
		}
	}
	return 0;
}

