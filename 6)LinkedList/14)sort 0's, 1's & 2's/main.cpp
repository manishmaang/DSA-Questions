// QUESTION : In usorted ll sort 0's , 1's and 2's in ll but data replace is not allowed
//  data replacement : ek node ki value change nhi kr skte

// data replacement allowed approach : 3 variable bna lenge of zero, one and two
// ll ko travel krenge or jo data milega uske respective variable ko increase kr denge
// fir starting se node me 0 rakhenge jb tk zero variable ki value 0 nhi ho jati fir one and two
#include <bits/stdc++.h>
using namespace std;
class nodes
{
public:
    int data;
    nodes *next;

    nodes(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    ~nodes()
    {
        this->data = 0;
        this->next = nullptr;
    }
};
void print(nodes *&head)
{
    nodes *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// approach 1 :  if data replace is allowed. agr interview me question puche to pehle yhi approach btani hai
// void sortll(nodes *&head)
// {
//     int zero = 0;
//     int one = 0;
//     int two = 0;
//     nodes *temp = head;
//     // step 1 : find no. of 0's , 1's and 2's in ll
//     while (temp != nullptr)
//     {
//         if (temp->data == 0)
//             zero++;
//         else if (temp->data == 1)
//         {
//             one++;
//         }
//         else if (temp->data == 2)
//         {
//             two++;
//         }
//         temp = temp->next;
//     }
//     temp = head;
//     // step 2 : replace node values to 0 till zero variable becomes 0
//     while (zero--)
//     {
//         temp->data = 0;
//         temp = temp->next;
//     }

//     // step 3 : replace node values to 1 till one variable becomes 0
//     while (one--)
//     {
//         temp->data = 1;
//         temp = temp->next;
//     }

//     // step 4 : replace node values to 2 till two variable becomes 0
//     while (two--)
//     {
//         temp->data = 2;
//         temp = temp->next;
//     }
// }

// approach 2 code : where we are not doing data replacement
// pehle hum 3 dummy nodes banaenge for 0,1 & 2 jisme hum koi bhi value rkh skte hai except (0,1,2)
// fir hum ll ke hr node ko visit krenge or use isolate krenge
// fir uski value ke hisb se use dummy node me connect krenge
// fir hum teeno dummy ll ko aps me connect krenge
// fir hum vo dummy node hataenge jise hume starting me dalla the to make dummy ll
// fir hum is ll ka head return kr denge

nodes *sortll(nodes *&head)
{
    // step 1 : create dummy nodes for
    nodes *dummyzero = new nodes(-1);
    nodes *dummyzerotail = dummyzero;

    nodes *dummyone = new nodes(-1);
    nodes *dummyonetail = dummyone;

    nodes *dummytwo = new nodes(-1);
    nodes *dummytwotail = dummytwo;

    // traverse original ll and nodes ko unke respective dummy nodes ke aage attach
    nodes *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            nodes *curr = temp;
            temp = temp->next;
            curr->next = nullptr;

            dummyzerotail->next = curr;
            dummyzerotail = curr;
        }

        else if (temp->data == 1)
        {
            nodes *curr = temp;
            temp = temp->next;
            curr->next = nullptr;
            dummyonetail->next = curr;
            dummyonetail = curr;
        }

        else if (temp->data == 2)
        {
            nodes *curr = temp;
            temp = temp->next;
            curr->next = nullptr;
            dummytwotail->next = curr;
            dummytwotail = curr;
        }
    }
    // STEP 3 : Join dummy ll and remove dummy nodes

    // ideal case : teno dummy ll me valid nodes present hai
    // OHTER CASES :
    // sirf zero me present ho, sirf one me present ho , sirf two me present ho
    // sirf zero one ya zero two me nodes present ho, sirf one or two me present ho
    // null pass hua ho
    // sirf ek node ho
    if (dummyone->next != nullptr)
    {
        dummyzerotail->next = dummyone->next;
        dummyonetail->next = dummytwo->next;
    }
    else if (dummytwo->next != nullptr)
    {
        dummyzerotail->next = dummytwo->next;
    }

    temp = dummyzero->next;

    dummyzero->next = nullptr;
    dummyone->next = nullptr;
    dummytwo->next = nullptr;
    delete dummyone;
    delete dummyzero;
    delete dummytwo;

    return temp;
}
int main()
{
    nodes *head = new nodes(2);
    nodes *sec = new nodes(1);
    nodes *third = new nodes(1);
    nodes *forth = new nodes(0);
    nodes *fifth = new nodes(2);
    nodes *tail = new nodes(0);

    head->next = sec;
    sec->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = tail;
    print(head);

    nodes *newhead = sortll(head);

    print(newhead);
    return 0;
}