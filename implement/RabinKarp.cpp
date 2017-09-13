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
	string text,pattern;
	int HText=0,HPattern=0;
	cout<<"Enter Text and Pattern"<<endl;
	cin>>text>>pattern;
	if(pattern.length()>text.length)
	{
		cout<<"Not Possible"<<endl;
	}
	for(int i=0;i<pattern.length();i++)
	{
		HPattern=HPattern+pow(2,i)*(pattern[i]-'a'+1);
		HText=HText + pow(2,i)*(text[i]-'a'+1);
	}
	vi noted;
	int n=pattern.length()-1;
	if(HPattern==HText)
		noted.pb(0);
	for(int i=1;i<text.length()-pattern.length();i++)
	{
		HText=HText-(text[i-1]-'a'+1);
		HText=HText/2;
		HText=HText+(text[i]-'a'+1)*pow(2,n);
		if(HText==HPattern)
		{
			noted.pb(i);
		}
	}
	if(noted.size()==0)
	{
		cout<<"Not Possible"<<endl;
	}
	else
	{
		for(int i=0;i<noted.size();i++)
		{
			int cnt=0;
			for(int j=noted[i];j<noted[i]+n;j++)
			{
				if(pattern[i]==text[j])
				{
					cnt++;
				}
				else break;
			}
			if(cnt==n)
				cout<<noted[i]<<endl;
		}
	}
	return 0;
}
