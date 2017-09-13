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


int change(char A[100023],int a,int n,int val)// utility function that takes number of items int the congruence class of x wrt 3
{
	int cnt=0;
	int t=n;
	for(int i=n-1;i>=0;i--)
	{
		if((A[i]-'0')%3==val)
		{
			A[i]='x';
			t--;
			cnt++;
		}
		if(cnt==a) break;
	}
//	cout<<cnt<<endl;
	if(cnt==n)
		return -1;
//	cout<<"r1"<<endl;
	for(int i=0;i<n;i++)
	{
		if((A[i]=='x' or A[i]=='0'))
		{
			if(A[i]=='0') t--;
		}
		else break;
	}
	return t;
}

void print(char A[100023],int n)
{
	bool enter=0;
	for(int i=0;i<n;i++)
	{
		if(A[i]=='x') continue;
		if(A[i]=='0' and !enter)
		{
			continue;
		}
		enter=1;
		cout<<A[i];
	}
	if(!enter) cout<<0;
	cout<<endl;
}
int main()
{
	char A[100023],B[100023],C[100023],D[100023];
	cin>>A;
	int sum=0;
	map<int,int>cnt;
	int n=strlen(A);
	for(int i=0;i<n;i++)
	{
		int c=A[i]-'0';
		sum+=c;
		cnt[c%3]++;	
	}
	strcpy(B,A);
        strcpy(C,A);
        strcpy(D,A);
	if(sum%3==0)
	{
		cout<<A<<endl;
		return 0;
	}
//	cout<<"r1"<<endl;
//	strcpy(B,A);
//	strcpy(C,A);
//	strcpy(D,A);
	else if(sum%3==1)
	{
		//cout<<"r1"<<endl;
		int n1=-1,n2=-1;
	//	cout<<cnt[1]<<endl;
		if(cnt[1])
			n1=change(A,1,n,1);
		if(cnt[2]>=2)
			n2=change(B,2,n,2);
		if(n1==-1 && n2==-1)
			cout<<-1<<endl;
		else if(n1>n2)
			print(A,n);
		else print(B,n);
	}
	else 
	{
		//cout<<"r2"<<endl;
		int n1=-1,n2=-1;
		if(cnt[1]>=2)
			n1=change(C,2,n,1);
		if(cnt[2])
			n2=change(D,1,n,2);
		//cout<<n1<<" "<<n2<<endl;
		if(n1==-1 and n2==-1)
			cout<<-1<<endl;
		else if(n1>n2)
			print(C,n);
		else print(D,n);
	}
	return 0;
}
