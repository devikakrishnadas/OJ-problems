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
	ll x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	ll a1=x2-x1;
	ll a2=x3-x1;
	ll b1=y2-y1;
	ll b2=y3-y1;
	ll  ans=a1*b2-b1*a2;
	if(ans==0)
	{
		cout<<"TOWARDS"<<endl;
	}
	else if(ans>0)
	{
		cout<<"LEFT" <<endl;
	}
	else
	{
		cout<<"RIGHT"<<endl;
	}
	return 0;
}

