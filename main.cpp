#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <list>
using namespace std;

int gen_hash_index(const string &s){
    int sum = 0;
    for (char c : s){
        sum += static_cast<int>(c);
    }
    return sum;
}

void print_100(const map<int, list<string>>&hash_table){
    int printed = 0;

    cout << "\n=== Displaying the FIRST 100 hash table entries ===\n\n";

    for (const auto &entry : hash_table) {
        if (printed >= 100) break;

        int index = entry.first;
        const list<string> &codes = entry.second;

        cout << "Index " << index << ": ";

        for (const string &c : codes) {
            cout << c << " ";
        }
        cout << endl;

        printed++;
    }
    cout << "\n(Printed entries = " << printed << ")\n";
} 

void search_key(const map<int, list<string>> &hash_table){
    string key;
    cout << "Enter key to search: ";
    cin >> key;

    int index = gen_hash_index(key);

    auto it = hash_table.find(index);
    if (it == hash_table.end()){
        cout << "key NOT found. (No bucket for index " << index << ".)\n";
        return;
    }

    const list<string> &bucket = it->second;

    auto pos = find(bucket.begin(), bucket.end(), key);

    if (pos == bucket.end()){
        cout << "Key NOT found in bucket index " << index << ".\n";
    } else {
        cout << "key FOUND in bucket index " << index << ".\n";
    }

}

int main() {
    ifstream fin("lab-37-data-2.txt");

    if (!fin.is_open()){
        cerr << "Error: could not open lab-37-data-2.txt" << endl;
        return 1;
    }

    map<int, list<string>> hash_table;
    string code;
    
    
    return 0;
} 
/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/