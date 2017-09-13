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
	int x,y;
	cin>>x>>y;
	int x1=0,y1=(abs(x)+abs(y))*(y/abs(y));
	int x2=(abs(x)+abs(y))*(x/abs(x)),y2=0;
	if(x1<x2) cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	else cout<<x2<<" "<<y2<<" "<<x1<<" "<<y1<<endl;
	return 0;
}

