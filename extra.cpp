#include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime> // for time

using namespace std;

class PageTableEntry
 {
public:
    int pageNum;
    int frameNum;
   
   PageTableEntry()
     {
        pageNum = 0;
        frameNum = 0;
    }

    PageTableEntry(int p, int f)
     {
        pageNum = p;
        frameNum = f;
    }
};

class PageTable {
public:
    int outerSize;
    int innerSize;
    PageTableEntry** table;

    PageTable(int os, int is) {
        outerSize = os;
        innerSize = is;
        table = new PageTableEntry*[outerSize];
        for (int i = 0; i < outerSize; i++) {
            table[i] = new PageTableEntry[innerSize];
            for (int j = 0; j < innerSize; j++) {
                table[i][j] = PageTableEntry(-1, -1);
            }
        }
    }

    ~PageTable() {
        for (int i = 0; i < outerSize; i++) {
            delete[] table[i];
        }
        delete[] table;
    }

    void insert(int pageNum) {
        srand(time(NULL)); // initialize random seed
        int frameNum = rand() % (outerSize * innerSize); // generate random frame number
        int outerIndex = pageNum / innerSize;
        int innerIndex = pageNum % innerSize;
        table[outerIndex][innerIndex] = PageTableEntry(pageNum, frameNum);
    }

    int lookup(int pageNum) {
        int outerIndex = pageNum / innerSize;
        int innerIndex = pageNum % innerSize;
        PageTableEntry entry = table[outerIndex][innerIndex];
        if (entry.pageNum == pageNum) {
            return entry.frameNum;
        } else {
            return -1;
        }
    }
};

int main() {
    int bitsPhysicalMemory, bitsFrameSize;
    cout << "Enter the number of bits for physical memory: ";
    cin >> bitsPhysicalMemory;
    cout << "Enter the number of bits for frame size: ";
    cin >> bitsFrameSize;
    int numFrames = bitsPhysicalMemory / bitsFrameSize;

    PageTable pt(numFrames, bitsFrameSize); // outer table size = number of frames, inner table size = bits per frame

    // insert some page table entries
    for (int i = 0; i < numFrames; i++) {
        pt.insert(rand() % numFrames); // generate a random page number
    }

    // lookup frame number for a given page number
    int pageNum;
    cout << "Enter a page number: ";
    cin >> pageNum;
    int outerIndex = pageNum / pt.innerSize;
    int innerIndex = pageNum % pt.innerSize;
    int frameNum = pt.lookup(pageNum);
    if (frameNum != -1) {
        cout << "The frame number for page " << pageNum << " is " << frameNum << endl;
        cout << "It is located in the outer table at index " << outerIndex << " and in the inner table at index " << innerIndex << endl;
    } else {
        cout << "Page " << pageNum << " is not present in the page table." << endl;
    }

    return 0;
}
