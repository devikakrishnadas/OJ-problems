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
	int h=0,t=0,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x==100) h++;
		else t++;
	}
	int val=(h*100+t*200)/2;
	if(val%100==50)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		while(val-200>=0 && t>0)
		{
			t--;
			val=val-200;
		}
		while(val-100>=0 && h>0)
		{
			h--;
			val=val-100;
		}
		if(val==0)
		{
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}

