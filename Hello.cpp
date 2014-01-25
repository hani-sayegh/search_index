#include<iostream>
#include "..\..\..\..\..\Desktop\Algorithms1\c++src\1\Sales_item.h"

//int main()
//{
//	std::cout << "Enter the data..." << std::endl;
//	Sales_item result; //Contains the result of the most recent transaction.
//
//	if (std::cin >> result)
//	{
//		Sales_item nextObject; //Contains the next transaction.
//		while (std::cin >> nextObject)
//		{
//			if (result.isbn() == nextObject.isbn())
//			{
//				result += nextObject;
//			}
//			else
//			{
//				std::cout << result << std::endl;
//				result = nextObject;
//			}
//		}
//		std::cout << "I am the final result: " << result << std::endl;
//	}
//	else
//	{
//		std::cout << "No data...aborting" << std::endl;
//		system("pause");
//		return -1;
//	}
//	system("pause");
//	return 0;
//}

//"fixed" says that floating - point numbers will be output in "fixed point format" 
//— that is, with a fixed number of digits following the decimal point.
//"scientific" uses exponential notation for numbers: e.g., 2.99E8.
//"setprecision( n )" sets the number of digits following the decimal point to n.

//#include <iostream>
//#include <string>
//#include <iomanip>
//
//using namespace std;
//
//int main()
//{
//	string test = "";
//
//	cin >> test;
//	cout << test << endl;
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int ival = 42;
//	int *p = &ival; // p holds the address of ival; p is a pointer to ival
//	std::cout << *p << std::endl;
//
//	system("pause");
//	return 0;
//}



//#include <fstream>
//#include <string>
//
//using namespace std;
//
//void copyChars()
//{
//	ifstream ifs("input.txt");
//	ofstream ofs("output.txt");
//
//	int charsCopied = 0;
//	ifs >> noskipws;
//	char key = 'a';
//	while (ifs)
//	{
//		char c;
//		ifs >> c;
//		ofs << (c ^ key);
//		++charsCopied;
//	}
//
//	ifs.close();
//	ofs.close();
//
//	cout << charsCopied << " characters copied." << endl;
//}
	
#include <fstream>
#include <string>
#include <vector>
	

using namespace std;

int main()
{
		ifstream ifs("fileNames.txt"); //Contains all other files.

		string fileName;
		ifs >> fileName; //Read the first file name.

		ifstream ifs2(fileName.c_str()); //Open the new file.

		vector<string> index; //This will contain all the different words. 
		
		string word;
		index.push_back("hani");
		while (ifs2 >> word)
		{
			index.push_back(word);
		}
		

		vector<vector<int>> documents; //Contains the different documents.
		ifstream ifs3(fileName.c_str()); //Open the file again.

		vector<int> row; //Vector for current document.

		//Go through each word in index, increment the actual index as necessary.
		for (int i = 0; i < index.size(); ++i)
		{
			string currentWord = index[i]; //Current word in index. 

			bool found = false; //Have we found the word?
			//Loop will check all words with currentWord, if match is found,
			//will increment by 1 for now, no match will increment by 0.
			while (ifs3 >> word)
			{
				if (word == currentWord)
				{
					row.push_back(1);					
					ifs3.seekg(0, ios::beg); //Reset the stream???
					found = true;
					break;
				}	
			}
			if (ifs3.eof())
			{
				ifs3.clear();
				ifs3.seekg(0, ios::beg); //Reset the stream???
			}
			if (found != true)
			{
				row.push_back(0);
			}		
		}
		documents.push_back(row);

		





















		//This is for debuging.
		int length = documents[0].size();
		for (int i = 0; i < length; ++i)
		{
			cout << documents[0][i] << endl;
		}

		//This is for debuging.
		for (string word : index)
		{
			cout << word << endl;
		}

	system("pause");
	return 0;
}
