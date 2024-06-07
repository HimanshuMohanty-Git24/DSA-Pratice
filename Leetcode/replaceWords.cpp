//648. Replace Words
#include<bits/stdc++.h>
using namespace std;
string replaceWords(vector<string>& dictionary, string sentence) {
    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    stringstream ss(sentence);
    string word;
    string res;
    while(ss >> word)
    {
        for(int i=1; i<=word.size(); i++)
        {
            if(dict.count(word.substr(0,i)))
            {
                word = word.substr(0,i);
                break;
            }
        } 
        res += word + " ";
    }
    return res.substr(0, res.size()-1);
}
int main()
{
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    cout<<replaceWords(dictionary, sentence)<<endl;
   return 0;
}