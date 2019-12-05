// HTMLParser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

vector<string> GetDataFile(string url);					// Function to read input file
vector<string> ParseData(vector<string> s, string pattern);		// Utility function to perform parsing
bool WriteExtractNews(vector<string>& news, vector<string>& urls);	// Function to write output file

int main()
{
	// 1. Declare vector that you want to use for processing
	// 2. Read input file from given url
	// 3. Start parsing (analyse the HTML document before deciding what to parse)
	// 4. Write output to file
	return 0;
}

vector<string> GetDataFile(string url) {

}

vector<string> ParseData(vector<string> s, string pattern) {

}

bool WriteExtractNews(vector<string>& news, vector<string>& urls) {

}
