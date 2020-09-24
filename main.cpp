#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

vector<string> split(string text) 
{
  replace(text.begin(), text.end(), '\t', ' ');
  istringstream is(text);
  
  string word;
  vector<string> vs;
  while (is >> word) vs.push_back(word);
 
  return vs;
}

void u(int N, vector <string>& strs) {
    string s = "";
    for (auto c : strs[N]){
        if ((int(c) >= int('A')) and (int(c) <= int('Z'))){
            c = char(int(c) + int('a') - int('A'));
        }
        s += c;
    }
    cout << s;
}

void U(int N, vector <string>& strs) {
    string s = "";
    for (auto c : strs[N]){
        if ((int(c) >= int('a')) and (int(c) <= int('z'))){
            c = char(int(c) + int('A') - int('a'));
        }
        s += c;
    }
    cout << s;
}

void UAB(int N, vector <string>& strs, char A, char B) {
    string s = "";
    for (auto c : strs[N]){
        if (c == A){
            c = B;
        }
        s += c;
    }
    cout << s;
}

int main(){
    string filename;
    cin >> filename;
    filename += ".txt";
    
    string s;
    ifstream file(filename);
    
    vector <string> strs;
    while(getline(file, s)){
        strs = split(s);
        for (int i = 0; i < strs.size(); i++){
            u(i, strs);
            cout << ' ';
        }
        cout << '\n';
        for (int i = 0; i < strs.size(); i++){
            U(i, strs);
            cout << ' ';
        }
        cout << '\n';
        for (int i = 0; i < strs.size(); i++){
            UAB(i, strs, 'l', 'r');
            cout << ' ';
        }
        cout << '\n';
    }

    file.close();

    return 0;
}
