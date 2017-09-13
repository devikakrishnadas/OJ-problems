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
	int n;
	int f=0;
	int z=0;
	int x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x==5)
			f++;
		else if(x==0)
		{
			z++;
		}
	}
	if(z==0) cout<<-1<<endl;
	else if(f<9) cout<<0<<endl;
	else
	{
		f=f-f%9;
		for(int i=0;i<f;i++) cout<<5;
		for(int i=0;i<z;i++) cout<<0;
		cout<<endl;
	}
	return 0;
}

