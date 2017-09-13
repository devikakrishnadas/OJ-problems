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
//	cin>>n;
	sf("%d",&n);
	char A[200023];
//	cin>>A;
	sf("%s",A);
	int k=1;
	for(int i=0;;i++)
	{
		if(A[i%n]=='X') continue;	

		int tk=k;
		while(A[i%n]==A[k%n] || A[k%n]=='X')
		{
			
		//	cout<<A[i%n]<<" "<<A[k%n]<<endl;
			k++;
			if(k==tk+n+1)
			{
		//		cout<<A[min(i,k)%n]<<endl;
				pf("%c\n",A[i%n]);
				return 0;
			}
		}
		A[k%n]='X';
	}
	return 0;
}

