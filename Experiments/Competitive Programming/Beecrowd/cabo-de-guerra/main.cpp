#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
};

class Classroom
{
public:
    vector<Student *> students;

    void insert_student()
    {
        Student *student = new Student();
        cin >> student->name;
        this->students.push_back(student);
    }
};

class StudentBinarySearch
{
public:
    int middle;
    int left;
    int right;

    Classroom *classroom;
    long long get_middle(int middle)
    {
        const auto &students = this->classroom->students;
        Student *student_middle = (*this->classroom).students[middle];
        // Student power for A and B subtracted
        long long sum_a = 0;
        long long sum_b = 0;
        for (int i = 0; i <= middle; i++)
            sum_a += accumulate(students[i]->name.begin(),
                                students[i]->name.end(), 0LL) *
                     (middle - i + 1);

        for (int i = middle + 1; i < (int)students.size(); i++)
            sum_b += accumulate(students[i]->name.begin(),
                                students[i]->name.end(), 0LL) *
                     (i - middle);
        return sum_a - sum_b;
    }

    StudentBinarySearch(Classroom *classroom)
    {
        this->classroom = classroom;
        this->left = 0;
        bool found = false;

        this->right = (int)classroom->students.size() - 1;
        while (this->left <= this->right)
        {
            this->middle = this->left + (this->right - this->left) / 2;
            long long power = this->get_middle(this->middle);

            if (power == 0)
            {
                cout << classroom->students[this->middle]->name << '\n';
                found = true;
                break;
            }
            else if (power > 0)
            {
                this->right = this->middle - 1;
            }
            else
            {
                this->left = this->middle + 1;
            }
        }

        if (!found)
            cout << "Impossibilidade de empate.\n";

        for (Student *student : classroom->students)
        {
            delete student;
        }
        delete classroom;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        Classroom *classroom = new Classroom();
        for (int i = 0; i < n; i++)
        {
            classroom->insert_student();
        }
        StudentBinarySearch *binary_search = new StudentBinarySearch(classroom);
        delete binary_search;
    }

    return 0;
}