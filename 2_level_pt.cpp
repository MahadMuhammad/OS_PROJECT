#include <iostream>
#include <cstdlib> 
#include <ctime> 

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
class PageTable
{
public:
    int outerSize;
    int innerSize;
    PageTableEntry** table;
    PageTable()
    {

    }

    PageTable(int o, int i) //creating 2 level page table
    {
        outerSize = o;
        innerSize = i;
        table = new PageTableEntry*[outerSize];
        for (int i = 0; i < outerSize; i++) 
        {
            table[i] = new PageTableEntry[innerSize];
            for (int j = 0; j < innerSize; j++) {
                table[i][j] = PageTableEntry(-1, -1);
            }
        }
    }


  void insert(int pageNum, int numFrames)
{
    static bool seeded = false;
    if (!seeded) {
        srand(time(NULL)); // seed random number generator only once
        seeded = true;
    }

    int outerIndex = pageNum / innerSize;
    int innerIndex = pageNum % innerSize;

    bool* frameUsed = new bool[numFrames];
    for (int i = 0; i < numFrames; i++) {
        frameUsed[i] = false;
    }

    // mark all previously assigned frame numbers as used
    for (int i = 0; i < outerSize; i++) {
        for (int j = 0; j < innerSize; j++) {
            if (table[i][j].pageNum != -1) {
                frameUsed[table[i][j].frameNum] = true;
            }
        }
    }

    int frameNum;
    bool frameAssigned = false;
    while (!frameAssigned) {
        frameNum = rand() % numFrames; // generate random frame number
        if (!frameUsed[frameNum]) {
            frameAssigned = true;
        }
    }

    delete[] frameUsed;

    table[outerIndex][innerIndex] = PageTableEntry(pageNum, frameNum);
}



    int search(int pageNum)
     {
        int outerIndex = pageNum / innerSize;
        int innerIndex = pageNum % innerSize;
        PageTableEntry entry = table[outerIndex][innerIndex];
        if (entry.pageNum == pageNum)
         {
            return entry.frameNum;
        } else 
        {
            return -1;
        }
    }
   void print() {
    for (int i = 0; i < outerSize; i++) {
        for (int j = 0; j < innerSize; j++) {
            if (table[i][j].pageNum != -1 && table[i][j].frameNum != -1) {
                cout << "Page " << table[i][j].pageNum << " -> Frame " << table[i][j].frameNum << endl;
            }
        }
    }
}

};
int main()
{
    int num;
int pbits;
int fbits;
int total_frames;
int outer_size;
int inner_size;
int logical;
int output;

cout<<"calculating the frames of memory"<<endl;
    cout << "Enter the number of bits required for physical memory: "<<endl;
    cin >> pbits;
    cout << "Enter the number of bits required for frame size: "<<endl;
    cin >> fbits;
    total_frames = pbits / fbits;
    cout<<"how many pages is the process divided into"<<endl;
    cin>>num;
    cout << "Enter the outer size of the page table: " << endl;
    cin >> outer_size;
    cout << "Enter the inner size of the page table: " << endl;
    cin >> inner_size;
    PageTable pt(outer_size, inner_size);
    for(int i=0;i<num; i++)
    {
       pt.insert(i,total_frames);
    }
    pt.print();
   // cout<<"enter the page number that cpu wants"<<endl;
   int t=fbits*num;
   cout<<"enter the logical address between 0 and "<<t<<endl;
    cin>>logical;
   int page_num=(logical/fbits);
   int offset=(logical%fbits);
    
    //int offset=
    output=pt.search(page_num);
    cout<<"the page number "<<page_num<<" is mapped to frame number "<<output<<endl;
    int physical_add=(output*fbits)+offset;
    cout<<"the physical address is "<<physical_add<<endl;
    cout<<endl;
    return 0;

}


