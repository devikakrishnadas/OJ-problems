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
	int x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	int mn=(y2-y1)*(y3-y2);
	int md=(x2-x1)*(x3-x2);	
	int a=x2-x1;
	int b=y2-y1;
	int c=-1*y1*a+x1*b;
	
	if((md==0 && mn==0) || mn==-1*md)
	{
		if(abs(-1*y3*a+x3*b)<abs(c))
		{
	
			cout<<"LEFT"<<endl;
	
		}
		else {
			cout<<"RIGHT"<<endl;
		}
	}
	else cout<<"TOWARDS"<<endl;
	return 0;
}

