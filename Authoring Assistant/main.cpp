//
//  main.cpp
//  Authoring Assistant
//
//  Created by Austin Wright on 2/21/24.
//

#include <iostream>
#include <string>
using namespace std;

int GetNumOfNonWSCharacters(const string& word) {
    int count = 0;
    for (char c: word) {
        if (!isspace(c)) {
            count++;
        }
    }
    return count;
}

int GetNumOfWords(const string& word) {
    int count = 0;
    bool inWord = false;
    for (char c: word) {
        if (isspace(c)) {
            inWord = false;
        } else {
            if (!inWord) {
                count ++;
                inWord = true;
            }
        }
    }
    return count;
}

int FindText(string found_word, const string& word) {
    int count = 0;
    unsigned long nPos = word.find(found_word, 0);
        while (nPos != string::npos)
        {
            count++;
            nPos = word.find(found_word, nPos + 1);
        }
    return count;
}

string ReplaceExclamation(string& word) {
    unsigned long l = word.length();
    for (int i = 0; i < l; i++) {
        if (word[i] == '!') {
            word[i] = '.';
        }
    }
    return word;
}

string ShortenSpace(string& word) {
    unsigned long l = word.length();
    for (int i = 0; i < l - 1; i++) {
        if (word[i] == ' ' && word[i + 1] == ' ') {
            word.erase(i, 1);
            l--;
            i--;
        }
    }
    return word;
}

void PrintMenu() {
    cout << "MENU" << endl;
    cout << "c - Number of non-whitespace characters" << endl;
    cout << "w - Number of words" << endl;
    cout << "f - Find text" << endl;
    cout << "r - Replace all !'s" << endl;
    cout << "s - Shorten spaces" << endl;
    cout << "q - Quit" << endl;
}

void ExecuteMenu(char c, const string& word) {
    switch (c) {
        case 'q':
            break;
        case 'c':
            cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(word) << endl;
            cout << endl;
            break;
        case 'f':
        {
            string choice;
            cout << "Enter a word or phrase to be found:" << endl;
            cin.ignore();
            getline(cin, choice);
            cout << '"' << choice << '"' << " instances: " << FindText(choice, word) << endl;
            cout << endl;
            break;
        }
        case 'w':
            cout << "Number of words: " << GetNumOfWords(word) << endl;
            cout << endl;
            break;
        case 'r':
        {
            string edited_version = word;
            cout << "Edited text: " << ReplaceExclamation(edited_version) << endl;
            cout << endl;
            break;
        }
        case 's':
        {
            string edited_version = word;
            cout << "Edited text: " << ShortenSpace(edited_version) << endl;
            cout << endl;
            break;
        }
        default:
            cout << "Invalid choice." <<endl;
    }
}

int main() {
    string text;
    char option;
    
    cout << "Enter a sample text:" << endl;
    cout << endl;
    getline(cin, text);
    
    cout << "You entered: " << text << endl;
    cout << endl;
    
    do {
        PrintMenu();
        cout << endl;
        cout << "Choose an option:" << endl;
        cin >> option;
        ExecuteMenu(option, text);
    } while (option != 'q');
    return 0;
}
