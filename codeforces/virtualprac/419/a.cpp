#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int Int(char a)
{
	return (a-'0');
}

bool isPali(int i,int j)
{
	vc h,m;
	//cout<<i<<" "<<j<<endl;
	while(i)
	{
		char a=i%10;
		a=a+'0';
		h.pb(a);
		i=i/10;
	}
	if(h.size()==1)
	{
		char a=h[0];
		h.clear();
		h.pb('0');
		h.pb(a);
	}
	else if(h.size()==0)
	{
		h.pb('0');
		h.pb('0');
	}
	else
		swap(h[0],h[1]);
	while(j)
        {
                char a=j%10;
                a=a+'0';
                m.pb(a);
                j=j/10;
        }
	//cout<<h[0]<<h[1]<<":"<<m[0]<<m[1]<<endl;
        if(m.size()==1)
        {
                char a=m[0];
                m.clear();
                m.pb('0');
                m.pb(a);
        }
	else if(m.size()==0)
	{
		m.pb('0');
		m.pb('0');
	}
	else swap(m[0],m[1]);
	
	//cout<<h[0]<<h[1]<<":"<<m[0]<<m[1]<<endl;
	if(h[1]==m[0] && h[0]==m[1])
		return true;
	else return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int h=Int(s[0])*10+Int(s[1]);
	int m=Int(s[3])*10+Int(s[4]);
	int min=0;
	//cout<<h<<" "<<m<<endl;
	for(int i=h;i<24;i++)
	{
		int start=0;
		if(i==h) start=m;
		for(int j=start;j<60;j++,min++)
		{
			//cout<<i<<" "<<j<<endl;
			if(isPali(i,j))
			{
				//cout<<i<<" "<<j<<endl;	
				cout<<min<<endl;
				return 0;
			}
		}
	}
	//cout<<"abc"<<endl;
	for(int i=0;i<=h;i++)
	{
		for(int j=0;j<m;j++,min++)
		{
			if(isPali(i,j))
			{
				//cout<<i<<" "<<j<<endl;
				cout<<min<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}

