#include<iostream>
#include<algorithm>
#define MAXLEN 100000
#define endl "\n"
#define YES "YES"
#define NO "NO"

using namespace std;

int N;
string word1, word2;
string consonant1, consonant2;
char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
int alpha[26];

int main(){
    cin >> N >> word1 >> word2;
    if(word1[0] != word2[0] || word1[N-1] != word2[N-1]){
        cout << NO << endl;
        return 0;
    }

    for(int i = 0; i < N; i++){
        alpha[word1[i] - 'a']++;
        alpha[word2[i] - 'a']--;
        if(find(begin(vowel), end(vowel), word1[i]) == end(vowel))
            consonant1 += word1[i];

        if(find(begin(vowel), end(vowel), word2[i]) == end(vowel))
            consonant2 += word2[i];
    }

    for(int i = 0; i < 26; i++){
        if(alpha[i] != 0){
            cout << NO << endl;
            return 0;
        }
    }
    if(consonant1 == consonant2)
        cout << YES << endl;
    else
        cout << NO << endl;
}