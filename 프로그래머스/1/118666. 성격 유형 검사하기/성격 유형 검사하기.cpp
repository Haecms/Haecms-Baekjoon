#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> alphabet = { 
        {'R', 0},
        {'T', 0},
        {'C', 0},
        {'F', 0},
        {'J', 0},
        {'M', 0},
        {'A', 0},
        {'N', 0},
    };

    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] == 1) {
            alphabet[survey[i][0]] += 3;
        }
        else if (choices[i] == 2) {
            alphabet[survey[i][0]] += 2;
        }
        else if (choices[i] == 3) {
            alphabet[survey[i][0]] += 1;
        }
        else if (choices[i] == 4) {
            continue;
        }
        else if (choices[i] == 5) {
            alphabet[survey[i][1]] += 1;
        }
        else if (choices[i] == 6) {
            alphabet[survey[i][1]] += 2;
        }
        else if (choices[i] == 7) {
            alphabet[survey[i][1]] += 3;
        }
    }
    if (alphabet['R'] == alphabet['T']) {
        answer += 'R';
    }
    else {
        answer += alphabet['R'] > alphabet['T'] ? 'R' : 'T';
    }
    if (alphabet['C'] == alphabet['F']) {
        answer += 'C';
    }
    else {
        answer += alphabet['C'] > alphabet['F'] ? 'C' : 'F';
    }
    if (alphabet['J'] == alphabet['M']) {
        answer += 'J';
    }
    else {
        answer += alphabet['J'] > alphabet['M'] ? 'J' : 'M';
    }
    if (alphabet['A'] == alphabet['N']) {
        answer += 'A';
    }
    else {
        answer += alphabet['A'] > alphabet['N'] ? 'A' : 'N';
    }
    return answer;
}