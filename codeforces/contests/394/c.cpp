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
	int n,m;
	cin>>n>>m;
	vector<vector<char> >A(n);
	char x;
	vector<pair<int,int> >ch,sp,num;
	char t[100023];
	for(int i=0;i<n;i++)
	{
		cin>>t;
		for(int j=0;j<m;j++)
		{
			x=t[j];
			A[i].pb(x);
			if(x=='#' || x=='*' || x=='&')
			{
				sp.pb(mp(min(j,m-j),i));
			}
			else if(x>='a' && x<='z')
			{
//				if(i==1 && j==0)
//					cout<<"ABFC"<<endl;

				ch.pb(mp(min(j,m-j),i));
			}
			else
			{
				num.pb(mp(min(j,m-j),i));
			}
		}
	}
	sort(ch.begin(),ch.end());
	sort(sp.begin(),sp.end());
	sort(num.begin(),num.end());
	int ans=INT_MAX;
//	for(int i=0;i<ch.size();i++)
//	{
//		cout<<ch[i].first<<" ";
//	}
//	cout<<endl;
	for(int i=0;i<ch.size();i++)
	{
		for(int j=0;j<sp.size();j++)
		{
			for(int k=0;k<num.size();k++)
			{
//				if(ch[i]==0 && sp[j]==0)
				{
//					cout<<ch[i].first<<" "<<ch
				}
//				if(ch[i].first==0 && num[j].first==0)
//				{
//					cout<<ch[i].first<<" "<<sp[j].first<<" "<<num[k].first<<endl;
//					cout<<"**"<<ch[i].second<<" "<<sp[j].second<<" "<<num[k].second<<endl;
//				}
				if(ch[i].second!=sp[j].second && ch[i].second!=num[k].second && num[k].second!=sp[j].second)
				{
					
//					cout<<ch[i].first<<" "<<sp[j].first<<" "<<num[k].first<<endl;
					ans=min(ans,ch[i].first+sp[j].first+num[k].first);
//					cout<<ans<<endl;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

