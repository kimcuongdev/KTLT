#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<vector<string>> doc, que;

vector<string> split(string s) {
    vector<string> words;
    stringstream ss(s);
    string word;
    while (getline(ss, word, ',')) {
        words.push_back(word);
    }
    return words;
}

void inp() {
    cin >> n;
    doc.resize(n);
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string temp;
        getline(cin, temp);
        doc[i] = split(temp);
    }
    cin >> q;
    que.resize(q);
    cin.ignore();
    for (int i = 0; i < q; i++) {
        string temp;
        getline(cin, temp);
        que[i] = split(temp);
    }
}

double calculateScore(const vector<string>& query, const vector<string>& document, unordered_map<string, int>& df, int N) {
    unordered_map<string, int> wordCount;
    int maxf = 0;
    for (const string& word : document) {
        wordCount[word]++;
        maxf = max(maxf, wordCount[word]);
    }
    
    double score = 0.0;
    for (const string& word : query) {
        if (wordCount.find(word) != wordCount.end()) {
            double tf = 0.5 + 0.5 * (double)wordCount[word] / maxf;
            double idf = log2((double)N / df[word]);
            score += tf * idf;
        }
    }
    return score;
}

int main() {
    inp();
    
    unordered_map<string, int> df;
    for (const auto& document : doc) {
        unordered_set<string> uniqueWords(document.begin(), document.end());
        for (const string& word : uniqueWords) {
            df[word]++;
        }
    }
    
    vector<int> results(q);
    for (int i = 0; i < q; i++) {
        const auto& query = que[i];
        double maxScore = -1;
        int bestDocIndex = -1;
        
        for (int j = 0; j < n; j++) {
            double score = calculateScore(query, doc[j], df, n);
            if (score > maxScore || (score == maxScore && j < bestDocIndex)) {
                maxScore = score;
                bestDocIndex = j;
            }
        }
        
        results[i] = bestDocIndex + 1;
    }
    
    for (int result : results) {
        cout << result << endl;
    }
    
    return 0;
}
