#include <bits/stdc++.h>
using namespace std;
	/**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
int n,q; vector<vector<string>> doc, que;
vector<string> split(string s){
	vector<string> words;
	stringstream ss(s);
	string word;
	while(getline(ss,word,','))
	{
		words.push_back(word);
	}
	return words;
}
void inp()
{
	cin>>n;
	doc.resize(n);
	cin.ignore();
	for (int i=0;i<n;i++)
	{
		string temp;
		getline(cin,temp);
		doc[i] = split(temp);
	}
	cin>>q;
	que.resize(q);
	cin.ignore();
	for (int i=0;i<q;i++)
	{
		string temp;
		getline(cin,temp);
		que[i] = split(temp);
	}
}
//tinh diem moi van ban
double calScoreDoc(const vector<string> &que, const vector<string> &doc, const unordered_map<string,int> &df, int n)
{
	double scoreDoc = 0.0;
	double tf,idf;
	int maxf = 0;
	//tinh f va maxf
	unordered_map<string,int> f;
	for (string word : doc)			//xet moi tu trong doc
	{
		f[word]++;
		maxf=max(f[word],maxf);
	}
	for (string word : que)
	{
		if (f[word] != 0)
		{
			//tinh tf
			tf = 0.5 + 0.5 * ((double)f[word]/maxf);
			//tinh idf
			idf = log2((double)n / df.at(word));
			scoreDoc += tf * idf;
		}
	}
	return scoreDoc;	
}
//tim van ban co diem cao nhat
int bestDocIndex(const vector<string> &que,const vector<vector<string>> &doc,int n)
{
	int bestIndex = -1;
	double bestScore = -1;
	//tinh df cua moi tu trong que
	unordered_map<string,int> df;
	unordered_set<string> distinct(que.begin(),que.end()); //cac tu phan biet
	for (string word : distinct)
	{
		for (const auto d : doc)
		{
			for (int i=0;i<d.size();i++)
			{
				if (d[i]==word)
				{
					df[word]++;
					break;
				}
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		//tinh diem doc[i]
		double scoreDoc = calScoreDoc(que,doc[i],df,n);
		//cap nhat diem max
		if (scoreDoc > bestScore || (scoreDoc == bestScore && i < bestIndex))
		{
			bestScore = scoreDoc;
			bestIndex = i;
		}
		//cap nhat index diem max
	}
	return bestIndex + 1;
}
int main()
{
	inp();
    vector<int> results;
    for (const auto& query : que) 
	{
        results.push_back(bestDocIndex(query, doc, n));
    }
    for (int result : results)
	{
        cout << result << endl;
    }
	return 0;
}