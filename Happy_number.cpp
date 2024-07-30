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

































/*
CODE EXPLANATION:

vector<char> into_string(int n) {
    string str = to_string(n);
    vector<char> num;
    for (int i = 0; i < str.size(); i++) {
        num.push_back(str[i]);
    }
    return num;
}

Explanation:

Purpose: This function converts an integer n into a vector of characters representing each digit.
Process:Convert the integer n to a string using to_string(n).
        Iterate over the string, pushing each character into the vector num.


vector<int> into_int(vector<char>& c) {
    vector<int> no;
    for (int i = 0; i < c.size(); i++) {
        int temp = c[i] - '0';  // Convert character to integer
        no.push_back(temp);
    }
    return no;
}
Explanation:

Purpose: This function converts a vector of characters c into a vector of integers.
Process:Iterate over the vector c of characters.
        Convert each character to an integer using c[i] - '0' and store it in the vector no.

int sumation(vector<int>& v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i] * v[i];
    }
    return sum;
}

Explanation:

Purpose: This function calculates the sum of the squares of the integers in the vector v.

Process:  Initialize sum to 0.
          Iterate over the vector v, adding the square of each element to sum.

  bool isHappy(int n) {
    set<int> seen;  // To detect cycles
    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        vector<char> str = into_string(n);
        vector<int> copy = into_int(str);
        n = sumation(copy);
    }
    return n == 1;
}

Explanation:

Purpose: This function determines if a number n is a happy number. A happy number is one where the sum of the squares of its digits eventually equals 1.
Process:
          Use a set seen to track numbers that have been processed, helping to detect cycles.
          Continue transforming the number n by:
          Converting n to a vector of characters with into_string.
          Converting this vector of characters to a vector of integers with into_int.
          Calculating the sum of the squares of these integers with sumation.
          If n becomes 1, return true (the number is happy). If a cycle is detected (the number is already in seen), return false (the number is not happy).




mistakes that i did initially ::


vector<char> into_string(int n){
    string str=to_string(n);
    vector<char>num;
    for(int i=0;i<str.size();i++){
        num.push_back(i);
    }
    return num;
}

Mistake: In the loop, num.push_back(i); should push str[i] instead of the index i.
Correction: Change num.push_back(i); to num.push_back(str[i]);.

vector<int> into_int(vector<char>&c){
    vector<int> no;
    for(int i=0;i<c.size();i++){
        int temp = stoi(i);
        no.push_back(temp);
    }
    return no;
}
Mistake: stoi(i); is incorrect because i is an integer index, not a character.
Correction: Convert c[i] to an integer using c[i] - '0'.

int sumation(vector<int>&v){
    int sum=0,counter=0,i=0;
    while(sum!=1&&counter!=1000){
        sum=sum+(v[i]*v[i]);
        i++;
        counter++;
    }
    return sum;
}

Mistake: The stopping condition sum != 1 && counter != 1000 is incorrect because sum should not affect the loop's continuation directly. Instead, you need to iterate through all the elements in v.
Correction: Iterate through all elements in the vector v and sum the squares of the digits.

bool isHappy(int n) {
    if(n < 10) return false;
    vector<char> str = into_string(n);
    vector<int> copy = into_int(str);
    int total_sum = sumation(copy);
    return total_sum == 1;
}

Mistake: The condition if(n < 10) return false; is incorrect because a single-digit number can be a happy number (for example, 1 or 7).
Mistake: Incorrectly using vectors in str.push_back(into_string(n)); and copy.push_back(into_int(str));.
Correction: Properly assign the result of into_string and into_int to vectors, and loop to calculate sums of squares until the number becomes 1 or a cycle is detected.


SET STL 
set is a part of the Standard Template Library (STL) in C++. The STL provides a set of template classes and functions for common data structures and algorithms. The set container in the STL is used to store unique elements in a specific order.

Key Features of std::set:
Unique Elements: A set automatically ensures that all elements are unique. If you try to insert a duplicate element, the set will not store it again.
Ordered Elements: The elements in a set are stored in a sorted order based on the element values. This ordering is typically in ascending order, but you can customize it by providing a comparator.
Efficient Operations: Common operations like insertion, deletion, and search have logarithmic time complexity, O(log n), due to the underlying balanced binary search tree structure (usually implemented as a Red-Black tree).
Common Operations:
Insertion: s.insert(value);
Deletion: s.erase(value);
Search: s.find(value); returns an iterator to the element or s.end() if not found.
Traversal: You can iterate over the elements in a set using iterators.

*/
