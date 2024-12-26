The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the ith sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the jth student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.

#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
        std::queue<int> studentQueue;
        for (int student : students) {
            studentQueue.push(student); // Initialize the queue with students' preferences
        }

        int sandwichIndex = 0;
        int n = students.size();
        
        while (!studentQueue.empty()) {
            int student = studentQueue.front();
            studentQueue.pop();
            
            if (student == sandwiches[sandwichIndex]) {
                // Student takes the sandwich
                sandwichIndex++;
            } else {
                // Student doesn't take the sandwich, go to the end of the queue
                studentQueue.push(student);
            }

           
            if (studentQueue.size() == n) {
                break;
            }
        }

        return studentQueue.size();
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    std::vector<int> students1 = {1, 1, 0, 0};
    std::vector<int> sandwiches1 = {0, 1, 0, 1};
    std::cout << "Students unable to eat: " << solution.countStudents(students1, sandwiches1) << std::endl;

    // Test case 2
    std::vector<int> students2 = {1, 1, 1, 0, 0, 1};
    std::vector<int> sandwiches2 = {1, 0, 0, 0, 1, 1};
    std::cout << "Students unable to eat: " << solution.countStudents(students2, sandwiches2) << std::endl;
    
    return 0;
}
