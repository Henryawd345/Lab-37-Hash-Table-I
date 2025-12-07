#include <iostream>
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
    string s;

    cout << "Enter a string: ";
    cin >> s;

    int result = sum_ascii(s);
    cout << "ASCII sum = " << result << endl;

    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
