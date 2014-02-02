//#include<iostream>
//#include "..\..\..\..\..\Desktop\Algorithms1\c++src\1\Sales_item.h"
//
////int main()
////{
////	std::cout << "Enter the data..." << std::endl;
////	Sales_item result; //Contains the result of the most recent transaction.
////
////	if (std::cin >> result)
////	{
////		Sales_item nextObject; //Contains the next transaction.
////		while (std::cin >> nextObject)
////		{
////			if (result.isbn() == nextObject.isbn())
////			{
////				result += nextObject;
////			}
////			else
////			{
////				std::cout << result << std::endl;
////				result = nextObject;
////			}
////		}
////		std::cout << "I am the final result: " << result << std::endl;
////	}
////	else
////	{
////		std::cout << "No data...aborting" << std::endl;
////		system("pause");
////		return -1;
////	}
////	system("pause");
////	return 0;
////}
//
////"fixed" says that floating - point numbers will be output in "fixed point format" 
////— that is, with a fixed number of digits following the decimal point.
////"scientific" uses exponential notation for numbers: e.g., 2.99E8.
////"setprecision( n )" sets the number of digits following the decimal point to n.
//
////#include <iostream>
////#include <string>
////#include <iomanip>
////
////using namespace std;
////
////int main()
////{
////	string test = "";
////
////	cin >> test;
////	cout << test << endl;
////
////	system("pause");
////	return 0;
////}
//
////int main()
////{
////	int ival = 42;
////	int *p = &ival; // p holds the address of ival; p is a pointer to ival
////	std::cout << *p << std::endl;
////
////	system("pause");
////	return 0;
////}
//
//
//
////#include <fstream>
////#include <string>
////
////using namespace std;
////
////void copyChars()
////{
////	ifstream ifs("input.txt");
////	ofstream ofs("output.txt");
////
////	int charsCopied = 0;
////	ifs >> noskipws;
////	char key = 'a';
////	while (ifs)
////	{
////		char c;
////		ifs >> c;
////		ofs << (c ^ key);
////		++charsCopied;
////	}
////
////	ifs.close();
////	ofs.close();
////
////	cout << charsCopied << " characters copied." << endl;
////}
//
//#include <fstream>
//#include <string>
//#include <vector>
//#include <cctype>
//#include <algorithm>
//
//using namespace std;
//
//char change_case(char c)
//{
//	if (std::isupper(c))
//		return std::tolower(c);
//	else
//	{
//		return c;
//	}
//}
//
////Fix bug with no +.
//std::string removePunc(std::string token)
//{
//	std::string newString;
//	for (int i = 0; i < token.size(); i++)
//	{
//		if (!((token[i] < 97 && token[i] != 43) || token[i] > 122 ))
//		{
//			newString += token[i];
//		}
//	}
//	return newString;
//}
//
//int main()
//{
//
//	ifstream ifs("fileNames.txt"); //Contains documents to read in.
//	string fileName;              //Contains the current document. 
//
//	vector<string> index;    //Contains all different tokens. 
//	while (ifs >> fileName) //While a document exists.
//	{
//		ifstream ifs2(fileName.c_str()); //Open the current document.
//		string word, finalWord;                    //Contains current word in document.
//		while (ifs2 >> word)
//		{
//			//Change to lower case.
//			std::transform(word.begin(), word.end(), word.begin(), change_case);
//			finalWord = removePunc(word);
//
//			bool duplicate = false;
//
//			//Checks for duplicate by comparing current word to rest of index.			
//			for (int i = 0; i < index.size(); ++i)
//			{
//				if (finalWord == index[i])
//				{
//					duplicate = true;
//					break;
//				}
//			}
//			//If not a duplicate then add to the index.
//			if (!duplicate)
//			{
//				index.push_back(finalWord);
//			}
//		}
//	}
//
//	//This is for debuging.
//	std::cout << endl << "This is the contents of the index:- " << endl << endl;
//	for (string word : index)
//	{
//		std::cout << "\"" << word << "\"" << "\t";
//	}
//	std::cout << endl << endl;
//	//@ this point the whole index should have been created.
//	/*************************************************************/
//
//	ifstream openAgain("fileNames.txt"); //Contains documents to read in.
//	string fileName2, word2, finalWord2;
//
//	//A multidimentional vector that contains a vector for each document.
//	vector<vector<int>> documentVectors;
//	int debugging = 0;
//
//	while (openAgain >> fileName2)
//	{
//		ifstream ifs3(fileName2.c_str()); //Open the current document.
//
//		vector<int> docVec; //Vector for current document.
//
//		//Go through each word in index, increment the actual index as necessary.
//		for (int i = 0; i < index.size(); ++i)
//		{
//			string currentWord = index[i]; //Current word in index. 
//
//			int frequency = 0;
//
//			//Compares all tokens in document with the current word in index,
//			//if a match is found, then increment frequency.
//			while (ifs3 >> word2)
//			{
//				//Convert to lowercase.
//				std::transform(word2.begin(), word2.end(), word2.begin(), change_case);
//				finalWord2 = removePunc(word2);
//				if (finalWord2 == currentWord)
//				{
//					++frequency;
//				}
//			}
//			//Puch frequency of current word to document vector.			
//			docVec.push_back(frequency);
//
//			//Must reset the stream since eof.
//			ifs3.clear();
//			ifs3.seekg(0, ios::beg);
//		}
//		//Push back docVec to documentVectors.
//		documentVectors.push_back(docVec);
//
//		//This is for debuging.
//		int length = documentVectors[debugging].size();
//		std::cout << "This contains the vector of the "
//			<< debugging + 1
//			<< "st document"
//			<< endl;
//
//		for (int i = 0; i < length; ++i)
//		{
//			std::cout << documentVectors[debugging][i] << "\t ";
//		}
//		std::cout << endl << endl;
//		++debugging;
//	}
//
//	//@ this point each document should have its own vector.
//	/****************************************************************************/
//	std::cout << "Enter your query:-" << endl;
//
//	vector<string> totalQuery; //Contains all tokens of the query.
//	string token;             //Takes one token of a query at a time.
//	while (cin >> token)     //How to not use control z?
//	{
//		//Convert to lower case.
//		std::transform(token.begin(), token.end(), token.begin(), change_case);
//		//Push the current token.
//		totalQuery.push_back(token);
//	}
//
//
//	vector<int> queryVector; //Contains vector for query.
//
//	//This creates vector for the query.
//	for (int i = 0; i < index.size(); ++i)
//	{
//		string currentWord = index[i];
//		int frequency = 0;
//		for (int j = 0; j < totalQuery.size(); ++j)
//		{
//			if (totalQuery[j] == index[i]) //.equals() for string?
//			{
//				++frequency;
//			}
//		}
//		queryVector.push_back(frequency);
//	}
//
//	//@ this point the query has its own vector.
//	/*****************************************************************************/
//	
//	//Stores each value created.
//	vector<double> cosSimValues; 
//
//	//Using formula to create value for each document.
//	for (int allDocs = 0; allDocs < documentVectors.size(); ++allDocs)
//	{
//		int numerator = 0;
//		//Does seem to give warning for reuse of i when bulding, can u change settings?
//		for (int i = 0; i < queryVector.size(); ++i)
//		{
//			numerator += queryVector[i] * documentVectors[allDocs][i];
//		}
//
//		double queryDistance = 0.0;
//		for (int i = 0; i < queryVector.size(); ++i)
//		{
//			queryDistance += pow(queryVector[i], 2);	//#include ????
//		}
//		queryDistance = sqrt(queryDistance);
//		/*****************************************************************/
//		double docVectorDistance = 0;
//		for (int i = 0; i < queryVector.size(); ++i)
//		{
//			docVectorDistance += pow(documentVectors[allDocs][i], 2);	//#include ????
//		}
//		docVectorDistance = sqrt(docVectorDistance);
//
//		double denominator = docVectorDistance * queryDistance;
//
//		double cosineSimilarity = numerator / denominator;
//		cosSimValues.push_back(cosineSimilarity);
//	}
//
//	/*********************************************************************/
//	vector<double> copy = cosSimValues;
//	sort(cosSimValues.begin(), cosSimValues.end()); //Why not by reference? Maybe
//	//Cuz of actual function.
//
//
//	ifstream documentNames("fileNames.txt");
//	vector<string> allDocumentNames;
//	string theName;
//	while (documentNames >> theName)
//	{
//		allDocumentNames.push_back(theName);
//	}
//
//	int top = 3; //TODO fix bug.
//	int highest = cosSimValues.size() - 1;
//	for (int i = highest; i > highest - top; --i)
//	{
//		string finallyyy;
//		for (int gogo = 0; gogo < copy.size(); ++gogo)
//		{
//			if (cosSimValues[i] == copy[gogo])
//			{
//				finallyyy = allDocumentNames[gogo];
//				break;
//			}
//		}
//		cout << "Rank" << i - top << ": " << finallyyy << " "
//			<< cosSimValues[i] << endl;
//	}
//
//	std::system("pause");
//	return 0;
//}
