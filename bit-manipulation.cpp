#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <limits>
#include <vector>
using namespace std;

// Short function start-->>
void printArray(int arr[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << arr[i] << " ";
    }
}
void printVector(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
}
void printVectorString(vector<string> &arr)
{
    for (auto it : arr)
    {
        cout << it << endl;
    }
}
void printVectorVector(vector<vector<int>> x)
{
    for (const auto &row : x)
    {
        cout << "[";
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "]";
        cout << std::endl;
    }
}
void printVectorVectorString(vector<vector<string>> x)
{
    for (const auto &row : x)
    {
        cout << "[";
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "]";
        cout << std::endl;
    }
}
void printString(string s, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << s[i] << " ";
    }
}
void printStack(stack<string> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// Short function end-->>

/*
1.
ANS :
Input :    || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
2.  Check whether K-th bit is set or not
ANS : Given a number ‘N’ and a number ‘K’. Return true if ‘K’th bit of number is set, else return false.
Input :  ‘N’ = 5, ‘K’ = 1 || Output : YES
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(1)
// SC : O(1)
bool isKthBitSet(int n, int k)
{
    int mask = (1 << (k - 1)); // k-1 bcz 1 based indexing
    return mask & n;
}

/*
3. ODD & EVEN Check
ANS : You are given an integer 'N'.
Return 'odd' if the given number 'N' is odd, else return 'even'.
Input :   n=5 || Output : ODD
*/
// Bruteforce ----------->
// TC : O(1)
// SC : O(1)
string oddEvenBruteforce(int N)
{
    if (N % 2 == 0)
        return "even";
    else
        return "odd";
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(1)
// SC : O(1)
string oddEvenOptimal(int N)
{
    if ((N & 1) == 1)
        return "odd";
    else
        return "even";
}

/*
4. Power of Two
ANS : You have been given an integer 'N'.
Your task is to return true if it is a power of two. Otherwise, return false.
An integer 'N' is a power of two, if it can be expressed as 2 ^ 'K' where 'K' is an integer.
Input :    || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
bool isPowerOfTwo(int n)
{
    return ((n & (n - 1)) == 0) ? true : false;
}

/*
5.  Count total set bits
ANS : For a given integer 'N', you have to return the number of set bits in the binary representation of the numbers from 1 to 'N'.
In a binary number '1' is considered as a set bit and '0' as not set.
Input :    || Output :
*/
// Bruteforce ----------->
// TC : O(logN)
// SC :O(1)
int countSetBitsBruteforce(int N)
{
    int cnt = 0;
    while (N != 0)
    {
        if ((N & 1) == 1)
            cnt++;
        N = N >> 1;
    }
    return cnt;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :  O(K), where K is the number of set bits in N.
// SC :O(1)
int countSetBitsOptimal(int N)
{
    int cnt = 0;
    while (N != 0)
    {
        N = N & (N - 1);
        cnt++;
    }
    return cnt;
}

/*
6. Set/Unset the rightmost unset bit
ANS :
Input :    || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Not right most
int unsetBits(int N)
{
    N = N & (N - 1);
    return N;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
int setBits(int N)
{
    if (N == 0)
        return 1;
    if ((N & (N + 1)) == 0)
    {
        return N; // Return N as is
    }

    return N | (N + 1);
}
/*
7.  Swap Two Numbers
ANS : You are given two numbers 'a' and 'b' as input.
You must swap the values of 'a' and 'b'.
Input :    || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
void swapNumberBruteforce(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
void swapNumberOptimal(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
/*
8. You are given two integers, ‘dividend’ and ‘divisor’.
You are required to divide the integers without using multiplication, division, and modular operators.
Your task is to return the quotient after dividing ‘dividend’ by ‘divisor’.
ANS :
Input :  dividend = 10’ and ‘divisor = 3’  || Output : 10/3 = 3.3333……’.=3
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
int divideTwoInteger(int dividend, int divisor)
{
    // Step 1: Handle special cases
    if (dividend == 0)
    {
        return 0;
    }

    // Step 2: Determine the sign of the result
    bool isNegative = (dividend < 0) != (divisor < 0);

    // Step 3: Convert both numbers to positive
    long long ldividend = std::abs(static_cast<long long>(dividend));
    long long ldivisor = std::abs(static_cast<long long>(divisor));

    // Step 4: Initialize the quotient
    long long quotient = 0;

    // Step 5: Bit manipulation for repeated subtraction
    while (ldividend >= ldivisor)
    {
        long long temp = ldivisor, multiple = 1;
        while (ldividend >= (temp << 1))
        {
            temp <<= 1;
            multiple <<= 1;
        }
        ldividend -= temp;
        quotient += multiple;
    }

    // Step 6: Adjust the sign of the result
    if (isNegative)
    {
        quotient = -quotient;
    }

    // Step 7: Ensure the result is within the 32-bit signed integer range
    quotient = std::min(std::max(quotient, static_cast<long long>(INT_MIN)), static_cast<long long>(INT_MAX));

    return static_cast<int>(quotient);
}

/*
9.Flip Bits
ANS : You are given two integers 'A' and 'B'.
Your objective is to determine the number of bit positions where the corresponding bits of ‘A’ and ‘B’ differ, i.e., the number of bits that need to be flipped in ‘A’ to obtain ‘B’.
Input :   A = 7 B = 12 || Output : 3
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(n)
// SC :O(1)
int countBitsToFlip(int A, int B)
{
    // Step 1: XOR Operation
    int xorResult = A ^ B;
    cout << xorResult << endl;

    // Step 2: Count Set Bits
    int count = 0;
    while (xorResult)
    {
        count += xorResult & 1; // Check the least significant bit
        xorResult >>= 1;        // Right shift to process the next bit
    }

    // Step 3: Return Count
    return count;
}

/*
10. One Odd Occurring
ANS : Given an array ‘ARR’ of ‘N’ integers, where all the elements occur an even number of times and only one number occurs an odd number of times.
Find and return the number which occurs an odd number of times.
Input :  [4 5 6 5 6 9 9 4 4]  || Output : 4
*/
// Bruteforce ----------->
// TC :O(n^2)
// SC :O(1)
// using 2 loop and count
int oneOddSearchBruteforce(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                cnt++;
        }
        if (cnt % 2 == 1)
            return arr[i];
    }
    return -1;
}
// Better ----------->
// TC :O(nlogn)
// SC :O(n)
int oneOddSearchBetter(vector<int> &arr, int n)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second % 2 == 1)
            return it.first;
    }
    return -1;
}
// Optimal ---------->
// TC :O(n)
// SC :O(1)
int oneOddSearchOptimal(vector<int> &arr, int n)
{
    int XOR = 0;
    for (int i = 0; i < n; i++)
    {
        XOR = XOR ^ arr[i];
    }
    return XOR;
}
/*
11. Power Set
ANS : Given an integer array nums of unique elements, return all possible subsets(the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Input :  nums = [1,2,3]  || Output : [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/
// Bruteforce ----------->
// TC : O(2^nxN) where n is the size of the input vector nums and N is the average size of the subsets.
// SC : O(2^nxN)
vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    for (int num = 0; num < (1 << n); num++)
    {
        vector<int> a;
        for (int bits = 0; bits < n; bits++)
        {
            if (num & (1 << bits))
                a.push_back(nums[bits]);
        }
        ans.push_back(a);
    }
    return ans;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
12.  L to R XOR
ANS : You are given two numbers 'L' and 'R'.
Find the XOR of the elements in the range [L, R].
Input :  L=1 R=5  || Output : 1
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(1)
// SC :
int findXOR(int L, int R)
{
    auto xorUpToN = [](int n)
    {
        int mod = n % 4;

        if (mod == 0)
            return n;

        if (mod == 1)
            return 1;

        if (mod == 2)
            return n + 1;

        return 0;
    };

    // XOR of numbers from 0 to R

    int xorResultR = xorUpToN(R);

    // XOR of numbers from 0 to L-1

    int xorResultL = xorUpToN(L - 1);

    // XOR of numbers in the range [L, R]

    int result = xorResultR ^ xorResultL;

    return result;
}

/*
13. Two Numbers With Odd Occurrences
ANS : You are given an array 'arr' of size 'n'.
It contains an even number of occurrences for all numbers except two numbers.
Find those two numbers which have odd occurrences and return in decreasing order.
Input :   'arr' = {2, 4, 1, 3, 2, 4}  || Output : {3,1}
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
vector<int> twoOddNum(vector<int> arr)
{
    int XOR = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        XOR = XOR ^ arr[i];
    }
    int cnt = 0;
    while (XOR)
    {
        if (XOR & 1)
            break;
        cnt++;
        XOR = XOR >> 1;
    }
    int XOR1 = 0, XOR2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] & (1 << cnt))
            XOR1 = XOR1 ^ arr[i];
        else
            XOR2 = XOR2 ^ arr[i];
    }
    if (XOR1 < XOR2)
        return {XOR2, XOR1};
    return {XOR1, XOR2};
}

/*
14. Count Primes
ANS : You are given an integer 'N'.
You must return the unique prime factors of 'N' in increasing order.
Input :  N=10  || Output : [2,5]
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
//  Time Complexity: O(Nlog(log(N))).
//    Space Complexity: O(N).
vector<int> countPrimes(int n)
{
    vector<bool> isPrime(n, true);
    vector<int> ans;
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i] == true)
        {
            if (n % i == 0)
            {
                ans.push_back(i);
            }
            for (int j = i * 2; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    return ans;
}

/*
15.  Print all Divisors of a number
ANS : Given an integer ‘N’, your task is to write a program that returns all the divisors of ‘N’ in ascending order.
Input :N=10   || Output : 1 2 5 10
*/
// Bruteforce ----------->
// TC : O(sqrt(n)) remeber O(NlogN) for sorting but its constant
// SC : O(1)
vector<int> printDivisorsBruteforce(int n)
{
    vector<int> ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if (n / i != i)
            {
                ans.push_back(n / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(N)
// SC :O(1)
vector<int> printDivisorsOptimal(int n)
{
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

/*
16. POW set
ANS :
Input :    || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
17. POW set
ANS :
Input :    || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
18. Power(x,n)
ANS : Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
Input: x = 2.00000, n = 10
Output: 1024.00000

*/
// Bruteforce ----------->
// TC :O(N)
// SC :
double myPowBruteforce(double x, int n)
{
    if (n < 0)
    {
        x = 1 / x;
    }

    long num = labs(n);

    double pow = 1;

    while (num)
    { // equivalent to while(num != 0)
        if (num & 1)
        { // equivalent to if((num & 1) != 0)
            pow *= x;
        }

        x *= x;
        num >>= 1;
    }

    return pow;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :  O(logN)
// SC :
double myPowOptimal(double x, int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
    {
        n = abs(n);
        x = 1 / x;
    }
    if (n % 2 == 0)
    {
        return myPowOptimal(x * x, n / 2);
    }
    else
    {
        return x * myPowOptimal(x, n - 1);
    }
}

/*
1. POW set
ANS :
Input :    || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
void powset(vector<int> &arr)
{
    int n = arr.size();
    for (int num = 0; num < (1 << n); num++)
    {
        vector<int> a;
        for (int bit = 0; bit < n; bit++)
        {
            if (num & (1 << bit))
                a.push_back(arr[bit]);
        }
        printVector(a);
    }
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
2. Petr and a Combination Lock
ANS :
Input :    || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
bool petrAndcombi(vector<int> &arr)
{
    int n = arr.size();
    bool flag = false;
    for (int num = 0; num < (1 << n); num++)
    {
        int sum = 0;
        for (int bit = 0; bit < n; bit++)
        {
            if (num & (1 << bit))
                sum += arr[bit];
            else
                sum -= arr[bit];
        }
        if (sum % 360 == 0)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

// ================================MAIN START=================================>>
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("./i.txt", "r", stdin);
    //     freopen("./o.txt", "w", stdout);
    // #endif
    /*
        Some short function
           int maxi = *max_element(arr.begin(), arr.end());
            int sum = accumulate(arr.begin(), arr.end(), 0);
    */

    vector<int> arr = {2, 4, 1, 3, 2, 4};
    // powset(arr);
    int n = 14;
    int m = 3;
    // cout << isKthBitSet(n, 1);
    // cout<<oddEvenBruteforce(n);
    // cout<<oddEvenOptimal(n);
    // cout<<isPowerOfTwo(n);
    // cout << countSetBitsBruteforce(n);
    // cout<<setBits(n)<<endl;
    // cout << unsetBits(n);
    // cout << n << ' ' << m;
    // swapNumberBruteforce(n,m);
    // swapNumberOptimal(n, m);
    // cout << endl;
    // cout << n << ' ' << m;
    // cout << divideTwoInteger(10, 3);
    // cout<<countBitsToFlip(n,m);
    // cout << oneOddSearchBruteforce(arr, arr.size());
    // cout << oneOddSearchBetter(arr, arr.size());
    // cout << oneOddSearchOptimal(arr, arr.size());

    // vector<vector<int>> sub = subsets(arr);
    // printVectorVector(sub);
    // vector<int> ans = twoOddNum(arr);
    // printVector(ans);
    // vector<int> ans = countPrimes(n);
    // vector<int> ans = printDivisorsBruteforce(n);
    // vector<int> ans = printDivisorsOptimal(n);
    // printVector(ans);

    // cout << myPowBruteforce(2.00, 10);
    cout << myPowOptimal(2.00, 10);

    // cout << petrAndcombi(arr);

    // End code here-------->>

    return 0;
}
