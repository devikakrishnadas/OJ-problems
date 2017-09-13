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

void print(vi a,int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	ll ec=0,oc=0;
	vi ae(100023,0),ao(100023,0),be(100023,0),bo(100023,0); /* Stores counts of 'a' and 'b' in even and odd positions */
	for(int i=s.length()-1,j=s.length();i>=0;i--,j--)
	{
		ae[j]=ae[j+1];
		ao[j]=ao[j+1];
		be[j]=be[j+1];
		bo[j]=bo[j+1];
		if(s[i]=='a')
		{
			if(i%2)
				ae[j]++;
			else 
				ao[j]++;
		}
		else if(s[i]=='b')
		{
			if(i%2)
			{
				be[j]++;
			}
			else 
				bo[j]++;
		}
	}
	for(int i=0,j=1;i<s.length();i++,j++)
	{
		if(s[i]=='a')
		{
			if(j%2)
			{
				oc+=(ao[j]);
				ec+=(ae[j+1]);
			}
			else
			{
				oc+=(ae[j]);
				ec+=(ao[j+1]);
			}
		}
		else
		{
			if(j%2)
			{
				oc+=(bo[j]);
				ec+=(be[j+1]);
			}
			else
			{
				oc+=(be[j]);
				ec+=(bo[j+1]);
			}
		}
	}
	/*print(ao,s.length());
	print(ae,s.length());
	print(bo,s.length());
	print(be,s.length());*/
	cout<<ec<<" "<<oc<<endl;
	return 0;
}

