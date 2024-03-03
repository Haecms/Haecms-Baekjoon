#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
unordered_map<string, int> name_list;
unordered_map<string, int> report_name_count;
unordered_map<string, vector<string>> report_name_reported_name;
unordered_map<string, vector<string>> reported_name_report_name;

for (int i = 0; i < report.size(); i++) {
	int space = report[i].find(" ", 0);
	string report_user = report[i].substr(0, space);
	string reported_user = report[i].substr(space+1, report[i].size() - space);
	
	if (report_name_reported_name[report_user].size()) {
		bool flag = true;
		for (int j = 0; j < report_name_reported_name[report_user].size(); j++) {
			
			if (report_name_reported_name[report_user][j] == reported_user) {
				flag = false;
				break;
			}
			else {
				
			}
		}
		if (flag) {
			report_name_reported_name[report_user].push_back(reported_user);
			reported_name_report_name[reported_user].push_back(report_user);
			report_name_count[reported_user]++;
		}

	}
	else {
		report_name_reported_name[report_user].push_back(reported_user);
		reported_name_report_name[reported_user].push_back(report_user);
		report_name_count[reported_user]++;
	}
}
vector<string> ban_list;

for (int i = 0; i < id_list.size(); i++) {
	if (report_name_count[id_list[i]] >= k) {
		ban_list.push_back(id_list[i]);
	}
	string hello2 = id_list[i];
	int hello = report_name_count[id_list[i]];
	name_list[id_list[i]] = 0;
}

for(int i=0; i<ban_list.size(); i++){
	for (int j = 0; j < reported_name_report_name[ban_list[i]].size(); j++) {
		name_list[reported_name_report_name[ban_list[i]][j]]++;
	}
}
for (int i = 0; i < id_list.size(); i++) {
	answer.push_back(name_list[id_list[i]]);
}
    return answer;
}