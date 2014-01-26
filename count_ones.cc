/*Write a function
 *  
 *      class Solution { public int hex_bitcount(String S);  }
 *       
 *       that, given a string S consisting of N characters containing a
 *       big-endian hexadecimal representation of a non-negative integer M,
 *       returns the number of bits set to 1 in the binary representation of
 *       number M.
 *        
 *       Assume that:
 *         
 *       N is an integer within the range [1..100,000];
 *       string S consists only of the following characters:
 *       0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E and/or
 *       F.
 *                          
 *       For example, given S = "2F", the function should
 *       return 5, because string "2F" represents number 47,
 *       the binary representation of number 47 is 101111
 *       and it contains five bits set to 1.
 *                           
 *       Complexity:
 *                            
 *       expected worst-case time complexity is
 *       O(N);
 *       expected worst-case space
 *       complexity is O(1) (not counting
 *       the storage required for input
 *       arguments).
 *       By Codility Limited.
 */
#include <iostream>
#include <string>
using namespace std;

int hex_bitcount1(string s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
       int cur_digit = (s[i] > 64) ? s[i] - 55 : s[i] - 48;

       int count_zero = 0;
       while (cur_digit)
       {
           cur_digit = cur_digit & (cur_digit - 1);
           count_zero++;
       }
       sum += count_zero;
    }
    return sum;
}

int hex_bitcount2(string s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
       int cur_digit = (s[i] > 64) ? s[i] - 55 : s[i] - 48;

       while (cur_digit)
       {
           sum += cur_digit & 1;
           cur_digit = cur_digit >> 1;
       }
    }
    return sum;
}

int main(int argc, char** argv)
{
    string s1("5F");
    string s2("0");
    string s3("C9");
    string s4("ABC8D");

    cout << s1 << ": " << hex_bitcount1(s1) << endl;
    cout << s2 << ": " << hex_bitcount1(s2) << endl;
    cout << s3 << ": " << hex_bitcount1(s3) << endl;
    cout << s4 << ": " << hex_bitcount1(s4) << endl;
    cout << endl;

    cout << s1 << ": " << hex_bitcount2(s1) << endl;
    cout << s2 << ": " << hex_bitcount2(s2) << endl;
    cout << s3 << ": " << hex_bitcount2(s3) << endl;
    cout << s4 << ": " << hex_bitcount2(s4) << endl;
 
    return 0;
}
