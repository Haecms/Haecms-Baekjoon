#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> st;

    st.push(numbers[numbers.size() - 1]);
    for (int i = numbers.size() - 2; i >= 0; i--) {
        bool flag = false;
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            if (top > numbers[i]) {
                answer[i] = top;
                flag = true;
                break;
            }
        }
        if (flag) {
            st.push(answer[i]);
        }
        st.push(numbers[i]);
    }
    return answer;
}