// HTMLParser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

vector<string> GetDataFile(string url);		// Function to read input file
vector<string> ParseData(vector<string> s, string pattern);		// Utility function to perform parsing
bool WriteExtractNews(vector<string>& news, vector<string>& urls);		// Function to write output file

int main()
{
	vector<string> sMatch[4];	// utility vector for processing
	
	vector<string> strDoc = GetDataFile("sourceNews.html");
	sMatch[0] = ParseData(strDoc, "^<a href=.+true\">.+</a>");		// will return you all links
	sMatch[1] = ParseData(sMatch[0], "https://.+?\"");
	sMatch[2] = ParseData(sMatch[0], "\"true\">.+</a>");	// need to truncate the header and footer

	if (WriteExtractNews(sMatch[2], sMatch[1])) {
		cout << "News Extraction COMPLETED\n";
	}

	return 0;
}

vector<string> GetDataFile(string url) {
	ifstream infile{ url, ios::in };
	if (!infile) {
		cerr << "File not found, url is invalid\n";
		exit(EXIT_FAILURE);
	}

	vector<string> strHTML;
	string strTmp{""};
	while (getline(infile, strTmp)) {
		strHTML.push_back(strTmp);
	}

	infile.close();
	return strHTML;
}

vector<string> ParseData(vector<string> s, string pattern) {
	vector<string> vMatch;
	regex word(pattern);
	for (int i = 0; i < s.size(); i++) {
		sregex_iterator next(s.at(i).begin(), s.at(i).end(), word);
		sregex_iterator end;

		while (next != end) {
			smatch match = *next;
			vMatch.push_back(match.str());
			next++;
		}
	}
	return vMatch;
}

bool WriteExtractNews(vector<string>& news, vector<string>& urls) {
	ofstream outFile{ "newsToday.txt", ios::out };

	if (!outFile) {
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}

	string title{};
	string url{};

	for (int i = 0; i < news.size(); i++) {
		title = news.at(i);
		url = urls.at(i);
		outFile << title.substr(7, title.length() - 11) << "\n";
		outFile << url.substr(0, url.length() - 1) << "\n\n";
	}

	outFile.close();
	return true;
}
