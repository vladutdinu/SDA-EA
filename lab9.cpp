#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> naiveSearch(string text, string pattern){
    vector<int> pos;
    int n = text.length();
    int m = pattern.length();

    for(int i = 0; i <= n - m; i++){
        bool ok = true;

        for(int j = 0; j < m; j++)
            if(text[i+j] != pattern[j]){
                ok = false;
                break;
            }

        if(ok == true) // if(ok)
            pos.push_back(i);
    }
    return pos;
}

vector<int> rabinKarpSearch(string text, string pattern, int q){
    vector<int> pos;
    int n = text.length();
    int m = pattern.length();
    int d = 256; // numarul de caractere din codificarea ASCII
    int h = 1;
    int ht = 0;
    int hp = 0;

    for(int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for(int i = 0; i < m; i++){
        hp = (d * hp + pattern[i]) % q;
        ht = (d * ht + text[i]) % q;
    }

    for(int i = 0; i <= n - m; i++){
        if(hp == ht){

            for(int x = 0; x < m; x++)
                cout << text[i + x] << " ";
            cout<< ht << endl;

            bool ok = true;

            for(int j = 0; j < m; j++)
                if(text[i+j] != pattern[j]){
                    ok = false;
                    break;
                }
            if(ok)
                pos.push_back(i);
        }

        if(i < n - m){
            ht = (d * (ht - text[i] * h) + text[i+m]) % q;
            if(ht < 0)
                ht = ht + q;
        }
    }

    return pos;
}

int main() {

    string text = "Acesta este un test, pentru un text cu un test";
    string pattern = "test";

    vector<int> result = naiveSearch(text, pattern);

    for(int pos : result)
        cout << "Am gasit pattern-ul la pozitia = " << pos << endl;

    vector<int> result1 = rabinKarpSearch(text, pattern, 1000003);

    for(int pos : result1)
        cout << "Am gasit pattern-ul la pozitia = " << pos << endl;


    return 0;
}
