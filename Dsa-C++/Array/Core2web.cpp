#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;



// Q1: Check if array is sorted
bool isSorted(vector<int> arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Q2: Find transition point (first index where 1 appears)
int transitionPoint(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) return i;
    }
    return -1; // no 1 found
}

// Q3: Diagonal sums
void diagonalSums(vector<vector<int>> matrix) {
    int N = matrix.size();
    int leftSum = 0, rightSum = 0;

    for (int i = 0; i < N; i++) {
        leftSum += matrix[i][i];
        rightSum += matrix[i][N - 1 - i];
    }

    int total = leftSum + rightSum;
    if (N % 2 == 1) {
        int middle = matrix[N / 2][N / 2];
        total -= middle; 
    }

    cout << "Left Diagonal Sum: " << leftSum << endl;
    cout << "Right Diagonal Sum: " << rightSum << endl;
    cout << "Total Sum of Both: " << total << endl;
}

// Find first and last occurrence of X
vector<int> firstAndLastOccurrence(vector<int> arr, int X) {
    int first = -1, last = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == X) {
            if (first == -1) first = i;
            last = i;
        }
    }
    vector<int> result;
    result.push_back(first);
    result.push_back(last);
    return result;
}

// Replace all 0s with 5 in given numbers
vector<int> replaceZerosWithFives(vector<int> arr) {
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
        string s = to_string(arr[i]);
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '0') s[j] = '5';
        }
        result.push_back(stoi(s));
    }
    return result;
}

// Count palindrome numbers
int countPalindromes(vector<int> arr) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        string s = to_string(arr[i]);
        string rev = s;
        reverse(rev.begin(), rev.end());
        if (s == rev) count++;
    }
    return count;
}

// Find first repeating element
int firstRepeatingElement(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] == arr[j]) {
                return arr[i];
            }
        }
    }
    return -1;
}

// Find most frequent element
int mostFrequentElement(vector<int> arr) {
    int maxCount = 0;
    int mostFreq = -1;
    for (int i = 0; i < arr.size(); i++) {
        int count = 0;
        for (int j = 0; j < arr.size(); j++) {
            if (arr[i] == arr[j]) count++;
        }
        if (count > maxCount) {
            maxCount = count;
            mostFreq = arr[i];
        }
    }
    if (maxCount <= 1) return -1;
    return mostFreq;
}

// Find majority element (more than n/2 times)
int majorityElement(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        int count = 0;
        for (int j = 0; j < arr.size(); j++) {
            if (arr[i] == arr[j]) count++;
        }
        if (count > arr.size() / 2) return arr[i];
    }
    return -1;
}

// Find second largest distinct element
int secondLargestDistinct(vector<int> arr) {
    int largest = INT_MIN, second = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
        } else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }
    if (second == INT_MIN) return -1;
    return second;
}

// Count frequencies of unique elements
map<int, int> uniqueElementCounts(vector<int> arr) {
    map<int, int> freq;
    for (int i = 0; i < arr.size(); i++) {
        freq[arr[i]]++;
    }
    return freq;
}

// Count intersection of two arrays
int intersectionCount(vector<int> a, vector<int> b) {
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                count++;
                break;
            }
        }
    }
    return count;
}

// Rotate array left by D
vector<int> rotateLeft(vector<int> arr, int D) {
    int N = arr.size();
    vector<int> result;
    D = D % N;
    for (int i = D; i < N; i++) result.push_back(arr[i]);
    for (int i = 0; i < D; i++) result.push_back(arr[i]);
    return result;
}

// Range sum queries
vector<int> rangeSumQueries(vector<int> arr, vector<pair<int, int>> queries) {
    vector<int> result;
    for (int i = 0; i < queries.size(); i++) {
        int L = queries[i].first;
        int R = queries[i].second;
        int sum = 0;
        for (int j = L; j <= R; j++) {
            sum += arr[j];
        }
        result.push_back(sum);
    }
    return result;
}

// Push zeros to end
vector<int> pushZerosToEnd(vector<int> arr) {
    vector<int> result;
    int zeroCount = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) result.push_back(arr[i]);
        else zeroCount++;
    }
    for (int i = 0; i < zeroCount; i++) result.push_back(0);
    return result;
}

int main() {
   
    vector<int> arr1 = {10, 20, 30, 40, 50};
    cout << "Array Sorted? " << (isSorted(arr1) ? "Yes" : "No") << endl;

    
    vector<int> arr2 = {0, 0, 0, 1, 1};
    cout << "Transition Point: " << transitionPoint(arr2) << endl;

   
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    diagonalSums(matrix);

   
    vector<int> a1 = {1,2,2,3,3,3,4};
    vector<int> fl = firstAndLastOccurrence(a1, 3);
    cout << "First and Last Occurrence of 3: " << fl[0] << ", " << fl[1] << endl;

    vector<int> a2 = {1004, 120, 500, 121};
    vector<int> r1 = replaceZerosWithFives(a2);
    cout << "Replace 0 with 5: ";
    for (int i = 0; i < r1.size(); i++) cout << r1[i] << " ";
    cout << endl;

    vector<int> a3 = {121,131,20,33,44,55};
    cout << "Palindrome Count: " << countPalindromes(a3) << endl;

    vector<int> a4 = {1,5,3,4,3,5,6};
    cout << "First Repeating Element: " << firstRepeatingElement(a4) << endl;

    vector<int> a5 = {1,3,2,3,4,3};
    cout << "Most Frequent Element: " << mostFrequentElement(a5) << endl;

    vector<int> a6 = {3,1,3,3,2};
    cout << "Majority Element: " << majorityElement(a6) << endl;

    vector<int> a7 = {12,35,1,10,34,1};
    cout << "Second Largest Distinct: " << secondLargestDistinct(a7) << endl;

    vector<int> a8 = {1,3,2,1,4,1,3,2};
    map<int,int> freq = uniqueElementCounts(a8);
    cout << "Frequencies:\n";
    for (map<int,int>::iterator it = freq.begin(); it != freq.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    vector<int> a9 = {1,2,3,4,5,6};
    vector<int> b9 = {3,4,5,6,7};
    cout << "Intersection Count: " << intersectionCount(a9,b9) << endl;

    vector<int> a10 = {1,2,3,4,5};
    vector<int> rot = rotateLeft(a10, 2);
    cout << "Rotated Left by 2: ";
    for (int i = 0; i < rot.size(); i++) cout << rot[i] << " ";
    cout << endl;

    vector<int> a11 = {2,4,6,8,10};
    vector<pair<int,int>> q11;
    q11.push_back(make_pair(0,2));
    q11.push_back(make_pair(1,3));
    q11.push_back(make_pair(2,4));
    vector<int> sums = rangeSumQueries(a11,q11);
    cout << "Range Sums: ";
    for (int i = 0; i < sums.size(); i++) cout << sums[i] << " ";
    cout << endl;

    vector<int> a12 = {5,0,0,4};
    vector<int> pushed = pushZerosToEnd(a12);
    cout << "Zeros Pushed to End: ";
    for (int i = 0; i < pushed.size(); i++) cout << pushed[i] << " ";
    cout << endl;

    return 0;
}