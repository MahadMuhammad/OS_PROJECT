#include <iostream>
#include <queue>
using namespace std;

int PID = 0; // Global variable to assign process id
class Process
{
private:
    int pid = -1;                    // process id (-1 for completed process, 0 for init process)
    bool state = 0;                 // 1 for running and 0 for waiting
    int time_slice = 0;             // time slice for round robin
    int burst_time =  -1;             // Time for which process will run
    int priority = -1;               // Priority of the process (1-10) 1 being highest priority
    unsigned int arrival_time = 0;           // Time at which process arrives
    unsigned int completion_time = 0;        // Time at which process completes
    int turn_around_time = 0;       // Time taken for process to complete
    int waiting_time = 0;           // Time for which process waits
    int response_time = 0;          // Time taken for  cout.width(3)    cout.width(3)   
        }
    }
    Process(int burst_time, int priority, int arrival_time, int policy, int time_slice)
    {
        if(PID == -1){
            pid = PID++;
        }
        this->time_slice = time_slice;
        this->burst_time = burst_time;
        this->priority = priority;
        this->arrival_time = arrival_time;
        completion_time = 0;
        turn_around_time = 0;
        waiting_time = 0;
        response_time = 0;
        remaining_time = burst_time;
        start_time = 0;
        end_time = 0;
        this->policy = policy;
    }
    int getPID()
    {
        if (pid == -1)
        {
            cout << "Process has been completed" << endl;
            return -1;
        }
        else
            return pid;
    }
    int getBurstTime()
    {
        if (burst_time == -1)
        {
            cout << "Burst time not assigned\n";
            return -1;
        }
        else
            return burst_time;
    }
    int getPriority()
    {
        if (priority == -1)
        {
            cout << "Priority not assigned\n";
            return -1;
        }
        else
            return priority;
    }
    int getArrivalTime()
    {
        return arrival_time;
    }
    int getCompletionTime()
    {
        return completion_time;
    }
    int getTurnAroundTime()
    {
        return turn_around_time;
    }
    int getWaitingTime()
    {
        return waiting_time;
    }
    int getResponseTime()
    {
        return response_time;
    }
    int getRemainingTime()
    {
        return remaining_time;
    }
    int getStartTime()
    {
        return start_time;
    }
    int getEndTime()
    {
        return end_time;
    }
    int getTimeSlice()
    {
        return time_slice;
    }
    int getPolicy()
    {
        return policy;
    }
    bool getState()
    {
        return state;
    }
    void setBurstTime(int burst_time)
    {
        this->burst_time = burst_time;
    }
    void setPriority(int priority)
    {
        this->priority = priority;
    }
    void setArrivalTime(int arrival_time)
    {
        this->arrival_time = arrival_time;
    }
    void setCompletionTime(int completion_time)
    {
        this->completion_time = completion_time;
    }
    void setTurnAroundTime(int turn_around_time)
    {
        this->turn_around_time = turn_around_time;
    }
    void setWaitingTime(int waiting_time)
    {
        this->waiting_time = waiting_time;
    }
    void setResponseTime(int response_time)
    {
        this->response_time = response_time;
    }
    void setRemainingTime(int remaining_time)
    {
        this->remaining_time = remaining_time;
    }
    void setStartTime(int start_time)
    {
        this->start_time = start_time;
    }
    void setEndTime(int end_time)
    {
        this->end_time = end_time;
    }
    void setTimeSlice(int time_slice)
    {
        this->time_slice = time_slice;
    }
    void setPolicy(int policy)
    {
        this->policy = policy;
    }
    void setState(bool state)
    {
        this->state = state;
    }
    void printProcess()
    {
        cout << "\nProcess ID: " << pid
            << "\nBurst Time: " << burst_time
            << "\nPriority: " << priority
            << "\nArrival Time: " << arrival_time
            << "\nCompletion Time: " << completion_time
            << "\nTurn Around Time: " << turn_around_time
            << "\nWaiting Time: " << waiting_time
            << "\nResponse Time: " << response_time
            << "\nRemaining Time: " << remaining_time
            << "\nStart Time: " << start_time
            << "\nEnd Time: " << end_time
            << "\nTime Slice: " << time_slice
            << "\nPolicy: " << policy
            << "\nState: " << state << '\n';
    }

};
int main()
{
    int no_of_processes = 0;
    int burst_time = 0;
    int priority = 0;
    int arrival_time = 0;
    int policy = 0;
    int time_slice = 0;
    cout <<"    Enter number of processes: ";
    cin >> no_of_processes;
    return 0;
}