#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
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
    int age = 0;                    // Age of the process
    float feedback_ratio = 0;       // Feedback ratio for feedback scheduling
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
    int getAge()
    {
        return age;
    }
    float getFeedbackRatio()
    {
        return feedback_ratio;
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
    void setAge(int age)
    {
        this->age = age;
    }
    void setFeedbackRatio(float feedback_ratio)
    {
        this->feedback_ratio = feedback_ratio;
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
            << "\nState: " << state 
            << "\nAge: " << age << '\n';
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
void multilevel_feedback_queue_scheduling();
void round_robin();
void longest_job_first();
void lowest_feedback_ratio_next();

int main()
{
    cout << "\n\t Welcome to CPU Scheduling Simulator \n\n";
    // multilevel_queue_scheduling();
    // round_robin();
    // multilevel_feedback_queue_scheduling();



    return 0;
}
// print_sequence function prints the sequence of the processes
void print_sequence(deque<int> sequence)
{
    cout << "\n\t";
    for (int i = 0; i < sequence.size(); i++)
    {
        cout << "P[" << sequence[i] << "] ->";
    }
    cout << "END\n";
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

void multilevel_feedback_queue_scheduling()
{

    // print sequence function
    cout << "\n\t Welcome to Multilevel Feedback Queue Scheduling \n\n"
        << "\n\t We have 3 queues: \n"
        << "\t\t Queue 1: First Come FIrst Serve\n"
        << "\t\t Queue 2: Shortest Remaining Time First\n"
        << "\t\t Queue 3: Round Robin\n"
        << "\t We also has the method for upgrading and degrading the process in queues\n\n";

    int no_of_process_in_q1 {0}, no_of_process_in_q2 {0}, no_of_process_in_q3 {0};

    cout << "\n\t Enter the number of processes in Queue 1: ";
    cin >> no_of_process_in_q1;
    cout << "\n\t Enter the number of processes in Queue 2: ";
    cin >> no_of_process_in_q2;
    cout << "\n\t Enter the number of processes in Queue 3: ";
    cin >> no_of_process_in_q3;

    deque<Process> q1, q2, q3;
    cout << "\n\t Enter the details for the processes in Queue 1: \n";
    for (int i = 0; i < no_of_process_in_q1; i++)
    {
        Process p;
        int pid, burst_time, arrival_time, priority;
        pid = i + 1;
        cout << "\n\t Enter the burst time for process [" << pid << "] : ";
        cin >> burst_time;
        cout << "\n\t Enter the arrival time for process [" << pid << "] : ";
        cin >> arrival_time;
        cout << "\n\t Enter the priority for process [" << pid << "] : ";
        cin >> priority;
        p.setBurstTime(burst_time);
        p.setArrivalTime(arrival_time);
        p.setPriority(priority);
        p.setPID(pid);
        q1.push_back(p);
    }

    cout << "\n\t Enter the details for the processes in Queue 2: \n";
    for (int i = 0; i < no_of_process_in_q2; i++)
    {
        Process p;
        int pid, burst_time, arrival_time, priority;
        pid = i + 1;
        cout << "\n\t Enter the burst time for process [" << pid << "] : ";
        cin >> burst_time;
        cout << "\n\t Enter the arrival time for process [" << pid << "] : ";
        cin >> arrival_time;
        cout << "\n\t Enter the priority for process [" << pid << "] : ";
        cin >> priority;
        p.setBurstTime(burst_time);
        p.setArrivalTime(arrival_time);
        p.setPriority(priority);
        p.setPID(pid);
        q2.push_back(p);
    }

    cout << "\n\t Enter the details for the processes in Queue 3: \n";
    for (int i = 0; i < no_of_process_in_q3; i++)
    {
        Process p;
        int pid, burst_time, arrival_time, priority;
        pid = i + 1;
        cout << "\n\t Enter the burst time for process [" << pid << "] : ";
        cin >> burst_time;
        cout << "\n\t Enter the arrival time for process [" << pid << "] : ";
        cin >> arrival_time;
        cout << "\n\t Enter the priority for process [" << pid << "] : ";
        cin >> priority;
        p.setBurstTime(burst_time);
        p.setArrivalTime(arrival_time);
        p.setPriority(priority);
        p.setPID(pid);
        q3.push_back(p);
    }

    int total_time {0};

    // The qunatum time of queue 1 is 8 with algorithm Fist Come First Serve
    // The quantum time of queue 2 is 16 with algorithm Shortest Remaining Time First
    // The quantum time of queue 3 is 4 with algorithm Round Robin
    // The upgrading policy if the process is queue 1 and it's time is greater than 8*2 = 16 then it will be upgraded to queue 2
    // The upgrading policy if the process is queue 2 and it's time is greater than 16*2 = 32 then it will be upgraded to queue 3
    // The degrading policy if the process is queue 2 and it's time is less than 16/2 = 8 then it will be degraded to queue 1
    // The degrading policy if the process is queue 3 and it's time is less than 4/2 = 2 then it will be degraded to queue 2

    int quantum_time_q1 {8}, quantum_time_q2 {16}, quantum_time_q3 {4};
    int upgrading_time_q1 {16}, upgrading_time_q2 {32};
    int degrading_time_q2 {8}, degrading_time_q3 {2};

    deque<int> sequence;

    while (!q1.empty() || !q2.empty() || !q3.empty())   // While there is any process in any queue
    {
        if (!q1.empty())        // First Come First Serve Algorithm
        {
            // sorting the queue according to the arrival time
            sort(q1.begin(), q1.end(), [](Process p1, Process p2) { return p1.getArrivalTime() < p2.getArrivalTime(); });
            // Also checking upgrading and degrading policy
            if (total_time >= upgrading_time_q1 && !q1.empty())
            {
                Process p = q1.front();
                q1.pop_front();
                p.setPriority(2);
                q2.push_back(p);
                continue;
            }
            // else if (total_time <= degrading_time_q2 && !q2.empty())
            // {
            //     Process p = q2.front();
            //     q2.pop_front();
            //     p.setPriority(1);
            //     q1.push_back(p);
            //     continue;
            // }
            Process p = q1.front();
            q1.pop_front();
            int pid = p.getPID();
            int burst_time = p.getBurstTime();
            int arrival_time = p.getArrivalTime();
            int priority = p.getPriority();
            if (burst_time > quantum_time_q1)   // If the burst time is greater than the quantum time
            {
                burst_time -= quantum_time_q1;
                total_time += quantum_time_q1;
                sequence.push_back(pid);
                p.setBurstTime(burst_time);
                q2.push_back(p);
            }
            else    // If the burst time is less than the quantum time
            {
                total_time += burst_time;
                sequence.push_back(pid);
            }
        }
        else if (!q2.empty())   // Shortest Remaining Time First Algorithm
        {
            // sorting the queue according to the burst time
            sort(q2.begin(), q2.end(), [](Process p1, Process p2) { return p1.getBurstTime() < p2.getBurstTime(); });
            // Also checking upgrading and degrading policy
            if (total_time >= upgrading_time_q2 && !q2.empty())
            {
                Process p = q2.front();
                q2.pop_front();
                p.setPriority(3);
                q3.push_back(p);
                continue;
            }
            else if (total_time <= degrading_time_q2 && !q1.empty())
            {
                Process p = q1.front();
                q1.pop_front();
                p.setPriority(2);
                q2.push_back(p);
                continue;
            }
            Process p = q2.front();
            q2.pop_front();
            int pid = p.getPID();
            int burst_time = p.getBurstTime();
            int arrival_time = p.getArrivalTime();
            int priority = p.getPriority();
            if (burst_time > quantum_time_q2)   // If the burst time is greater than the quantum time
            {
                burst_time -= quantum_time_q2;
                total_time += quantum_time_q2;
                sequence.push_back(pid);
                p.setBurstTime(burst_time);
                q3.push_back(p);
            }
            else    // If the burst time is less than the quantum time
            {
                total_time += burst_time;
                sequence.push_back(pid);
            }
        }
        else if (!q3.empty())   // Round Robin Algorithm
        {
            // Also checking upgrading and degrading policy
            if (total_time <= degrading_time_q3 && !q2.empty())
            {
                Process p = q2.front();
                q2.pop_front();
                p.setPriority(2);
                q3.push_back(p);
                continue;
            }
            Process p = q3.front();
            q3.pop_front();
            int pid = p.getPID();
            int burst_time = p.getBurstTime();
            int arrival_time = p.getArrivalTime();
            int priority = p.getPriority();
            if (burst_time > quantum_time_q3)   // If the burst time is greater than the quantum time
            {
                burst_time -= quantum_time_q3;
                total_time += quantum_time_q3;
                sequence.push_back(pid);
                p.setBurstTime(burst_time);
                q3.push_back(p);
            }
            else
            {
                total_time += burst_time;
                sequence.push_back(pid);
            }
        }
    }

    cout << "\n\t Total time taken by the processes is: " << total_time << endl;
    cout << "\n\t Average time taken by the processes is: " << (float)total_time / (float)(no_of_process_in_q1 + no_of_process_in_q2 + no_of_process_in_q3) << endl;

    cout << "\n\t The sequence of the processes is: ";
    print_sequence(sequence);
    cout << endl;
}

void round_robin()
{
    cout << "\n\t Welcome to Round Robin Scheduling \n\n";
    int no_of_process {0};
    cout << "\n\t Enter the number of processes: ";
    cin >> no_of_process;
    deque<Process> q;
    cout << "\n\t Enter the details for the processes: \n";
    for (int i = 0; i < no_of_process; i++)
    {
        Process p;
        int pid, burst_time, arrival_time, priority;
        pid = i + 1;
        cout << "\n\t Enter the burst time for process [" << pid << "] : ";
        cin >> burst_time;
        cout << "\n\t Enter the arrival time for process [" << pid << "] : ";
        cin >> arrival_time;
        cout << "\n\t Enter the priority for process [" << pid << "] : ";
        cin >> priority;
        p.setBurstTime(burst_time);
        p.setArrivalTime(arrival_time);
        p.setPriority(priority);
        p.setPID(pid);
        q.push_back(p);
    }

    // sorting the queue according to arrival time
    sort(q.begin(), q.end(), [](Process p1, Process p2) {
        return p1.getArrivalTime() < p2.getArrivalTime();
    });

    // taking the time quantum
    int time_quantum {0};
    cout << "\n\t Enter the time quantum: ";
    cin >> time_quantum;

    // calculating the average turn around time and average waiting time
    float avg_turn_around_time {0}, avg_waiting_time {0};

    // copying the queue
    deque<Process> q_copy = q;


    // processing the queue
    int total_time {0};
    while (!q.empty())
    {
        Process p = q.front();
        q.pop_front();
        if (p.getBurstTime() <= time_quantum)
        {
            total_time += p.getBurstTime();
            p.setBurstTime(0);
            p.setCompletionTime(total_time);
            p.setTurnAroundTime(p.getCompletionTime() - p.getArrivalTime());
            p.setWaitingTime(p.getTurnAroundTime() - p.getBurstTime());
            cout << "\n\t Process [" << p.getPID() << "] is completed at time " << p.getCompletionTime() << " with turn around time " << p.getTurnAroundTime() << " and waiting time " << p.getWaitingTime() << "\n";
            avg_waiting_time += p.getWaitingTime();
            avg_turn_around_time += p.getTurnAroundTime();
        }
        else
        {
            total_time += time_quantum;
            p.setBurstTime(p.getBurstTime() - time_quantum);

            // pushing the process to the back of the queue
            q.push_back(p);
        }
    }

    avg_turn_around_time /= no_of_process;
    avg_waiting_time /= no_of_process;
    cout << "\n\t Average Turn Around Time is: " << avg_turn_around_time << "\n";
    cout << "\n\t Average Waiting Time is: " << avg_waiting_time << "\n";

    // // printing the gantt chart
    // cout << "\n\t Gantt Chart: \n";
    // for (int i = 0; i < no_of_process; i++)
    // {
    //     cout << "\t| P" << q[i].getPID() << " ";
    // }
    // cout << "\t|\n\t";
    // for (int i = 0; i < no_of_process; i++)
    // {
    //     cout << q[i].getCompletionTime() << "\t";
    // }
    // cout << "\n";

    // // printing the table
    // cout << "\n\t Process ID \t Burst Time \t Arrival Time \t Turn Around Time \t Waiting Time \n";
    // for (int i = 0; i < no_of_process; i++)
    // {
    //     cout << "\n\t " << q[i].getPID() << "\t\t" << q[i].getBurstTime() << "\t\t" << q[i].getArrivalTime() << "\t\t" << q[i].getTurnAroundTime() << "\t\t\t" << q[i].getWaitingTime() << "\n";
    // }

    // // printing the queue
    // cout << "\n\t Queue: \n";
    // for (int i = 0; i < no_of_process; i++)
    // {
    //     cout << "\t| P" << q[i].getPID() << " ";
    // }
    // cout << "\t|\n\t";
    // for (int i = 0; i < no_of_process; i++)
    // {
    //     cout << q[i].getCompletionTime() << "\t";
    // }
    // cout << "\n";


}


void longest_job_first()
{
    // long job first with preemption
    cout << "\n\t Welcome to Longest Job First Scheduling \n\n";
    int no_of_process {0};
    cout << "\n\t Enter the number of processes: ";
    cin >> no_of_process;
    deque<Process> q;
    cout << "\n\t Enter the details for the processes: \n";
    for (int i = 0; i < no_of_process; i++)
    {
        Process p;
        int pid, burst_time, arrival_time, priority;
        pid = i + 1;
        cout << "\n\t Enter the burst time for process [" << pid << "] : ";
        cin >> burst_time;
        cout << "\n\t Enter the arrival time for process [" << pid << "] : ";
        cin >> arrival_time;
        cout << "\n\t Enter the priority for process [" << pid << "] : ";
        cin >> priority;
        p.setBurstTime(burst_time);
        p.setArrivalTime(arrival_time);
        p.setPriority(priority);
        p.setPID(pid);
        q.push_back(p);
    }

    // sorting the queue according to longest burst time
    sort(q.begin(), q.end(), [](Process p1, Process p2) {
        // sorting first on the basis of arrival time
        if (p1.getArrivalTime() == p2.getArrivalTime())
        {
            return p1.getBurstTime() > p2.getBurstTime();
        }
        return p1.getBurstTime() > p2.getBurstTime();
    });

    // calculating the average turn around time and average waiting time
    float avg_turn_around_time {0}, avg_waiting_time {0};

    int time_quantum {0};
    cout << "\n\t Enter the time quantum: ";
    cin >> time_quantum;
    // processig the process first which has longest burst time and which arrives first
    int total_time {0};
    while (!q.empty())
    {
        Process p = q.front();
        q.pop_front();
        if (p.getBurstTime() <= time_quantum)
        {
            total_time += p.getBurstTime();
            p.setBurstTime(0);
            p.setCompletionTime(total_time);
            p.setTurnAroundTime(p.getCompletionTime() - p.getArrivalTime());
            p.setWaitingTime(p.getTurnAroundTime() - p.getBurstTime());
            cout << "\n\t Process [" << p.getPID() << "] is completed at time " << p.getCompletionTime() 
                << " with turn around time " << p.getTurnAroundTime() << " and waiting time "  
                << p.getWaitingTime() << "\n";
            avg_waiting_time += p.getWaitingTime();
            avg_turn_around_time += p.getTurnAroundTime();
        }
        else
        {
            total_time += time_quantum;
            p.setBurstTime(p.getBurstTime() - time_quantum);

            // pushing the process to the back of the queue
            q.push_back(p);
        }
        
    }
}

void lowest_feedback_ratio_next()
{
//     ● Lowest Feedback Ratio Next Scheduling 
// Lowest Feedback Ratio Next is one of the scheduling algorithms. This is 
// a non-preemptive algorithm in which the scheduling is done on the basis of an 
// extra parameter called Feedback Ratio. A Feedback Ratio is calculated for each 
// of the available jobs and the Job with the lowest feedback ratio is given priority 
// over the others. 
// Feedback Ratio is calculated by the given formula: 
// 1. Feedback Ratio = (W+S)/S 
// Where: W is Waiting Time, S is Service Time or Burst Time 
    cout << "\n\t Welcome to Lowest Feedback Ratio Next Scheduling \n\n";
    int no_of_process {0};
    cout << "\n\t Enter the number of processes: ";
    cin >> no_of_process;
    deque<Process> q;
    cout << "\n\t Enter the details for the processes: \n";
    for (int i = 0; i < no_of_process; i++)
    {
        Process p;
        int pid, burst_time, arrival_time, priority,wating_time;
        pid = i + 1;
        cout << "\n\t Enter the burst time for process [" << pid << "] : ";
        cin >> burst_time;
        cout << "\n\t Enter the arrival time for process [" << pid << "] : ";
        cin >> arrival_time;
        cout << "\n\t Enter the priority for process [" << pid << "] : ";
        cin >> priority;
        cout << "\n\t Enter the waiting time for process [" << pid << "] : ";
        cin >> wating_time;
        p.setBurstTime(burst_time);
        p.setArrivalTime(arrival_time);
        p.setPriority(priority);
        p.setWaitingTime(wating_time);
        p.setPID(pid);
        q.push_back(p);
    }

    // first sorting the queue according to arrival time
    sort(q.begin(), q.end(), [](Process p1, Process p2) {
        // sorting first on the basis of arrival time
        if (p1.getArrivalTime() == p2.getArrivalTime())
        {
            return p1.getPriority() < p2.getPriority();
        }
        else
            return p1.getArrivalTime() < p2.getArrivalTime();
    });

    // calculating feedback ratio for each process
    for (int i = 0; i < no_of_process; i++)
    {
        Process p = q[i];
        float feedback_ratio = (p.getWaitingTime() + p.getBurstTime()) / p.getBurstTime();
        p.setFeedbackRatio(feedback_ratio);
        q[i] = p;
    }

    // sorting the queue according to feedback ratio
    sort(q.begin(), q.end(), [](Process p1, Process p2) {
        return p1.getFeedbackRatio() < p2.getFeedbackRatio();
    });

    // calculating the average turn around time and average waiting time
    float avg_turn_around_time {0}, avg_waiting_time {0};

    // processig the process first which has longest burst time and which arrives first
    int total_time {0};
    for (int i = 0; i < no_of_process; i++)
    {
        Process p = q[i];
        total_time += p.getBurstTime();  
        p.setCompletionTime(total_time);
        p.setTurnAroundTime(p.getCompletionTime() - p.getArrivalTime());        // TAT = CT - AT
        p.setWaitingTime(p.getTurnAroundTime() - p.getBurstTime());             // WT = TAT - BT
        cout << "\n\t Process [" << p.getPID() << "] is completed at time " << p.getCompletionTime() 
            << " with turn around time " << p.getTurnAroundTime() << " and waiting time "  
            << p.getWaitingTime() << "\n";
        avg_waiting_time += p.getWaitingTime();
        avg_turn_around_time += p.getTurnAroundTime();
    }

    cout << "\n\t Average waiting time: " << avg_waiting_time / no_of_process;
    cout << "\n\t Average turn around time: " << avg_turn_around_time / no_of_process;

    
}
//