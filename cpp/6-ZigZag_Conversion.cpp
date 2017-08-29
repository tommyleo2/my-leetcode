/**
   The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

   P   A   H   N
   A P L S I I G
   Y   I   R
   And then read line by line: "PAHNAPLSIIGYIR"
   Write the code that will take a string and make this conversion given a number of rows:

   string convert(string text, int nRows);
   convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

#include "headers.hpp"

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    vector<string> strings;
    for (int i = 0; i < numRows; i++) {
      strings.push_back(string());
    }
    int row = 0;
    bool upward = true;
    for (char ch : s) {
      strings[row].push_back(ch);
      if (upward) {
        if (row < numRows - 1) {
          row++;
        } else {
          row--;
          upward = false;
        }
      } else {
        if (row > 0) {
          row--;
        } else {
          row++;
          upward = true;
        }
      }
    }
    string result;
    for (string &str: strings) {
      result += str;
    }
    return result;
  }
};

int main(void) {
  Solution s;
  string result = s.convert("PAYPALISHIRING", 1);
  cout << result << endl << (result ==  "PAHNAPLSIIGYIR") << endl;
  return 0;
}
