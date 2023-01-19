#include<iostream>
#define up 1
#define left 2
#define corner 3
using namespace std;
struct LCS{
    int **data;
    int **direction;
} lcs;

int LCSLength(string str1, string str2, int len1, int len2)
{
   if (len1 == 0 || len2 == 0)
        return 0;

    if (str1[len1] == str2[len2])
        return 1 + LCSLength(str1,str2, len1-1,len2-1);
    else
        return max(LCSLength(str1,str2,len1,len2-1), LCSLength(str1,str2,len1-1, len2));
}

int main()
{
    string str1, str2;
    cout << "Enter the first string : ";
    cin >> str1;
    str1 = "0" + str1;
    cout << "Enter the second string : ";
    cin >> str2;
    str2 = "0" + str2;
    int len1 = str1.size() - 1;
    int len2 = str2.size() - 1;

    lcs.data = new int*[len1+1];
    lcs.direction = new int*[len1+1];
    for(int i =0; i <= len1; i++)
    {
        lcs.data[i] = new int[len2+1];
        lcs.direction[i] = new int[len2+1];
    }
    
    cout << "Length of LCS : " << LCSLength(str1,str2,len1,len2) << endl;

    return 0;
}