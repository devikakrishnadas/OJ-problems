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

void bs(int s,int e,int &val,bool x,int y)
{
	if(s>=e)
	{
		//if(enter)
		{
			val=s-1;
			return;
		}
		//enter=1;
	}
	
	int m=(s+e)/2;
	//cout<<"*"<<s<<" "<<e<<" "<<m<<endl;
	if(!x)
	cout<<"? "<<y<<" "<<m<<endl;
	else
	cout<<"? "<<m<<" "<<y<<endl;
	fflush(stdout);
	cin>>A;
	if(strcmp(A,"NO")==0)
	{
		bs(s,m,val,x,y);
	}
	else bs(m+1,e,val,x,y);
}

void check(double m,
int bs(double l,double e,vi x, vi v,int val)
{
	if(l>=e)
	{
		val=l-1;
	}
	double m=((s+e)*1.0)/2;
	check(m,x,v);
}
int main()
{
	int n;
	cin>>n;
	vi x(n),v(n);
	
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	bs(0,DBL_MAX,x,v);
	return 0;
}

