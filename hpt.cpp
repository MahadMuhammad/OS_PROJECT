#include <iostream>
using namespace std;
int hash_func(int p)
{
    int index=p%10;
    return index;
}
class node
{
public:
    int pageNumber;
    int mapped_frame;
    node *next;

    node(int pn, int fn)
     {
        pageNumber = pn;
        mapped_frame = fn;
        this->next = nullptr;
    }
};
class hpt
{
 node *new_node[10];
 public:
 hpt()
    {
        for (int i = 0; i < 10; i++)
        {
           new_node[i] = nullptr;
        }
    }
 void insert(int pn,int mf)
 {
    int hashIndex=hash_func(pn);
    node*newnode=new node(pn,mf);
     node*n = new node(pn, mf);
        if (new_node[hashIndex] == nullptr) 
        {
            new_node[hashIndex] = n;
        } else 
        {
            node *current = new_node[hashIndex];
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = n;
        }
 }
 bool search(int pageNumber,int &f) 
 {
        int hashIndex=hash_func(pageNumber);
       node *current = new_node[hashIndex];
        while (current != nullptr) 
        {
            if (current->pageNumber == pageNumber) 
            {
                f= current->mapped_frame;
                return true;
            }
            current = current->next;
        }
        return false;
    }
 
};
class TLBNode
{
public:
    int page_number;
    int frame_number;
    TLBNode()
    {
      page_number = 0;
      frame_number = 0;
    }

    TLBNode(int p, int f) 
    {
        page_number = p;
        frame_number = f;
    }
};
class TLB
{
private:
    TLBNode *new_node[5];
    int next=0;
 public:
 TLB()
    {
        for (int i = 0; i < 5; i++)
        {
           new_node[i] = nullptr;
        }
    }

    

    void TLB_insert(int page, int frame)
    {
         TLBNode*n = new TLBNode(page, frame);
            new_node[next] = n;
            next = (next + 1) % 5;
        
    }

    bool TLB_search(int page,int&frame) 
    {
        for (int i = 0; i < 5; i++)
        {
            if (new_node[i]->page_number == page) 
            {
                frame = new_node[i]->frame_number;
                return true;
            }
        }
        return false;
    }
    void print_TLB()
{
    std::cout << "TLB contents:" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        if (new_node[i] != nullptr)
        {
            std::cout << "Page " << new_node[i]->page_number 
                      << " is mapped to frame " << new_node[i]->frame_number 
                      << std::endl;
        }
    }
}

};
int main()
{
     hpt hashPageTable;
    hashPageTable.insert(40, 20);
    hashPageTable.insert(2, 2);
    hashPageTable.insert(15, 15);
    hashPageTable.insert(4, 4);

    TLB t;
    t.TLB_insert(40,20);
    t.TLB_insert(4,0);
    t.TLB_insert(3,4);
    t.TLB_insert(15,15);
    t.TLB_insert(5,6);
 
    //t.print_TLB();
   int n;
   int x;
   int y;
    cout<<"enter the page number that cpu wants"<<endl;
    cin>>n;
    if(t.TLB_search(n,x)==true)
{
    cout<<"the page is found in TLB and is mapped to frame number: "<<x<<endl;
}
else if (hashPageTable.search(n,y)==true)
{
   cout<<"the page is found in hashTable and is mapped to frame number: "<<y<< endl;
   cout<<"tlb has also been updated"<<endl;
   t.TLB_insert(n,y);
   t.print_TLB();


}
else
cout<<"the page number neither exists in tlb nor hash table.so we insert it in the hash table"<<endl;



   
   
    return 0;
}