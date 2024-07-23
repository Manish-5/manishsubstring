
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SubstringAnalyzer {
public:
    string getMaxCommonSubstring(const string& str1, const string& str2) {
        int len1 = str1.length(), len2 = str2.length();
        vector<vector<int>> commonLengths(len1 + 1, vector<int>(len2 + 1, 0));
        int longestLength = 0, endIndex = 0;

        // Populate the commonLengths table with lengths of common substrings
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (str1[i-1] == str2[j-1]) {
                    commonLengths[i][j] = commonLengths[i-1][j-1] + 1;
                    if (commonLengths[i][j] > longestLength) {
                        longestLength = commonLengths[i][j];
                        endIndex = i;
                    }
                }
            }
        }

        // Retrieve the longest common substring based on the table
        return str1.substr(endIndex - longestLength, longestLength);
    }

    void showTable(const string& str1, const string& str2) {
        int len1 = str1.length(), len2 = str2.length();
        vector<vector<int>> commonLengths(len1 + 1, vector<int>(len2 + 1, 0));

        // Calculate the lengths for common substrings
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    commonLengths[i][j] = commonLengths[i - 1][j - 1] + 1;
                }
            }
        }

        // Display the table of common substring lengths
        cout << "   ";
        for (int j = 0; j < len2; ++j) {
            cout << str2[j] << " ";
        }
        cout << endl;

        for (int i = 0; i <= len1; ++i) {
            if (i > 0) {
                cout << str1[i - 1] << " ";
            } else {
                cout << "  ";
            }
            for (int j = 0; j <= len2; ++j) {
                cout << commonLengths[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    string input1, input2;
    SubstringAnalyzer analyzer;

    cout << "Please enter the first sequence: ";
    cin >> input1;

    cout << "Please enter the second sequence: ";
    cin >> input2;

    // Display the table before finding the longest common substring
    cout << "Common Substring Lengths Table:" << endl;
    analyzer.showTable(input1, input2);

    string longestCommonSubstring = analyzer.getMaxCommonSubstring(input1, input2);
    cout << "The longest common substring is: " << longestCommonSubstring << endl;
    cout << "Its length is: " << longestCommonSubstring.length() << endl;

    return 0;
}
