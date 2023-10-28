#include <iostream>
#include <vector>
using namespace std;

int grade_exam(const vector<char>& correct_answers, const vector<char>& student_answers) {
    if (correct_answers.size() != student_answers.size()) {
        cout << "Error: Answer lists are not the same length." << endl;
        return -1;
    }

    int score = 0;
    vector<int> incorrect_questions;
    for (int i = 0; i < correct_answers.size(); i++) {
        if (correct_answers[i] == student_answers[i]) {
            score++;
        } else {
            incorrect_questions.push_back(i+1);
        }
    }

    if (score >= 15) cout << "You passed exam." << endl;
    else cout << "You failed exam." << endl;
    cout << "Total number of correctly answered questions: " << score << endl;
    cout << "Total number of incorrectly answered questions: " << incorrect_questions.size() << endl;
    cout << "Incorrectly answered questions are: ";
    for (int q : incorrect_questions) {
        cout << q << " ";
    }
}

bool validate_answer(char answer) {
    return answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D';
}

int main() {
    vector<char> correct_answers = {'B', 'D', 'A', 'A', 'C', 'A', 'B', 'A', 'C', 'D', 'B', 'C', 'D', 'A', 'D', 'C', 'C', 'B', 'D', 'A'};
    vector<char> student_answers(20);

    cout << "Please enter your answers to the 20 questions (A-D):" << endl;
    for (int i = 0; i < 20; i++) {
        cout << i+1 << ". ";
        char answer;
        cin >> answer;
        while (!validate_answer(answer)) {
            cout << "Invalid input. Please enter A, B, C, or D." << endl;
            cin >> answer;
        }
        student_answers[i] = answer;
    }

    grade_exam(correct_answers, student_answers);

    return 0;
}
