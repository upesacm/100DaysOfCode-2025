#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<int,int> analyzeArrayAndString(vector<int>& arr, string s) {
    int sum = 0;
    for (int x : arr) if (x > 0) sum += x;

    int vowels = 0;
    for (char c : s) {
        char ch = tolower(c);
        if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') vowels++;
    }

    return {sum, vowels};
}

int main() {
    vector<int> arr = {1, -2, 3, -4, 5};
    string s = "Hello World";

    auto [sum, vowels] = analyzeArrayAndString(arr, s);
    cout << "Sum: " << sum << ", Vowels: " << vowels << endl;
    return 0;
}
