/*
Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:

  Starting with any positive integer, replace the number by the sum of the squares of its digits.
  Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
  Those numbers for which this process ends in 1 are happy.
  Return true if n is a happy number, and false if not.

Example 1:
Input: n = 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

Example 2:
Input: n = 2
Output: false
 
Constraints:
1 <= n <= 231 - 1

*/
class Solution {
public:
    // Convert an integer to a vector of its digits (characters).
    vector<char> into_string(int n) {
        string str = to_string(n);
        vector<char> num;
        for (int i = 0; i < str.size(); i++) {
            num.push_back(str[i]);
        }
        return num;
    }

    // Convert a vector of characters to a vector of integers.
    vector<int> into_int(vector<char>& c) {
        vector<int> no;
        for (int i = 0; i < c.size(); i++) {
            int temp = c[i] - '0'; // Convert character to integer
            no.push_back(temp);
        }
        return no;
    }

    // Calculate the sum of squares of the digits.
    int sumation(vector<int>& v) {
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += v[i] * v[i];
        }
        return sum;
    }

    // Determine if a number is a happy number.
    bool isHappy(int n) {
        set<int> seen; // To detect cycles
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            vector<char> str = into_string(n);
            vector<int> copy = into_int(str);
            n = sumation(copy);
        }
        return n == 1;
    }
};
