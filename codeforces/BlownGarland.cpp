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
	char A[10]={0};
	char x;
	int n;
	//cin>>n;
	char B[200];
	cin>>B;
	n=strlen(B);
	map<int,int>C;
	for(int i=0;i<n;i++)
	{
	//	cin>>B[i];
		if(B[i]!='!')
		A[i%4]=B[i];
	}
	for(int i=0;i<n;i++)
	{
		if(B[i]=='!')
			C[A[i%4]]++;
	}
	cout<<C['R']<<" "<<C['B']<<" "<<C['Y']<<" "<<C['G']<<endl;
	return 0;
}

