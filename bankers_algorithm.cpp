#include <iostream>
#include <string>
using namespace std;

//  Function to print safe sequence
 void printSafeSequence(int numProcesses, int numResources, int *safeSequence)
 {
     cout << "Safe Sequence: ";
     for (int i = 0; i < numProcesses; i++)
     {
         cout << safeSequence[i] << " ";
     }
     cout << endl << endl;
 }
 //calculating need matrix
int **cal_need_matrix( int maximum[][10],int allocation[][10],int numProcesses,int numResources)
{
   int ** need=new int*[10];
   for(int k=0;k<10;k++)
   {
    need[k]=new int[10];
   }
 for (int i = 0; i < numProcesses; i++)
    {
        for (int j = 0; j < numResources; j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
    return need;
}
//printing need matrix
void print_need_matrice(int**need,int numProcesses,int numResources)
{
 for (int i = 0; i < numProcesses; i++)
    {
        for (int j = 0; j < numResources; j++)
        {
            cout<<need[i][j];
            cout<<" "; 
        }
        cout<<endl;
    }  
}
//safety algorithm
bool safetyAlgorithm(int numProcesses, int numResources, int maximum[][10], int allocation[][10], int available[], int *safeSequence, int**need)
{
    int work[10];
    bool is_finish[10];
    int total = 0;
    for (int i = 0; i < numResources; i++)
    {
        work[i] = available[i];
    }
    for (int i = 0; i < numProcesses; i++)
    {
        is_finish[i] = false;
    }
    while (total < numProcesses)
    {
        bool found = false;
        for (int i = 0; i < numProcesses; i++)
        {
            if (!is_finish[i])
            {
                   bool check=true;
                    for (int j = 0; j < numResources; j++)
                    {
                        if (need[i][j] > work[j])//>available
                            {
                                check=false;
                                break;
                            }
                    }
                    
                if(check==true)
                {
                    safeSequence[total] = i;
                    total++;
                 
                    for (int j = 0; j < numResources; j++)
                    {
                        work[j] =work[j]+ allocation[i][j];
                    }
                    
                    is_finish[i] = true;
                    
                    // Set found to true
                    found = true;
                }
            }
        }
        if (!found)
        {
            cout<<"sorry the system is not in safe state"<<endl;
            return false;
        }
    }
        cout<<"the system is in safe state"<<endl;
        printSafeSequence(numProcesses, numResources, safeSequence);
        return true;
}

int main()
{
    int numProcesses;
    int numResources;
    int available[10];
    int maximum[10][10];
    int allocation[10][10];
    int request[10];

    cout << "Enter the total number of processes: ";
    cin >> numProcesses;
    cout << "How many types resources are there in the system: ";//total types of recorces
    cin >> numResources;
    int *safeSequence=new int(numProcesses);
    //how much maximum resources each process needs 
    for (int i = 0; i < numProcesses; i++)
    {
        cout<<"enter the maximum recources required by process "<<i+1<<endl;
        for (int j = 0; j < numResources; j++)
        {
            cin >> maximum[i][j];
        }
    }
     
    
   //allocation
    for (int i = 0; i < numProcesses; i++)
    {
         cout << "please enter the resources allocated to process "<<i+1<<endl;
        for (int j = 0; j < numResources; j++)
        {
            cin >> allocation[i][j];
        }
    }

    int** need;
    need=cal_need_matrix(maximum,allocation,numProcesses,numResources);
    cout<<endl;
    cout<<"the need matrix calculated is:"<<endl;
    print_need_matrice(need,numProcesses,numResources);
    
    // Get available resources
   
    for (int i = 0; i < numResources; i++)
    {
         cout << "please enter how many resources are available in the system for instance : "<<i+1<<endl;
        cin >> available[i];
    }
    cout<<"Running The Safety Algorithm"<<endl;
    bool is_safe = safetyAlgorithm(numProcesses, numResources, maximum, allocation, available, safeSequence,need);
   
    
    //resource_request_algorithm
    cout<<"Running The Resource Request Algorithm"<<endl;
    cout << "Enter the process requesting resources: ";
    int process;
    cin >> process;
    cout << "Enter the request: ";
    for (int i = 0; i < numResources; i++)
    {
        cin >> request[i];
    }
    bool flag1=true;
    for(int i=0;i<numResources;i++)
    {
        if(request[i]>need[process][i])
        {
            flag1=false;
            break;
        }
    }
    if(flag1==false)
    {
        cout<<"cannot grant access";
    }
    int flag2;
    for(int i=0;i<numResources;i++)
    {
            if(request[i]>available[i])
         {
            flag2=false;
            break;
        }
    }
    if(flag2==false)
    {
        cout<<"cannot grant access";
    }  
    for(int i=0;i<numResources;i++)
    {
            available[i]=available[i]-request[i];
            allocation[process][i]=allocation[process][i]+request[i];
            need[process][i]=need[process][i]-request[i];
    }
     cout<<"the need matrix calculated is:"<<endl;
    print_need_matrice(need,numProcesses,numResources);
    cout<<"the allocation matrix is"<<endl;
    for (int i = 0; i < numProcesses; i++)
    {
        for (int j = 0; j < numResources; j++)
        {
            cout<<allocation[i][j];
            cout<<" "; 
        }
        cout<<endl;
    }
    cout<<"available resources are"<<endl;
     for (int i = 0; i < numResources; i++)
     {
        cout<<available[i];
        cout<<" ";
     }  
     cout<<endl;
    
   bool issafe = safetyAlgorithm(numProcesses, numResources, maximum, allocation, available, safeSequence,need);
    
    // Print safe sequence
     if (issafe)
     {
         cout<<"request granted"<<endl;
       
     }
     else
     {
         cout << "cannot grant the request." << endl;
     }

 

    return 0;
}





