#include <iostream>
#include <queue>
using namespace std;
int p;
class Process
 {  
    public:
    int pid;
    long state;//1 for running and 0 for waiting
    int time_slice; 
    int burst_time;    
    int priority;        
    int arrival_time;   
   

    Process( int Burst_time, int Priority, int Arrival_time,int quantum)
     {
        pid = p;
        p++;
        burst_time = Burst_time;
        priority = Priority;
        arrival_time = Arrival_time;
        time_slice=quantum;
        
    
       
    }
    int process_id()
    {
        
    }
};
int main()
{
    return 0;
}