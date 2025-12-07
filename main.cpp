#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(const string &s){
    int sum = 0;
    for (char c : s){
        sum += static_cast<int>(c);
    }
    return sum;
}

int main() {
    ifstream fin("lab-37-data-2.txt");

    if (!fin.is_open()){
        cerr << "Error: could not open lab-37-data-2.txt" << endl;
        return 1;
    }

    map<int, list<string>> hash_table;
    string code;
    
    while (fin >> code){
        int index = gen_hash_index(code);
        hash_table[index].push_back(code);
    }
    fin.close();

    int printed = 0;

    cout << "=== Displaying the FIRST 100 hash table entries ===" << endl << endl;

    for (const auto &entry : hash_table) {
        int index = entry.first;
        const list<string> &codes = entry.second;

        cout << "Index " << index << ": ";

        for (const string &c : codes) {
            cout << c << " ";
        }
        cout << endl;

        printed++;

        if (printed >= 100) {
            break;   
        }
    }
    return 0;

} 

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/