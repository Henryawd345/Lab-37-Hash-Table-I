#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int sum_ascii(const string &s){
    int sum = 0;
    for (char c : s){
        sum += static_cast<int>(c);
    }
    return sum;
}

int main() {
    ifstream fin("lab-37-data-2.txt");

    if (!fin){
        cerr << "Error: could not open lab-37-data.txt" << endl;
        return 1;
    }

    string code;
    long long grand_total = 0;
    int count = 0;
    
    while (fin >> code){
        if (count < 5){
            cout << "Read code: " << code << endl;
        }
        grand_total += sum_ascii(code);
        count++;
    }

    cout << "Total codes read = " << count << endl;
    cout << "Grand total ASCII sum = " << grand_total << endl;


} 

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/