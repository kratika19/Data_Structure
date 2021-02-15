#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Node {
    string name;
    struct Node *next;
} *first = NULL;

void createLL(vector<string> studentList, int n) {
    struct Node *t, *last;
    first = new Node;
    first->name = studentList[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->name = studentList[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int count(struct Node *p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void displayLL(struct Node *p) {
    if (p != NULL) {
        cout << p->name << endl;
        displayLL(p->next);
    }
}

void displayReverseLL(struct Node *p) {
    if (p != NULL) {
        displayReverseLL(p->next);
        cout << p->name << endl;
    }
}

void sortList(struct Node *p) {
    vector<string> Name;
    string s;
    while (p != 0) {
        s = p->name;
        Name.push_back(s);
        p = p->next;
    }
    int n = Name.size();
    sort(Name.begin(), Name.begin() + n);
    cout << "List Sorted Successfully" << endl;
    createLL(Name, n);
}

void insertStudent(struct Node *p, int pos, int size) {
    struct Node *t;
    t = new Node;
    string newName = "";
    cout << "Enter the student's name: ";
    cin >> newName;
    t->name = newName;
    if (p == 0) {
        t->next = p;
        p = t;
    } else if (pos > 0 && pos <= size) {
        for (int i = 1; i < pos - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    } else return;
    cout << "Student Added Successfully !" << endl;
}

void deleteNode(struct Node *p, int pos) {
    struct Node *q = NULL;
    string x = "null";
    if (pos >= 1 || pos <= count(p)) {
        if (pos == 1) {
            q = first;
            x = first->name;
            first = first->next;
            delete q;
            cout << "Deleted Successfully" << endl;
        } else {
            for (int i = 1; i < pos - 1; i++) {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            x = p->name;
            delete p;
            cout << "Deleted Successfully" << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of students :";
    cin >> n;
    vector<string> students;
    string name;
    for (int i = 0; i < n; i++) {
        cout << "Enter name of the student :";
        cin >> name;
        students.push_back(name);
    }
    cout<<endl;
    createLL(students, n);
    int choice = 1;
    cout << "********** Welcome to Student Portal ***********" << endl;
    while (choice >= 1 && choice <= 5) {
        cout << "Press 1 to display the names" << endl;
        cout << "Press 2 to reverse the list and display names" << endl;
        cout << "Press 3 to display names in alphabetical order" << endl;
        cout << "Press 4 to insert a new name" << endl;
        cout << "Press 5 to delete a name" << endl;
        cout << "Press 6 to exit" << endl;
        cout << "Make your choice :" << endl;
        cin >> choice;
        if (choice == 1) {
            displayLL(first);
            cout<<endl;
        } else if (choice == 2) {
            displayReverseLL(first);
            cout<<endl;
        } else if (choice == 3) {
            sortList(first);
            cout<<endl;
        } else if (choice == 4) {
            int pos;
            cout << "Enter the position you wish to add the student:" << endl;
            cin >> pos;
            insertStudent(first, pos, students.size());
            cout<<endl;
        } else if (choice == 5) {
            int pos;
            cout << "Enter the position you wish to delete the student:" << endl;
            cin >> pos;
            deleteNode(first, pos);
            cout<<endl;
        } else if (choice == 6)
            break;
    }
    return 0;
}