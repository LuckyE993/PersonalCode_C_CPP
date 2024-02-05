//
// Created by LuckyE on 2024/2/4.
//
#include "bits/stdc++.h"
#define Cpp 1
#if Cpp
using namespace std;
const int N=100010;
struct TrieNode
{
	int cnt;
	TrieNode* next[26]{};

	TrieNode()
	{
		cnt = 0;
		memset(next,0, sizeof(next));
	}

};

class Trie
{
public:
	Trie()
	{
		root = new TrieNode;
	}
	void insert(const string& word)
	{
		TrieNode*  cur = root;
		for(char c: word)
		{
			int index = c-'a';
			if(cur->next[index]== nullptr)
			{
				cur->next[index] = new TrieNode();

			}
			cur = cur->next[index];
		}
		cur->cnt++;
	}

	int query(const string& word)
	{
		TrieNode* cur = root;
		for(char c : word)
		{
			int index = c-'a';
			if(cur->next[index]== nullptr)
			{
				return 0;
			}
			cur=cur->next[index];
		}
		return cur->cnt;
	}
private:
	TrieNode* root;
};
int main()
{
	Trie trie;
	int n;
	cin>>n;
	while(n--)
	{
		string op,word;
		cin>>op;
		cin>>word;
		if(op == "I")
		{
			trie.insert(word);
		}
		if(op=="Q")
		{
			cout<<trie.query(word)<<endl;
		}
	}
	return 0;
}


#else
using namespace std;
const int N=100010;
int son[N][26],cnt[N],idx;
string str;

void insert(string str)
{
	int p=0;
	for(int i=0;str[i];i++)
	{
		int u=str[i]-'a';
		if(!son[p][u])
		{
			son[p][u]= ++idx;

		}
		p=son[p][u];

	}
	cnt[p]++;
}
int query(string str)
{
	int p=0;
	for(int i=0;str[i];i++)
	{
		int u=str[i]-'a';
		if(!son[p][u])
		{
			return 0;
		}
		p=son[p][u];
	}
	return cnt[p];
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string op;
		cin>>op>>str;
		if(op[0]=='I')
		{
			insert(str);
		}
		else
		{
			int Cnt = query(str);
			cout<<Cnt<<endl;
		}
	}

	return 0;
}

#endif
