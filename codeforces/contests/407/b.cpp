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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll b,q,l,m;
	int zzzzz,zz;
	cin>>b>>q>>l>>m;
	vll a(m);
	for(int i=0;i<m;i++) cin>>a[i];
	bool neg=0;
	if(b<0) neg=1;
	b=abs(b);
	if(abs(b)>l)
	{
		cout<<0<<endl;
	}
	else if(((b==0||q==0) && l!=0 ) ||(q==1 && l!=b))
	{
		if((b==0 || q==0) && l!=0)
		{
			for(int i=0;i<m;i++) 
			{
				if(a[i]==0) 
				{
					if(l>=abs(b) && b!=0)
					{
						for(int kk=0;kk<m;kk++) if(a[kk]==b){ cout<<0<<endl; return 0;}
						
						cout<<1<<endl;
					}
					else
						cout<<0<<endl; 
					return 0;
				}
			}
			cout<<"inf"<<endl;
			return 0;
		}
		else if((q==1 && l!=b))
		{
			if(neg)
                        b=-1*b;
			if(l<abs(b)) cout<<0<<endl;
			else
			{for(int i=0;i<m;i++) 
			{
				if(a[i]==b && l>=abs(b)) 
				{
					cout<<0<<endl; 
					return 0;
				}
			}
			cout<<"inf"<<endl;}
			b=abs(b);
		}
	}
	else if((b==0 || q==0) && l==0)
	{
		if(neg)
                        b=-1*b;
		if(abs(b)<l)
			cout<<0<<endl;
		for(int i=0;i<m;i++) 
		{
			if(a[i]==0) 
			{
				if(abs(b)>l || b==0)
					cout<<0<<endl;
				else if(q==0) 
				{		
					for(int kk=0;kk<m;kk++) if(a[kk]==b){ cout<<0<<endl; return 0;}
					cout<<1<<endl; 
				}
				return 0;
			}
		}
		cout<<2<<endl;
		b=abs(b);
	}
	else if((q==1 && l==b))
	{
		if(neg)
			b=-1*b;
		for(int i=0;i<m;i++) if(a[i]==b) {cout<<0<<endl; return 0;}
		cout<<1<<endl;
		b=abs(b);
	}
	else if(q==-1)
	{
		if(b==0)
		{
			
		}
	}
	else
	{
		ll n=0;
		ll tq=1;
		b=abs(b);
		while(b*tq<l) 
		{
			n++ ;
			tq=tq*q ;
		}
		//in++;
//		cout<<n<<endl;
//		cout<<log(0)<<endl;
		if(neg && b>0)
                        b=-1*b;
		for(int i=0;i<m;i++)
		{
			if(abs(a[i])>l) continue;
			//if(a[i]<b && (a[i]>0 && b>0)) continue;
			//if(a[i]>b && (a[i]<0 && b<0)) continue;
			if(a[i]==0) continue;
			//if((b<0 && a[i]>0) || (a[i]<0 && b>0)) continue;
			//if(a[i]==0 || (a[i]/b)==0 || q==0) continue;
			tq=1;
			while(b*tq<a[i] && abs(b*tq)<=l)
			{
				tq=tq*q;
			}
			if(b*tq==a[i]) n--;
			
		}
		if(n<0) n=0;
		cout<<n<<endl;
	}
	return 0;
}

