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
	char A[100024],B[100023];
	cin>>A>>B;
	map<int,int>a,b;
	int n1=strlen(A);
	int n2=strlen(B);
	int j=0;
	
	for(int i=0;i<n2;i++)
	{
		while(A[j]!=B[i] && j<n1)
		{
			j++;
		}
		if(j==n1)
		{
			j=0;
		}
		
	}
	return 0;
}

