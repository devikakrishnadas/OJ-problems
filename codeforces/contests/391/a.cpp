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
	char A[100023];
	cin>>A;
	int B=0,u=0,l=0,b=0,a=0,s=0,r=0;
	for(int i=0;i<strlen(A);i++)
	{
		if(A[i]=='B')
			B++;
		if(A[i]=='u')
			u++;
		if(A[i]=='l')
			l++;
		if(A[i]=='b')
			b++;
		if(A[i]=='a')
			a++;
		if(A[i]=='s')
			s++;
		if(A[i]=='r')
			r++;
	}
	u=u/2;
	a=a/2;
	cout<<min(B,min(u,min(l,min(b,min(a,min(s,r))))))<<endl;
	return 0;
}

