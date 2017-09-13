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
	char A[50];
	char B[50];
	cin>>A>>B;
	int a=0,b=0;
	int ao=0,bo=0;
	for(int i=0;i<strlen(A);i++)
	{
		ao=ao*10+(A[i]-'0');
		if(A[i]=='0') continue;
		else a=a*10+(A[i]-'0');
	}
	for(int i=0;i<strlen(B);i++)
	{
		bo=bo*10+(B[i]-'0');
		if(B[i]=='0')continue;
		else b=b*10+(B[i]-'0');
	}
	int co=ao+bo;
	int c=a+b;
	int C[50]={0};
	int k=0;
	while(co)
	{
		C[k]=co%10;
		co=co/10;
		k++;
	}
	int fin=0;
	reverse(C,C+k);
	for(int i=0;i<k;i++)
	{
		if(C[i]==0) continue;
		else fin=fin*10+C[i];
	}
	if(fin==c) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}

