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
	string a;
	int n;
	map<string,int>M;
	string b,home;
	cin>>n;
	cin>>home;
	M[home]++;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		b=a.substr(5,3);
		a=a.substr(0,3);
		M[a]--;
		M[b]++;
	}
	if(M[home]) cout<<"home"<<endl;
	else cout<<"contest"<<endl;
	return 0;
}

