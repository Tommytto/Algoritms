#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>

using namespace std;
typedef vector<int> intSet;
map<string, intSet> words;

void initDictionary(vector<string> fileNameList) {
    ofstream fout;
    ifstream fin;
    string word;

    fout.open("dictionray.txt");
    for (int i = 0; i < fileNameList.size(); i++) {
        fin.open(fileNameList[i]);

        while (fin >> word) {
            if (words.find(word) == words.end()) {
                words[word] = intSet({i});
            } else {
                const int vectorSize = words[word].size();
                if (0 < vectorSize && words[word][vectorSize - 1] != i) {
                    words[word].push_back(i);
                }
            }
        }
        fin.close();
    }
    for (auto const& x : words) {
        fout << x.first << " ";
        for (int i = 0; i < x.second.size(); i++) {
            if (i != x.second.size()-1) {
                fout << x.second[i] << " ";
            } else {
                fout << x.second[i];
            }
        }
        fout << endl;
    }
}

void invertedSearch(vector<string> fileNameList, vector<string> wordsToSearch) {
    for (int i = 0; i < wordsToSearch.size(); i++) {
        const string currentWord = wordsToSearch[i];
        if (words.find(currentWord) == words.end()) {
            cout << "Sorry, there is not: \"" << wordsToSearch[i] << "\" in these texts" << endl;
        } else {
            cout << "The word \"" << currentWord << "\" there is in: ";
            for (int i = 0; i < words[currentWord].size(); i++) {
                if (i != words[currentWord].size() - 1) {
                    cout << fileNameList[words[currentWord][i]] << ", ";
                } else {
                    cout << fileNameList[words[currentWord][i]];
                }
            }
            cout << "\n";
        }
    }
}

void simpleSearch(vector<string> fileNameList, vector<string> wordsToSearch) {
    ifstream fin;
    string word;

    for (int i = 0; i < wordsToSearch.size(); i++) {
        vector<int> textNumber;
        for (int j = 0; j < fileNameList.size(); j++) {
            fin.open(fileNameList[j]);

            while (fin >> word) {
                if (word == wordsToSearch[i]) {
                    const int vectorSize = textNumber.size();

                    if (0 < vectorSize && textNumber[vectorSize - 1] != j) {
                        textNumber.push_back(j);
                    } else if (0 == vectorSize) {
                        textNumber.push_back(j);
                    }
                }
            }
            fin.close();
        }
        if (0 == textNumber.size()) {
            cout << "Sorry, there is not: \"" << wordsToSearch[i] << "\" in these texts" << endl;
        } else {
            cout << "The word \"" << wordsToSearch[i] << "\" there is in: ";
            for (int k = 0; k < textNumber.size(); k++) {
                if (i != textNumber.size() - 1) {
                    cout << fileNameList[textNumber[k]] << ", ";
                } else {
                    cout << fileNameList[textNumber[k]];
                }
            }
            cout << "\n";
        }
    }
}

int main() {
    const int TEXT_COUNT = 10;
    vector<string> fileNameList;
    ofstream fout;

    for (unsigned i = 0; i < TEXT_COUNT; i++) {
        string fileName = "hello" + to_string(i) + ".txt";
        fileNameList.push_back(fileName);
        fout.open(fileNameList[i]);
        if (0 == i % 2) {
            fout << "Lorem Ipsum is simply dummy text \n"
                    "of the printing and typesetting industry. \n"
                    "Lorem Ipsum has been the industry's standard \n"
                    "dummy text ever since the 1500s when an unknown\n"
                    " printer took a galley of type and scrambled it \n"
                    "to make a type specimen book It has survived not \n"
                    "only five centuries but also the leap into electronic typesetting \n"
                    "remaining essentially unchanged It was popularised in the 1960s with the release of\n"
                    " Letraset sheets containing Lorem Ipsum passages and more recently with \n"
                    "desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum";
        } else {
            fout << "There are many variations of \n"
                    "passages of Lorem Ipsum available\n"
                    " but the majority have suffered alteration in so\n"
                    "me form by injected humour or randomised words which don't look e\n"
                    "ven slightly believable If you are going to use a passage of Lorem Ipsum you \n"
                    "need to be sure there isn't anything embarrassing hidden in the middle of text All the \n"
                    "Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary making\n"
                    " this the first true generator on the Internet It uses a dictionary of over 200 Latin words c\n"
                    "ombined with a handful of model sentence structures to generate Lorem Ipsum whi\n"
                    "ch looks reasonable The generated Lorem Ipsum is there\n"
                    "fore always free from repetition injected humour or non-characteristic words etc";
        }
        fout.close();
    }

    vector<string> stringToSearch({"Aldus", "injected", "humour"});
    initDictionary(fileNameList);
    cout << "Inverted search: " << endl;
    unsigned int startTime = clock();
    invertedSearch(fileNameList, stringToSearch);
    unsigned int stopTime = clock();

    unsigned int invertedTime = stopTime - startTime;

    cout << "Simple search: " << endl;
    startTime = clock();
    simpleSearch(fileNameList, stringToSearch);
    stopTime = clock();

    unsigned int simpleTime = stopTime - startTime;

    cout << "------------------------------------------" << endl;
    cout << "Time: " << endl;
    cout << "inverted " << invertedTime << endl;
    cout << "simple " << simpleTime << endl;
    return 0;
}