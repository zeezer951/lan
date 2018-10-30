#include <unordered_map> //hash table
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "StringSplitter.h"
#include <algorithm>

using namespace std;

//LAB EXTRA CREDIT
void concordance(string text)
{
	unordered_map<string, int> frequencies{};
	vector<string> words = StringSplitter::split(text, " ");
	for (auto word : words)
	{
		frequencies[word]++;
	}

	vector<string> keys{};
	for (auto kvp : frequencies)
	{
		keys.push_back(kvp.first);

	}
	sort(keys.begin(), keys.end());
	for (auto key : keys)
	{
		cout << key << ":" << frequencies[key] << endl;


	}


}

bool hasUniqueChars(string text)
{
	
	unordered_map<char, int> character; 
	
	
	for (auto key : text)
	{	
		character[key]++; 
	
	}
	
	for (auto c : character)
	{
	
		if (c.second > 1)
		{
		
			return false; 
		}
		

	}
	return true; 

}

bool isAnagram(string first, string second)
{
	
	unordered_map<char, int> str1; 
	unordered_map<char, int> str2;




	for (auto f : first)
	{
		str1[f]++; 
		
	}
	
	for (auto s : second)
	{
	
		str2[s]++; 
	
	}
	
	if (str1 == str2)
	{
		for (auto x : str1)
		{
			for (auto y : str2)
			{ 
				if (x.second == y.second)
					return true; 
				
			}

		}
			
			
			return true; 
	}
	
	
	return false; 

}

string mostCommonSubstring(string text, int size)
{
	/*
	unordered_map<char, int> common; 

	for (auto key : text)
	{
	
		common[key]++; 
	
	}
	

	for (auto repeat : common)
	{
	
		if (repeat.first > repeat.second)
		{
			return repe
		}

	}
	
	*/	
	
	
	
	return "";
}



int main(void)
{
	
	ifstream input_file{ "test_file.txt" };
	
	string all_lines;

		if(input_file.is_open() == true)
		{
			while (input_file.good() == true)
			{
			
				string line; 
				getline(input_file, line); 
				all_lines += " " + line; 
				
			
			}
			
		}
	
		concordance(all_lines); 
	
	
	
	
	
	//unique chars test
	cout << boolalpha;
	cout << "***unique characters test***" << endl;

	//test case #1
	cout << "abcde: " <<
		hasUniqueChars("abcde")
		<< " (expected: true)"
		<< endl;

	//test case #2:
	cout << "aaaa: " <<
		hasUniqueChars("aaaa")
		<< " (expected: false)"
		<< endl;

	//test case #3:
	cout << "(empty string): " <<
		hasUniqueChars("")
		<< " (expected: true)"
		<< endl;

	//test case #4:
	cout << "abcdea: " <<
		hasUniqueChars("abcdea")
		<< " (expected: false)"
		<< endl;

	//anagram tests
	cout << endl << endl;
	cout << "***anagram tests***" << endl;

	//test case #1:
	cout << "tab, bat: " <<
		isAnagram("tab", "bat")
		<< " (expected: true)"
		<< endl;

	//test case #2
	cout << "bat, tab: " <<
		isAnagram("bat", "tab")
		<< " (expected: true)"
		<< endl;

	//test case #3
	cout << "(empty), (empty): " <<
		isAnagram("", "")
		<< " (expected: true)"
		<< endl;

	//test case #4
	cout << "dog, cat: " <<
		isAnagram("dog", "cat")
		<< " (expected: false)"
		<< endl;

	//test case #5
	cout << "castles, castle: " <<
		isAnagram("castles", "castle")
		<< " (expected: false)"
		<< endl;

	//test case #6
	cout << "bat, tabb: " <<
		isAnagram("bat", "tabb")
		<< " (expected: false)"
		<< endl;

	//most common substring
	cout << endl << endl << "***Most common substring***" << endl;

	//test case #1
	cout << "abcabcdefdefabc. 3: " <<
		mostCommonSubstring("abcabcdefdefabc", 3)
		<< " (expected: abc)"
		<< endl;

	//test case #2
	cout << "defdefabcabc, 3: " <<
		mostCommonSubstring("defdefabcabc", 3)
		<< " (expected: def)"
		<< endl;

	//test case #3
	cout << "aaabbcccc, 1: " <<
		mostCommonSubstring("aaabbcccc", 1)
		<< " (expected: c)"
		<< endl;

	//test case #4
	cout << "abcdefhijklmnopqrstuvwxyz, 4: " <<
		mostCommonSubstring("abcdefhijklmnopqrstuvwxyz", 4)
		<< " (expected: abcd)"
		<< endl;

	//test case #5
	cout << "abc, 5: " <<
		mostCommonSubstring("abc", 5)
		<< " (expected: NULL)"
		<< endl;

	//test case #6
	cout << "(Empty), 1: " <<
		mostCommonSubstring("", 1)
		<< " (expected: NULL)"
		<< endl;

	//test case #7
	cout << "abcabcab, 3: " <<
		mostCommonSubstring("abcabcab", 3)
		<< " (expected: abc)"
		<< endl;

	//test case #8
	cout << "abcabcab, 0: " <<
		mostCommonSubstring("abcabcab", 0)
		<< " (expected: NULL)"
		<< endl;

	return 0;
}