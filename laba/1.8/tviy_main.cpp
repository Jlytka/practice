#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

void generate_anagrams(string word, string current, vector<bool>& used, set<string>& anagrams) {
    if (current.length() == word.length()) {
        anagrams.insert(current);
        return;
    }
    
    for (int i = 0; i < word.length(); i++) {
        if (!used[i]) {
            used[i] = true;
            generate_anagrams(word, current + word[i], used, anagrams);
            used[i] = false;
        }
    }
}

int main() {
    int numWords;
    cout << "Enter the number of words: ";
    cin >> numWords;
    
    vector<string> words(numWords);
    for (int i = 0; i < numWords; i++) {
        cout << "Enter word " << i + 1 << ": ";
        cin >> words[i];
    }
    
    map<string, set<string>> wordAnagrams;
    
    for (const string& word : words) {
        vector<bool> used(word.length(), false);
        set<string> anagrams;
        
        generate_anagrams(word, "", used, anagrams);
        
        wordAnagrams[word] = anagrams;
    }
    
    for (const auto& entry : wordAnagrams) {
        cout << "Anagrams for " << entry.first << ": ";
        for (const string& anagram : entry.second) {
            cout << anagram << " ";
        }
        cout << endl;
    }
     
    return 0;
}
