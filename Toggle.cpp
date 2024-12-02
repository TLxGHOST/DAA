#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<string> splitString(const string &s, int length) {
    vector<string> result;
    for (int i = 0; i < s.size(); i += length) {
        result.push_back(s.substr(i, length));
    }
    return result;
}


bool isValidToggle(const string &current, const string &target) {
    int diff = 0;
    for (int i = 0; i < 9; ++i) {
        if (current[i] != target[i]) {
            diff++;
            if (diff > 1) return false;
        }
    }
    return true;
}

void generateNumbers(const vector<string> &digits, const vector<string> &input, long long &sum) {
    vector<string> results(1, "");
    for (const string &segment : input) {
        vector<string> newResults;
        for (const string &partial : results) {
            for (int i = 0; i < 10; ++i) {
                if (isValidToggle(segment, digits[i])) {
                    newResults.push_back(partial + to_string(i));
                }
            }
        }
        results.swap(newResults);
    }
    for (const string &number : results) {
        sum += stoll(number);
    }
}

int main() {
    vector<string> digits(10);
    for (int i = 0; i < 3; ++i) {
        string line;
        cin >> line;
        vector<string> split = splitString(line, 3);
        for (int j = 0; j < 10; ++j) {
            digits[j] += split[j];
        }
    }
    vector<string> input(3), segments;
    for (int i = 0; i < 3; ++i) {
        cin >> input[i];
    }
    for (int i = 0; i < input[0].size() / 3; ++i) {
        string segment;
        for (int j = 0; j < 3; ++j) {
            segment += input[j].substr(i * 3, 3);
        }
        segments.push_back(segment);
    }
    for (const string &segment : segments) {
        bool valid = false;
        for (int i = 0; i < 10; ++i) {
            if (isValidToggle(segment, digits[i])) {
                valid = true;
                break;
            }
        }
        if (!valid) {
            cout << "Invalid" << endl;
            return 0;
        }
    }
    long long sum = 0;
    generateNumbers(digits, segments, sum);
    cout << sum << endl;
    return 0;
}