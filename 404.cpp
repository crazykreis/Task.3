#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	bool opencomment = false, tag = true;
	int begintag, k = 0;
	string temp;
	ifstream infile("test.txt");
	vector<string> vecfile;
	if (!infile)
	{
		cout << "Error404! No input file";
	}
	else
	{
		getline(infile, temp);
		vecfile.insert(vecfile.end(), temp);
		for (size_t i = 0; i < vecfile.size(); i++)
		{
			if (vecfile[i].find("/**", 0) != -1)
			{
				opencomment = true;
			}
			if (opencomment)
			{
				if (tag)
				{
					begintag = vecfile[i].find("\\func", 0);
				}
				else if (vecfile[i].find("*/") != 0) cout << "1\n";
				if (begintag != -1 && tag)
				{
					tag = false;
					begintag += 6;
					cout << ++k << ". ";
				}
				for (int j = 0; !tag && j < vecfile[i].size(); j++)
				{
					if (j == vecfile[i].find("*/"))
					{
						tag = true;
						opencomment = false;
						cout << "2\n";
						break;
					}
					if (j >= begintag) cout << vecfile[i][j];
				}
				if (!tag) begintag = 0;
			}
		}
	}
	system("pause");
	return 0;
}
