#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool sortByVal(const pair<char, int> &a,
               const pair<char, int> &b)
{
    return (a.second > b.second);
}

map<char,int> countMap(string countString){

    char currentChar;
    std::map<char,int> outMap;
    int counter = 0;

    for(int i=0; i<countString.length();i++){
        currentChar = countString[i];

        if(countMap[currentChar]!=0){
            counter = outMap[currentChar];
            outMap[currentChar]= counter + 1;
        }else{
            outMap[currentChar]= 1;
        }
    }
    return outMap;
}

void printSorted(map<char, int> countMap){

    vector<pair<char, int>> vec;

    map<char, int> :: iterator it2;
    for (it2=countMap.begin(); it2!=countMap.end(); it2++)
    {
        vec.push_back(make_pair(it2->first, it2->second));
    }

    sort(vec.begin(), vec.end(), sortByVal);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first << ": " << vec[i].second << endl;
	}

}


string firstLetters(string str)
{
    int i;
    string firstLetterString;

    for (i = 0; i < str.length(); i++)
    {
        if (i == 0)
            firstLetterString = firstLetterString+str[i];

        if (str[i] == ' ')
        {
            firstLetterString = firstLetterString+str[i+1];
        }
    }
    return firstLetterString;
}

string processWords(char *input)
{
    char *p;
    vector<string> s;

    p = strtok(input, " ");
    while (p != NULL)
    {
        s.push_back(p);
        p = strtok(NULL, " ");
    }

    string charBuffer;

    for (string values : s)
        charBuffer += values[0];

    return charBuffer;
}

int main()
{
    std::map<char,int> firstLetterCountMap;
    std::map<char,int> charCountMap;

    char currentChar='\0';
    string sentence = "";
    int counter = 0;

    cout<<"Enter sentence : " <<endl;
    getline(cin,sentence);





    cout << "The number of words starting with this letter: " << endl;
    string firsts = firstLetters(sentence);
    firstLetterCountMap = countMap(firsts);
    printSorted(firstLetterCountMap);

    cout << "The number of different characters in the text: " << endl;
    firstLetterCountMap = countMap(sentence);
    printSorted(firstLetterCountMap);









    for(int i=0; i<sentence.length();i++){
        currentChar = sentence[i];

        if(charCountMap[currentChar]!=0){
            counter = charCountMap[currentChar];
            charCountMap[currentChar]= counter + 1;
        }else{
            charCountMap[currentChar]= 1;
        }
    }


    vector<pair<char, int>> vec;

    map<char, int> :: iterator it2;
    for (it2=charCountMap.begin(); it2!=charCountMap.end(); it2++)
    {
        vec.push_back(make_pair(it2->first, it2->second));
    }

    sort(vec.begin(), vec.end(), sortByVal);

    cout << "The number of different characters in the text: " << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first << ": " << vec[i].second << endl;
	}

}
