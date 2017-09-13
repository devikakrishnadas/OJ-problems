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

struct TrieNode
{
     struct TrieNode *children[200];
     bool isLeaf;
};

char c;
int main()
{
	TrieNode *root=new TrieNode;
	char S[100];
	int n;
	cin>>n;
	TrieNode *t=NULL;
	for(int i=0;i<30;i++)
		root->children[i+'a']=NULL;
	while(n--)
	{
		cin>>S;
		t=root;
		for(int i=0;i<strlen(S);i++)
		{
			TrieNode *P=new TrieNode;
			t->isLeaf=0;
			for(int j='a';j<'a'+26;j++)
				P->children[j]=NULL;
			if(t->children[S[i]]!=NULL)
			{
				t=t->children[S[i]];
//				cout<<S[i]<<" ";
			}
			else if(i==strlen(S)-1)
                        {
                                t->children[S[i]]=P;
//				cout<<S[i]<<" ";
				t=P;
                                t->isLeaf=1;
                        }

			else
			{
 

				t->children[S[i]]=P;
				t=t->children[S[i]];
			}
//			cout<<S[i]-'a'<<" ";
		}
//		cout<<endl;
	}
//	cout<<"1abc"<<endl;
	t=root;
	bool enter =1;
//	cout<<"abc"<<endl;
	while(enter)
	{
		enter=0;
		for(int i=0;i<26;i++)
		{
			if(t->children[i+'a']!=NULL)
			{
				enter=1;
				cout<<(char)('a'+i)<<" ";
			}
		}
		cout<<endl;
		if(!enter) break;
		cin>>c;
		t=t->children[c];
	}
	return 0;
}

