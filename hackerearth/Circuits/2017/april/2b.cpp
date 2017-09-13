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

int gru[2048576]={0};

int findval(int a[30],int n,int m)
{
	int val=1;
	int ans=0;
	for(int i=0;i<n*m;i++)
	{
		if(a[i]) ans+=val;
		val=val*2;
	}
	return ans;
}
void findvalarr(int a,int bits[30])
{
	int j=0;
	while(a)
	{
		bits[j]=a%2;
		a=a/2;
		j++;
	}
}
int func(int a[30],int n,int m)
{
	vi xorg;
	for(int i=0;i<n*m;i++)
	{
		if(a[i])
		{
			if(i-m>0 && a[i-m])
			{
				a[i]=0;
				int t1=findval(a,n,m);
				int t=gru[t1];
				//cout<<"*"<<t<<"*"<<t1<<"&"<<endl;
				xorg.pb(t);
				a[i]=1;
			}
			else if(i+m<n*m && a[i+m])
			{
				a[i]=0;
				int t1=findval(a,n,m);
				int t=gru[t1];
				//cout<<"*"<<t<<"*"<<t1<<"&"<<endl;
                                xorg.pb(t);
				a[i]=1;
			}
			else if(i%m!=m-1 && a[i+1])
			{
				a[i]=0;
                                int t1=findval(a,n,m);
                                int t=gru[t1];
				//cout<<"*"<<t<<"*"<<t1<<"&"<<endl;
                                xorg.pb(t);
                                a[i]=1;
			}
			else if(i%m!=0 && a[i-1])
			{
				a[i]=0;
                                int t1=findval(a,n,m);
                                int t=gru[t1];
				//cout<<"*"<<t<<"*"<<t1<<"&"<<endl;
                                xorg.pb(t);
                                a[i]=1;
			}
		}
	}
	if(xorg.size()==0) return 0;
	sort(all(xorg));
	int g=0;
	for(int i=0;i<xorg.size();i++)
	{
		if(xorg[i]==g) g++;
		else if(xorg[i]>g) return g;	
	}
	return g;
}

void findGrundy(int n,int m)
{
	int l=pow(2,n*m);
	for(int i=1;i<l;i++)
	{
		int bits[30]={0};
		findvalarr(i,bits);
		gru[i]=func(bits,n,m);
		
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	findGrundy(n,m);
//	cout<<gru[59]<<" "<<gru[55]<<endl;
	while(q--)
	{
		int a[20];
		char b;
		int k=0;
		for(int i=0;i<n;i++)
		{
			
			for(int j=0;j<m;j++)
			{
				cin>>b;
				if(b=='0') a[k]=1;
				else a[k]=0;
				k++;
			}
		}
		cout<<(gru[findval(a,n,m)]>0 ? 0 : 1)<<endl;
	}
	return 0;
}

