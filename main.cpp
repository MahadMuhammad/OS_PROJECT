#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int PID = 1; // Global variable to assign process id
class Process
{
private:
    int pid = -1;                    // process id (-1 for completed process, 0 for init process)
    bool state = 0;                 // 1 for running and 0 for waiting
    int time_slice = 0;             // time slice for round robin
    int burst_time =  0;             // Time for which process will run
    int priority = -1;               // Priority of the process (1-10) 1 being highest priority
    int arrival_time = 0;           // Time at which process arrives
    int completion_time = -1;        // Time at which process completes
    int turn_around_time = 0;       // Time taken for process to complete
    int waiting_time = 0;           // Time for which process waits
    int response_time = 0;          // Time taken for  cout.width(3)    cout.width(3)   
    int remaining_time = 0;         // Time left for process to complete
    int start_time = 0;             // Time at which process starts
    int end_time = 0;               // Time at which process ends
    int policy = 0;                 // 1 for Priority, 2 for Round Robin, 3 for SRJF
public:
    // make a constructor to initialize the process
    Process()
    {
        if(pid == -1){
            pid = PID++;
        }
    }
    Process(int burst_time, int priority, int arrival_time, int policy, int time_slice)
    {
        if(pid == -1){
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
    void setPID(int pid)
    {
        this->pid = pid;
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


void running(int time)
{
    // CPU spinning (for showing the CPU is running)
    time *= 100;
    while (time--)
        ;
}
/// Prototype of functions
void multilevel_queue_scheduling();

int main()
{
    cout << "\n\t Welcome to CPU Scheduling Simulator \n\n";
    multilevel_queue_scheduling();



    return 0;
}


void multilevel_queue_scheduling()
{
    cout << "\n\t MULTILEVEL QUEUE SCHEDULING \n\n"
        << "\nThere are three queues :"
        << "\n\t Queue 1 [Highest Priority]: Priority Scheduling "
        << "\n\t Queue 2 [Medium Priority]: Round Robin  "
        << "\n\t Queue 3 [Lowest Priority]: SRJF (Shortest Remaining Job First) \n\n";

    int no_of_q1_process = 0, no_of_q2_process  = 0 , no_of_q3_process = 0;
    cout << "\nEnter number of processes in Queue 1: ";
    cin >> no_of_q1_process;

    // cout << "\nEnter number of processes in Queue 2: ";
    // cin >> no_of_q2_process;

    cout << "\nEnter number of process in Queue 3: ";
    cin >> no_of_q3_process;

    deque<Process> q1(no_of_q1_process);
    // deque<Process> q2(no_of_q2_process);
    deque<Process> q3(no_of_q3_process);
    vector<int> sequence(no_of_q1_process + no_of_q2_process + no_of_q3_process);
    int A = 0;

    cout << "\n\nEnter the details of processes in Queue 1: \n";
    for (int i = 0; i < no_of_q1_process; i++)
    {
        int burst_time, priority, arrival_time;
        cout << "\nProcess " << i + 1 << ":\n";
        cout << "Burst Time: ";
        cin >> burst_time;
        cout << "Priority: ";
        cin >> priority;
        // cout << "Arrival Time: ";
        // cin >> arrival_time;
        q1[i] = Process(burst_time, priority,  0 /* arrival_time */, 1, 0);
        q1[i].setPID(i+1);
    }

    // cout << "\n\nEnter the details of processes in Queue 2: \n";
    // for (int i = 0; i < no_of_q2_process; i++)
    // {
    //     int burst_time, priority, arrival_time;
    //     cout << "\nProcess " << i + 1 << ":\n";
    //     cout << "Burst Time: ";
    //     cin >> burst_time;
    //     cout << "Priority: ";
    //     cin >> priority;
    //     cout << "Arrival Time: ";
    //     cin >> arrival_time;
    //     q2[i].setPID(i+1);
    //     q2[i] = Process(burst_time, priority, arrival_time, 2, 0);
    // }

    cout << "\n\nEnter the details of processes in Queue 3: \n";
    for (int i = 0; i < no_of_q3_process; i++)
    {
        int burst_time, priority, arrival_time;
        cout << "\nProcess " << i + 1  << "  ORIGNAL ["<< i+1+no_of_q1_process+no_of_q2_process <<"]:\n";
        cout << "Burst Time: ";
        cin >> burst_time;
        cout << "Priority: ";
        cin >> priority;
        /* cout << "Arrival Time: ";
        cin >> arrival_time; */
        // cout << "Process ID: " << q3[i].getPID() << '\n';
        // storing the process id
        q3[i] = Process(burst_time, priority,0 /* arrival_time */, 3, 0);
        q3[i].setPID(i+1+no_of_q1_process /* +no_of_q2_process */);
    }

    int total_time = 0;
    for (int i = 0; i < no_of_q1_process; i++)
    {
        total_time += q1[i].getBurstTime();
    }
    // for (int i = 0; i < no_of_q2_process; i++)
    // {
    //     total_time += q2[i].getBurstTime();
    // }
    for (int i = 0; i < no_of_q3_process; i++)
    {
        total_time += q3[i].getBurstTime();
    }

    // running till all processes are completed
    while(!(q1.empty()  /* && q2.empty() */&& q3.empty()))
    {
        cout << "\nIn Queue 1: \n";
        // checking for processes in queue 1
        while(!q1.empty())     // Priority Scheduling
        {
            // sorting queue 1 according to priority
            sort(q1.begin(), q1.end(), [](Process a, Process b) {
                // sort according to priority and arrival time
                if (a.getPriority() == b.getPriority())
                    return a.getArrivalTime() < b.getArrivalTime();
                return a.getPriority() < b.getPriority();
            });

            // running the process with highest priority
            q1[0].setStartTime(total_time);
            q1[0].setEndTime(total_time + q1[0].getBurstTime());        // expected end time
            q1[0].setCompletionTime(q1[0].getEndTime() - q1[0].getArrivalTime());           // TODO: Fix Error
            q1[0].setTurnAroundTime(q1[0].getCompletionTime() - q1[0].getArrivalTime());
            q1[0].setWaitingTime(q1[0].getTurnAroundTime() - q1[0].getBurstTime());
            q1[0].setResponseTime(q1[0].getStartTime() - q1[0].getArrivalTime());
            running(q1[0].getBurstTime());
            q1[0].setRemainingTime(0);
            q1[0].setState(true);
            total_time += q1[0].getBurstTime();             // FIX ERROR
            cout << "\n\tProcess " << q1[0].getPID() /* - (2*no_of_q1_process) */   << " completed.\n";
            sequence[A++] = q1[0].getPID();
            q1.pop_front();
        }

        // cout << "\nIn Queue 2: \n";
        // Queue 2

        cout << "\nIn Queue 3: \n";
        while((!q3.empty()) && q1.empty()/* &&  q2.empty() */)
        {
            // shortest remaining job first
            sort(q3.begin(), q3.end(), 
            [](Process a, Process b) {
                // sort according to remaining time and arrival time
                if (a.getRemainingTime() == b.getRemainingTime())
                    return a.getArrivalTime() < b.getArrivalTime();
                return a.getRemainingTime() < b.getRemainingTime();
            });

            // running the process with shortest remaining time
            q3[0].setStartTime(total_time);
            q3[0].setEndTime(total_time + q3[0].getRemainingTime());
            q3[0].setCompletionTime(q3[0].getEndTime() - q3[0].getArrivalTime());
            q3[0].setTurnAroundTime(q3[0].getCompletionTime() - q3[0].getArrivalTime());
            q3[0].setWaitingTime(q3[0].getTurnAroundTime() - q3[0].getBurstTime());
            q3[0].setResponseTime(q3[0].getStartTime() - q3[0].getArrivalTime());
            running(q3[0].getRemainingTime());
            q3[0].setRemainingTime(0);
            q3[0].setState(true);
            total_time += q3[0].getRemainingTime();
            cout << "\n\tProcess " << q3[0].getPID()  /* - (2*no_of_q3_process) */ << " completed.\n";
            sequence[A++] = q3[0].getPID();
            q3.pop_front();
        }
    }
    cout << "\n\n The sequence of execution is: \n"
        << "\t For Queue 1: \n\t\t";
    int i = 0;
    for (; i < no_of_q1_process; i++)
    {
        cout << "P[" << sequence[i] << "] --> ";
    } cout << "END\n";

    cout << "\t For Queue 2: \n\t\t";
    for (; i < no_of_q1_process + no_of_q2_process ; i++)
    {
        cout << "P[" << sequence[i] << "] -->";
    } cout << "END\n";

    cout << "\t For Queue 3: \n\t\t";
    for(; i < no_of_q1_process + no_of_q2_process + no_of_q3_process; i++)
    {
        cout << "P[" << sequence[i] << "] --> ";
    } cout << "END\n";
}