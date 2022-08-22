#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
class Node
{
public:
    int seat_no;
    char status;
    Node *prev, *next;
    Node(int j)
    {
        seat_no = j;
        status = '_';
        next = NULL;
    }
    Node(){

    };
    void initiallize(Node *&, int);
    void traverse(Node *&, int);
    void BookTicket(Node *, int);
};
void Node ::initiallize(Node *&col, int i)
{
    for (int j = 1; j <= 10; j++)
    {
        Node *n = new Node(j);
        Node *temp = col;
        if (col == NULL)
        {
            col = n;
            continue;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}
void Node ::traverse(Node *&col, int i)
{
    Node *temp = col;
    while (temp != NULL)
    {
        cout << "[" << temp->status << "]   ";
        temp = temp->next;
    }
}
void Node ::BookTicket(Node *row, int c)
{
    Node *temp = row;
    for (int i = 1; i < c; i++)
    {
        temp = temp->next;
    }
    try
    {

        if (temp->status == 'X')
        {
            int a;
            throw a;
        }
    }
    catch (int a)
    {

        cout << "---------------------------------" << endl;
        cout << "Sorry This Seat Is Already Booked" << endl;
        cout << "---------------------------------" << endl;
    }
    if (temp->status != 'X')
    {
        temp->status = 'X';
    }
}
void CancelTicket(Node *row, int c)
{
    Node *temp = row;
    for (int i = 1; i < c; i++)
    {
        temp = temp->next;
    }
    try
    {

        if (temp->status == '_')
        {
            int b;
            throw b;
        }
    }
    catch (int b)
    {
        cout << "----------------------------------------------------------------------" << endl;
        cout << "This Seat Is Not Booked, Please Enter Correct Row And Coloumn Numbers" << endl;
        cout << "----------------------------------------------------------------------" << endl;
    }
    if (temp->status != '_')
    {
        temp->status = '_';
    }
}
int main()
{
    Node Train_Book;
    Node *col[15];
    for (int i = 0; i < 15; i++)
    {
        col[i] = NULL;
    }
    for (int i = 0; i < 15; i++)
    {
        Train_Book.initiallize(col[i], i + 1);
    }

    int ch;
    do
    {
        cout << "Enter 1: To See The Available Tickets" << endl;
        cout << "Enter 2: To Book Tickets" << endl;
        cout << "Enter 3: Cancel Tickets" << endl;
        cout << "Enter 4: To Exit" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            system("cls");
            cout << "      ";
            for (int i = 1; i <= 10; i++)
            {
                cout << " " << i << "    ";
            }
            cout << endl;
            for (int i = 0; i < 15; i++)
            {
                if (i >= 9)
                {
                    cout << i + 1 << " -> ";
                }
                else
                    cout << i + 1 << " ->  ";

                Train_Book.traverse(col[i], i + 1);
                cout << endl;
                cout << endl;
            }
            break;

        case 2:
        {
            int r, c;
            cout << "Enter Row Number: ";
            cin >> r;
            cout << "Enter Col Number: ";
            cin >> c;
            Train_Book.BookTicket(col[r - 1], c);
            ofstream MyFile("filename.txt", ios::app);
            MyFile << "Seat:-"
                   << "[" << r << "]"
                   << "[" << c << "]"
                   << "booked" << endl;
            MyFile.close();
        }

        break;

        case 3:
            int rc, cc, r, c;
            cout << "Enter Row Number: ";
            cin >> r;
            cout << "Enter Col Number: ";
            cin >> c;
            CancelTicket(col[r - 1], c);
            break;

        case 4:
            cout << "Thank You For Using Our Services" << endl;
        }
    } while (ch != 4);
    return 0;
}