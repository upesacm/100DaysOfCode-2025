#include <vector>
#include <string>
#include <cctype>
using std::vector;
using std::string;

// Returns {sum of positives, vowel count}
std::pair<int, int> arraySumAndVowelCount(const vector<int>& arr, const string& s) {
	int sum = 0, vowels = 0;
	for (int x : arr) if (x > 0) sum += x;
	for (char c : s) {
		char ch = std::tolower(c);
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ++vowels;
	}
	return {sum, vowels};
}
