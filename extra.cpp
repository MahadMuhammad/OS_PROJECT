#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;

struct Node {
    int value;
    int use_bit;
    Node* next;
};
 Node* replace(int x, Node* head, int frames, Node* pointer) 
{
    Node* current = pointer;
    while (true)
     {
       
        if (current->use_bit == 0)
         {
           
            current->value = x;
            current->use_bit = 1;
            return current->next;
        }
        current->use_bit = 0;
        current = current->next;
    }
}

 void page_fault(int *a, int frames, int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* pointer = nullptr;
    int i,x, pf;

    for (i = 0; i < frames; i++) {
        Node* newNode = new Node;
        newNode->value = -1;
        newNode->use_bit = 1;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    tail->next = head;

    int use_bit[frames];
    pointer = head;

    pf = 0;
    for (i = 0; i < n; i++)
     {
        x = a[i];
        bool flag = false;
        Node* current = head;
        for (int i = 0; i < frames; i++) {
            if (current->value == x)
             {
                cout << "hit on " << x << endl;
                if (current->use_bit == 0) 
                {
                    current->use_bit = 1;
                }
                 current->use_bit = 1;
                flag = true;
                break;
            }
            current = current->next;
        }

        if (!flag)
         {
            bool flag1 = false;
            Node* current = head;
            for (int i = 0; i < frames; i++)
             {
                if (current->value == -1)
                {
                    pf++;
                    cout << "fault1 on " << x << endl;
                    current->value = x;
                    current->use_bit = 1;
                    flag1 = true;
                    break;
                }
                current = current->next;
            }
            if (!flag1)
             {
                cout << "fault on " << x << endl;
                pointer = replace(x, head, frames, pointer);
                pf++;
            }
        }
    }
    float prob = (1.0 *(float) pf) / n;
    cout << "The total number of page faults are " << pf << "\n";
    cout << "The page fault probability is " << prob << "\n";
    float k = (1.0 *(float)pf /(float) n) * 100;
 cout << "Percentage of page faults = " << k << "%" << endl;

}
 

int main()
{   
    int frames = 3;
    int a1[18]={5,4,3,4,5,4,2,4,3,4,1,2,3,2,5,4,6,4};
    page_fault(a1,frames,18);
     
    return 0;
}