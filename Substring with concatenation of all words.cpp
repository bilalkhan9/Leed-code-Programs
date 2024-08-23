#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    if (s.empty() || words.empty()) return result;

    int wordLength = words[0].length();
    int numWords = words.size();
    int totalLength = wordLength * numWords;

    
    map<string, int> wordCount;
    for (int i = 0; i < words.size(); ++i) {
        wordCount[words[i]]++;
    }

    
    for (int i = 0; i < wordLength; ++i) {
        map<string, int> currentCount;
        int left = i, right = i, count = 0;

        while (right + wordLength <= s.length()) {
            string word = s.substr(right, wordLength);
            right += wordLength;

            if (wordCount.find(word) != wordCount.end()) {
                currentCount[word]++;
                count++;

                while (currentCount[word] > wordCount[word]) {
                    currentCount[s.substr(left, wordLength)]--;
                    left += wordLength;
                    count--;
                }

                if (count == numWords) {
                    result.push_back(left);
                }
            } else {
                currentCount.clear();
                count = 0;
                left = right;
            }
        }
    }

    return result;
}

void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    
    vector<string> words1;
    words1.push_back("foo");
    words1.push_back("bar");
    
    vector<string> words2;
    words2.push_back("word");
    words2.push_back("good");
    words2.push_back("best");
    words2.push_back("word");
    
    vector<string> words3;
    words3.push_back("bar");
    words3.push_back("foo");
    words3.push_back("the");

    string s1 = "barfoothefoobarman";
    vector<int> result1 = findSubstring(s1, words1);
    cout << "Output: ";
    printVector(result1); 

    string s2 = "wordgoodgoodgoodbestword";
    vector<int> result2 = findSubstring(s2, words2);
    cout << "Output: ";
    printVector(result2); 

    string s3 = "barfoofoobarthefoobarman";
    vector<int> result3 = findSubstring(s3, words3);
    cout << "Output: ";
    printVector(result3); 
	system("pause");
    return 0;
}
