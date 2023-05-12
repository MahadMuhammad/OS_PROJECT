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
    
    node()
    {
        pageNumber =0;
        mapped_frame = 0;
        this->next = nullptr;
    }

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
    int Index=hash_func(pn);

     node*n = new node(pn, mf);
        if (new_node[Index] == nullptr) 
        {
            new_node[Index] = n;
        }
         else 
        {
            node *current = new_node[Index];
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
 void print_hpt()
{
    cout << "the hpt is as follows:" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (new_node[i] != nullptr)
        {
            cout << "Page " << new_node[i]->pageNumber
                      << " is mapped to frame " << new_node[i]->mapped_frame << endl;
        }
    }
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

    bool TLB_search(int page,int&f) 
    {
        for (int i = 0; i < 5; i++)
        {
            if(new_node[i]!=nullptr)
         {
            if (new_node[i]->page_number == page) 
            {
                f = new_node[i]->frame_number;
                return true;
            }
         }
        }
        return false;
    }
    void print_TLB()
{
    cout << "the tlb is as follows:" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (new_node[i] != nullptr)
        {
            cout << "Page " << new_node[i]->page_number 
                      << " is mapped to frame " << new_node[i]->frame_number << endl;
        }
    }
}

};
int main()
{
     hpt h;
    h.insert(7,6);
    h.insert(32, 2);
    h.insert(12,56);
    h.insert(14, 4);
   // h.print_hpt();
    

    TLB t;
    t.TLB_insert(7,6);
    t.TLB_insert(4,0);
    t.TLB_insert(3,4);
    t.TLB_insert(14,4);
    t.TLB_insert(5,6);
 
  t.print_TLB();
   int n;
   int x;
   int y;
    cout<<"enter the page number that cpu wants"<<endl;
    cin>>n;
    if(t.TLB_search(n,x)==true)
{
    cout<<"the page is found in TLB and is mapped to frame number: "<<x<<endl;
}
else if (h.search(n,y)==true)
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