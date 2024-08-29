
#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Parser {
public:
    static vector<string> split(string line) {
        vector<string> words;
        stringstream ss(line);
        string word;

        for (int i = 0; i < 4; i++) {
            ss >> word;
            words.push_back(word);
        }
        return words;
    }

    static Client parserToClient(string line) {
        vector<string> words = split(line);
        Client c;
        c.setName(words[0]);
        c.setID(stoi(words[1]));
        c.setPass(words[2]);
        c.setBalance(stoi(words[3]));
        return c;
    }

    static Employee parserToEmployee(string line) {
        vector<string> words = split(line);
        Employee e;
        e.setName(words[0]);
        e.setID(stoi(words[1]));
        e.setPass(words[2]);
        e.setSalary(stoi(words[3]));
        return e;
    }

    static Admin parserToAdmin(string line) {
        vector<string> words = split(line);
        Admin a;
        a.setName(words[0]);
        a.setID(stoi(words[1]));
        a.setPass(words[2]);
        a.setSalary(stoi(words[3]));
        return a;
    }
};

#endif // PARSER_H
