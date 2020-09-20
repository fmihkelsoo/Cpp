#include <bits/stdc++.h>

using namespace std;

string readFile(string path){

    ifstream stream(path);

    if ( ! stream ) {
        cout << "Error: Can't open the file from path : "<< path <<"\n";
        exit(1);
    }

    stringstream buffer;
    buffer << stream.rdbuf();
    return buffer.str();

}

map<char,int> countMap(string countString){

    char currentChar;
    map<char,int> outMap;
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

bool sortByVal(const pair<char, int> &a,
               const pair<char, int> &b){
                   return (a.second > b.second);
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
		cout << vec[i].first << " : " << vec[i].second << endl;
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

int main()
{
    string path;
    string text;

    cout<<"Enter file path : " <<endl;
    getline(cin,path);
    text = readFile(path);

    map<char,int> charCountMap;

    cout << "The number of words starting with this letter: " << endl;
    string firsts = firstLetters(text);
    charCountMap = countMap(firsts);
    printSorted(charCountMap);

    cout << "The number of different characters in the text: " << endl;
    charCountMap = countMap(text);
    printSorted(charCountMap);

}
