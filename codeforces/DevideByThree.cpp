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
	char A[100023],C[100023];
	cin>>A;
	int sum=0;
	map<int,int>B;
	B[1]=0;
	B[2]=0;
	int n=strlen(A);
	if(n==1)
	{
		if((A[0]-'0')%3==0)
		{
			cout<<A[0]<<endl;
		}
		else cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		sum+=(A[i]-'0');
	//	if(i)
		B[(A[i]-'0')%3]++;
	}
//	cout<<B[0]<<" "<<B[1]<<" "<<B[2]<<endl;
	int change=0;
	int cn=INT_MIN,an=INT_MIN;
//	cout<<sum<<endl;
	int cchange=0,achange=0;
	if(sum%3==0)
	{
		cout<<A<<endl;
		return 0;
	}
	else if(sum%3==1)
	{
		if(B[1])
		{
			for(int i=n-1;i>=0;i--)
			{
				if((A[i]-'0')%3==1)
				{
					A[i]='x';
					change++;
					break;
				}
			}
			//cout<<A<<endl;
		}
		int enter=0;
		if(B[2]>=2)
		{
			for(int i=n-1;i>=0;i--)
			{
				if((A[i]-'0')%3==2)
				{
					A[i]='x';
					change ++;
					enter++;
				}
				if(enter==2) break;
			}
			
		}
		else
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	else if(sum%3==2)
	{	
	//	cn=0;
//		int cn=0,an=0;
//		cout<<B[2]<<" "<<B[1]<<endl;
		if(B[2])
		{
//			cout<<"r1"<<endl;
			cn=0;
			//char C[100023];
			strcpy(C,A);
			for(int i=n-1;i>=0;i--)
			{
				if((C[i]-'0')%3==2)
				{
					C[i]='x';
					change++;
					break;
				}
			}
			//cout<<A<<endl;
			cchange=change;
			bool enter =0;
			for(int i=0;i<n;i++)
			{
				if((C[i]=='0'||C[i]=='x') && !enter)
				{
					if(C[i]=='0')
					change++;
				}
				else break;
			}
			cn=n-change;
			change=0;
		}
		if(B[1]>=2)
		{
			an=0;
			int enter=0;
			for(int i=n-1;i>=0;i--)
			{
				if((A[i]-'0')%3==1)
				{
					enter++;
					change++;
					A[i]='x';
				}
				if(enter==2) break;
				achange=change;
			}
			an=n-change;
		}
		if(B[1]<2 && B[2]==0)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	bool enter=0;
//	cout<<cn<<" "<<an<<endl;
	if(cn>an && cn!=INT_MAX)
	{
		if(cn==0) {cout<<-1<<endl;return 0;}
		for(int i=0;i<n;i++)
		{
			if(C[i]=='x') continue;
			if(C[i]=='0' && !enter)
				continue;
			enter=1;
			cout<<C[i];
		}
//		cout<<endl;
		if(!enter && cn<n) cout<<0;
		else if(!enter and cn>=n) cout<<-1;
		cout<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(an==0) {cout<<-1<<endl;return 0;}
		if(A[i]=='x') continue;
		if(A[i]=='0' && !enter)
			continue;
		enter=1;
		cout<<A[i];
	}
//	cout<<change<<endl;
	if(!enter && an<n) cout<<0;
	else if(!enter && an>=n) cout<<-1;
	cout<<endl;
	return 0;
}

