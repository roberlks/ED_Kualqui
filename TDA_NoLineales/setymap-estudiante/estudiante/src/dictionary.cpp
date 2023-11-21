
#include "./../include/dictionary.h"
#include <iostream>

using namespace std;
Dictionary::Dictionary() {
    this->words = set<string>();
}

Dictionary::Dictionary(const Dictionary& other) {
    this->words = other.words;
}

bool Dictionary::exists(const string &word) const {
    return this->words.find(word) != this->words.end();
}

bool Dictionary::insert(const string &word){
    return this-> words.insert(word).second;
}

bool Dictionary::erase (const string &word){
    return (this->words.erase(word) > 0);
}
void Dictionary::clear(){
    this->words.clear();
}
bool Dictionary::empty() const{
    return this->words.empty();
}


unsigned int Dictionary::size() const{
    return this->words.size();
}

std::vector<string> Dictionary::wordsOfLength (int length) {
    std::vector<string> toRet;
    for (auto it = this->words.begin(); it != this->words.end(); ++it) {
        if ((*it).length() == length) {
            toRet.push_back(*it);
        }
    }
    return toRet;
}

int Dictionary::getOcurrences(const char c) {
    int counter = 0;
    /**for (auto it = this->words.begin(); it != this->words.end(); ++it) {
        for(int i = 0; i < (*it).length(); ++i) {
            if ((*it).at(i) == c) {
                ++counter;
            }
        }
    }*/

    for (auto& word : this->words) { //Recomendación del corrector automatico de clion
        for (char i : word) {
            if (i == c) {
                ++counter;
            }
        }
    }
    return counter;
}

Dictionary operator+(const Dictionary &dic1, const Dictionary &dic2) {
    Dictionary dic;
    for (auto& word : dic1.words) {
        dic.words.insert(word);
    }
    for (auto& word : dic2.words) {
        dic.words.insert(word);
    }
    return dic;
}

    	
