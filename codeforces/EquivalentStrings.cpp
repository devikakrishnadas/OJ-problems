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

bool eq(string &a,string &b, int a1,int al,int b1,int bl)
{
	if(al!=bl)
	{
		return false;
	}
	if(al==1)
	{
		//cout<<a1<<"-"<<a[a1]<<" "<<b1<<"-"<<b[b1]<<endl;
		if(a[a1]==b[b1])
			return true;
		return false;
	}
	if(al%2)
	{
		int a11=a1;	
		int al1=al/2;
		int a12=al/2;
		int al2=1;
		int a13=a12+al2;
		int al3=al/2;
		int b11=b1;
                int bl1=bl/2;
                int b12=bl/2;
                int bl2=1;
                int b13=b12+bl2;
                int bl3=bl/2;
		return ((a[a12]==b[b12])&&((eq(a,b,a11,al1,b11,bl1)&&eq(a,b,a13,al3,b13,bl3))||eq(a,b,a11,al1,b13,bl3)&&eq(a,b,a13,al3,b11,bl1)));
	}
	else
	{
		int a11=a1;
		int al1=al/2;
		int a12=a1+al/2;
		int al2=al-al/2;
		int b11=b1;
                int bl1=bl/2;
                int b12=b1+bl/2;
                int bl2=bl-bl/2;
		return((eq(a,b,a11,al1,b11,bl1)&&eq(a,b,a12,al2,b12,bl2))||(eq(a,b,a11,al1,b12,bl2)&&eq(a,b,a12,al2,b11,bl1)));
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b;
	cin>>a>>b;
	if(eq(a,b,0,a.length(),0,b.length()))
		cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}

