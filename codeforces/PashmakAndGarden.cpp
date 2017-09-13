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
	int x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	int a,b,c,d;
	if(x1==x2)
	{
		int d=y2-y1;
		cout<<x1+d<<" "<<y1<<" "<<x2+d<<" "<<y2<<endl;
	}
	else if(y1==y2)
	{
		int d=x2-x1;
		cout<<x1<<" "<<y1+d<<" "<<x2<<" "<<y2+d<<endl;
	}
	else if(abs(x2-x1)==abs(y2-y1)) 
	{
		cout<<x1<<" "<<y2<<" "<<x2<< " "<<y1<<endl;
	}
	else
		cout<<-1<<endl;
	return 0;
}

