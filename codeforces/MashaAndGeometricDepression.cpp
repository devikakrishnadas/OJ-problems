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
	ll b,q,l,m;
	cin>>b>>q>>l>>m;
	vll a(m);
	map<ll,ll>t,bad;
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
		bad[a[i]]=1;
	}
	ll pp=1;
	int tot=0;
	vll val;
	bool enter=0;
	for(int i=0;i<1000000;i++)
	{
		if(abs(pp*b)<=l)
			t[pp*b]++;
		else break;
		
		if(t[pp*b]==2 )
		{
			
			enter=1;
			t[pp*b]=1;
			break;
		}
		else if(t[pp*b]==1)
		{
			tot++;
			val.pb(pp*b);
			//enter=1;
		}
		//cout<<pp<<endl;
		pp=pp*q;
	
	}
	for(int i=0;i<m;i++)
	{
		if(t[a[i]]==1)
		{
			t[a[i]]=0;
			tot--;
		}
	}
	if(tot==0)
	{
		cout<<0<<endl;
	}
	else if(!enter)
	{
		cout<<tot<<endl;
	}
	else
	{
		//cout<<t[q]<<endl;
		if(q==0 && b!=0)
		{
			if(t[q]==0) 
			{
				cout<<1<<endl; 
				return 0;
			}
		}
		cout<<"inf"<<endl;
	}
	return 0;
}

