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

char A[100023];
int enter=0;
bool K[1023][1023]={0};
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
int main()
{
	int a,base,height;
	bs(1,1001,a,true,0);
	//cout<<a<<endl;
	
	bs(a+1,1001,base,true,2*a);
	bs(2*a+1,1001,height,false,0);
	a=a*2;
	base=base*2;
	height=height-a;
	cout<<"! "<<(base*height)/2 + a*a<<endl;
	
	return 0;
}

