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
	map<string,int>A;
	string temp;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		A[temp]++;
	}
	map<string,int>::iterator it=A.begin(),it1=A.begin();
	if(A.size()==1)
	{
		cout<<it->first<<endl;
		return 0;
	}
	it1++;
	if((it->second)>(it1->second))
		cout<<(it->first)<<endl;
	else cout<<(it1->first)<<endl;
	return 0;
}

