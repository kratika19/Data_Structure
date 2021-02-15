#include <bits/stdc++.h>
using namespace std;

struct Polynomial {
    int data;
    int power;
    Polynomial *next;
} *first = nullptr;

void displayPolynomial(Polynomial *head) {
    Polynomial *t = head;
    while (t != nullptr) {
        cout << t->data << "x^" << t->power << " + ";
        t = t->next;
    }
}

void createPolynomial(Polynomial **head, Polynomial *newNode) {
    newNode->next = *head;
    *head = newNode;
}

void resultPoly(Polynomial **head, int coefficient1, int coefficient2, int expo) {
    Polynomial *last;
    Polynomial *new_node = new Polynomial;
    new_node->data = coefficient1 - coefficient2;
    new_node->power = expo;
    new_node->next = nullptr;

    if (*head == nullptr) {
        *head = new_node;
        last = new_node;
        return;
    } else {
        last->next = new_node;
        last = new_node;
    }
    if (coefficient2 == 0 || coefficient1 == 0) {
        last->next = new_node;
        last = new_node;
    }
}

void subtractPolynomial(Polynomial **head1, Polynomial **head2) {
    Polynomial *finalPoly = nullptr;
    Polynomial *t1 = *head1;
    Polynomial *t2 = *head2;
    Polynomial *last = nullptr;
    while (t1 != nullptr && t2 != nullptr) {
        if (t1->power == t2->power) {
            resultPoly(&finalPoly, t1->data, t2->data, t1->power);
            t1 = t1->next;
            t2 = t2->next;
        } else if (t1->power > t2->power) {
            resultPoly(&finalPoly, t1->data, 0, t1->power);
            t1 = t1->next;
        } else if (t2->power > t1->power) {
            resultPoly(&finalPoly, 0, t2->data, t2->power);
            t2 = t2->next;
        }
    }
    cout << "Difference of the polynomials is:";
    displayPolynomial(finalPoly);
}

void resultPolynomial(Polynomial **second, Polynomial **head, Polynomial *current) {
    Polynomial *t1 = *second;
    while (t1 != nullptr) {
        Polynomial *new_node = new Polynomial;
        new_node->data = (t1->data) * (current->data);
        new_node->power = t1->power + current->power;
        createPolynomial(&*head, new_node);
        t1 = t1->next;
    }
}

void addDuplicates(Polynomial **start) {
    Polynomial *t3 = *start;
    Polynomial *t4, *dup;
    while (t3 != nullptr && t3->next != nullptr) {
        t4 = t3;
        while (t4->next != nullptr) {
            if (t3->power == t4->next->power) {
                t3->data = t3->data + t4->next->data;
                // dup = t4->next;
                t4->next = t4->next->next;
                // delete (dup);
            } else {
                t4 = t4->next;
            }
        }
        t3 = t3->next;
    }
    cout << "Product of the polynomials is:";
    displayPolynomial(*start);
}

void multiplyPolynomial(Polynomial **head1, Polynomial **head2) {
    Polynomial *second = nullptr;
    Polynomial *t1, *t2;
    t1 = *head1;
    t2 = *head2;
    while (t1 != nullptr) {
        resultPolynomial(&t2, &second, t1);
        t1 = t1->next;
    }
    addDuplicates(&second);
}

int main() {
    int degree1 = 0, degree2 = 0;
    cout << "Enter the degree of first polynomial:";
    cin >> degree1;
    for (int i = 0; i <= degree1; i++) {
        int coefficient;
        cout << "Enter the coefficient of x^" << i << ":";
        cin >> coefficient;
        Polynomial *new_node = new Polynomial;
        new_node->data = coefficient;
        new_node->power = i;
        new_node->next = nullptr;
        createPolynomial(&first, new_node);
    }
    cout << "Your First polynomial: ";
    displayPolynomial(first);
    cout << endl;
    Polynomial *second = nullptr;
    cout << endl;
    cout << "Enter the degree of second polynomial:";
    cin >> degree2;
    for (int i = 0; i <= degree2; i++) {
        int coefficient;
        cout << "Enter the coefficient of x^" << i << ":";
        cin >> coefficient;
        Polynomial *new_node = new Polynomial;
        new_node->data = coefficient;
        new_node->power = i;
        new_node->next = nullptr;
        createPolynomial(&second, new_node);
    }
    cout << "Your Second polynomial:";
    displayPolynomial(second);
    cout << endl;
    int choice;
    while (true) {
        cout << endl;
        cout << endl;
        cout << "******* Polynomial Menu *******" << endl;
        cout << "Enter 1 to subtract the polynomials" << endl;
        cout << "Enter 2 to multiply the polynomials" << endl;
        cout << "Enter any number other than 1 or 2 to exit" << endl;
        cout << "Make your choice:";
        cin >> choice;
        if (choice == 1) {
            subtractPolynomial(&first, &second);
        } else if (choice == 2) {
            multiplyPolynomial(&first, &second);
        } else {
            break;
        }
    }
}