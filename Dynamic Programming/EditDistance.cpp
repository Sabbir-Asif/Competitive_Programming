#include<iostream>
#define up 1
#define left 2
#define corner 3
#define noEdit 4
using namespace std;
struct ED{
    int **data;
    int **direction;
} ed;

void EDLength(string str1, string str2, int len1, int len2)
{
    for(int i =0; i <= len1; i++)
    {
        ed.data[i][0] = i;
        ed.direction[i][0] = up;
    }
    for(int j = 0; j <= len2; j++)
    {
        ed.data[0][j] = j;
        ed.direction[0][j] = left;
    }
    
    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            if(str1[i] == str2[j])
            {
                ed.data[i][j] = ed.data[i-1][j-1];
                ed.direction[i][j] = noEdit;
            }
            else
            {
                if(ed.data[i-1][j-1] <= ed.data[i-1][j] && ed.data[i-1][j-1] <= ed.data[i][j-1])
                {
                    ed.data[i][j] = ed.data[i-1][j-1] + 1;
                    ed.direction[i][j] = corner;
                }
                else if(ed.data[i][j-1] <= ed.data[i-1][j-1] && ed.data[i][j-1] <= ed.data[i-1][j])
                {
                    ed.data[i][j] = ed.data[i][j-1] + 1;
                    ed.direction[i][j] = left;
                }
                else
                {
                    ed.data[i][j] = ed.data[i-1][j] + 1;
                    ed.direction[i][j] = up;
                }
            }
        }
    }
}

void printED(struct ED ed, string str1, string str2,int i, int j)
{
    if(i == 0 && j == 0)
    return;
    if(ed.direction[i][j] == corner)
    {
        printED(ed, str1, str2, i-1, j-1);
        cout << "* Replace " << str1[i-1] << " by " << str2[j];
    }
    else if(ed.direction[i][i] == up)
    {
        printED(ed, str1, str2, i-1, j);
        cout << "* Delete " << str1[i] << " from str1" << endl;
    }
    else if(ed.direction[i][i] == left)
    {
        printED(ed, str1, str2, i, j-1);
        cout << "* Insert " << str2[j] << " in str1 at position " << i << endl;
    }
    else
    {
        printED(ed, str1, str2, i-1, j-1);
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

    ed.data = new int*[len1+1];
    ed.direction = new int*[len1+1];
    for(int i =0; i <= len1; i++)
    {
        ed.data[i] = new int[len2+1];
        ed.direction[i] = new int[len2+1];
    }

    //debug(lcs,len1,len2);
    EDLength(str1,str2,len1,len2);
    cout << "Minimum edit distance : ";
    cout << ed.data[len1][len2] << endl;
    cout << "Elements : ";
    printED(ed,str1,str2,len1,len2);
    cout << endl;

    return 0;
}