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
	int n;
	cin>>n;
	int weights[1000];
	for(int i=0;i<n;i++)
		cin>>weights[i];
	int k;
	cin>>k;
	int afterw[1000];
	for(int i=0;i<k;i++)
	{
		cin>>afterw[i];
	}
	int i1=0;
	int i2=0;
	vi l[1000];
	bool no=0;
	for(i1=0;i1<k ;i1++)
	{
		int sum=weights[i2];
		while(sum<afterw[i1] && i2<n)
		{
			l[i1].pb(i2);
			i2++;
			sum=sum+weights[i2];
			if(i2==n) break;	
		}
		if(sum>afterw[i1])
		{
			no=1;
			break;
		}
	
	//	l[i1].pb(-1);
		l[i1].pb(i2);
		i2++;
		sum=0;
		if(i1==k-1 && i2==n-1) break;

	}
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<l[i].size();j++)
		{
			cout<<l[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<i1<<" "<<i2<<endl;
	if(i2!=n || i1!=k || no)
	{
		if(i2!=n-1) cout<<"AAA"<<endl;
		if(i1!=k-1) cout<<"KKK"<<endl;
		if(no)	cout<<"NO"<<endl;
		cout<<"NO"<<endl;
		return 0;
	}
	else cout<<"YES"<<endl;
	int m=0,mi=-1;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<l[i].size();j++)
		{
			if(m>weights[l[i][j]])
			{
				m=weights[l[i][j]];
				mi=j;
			}
		//	cout<<l[i][j]<<" ";
		}
		//cout<<endl;
		for(int j=mi;j>=0;j--)
		{
			cout<<l[i][j]+1<<" "<<'L'<<endl;
		}
		for(int j=mi+1;j<l[i].size();j++)
		{
			cout<<1<<" "<<'R'<<endl;
		}
	}
	return 0;
}

