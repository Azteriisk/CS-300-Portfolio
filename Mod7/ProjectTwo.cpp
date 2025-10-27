#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Course structure to store course data
struct Course {
    string courseNumber;
    string courseName;
    vector<string> prerequisites;
};

// Convert string to uppercase for case-insensitive comparison
string toUpper(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

// Load courses from CSV file into data structure
void loadCourses(map<string, Course>& courses) {
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;
    
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return;
    }
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        
        // Parse comma-separated values
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        
        // Create course if valid data exists
        if (tokens.size() >= 2) {
            Course course;
            course.courseNumber = tokens[0];
            course.courseName = tokens[1];
            
            // Add prerequisites if they exist
            for (int i = 2; i < tokens.size(); i++) {
                course.prerequisites.push_back(tokens[i]);
            }
            
            courses[toUpper(course.courseNumber)] = course;
        }
    }
    
    file.close();
    cout << "Data loaded successfully." << endl;
}

// Print all courses in alphanumeric order
void printCourseList(map<string, Course>& courses) {
    if (courses.empty()) {
        cout << "No courses loaded." << endl;
        return;
    }
    
    cout << "Here is a sample schedule:" << endl;
    cout << endl;
    
    // Map automatically keeps keys sorted
    for (map<string, Course>::iterator it = courses.begin(); 
         it != courses.end(); it++) {
        cout << it->second.courseNumber << ", " 
             << it->second.courseName << endl;
    }
    cout << endl;
}

// Print information for a specific course including prerequisites
void printCourse(map<string, Course>& courses) {
    string courseNum;
    cout << "What course do you want to know about? ";
    cin >> courseNum;
    
    string key = toUpper(courseNum);
    
    if (courses.find(key) != courses.end()) {
        Course c = courses[key];
        cout << c.courseNumber << ", " << c.courseName << endl;
        
        // Display prerequisites if they exist
        if (c.prerequisites.size() > 0) {
            cout << "Prerequisites: ";
            for (int i = 0; i < c.prerequisites.size(); i++) {
                cout << c.prerequisites[i];
                if (i < c.prerequisites.size() - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
        }
    } else {
        cout << "Course not found." << endl;
    }
    cout << endl;
}

int main() {
    map<string, Course> courses;
    int choice = 0;
    
    cout << "Welcome to the course planner." << endl;
    cout << endl;
    
    while (choice != 9) {
        // Display menu
        cout << "  1. Load Data Structure." << endl;
        cout << "  2. Print Course List." << endl;
        cout << "  3. Print Course." << endl;
        cout << "  9. Exit" << endl;
        cout << endl;
        cout << "What would you like to do? ";
        cin >> choice;
        
        // Handle invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
        }
        
        cout << endl;
        
        // Process menu selection
        switch (choice) {
            case 1:
                loadCourses(courses);
                break;
            case 2:
                printCourseList(courses);
                break;
            case 3:
                printCourse(courses);
                break;
            case 9:
                cout << "Thank you for using the course planner!" << endl;
                break;
            default:
                cout << choice << " is not a valid option." << endl;
                break;
        }
        
        if (choice != 9) {
            cout << endl;
        }
    }
    
    return 0;
}