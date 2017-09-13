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
	char S[500];
	cin>>n>>S;
	int a=0,c=0,t=0,g=0,q=0;
	for(int i=0;i<n;i++)
	{
		if(S[i]=='?') q++;
		else if(S[i]=='A') a++;
		else if(S[i]=='C') c++;
		else if(S[i]=='G') g++;
		else if(S[i]=='T') t++;
	}
	int maxe=max(a,max(c,max(g,t)));
	int minq=4*maxe-a-c-g-t;
	a=maxe-a;
	c=maxe-c;
	g=maxe-g;
	t=maxe-t;
//	cout<<q<<" "<<minq<<endl;
	if(q<minq)
	{
		cout<<"==="<<endl;
		return 0;
	}
	else
	{
		if(q>minq)
		{
			if((q-minq)%4!=0)
			{
				cout<<"==="<<endl;
				return 0;
			}
			else
			{
				int temp=(q-minq)/4;
				a=a+temp;
				c=c+temp;
				g=g+temp;
				t=t+temp;
				
			}
		}
		for(int i=0;i<n;i++)
		{
			if(S[i]=='?')
			{
				if(a)
				{
					S[i]='A';
					a--;
				}
				else if(c)
				{
					S[i]='C';
					c--;
				}
				else if(g)
				{
					S[i]='G';
					g--;
				}
				else if(t)
				{
					S[i]='T';
					t--;
				}
			}
		}
		cout<<S<<endl;
	}
	return 0;
}

