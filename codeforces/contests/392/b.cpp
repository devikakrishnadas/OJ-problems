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
	ll R=0,B=0,G=0,Y=0,D=0;
	char A[1000],S[1000];
	cin>>A;
	for(int i=0;i<strlen(A);i++)
	S[i]=A[i];
	S[strlen(A)]='\0';
//	strcpy(S,A);
	ll Di=-1;
	bool enter=1;
	while(enter){
	enter=0;
	for(int i=0;i<strlen(A)-3;i++)	
	{
		R=G=B=Y=0;
		D=0;
		
		Di=-1;
		for(int j=i;j<i+4;j++)
		{
			if(A[j]=='R') R++;
			else if(A[j]=='B') B++;
			else if(A[j]=='G') G++;
			else if(A[j]=='Y') Y++;
			else { D++;enter=1;
				Di=j;}
//			if(j==strlen(S)-1)
//			{
//				cout<<R<<" "<<B<<" "<<G<<" "<<Y<<endl;
//			}
		}
		if(D==1)
		{
			if(R==0)	
			{
				A[Di]='R';
			}
			else if(G==0) A[Di]='G';
			else if(B==0) A[Di]='B';
			else if(Y==0) A[Di]='Y';
		}
//		cout<<D<<endl;
	}
	}
	G=B=Y=R=0;
//	cout<<A<<endl;
//	cout<<S<<endl;

	for(int i=0;i<strlen(A);i++)
	{
		if(A[i]!=S[i])
		{
			if(A[i]=='G') G++;
			else if(A[i]=='Y') Y++;
			else if(A[i]=='R') R++;
			else if(A[i]=='B') B++;
		}
	}	
	cout<<R<<" "<<B<<" "<<Y<<" "<<G<<endl;
	return 0;
}

