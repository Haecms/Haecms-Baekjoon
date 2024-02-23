#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int a, int b, int c, int d) {
    vector<int> array = { a,b,c,d };
    unordered_map<int, int> dictionary = { 
	    {1, 0},
	    {2, 0},
	    {3, 0},
	    {4, 0},
	    {5, 0},
	    {6, 0},
        };
    int answer = 7;

    for (int i = 0; i < array.size(); i++) {
	    dictionary[array[i]]++;
    }

    unordered_map<int, int> save;
    int count = 0;
    for (int i = 1; i <= dictionary.size(); i++) {
	    if (dictionary[i]) {
		    save[count] = i;
		    count++;
	    }
    }
    if (save.size() == 1) {
	    answer = a * 1111;
    }
    else if (save.size() == 2) {
	    if (dictionary[save[0]] == dictionary[save[1]]) {
		    answer = (save[0] + save[1]) * (save[1] - save[0]);
	    }
	    else {
		    answer = dictionary[save[0]] > dictionary[save[1]] ? (10 * save[0] + save[1]) * (10 * save[0] + save[1]) : (10 * save[1] + save[0]) * (10 * save[1] + save[0]);
	    }
    }
    else if (save.size() == 4) {
	    for (int i = 0; i < save.size(); i++) {
		    answer = answer > save[i] ? save[i] : answer;
	    }
    }
    else {
	    vector<int> differnt_Number;
	    for (int i = 0; i < save.size(); i++) {
		    if (dictionary[save[i]] == 1) {
			    differnt_Number.push_back(save[i]);
		    }
	    }
	    answer = differnt_Number[0] * differnt_Number[1];
    }
    return answer;
}