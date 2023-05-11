
#include <iostream>
using namespace std;
int hash_func(int p)
{
    int index=p%10;
    return index;
}

#define MAXLINE 80 // The maximum length command
#define MAXARGS 20 // The maximum number of arguments

// Hash page table entry class
class HashPageTableEntry
{
public:
    int pageNumber;
    int frameNumber;
    HashPageTableEntry *next;

    // Constructor
    HashPageTableEntry(int pageNumber, int frameNumber)
     {
        this->pageNumber = pageNumber;
        this->frameNumber = frameNumber;
        this->next = nullptr;
    }
};

// Hash page table class
class HashPageTable
{
public:
    HashPageTableEntry *hashPageTableEntry[MAXARGS];
  // HashPageTableEntry *hashPageTableEntry=new HashPageTableEntry[ MAXARGS] ;

    // Constructor
    HashPageTable()
    {
        for (int i = 0; i < MAXARGS; i++)
        {
            hashPageTableEntry[i] = nullptr;
        }
    }

    // Inserting a hash page table entry into the hash page table
    void insertHashPageTableEntry(int pageNumber, int frameNumber)
     {
       // int hashIndex = pageNumber % MAXARGS;//applying hash function
       int hashIndex=hash_func(pageNumber);
        HashPageTableEntry *newHashPageTableEntry = new HashPageTableEntry(pageNumber, frameNumber);
        if (hashPageTableEntry[hashIndex] == nullptr) {
            hashPageTableEntry[hashIndex] = newHashPageTableEntry;
        } else {
            HashPageTableEntry *currentHashPageTableEntry = hashPageTableEntry[hashIndex];
            while (currentHashPageTableEntry->next != nullptr) {
                currentHashPageTableEntry = currentHashPageTableEntry->next;
            }
            currentHashPageTableEntry->next = newHashPageTableEntry;
        }
    }
    

    // Searching for a hash page table entry in the hash page table
    int searchHashPageTableEntry(int pageNumber) {
        int hashIndex = pageNumber % MAXARGS;
        HashPageTableEntry *currentHashPageTableEntry = hashPageTableEntry[hashIndex];
        while (currentHashPageTableEntry != nullptr) {
            if (currentHashPageTableEntry->pageNumber == pageNumber) {
                return currentHashPageTableEntry->frameNumber;
            }
            currentHashPageTableEntry = currentHashPageTableEntry->next;
        }
        return -1;
    }

    // Printing the hash page table
    void printHashPageTable() {
        for (int i = 0; i < MAXARGS; i++) {
            if (hashPageTableEntry[i] != nullptr) {
                HashPageTableEntry *currentHashPageTableEntry = hashPageTableEntry[i];
                while (currentHashPageTableEntry != nullptr) {
                    printf("Page number: %d, Frame number: %d -> ", currentHashPageTableEntry->pageNumber, currentHashPageTableEntry->frameNumber);
                    currentHashPageTableEntry = currentHashPageTableEntry->next;
                }
                printf("NULL");
                printf(" (Hash index: %d)", i);
                printf("\n");
            }
        }
    }
};

int main(int argc, char *argv[]) {
    // Creating a hash page table
    HashPageTable hashPageTable;

    // Insert hash page table entries into the hash page table
    hashPageTable.insertHashPageTableEntry(40, 20);
    hashPageTable.insertHashPageTableEntry(2, 2);
    hashPageTable.insertHashPageTableEntry(15, 15);
    hashPageTable.insertHashPageTableEntry(4, 4);
    hashPageTable.printHashPageTable();
    //hashPageTable.insertHashPageTableEntry
}