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
	
	//pair<string,string>m,t;
	int n;
	vector<pair<char*,char*> >ans;
	char a[2000],b[2000],ma[2000],mb[2000];
	cin>>ma>>mb;
	//m.mp(a,b);
	cin>>n;
	//cout<<a<<" "<<b<<endl;
	ans.pb(mp(ma,mb));
	cout<<ma<<" "<<mb<<endl;
	while(n--)
	{
		cin>>a>>b;
		if(strcmp(a,ma)==0)
		{
			strcpy(ma,b);
		}
		else strcpy(mb,b);
		ans.pb(mp(ma,mb));
		cout<<ma<<" "<<mb<<endl;
	}
//	cout<<ans[0].first<<" "<<ans[0].second<<endl;
//	for(int i=0;i<ans.size();i++)
//	{
	//	cout<<ans[0].first<<" "<<ans[0].second<<endl;	
//	}i
	return 0;
}

