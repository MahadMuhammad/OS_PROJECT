#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;


struct Node
 {
    int value;
    bool second_chance;
    Node* next;
};

// If page found, updates the second chance bit to true
static bool findAndUpdate(int x, Node* head, int frames)
{
    Node* current = head;
    for(int i = 0; i < frames; i++)
    {
        if(current->value == x)
        {
            // Mark that the page deserves a second chance
            current->second_chance = true;

            // Return 'true', that is there was a hit
            // and so there's no need to replace any page
            return true;
        }
        current = current->next;
    }

    // Return 'false' so that a page for replacement is selected
    // as the requested page doesn't exist in memory
    return false;
}

// Updates the page in memory and returns the pointer
static Node* replaceAndUpdate(int x, Node* head, int frames, Node* pointer)
{
    Node* current = pointer;
    while(true)
    {
        // We found the page to replace
        if(!current->second_chance)
        {
            // Replace with new page
            current->value = x;

            // Return updated pointer
            return current->next;
        }

        // Mark it 'false' as it got one chance
        // and will be replaced next time unless accessed again
        current->second_chance = false;

        // Pointer is updated in round robin manner
        current = current->next;
    }
}

static void printHitsAndFaults(string reference_string, int frames)
{
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* pointer = nullptr;
    int i, l=0, x, pf;

    // Create a circular linked list to hold page numbers
    for(i = 0; i < frames; i++)
    {
        Node* newNode = new Node;
        newNode->value = -1;
        newNode->second_chance = false;
        newNode->next = nullptr;

        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    tail->next = head;

    // No pages initially in frame

    // Create second chance array.
    // Can also be a byte array for optimizing memory
    bool second_chance[frames];

    // Split the string into tokens,
    // that is page numbers, based on space

    string str[100];
    string word = "";
    for (auto x : reference_string)
    {
        if (x == ' ')
        {
            str[l]=word;
            word = "";
            l++;
        }
        else
        {
            word = word + x;
        }
    }
    str[l] = word;
    l++;
    // l=the length of array

    // Initially, pointer points to the head of the linked list
    pointer = head;

    // Number of page faults
    pf = 0;
    for(i = 0; i < l; i++)
    {
        x = stoi(str[i]);
    bool flag=false;
    Node* current = head;
    for(int i = 0; i < frames; i++)
    {
        if(current->value == x)
        {
            // Mark that the page deserves a second chance
            current->second_chance = true;

            // Return 'true', that is there was a hit
            // and so there's no need to replace any page
            flag=true;
            break;
        }
        current = current->next;
    }

    // Return 'false' so that a page for replacement is selected
    // as the requested page doesn't exist in memory
   
        //if(!findAndUpdate(x,head,frames))
        if(!flag)
        {
            // Selects and updates a victim page
            pointer = replaceAndUpdate(x,head,frames,pointer);

            pf++;
        }
    }

    // Delete the circular linked list

    cout << "Total page faults were " << pf << "\n";
}
 
// Driver code
int main()
{
    string reference_string = "";    
    int frames = 0;
 
    // Test 1:
    reference_string = "6 1 1 2 0 3 4 6 0 2 1 2 1 2 0 3 2 1 4 0";
    frames = 3;
     
    // Output is 9
    printHitsAndFaults(reference_string,frames);
     
    // Test 2:
    reference_string = "2 5 10 1 2 2 6 9 1 2 10 2 6 1 2 1 6 9 5 1";
    frames = 4;
     
    // Output is 11
    printHitsAndFaults(reference_string,frames);
    return 0;
}