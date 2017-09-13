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
	ifstream fin;
	ofstream fout;
	fin.open("");
	fout.open("");
	int t;
	fin>>t;
	while(t--)
	{
		int n;
		fin>>n;
		int x;
		map<int,int>P;
		vi A;
		for(int i=0;i<2*n;i++)
		{
			cin>>x;
			P[x]++;
		}
		map<int,int>::iterator it=P.end();
		P--;
		for(;;;)
		{
			int a=it->first;
			a=a/4;
			a=a*3;
			P[a]-=it->second;
			n=n-

		}
	}
	return 0;
}

