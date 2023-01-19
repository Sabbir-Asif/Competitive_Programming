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

int EDLength(string str1, string str2, int len1, int len2)
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

	return ed.data[len1][len2];
}

int main()
{
	string words[] = {"abaculi", "abacus", "abacuses", "abide", "abduct", "abbreviation"};
    int dataLength = words->size();
    string str1, str2;
	int arr[dataLength];
    cout << "Enter your word : ";
    cin >> str2;
    str2 = "0" + str2;
    int len2 = str2.size() - 1;
	for(int i = 0; i < dataLength; i++)
	{
		str1 = words[i];
		str1 = "0" + str1;
		int len1 = str1.size() - 1;
		ed.data = new int*[len1+1];
        ed.direction = new int*[len1+1];
        for(int i =0; i <= len1; i++)
        {
           ed.data[i] = new int[len2+1];
           ed.direction[i] = new int[len2+1];
        }

		arr[i] = EDLength(str1,str2,len1,len2);
	}

	int cmp = INT_MAX;
	int minX = -1;
	for(int i = 0; i < dataLength ; i++)
	{
		if(arr[i] < cmp)
		{
			minX = i;
			cmp = arr[i];
		}
	}
	
	cout << "Correct spelling : " << words[minX] << endl;

    return 0;
}