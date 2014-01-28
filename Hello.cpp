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
#include <cctype>
#include <algorithm>

using namespace std;

char change_case(char c) 
{
	if (std::isupper(c))
		return std::tolower(c);
	else
	{
		return c;
	}
}

int main()
{
	////For debugging.
	//cout << sqrt(25) << endl;
	//system("pause");

	ifstream ifs("fileNames.txt"); //Contains all other files.
	string fileName;

	vector<string> index; //This will contain all the different words. 
	while (ifs >> fileName) //Read all content of all file names.
	{
		ifstream ifs2(fileName.c_str()); //Open the new file.
		string word;
		while (ifs2 >> word)
		{
			std::transform(word.begin(), word.end(), word.begin(), change_case);

			bool duplicate = false;

			//Checks for duplicates by comparing current word to rest of index.			
			for (int i = 0; i < index.size(); ++i)
			{
				if (word == index[i])
				{
					duplicate = true;
					break;
				}
			}
			if (!duplicate)
			{
				index.push_back(word);
			}
		}
	}

	//This is for debuging.
	std::cout << endl << "This is the contents of the index:- " << endl << endl;
	for (string word : index)
	{
		std::cout << "\"" << word << "\"" << "\t";
	}
	std::cout << endl << endl;
	//@ this point the whole index should have been created.
	/*************************************************************/

	ifstream openAgain("fileNames.txt"); //Contains all other files.
	string fileName2, word2;
	vector<vector<int>> documents; //Contains the different documents.
	int debugging = 0;

	while (openAgain >> fileName2)
	{
		ifstream ifs3(fileName2.c_str()); //Open the file again.

		vector<int> row; //Vector for current document.

		//Go through each word in index, increment the actual index as necessary.
		for (int i = 0; i < index.size(); ++i)
		{
			string currentWord = index[i]; //Current word in index. 

			//Loop will check all words with currentWord, if match is found,
			//will increment by 1 for now, no match will increment by 0.
			int frequency = 0;
			while (ifs3 >> word2)
			{
				std::transform(word2.begin(), word2.end(), word2.begin(), change_case);

				if (word2 == currentWord)
				{
					++frequency;
				}
			}
			row.push_back(frequency);

			if (ifs3.eof())
			{
				ifs3.clear();
				ifs3.seekg(0, ios::beg); //Reset the stream???
			}
		}
		documents.push_back(row);

		//This is for debuging.
		int length = documents[debugging].size();
		std::cout << "This contains the vector of the " 
			      << debugging + 1 
				  << "st document" 
				  << endl;

		for (int i = 0; i < length; ++i)
		{
			std::cout << documents[debugging][i] << "\t ";
		}
		std::cout << endl << endl;
		++debugging;
	}

		
	std::cout << "Enter your query:-" << endl;
	vector<string> totalQuery;
	string query;
	while (cin >> query) //Only reads first???//How to not use control z.
	{
		std::transform(query.begin(), query.end(), query.begin(), change_case);
		totalQuery.push_back(query);		
	}

	vector<int> queryVector; //Contains vector of the query.
	for (int i = 0; i < index.size(); ++i)
	{
		string currentWord = index[i];
		int frequency = 0;
		for (int j = 0; j < totalQuery.size(); ++j)
		{
			if (totalQuery[j] == index[i]) //.equals() for string?
			{
				++frequency;
			}
		}
		queryVector.push_back(frequency);
	}

	vector<double> cosSimValues;
	for (int allDocs = 0; allDocs < documents.size(); ++allDocs)
	{
		int numerator = 0; //needs queryVector & documets[i] vector for now.
		//Does seem to give warning for reuse of i when bulding, can u change settings?
		for (int i = 0; i < queryVector.size(); ++i)
		{
			numerator += queryVector[i] * documents[allDocs][i];
		}

		double queryDistance = 0.0;
		for (int i = 0; i < queryVector.size(); ++i)
		{
			queryDistance += pow(queryVector[i], 2);	//#include ????
		}
		queryDistance = sqrt(queryDistance);
		/*****************************************************************/
		double docVectorDistance = 0;
		for (int i = 0; i < queryVector.size(); ++i)
		{
			docVectorDistance += pow(documents[allDocs][i], 2);	//#include ????
		}
		docVectorDistance = sqrt(docVectorDistance);

		double denominator = docVectorDistance * queryDistance;

		double cosineSimilarity = numerator / denominator;
		cosSimValues.push_back(cosineSimilarity);
	}

	vector<double> copy = cosSimValues;
	sort(cosSimValues.begin(), cosSimValues.end()); //Why not by reference? Maybe
	                                               //Cuz of actual function.


	ifstream documentNames("fileNames.txt");
	vector<string> allDocumentNames;
	string theName;
	while (documentNames >> theName)
	{
		allDocumentNames.push_back(theName);
	}

	int top = 1; //TODO fix bug.
	int highest = cosSimValues.size() - 1;
	for (int i = highest; i > highest - top; --i)
	{
		string finallyyy;
		for (int gogo = 0; gogo < copy.size(); ++gogo)
		{
			if (cosSimValues[i] == copy[gogo])
			{
				finallyyy = allDocumentNames[gogo];
				break;
			}
		}
		cout << "Rank" << i - top << ": " << finallyyy << " " 
			 << cosSimValues[i] << endl;
	}








	

























	std::system("pause");
	return 0;
}
