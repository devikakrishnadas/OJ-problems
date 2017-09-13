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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ifstream fin;
	ofstream fout;
	fout.open("output.txt");
	fin.open("B-small-attempt0.txt");
	int t;
	fin>>t;
	int cnt=1;
	
	while(t--)
	{
		fout<<"Case #"<<cnt<<": ";
		int n;
		fin>>n;
		cnt++;
		int rc[1000]={0};
		int cc[1000]={0};
		for(int i=0;i<n;i++)
		{
			char x;
			for(int j=0;j<n;j++)
			{
				fin>>x;
				if(x=='X')
				{
					rc[i]++;
					cc[j]++;
				}
			}
		}
		int r2=0,r1=0,c2=0,c1=0;
		int enter=0;
		for(int i=0;i<n;i++)
		{
			if(rc[i]==2)
			{
				r2++;
			}
			else if(rc[i]==1)
			{
				r1++;
			}
			else
			{
				enter=1;
				fout<<"IMPOSSIBLE"<<endl;
				break;
			}
			if(cc[i]==2)
			{
				c2++;
			}
			else if(cc[i]==1)
			{
				c1++;
			}
			else
			{
				enter=1;
				fout<<"IMPOSSIBLE"<<endl;
				break;
			}
			
		}
		if(enter)
		{
			continue;
		}
		if(r1!=1 || c1!=1)
		{
			fout<<"IMPOSSIBLE"<<endl;
		}
		else fout<<"POSSIBLE"<<endl;
	}
	return 0;
}

