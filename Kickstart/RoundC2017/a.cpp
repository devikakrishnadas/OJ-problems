#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ofstream fout;
	ifstream fin;
	fin.open("A-large.txt");
	fout.open("output.txt");
	int t;
	fin>>t;
	cout<<t<<endl;
	int cnt=1;
	while(cnt<=t)
	{
		fout<<"Case #"<<cnt<<": ";
		int n;
		
		string S;
		fin>>S;
		cout<<cnt<<endl;
		cnt++;
		n=S.length();
		if(n==2)
		{
			swap(S[0],S[1]);
			fout<<S<<endl;
			continue;
		}
		else if(n==3)
		{
			fout<<"AMBIGUOUS"<<endl;
			continue;
		}
		char ans[10023];
	
		ans[1]=S[0]-'A';
//	cout<<"2nd "<<(char)(ans[1]+'A')<<endl;
		for(int i=2;i<S.length()-2;i+=2)
		{
			ans[i+1]=((S[i]-'A'-ans[i-1])+26)%26;
//		cout<<(char)(ans[i+1]+'A')<<endl;
		}

		ans[n-2]=S[n-1]-'A';
//	cout<<"3rd "<<(char)(ans[n-2]+'A')<<endl;
		for(int i=2;i<n-2;i+=2)
		{
			ans[i]=(ans[i+2]-(S[i+1]-'A')+26)%26;
//		cout<<(char)(ans[i]+'A')<<endl;
		}
		ans[0]=(S[1]-'A'-ans[2]+26)%26;

//	cout<<"1st "<<(char)(ans[0]+'A')<<endl;

		ans[n-1]=(S[n-2]-'A'-ans[n-3]+26)%26;
//	cout<<"4th "<<(char)(ans[n-1]+'A')<<endl;
		for(int i=0;i<n;i++)
		{
			fout<<(char)(ans[i]+'A');
			cout<<(char)(ans[i]+'A');
		}	
		cout<<endl;
		fout<<endl;
	}
	return 0;
}

