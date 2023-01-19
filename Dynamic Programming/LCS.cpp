#include<iostream>
#define up 1
#define left 2
#define corner 3
using namespace std;
struct LCS{
    int **data;
    int **direction;
} lcs;

void LCSLength(string str1, string str2, int len1, int len2)
{
    for(int i =0; i <= len1; i++)
    {
        lcs.data[i][0] = 0;
    }
    for(int j = 0; j <= len2; j++)
    {
        lcs.data[0][j] = 0;
    }

    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            if(str1[i] == str2[j])
            {
                lcs.data[i][j] = lcs.data[i-1][j-1] + 1;
                lcs.direction[i][j] = corner;
            }
            else if(lcs.data[i-1][j] >= lcs.data[i][j-1])
            {
                lcs.data[i][j] = lcs.data[i-1][j];
                lcs.direction[i][j] = up;
            }
            else
            {
                lcs.data[i][j] = lcs.data[i][j-1];
                lcs.direction[i][j] = left;
            }
        }
    }
}

void printLCS(struct LCS lcs, string str1, int len1, int len2)
{
    if(len1 == 0 || len2 == 0)
    return;
    if(lcs.direction[len1][len2] == corner)
    {
        printLCS(lcs, str1, len1-1, len2-1);
        cout << str1[len1] << " ";
    }
    else if(lcs.direction[len1][len2] == up)
    {
        printLCS(lcs, str1, len1-1, len2);
    }
    else
    {
        printLCS(lcs, str1, len1, len2-1);
    }
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

    //debug(lcs,len1,len2);
    LCSLength(str1,str2,len1,len2);
    cout << "Length of LCS : ";
    cout << lcs.data[len1][len2] << endl;
    cout << "Elements : ";
    printLCS(lcs,str1,len1,len2);
    cout << endl;

    return 0;
}