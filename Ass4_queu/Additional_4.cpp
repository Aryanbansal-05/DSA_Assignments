#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
   for(int i = 0;i<students.size();i++){
        q.push(students[i]);
    }

    int i = 0; 
    int round = 0; 

    while (!q.empty()) {
        if (q.front() == sandwiches[i]) {
            q.pop();
            i++;
            round = 0; 
        }
        else {
            q.push(q.front());
            q.pop();
            round++;
        }

        if (round == q.size())
            break;
    }

    return q.size();
}

int main() {
    vector<int> students = {1,1,0,0,1};
    vector<int> sandwiches = {0,1,0,1,1};

    cout << countStudents(students, sandwiches) << endl;
    return 0;
}
