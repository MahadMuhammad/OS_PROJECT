#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int Replace_Page(char temp, char queue[], int use_bit[], int frames, int &front, int &rear)
{
    while (true)
    {
        if (use_bit[front] == 0)
        {
            queue[front] = temp;
            use_bit[front] = 1;
            front = (front + 1) % frames;
            return rear;
        }
        use_bit[front] = 0;
        front = (front + 1) % frames;
        rear = (rear + 1) % frames;
    }
}

void print(string str[100], int frames, int len)
{
    int front = 0, rear = 0;
    int pg_faults = 0;
    char *queue = new char[frames];
    int *use_bit = new int[frames];
    int temp = 0;
    for (int i = 0; i < len; i++)
    {

        temp = stoi(str[i]);
        bool flag = false;
        for (int k = 0; k < frames; k++)
        {
            if (queue[k] == temp)
            {
                use_bit[k] = 1;
                flag = true;
                break;
            }
        }
        if (flag != true)
        {
            rear = Replace_Page(temp, queue, use_bit, frames, front, rear);
            pg_faults++;
        }
    }
    cout << "Total page faults = " << pg_faults << endl;
    float k = ((1.0 * pg_faults) / (1.0 * len)) * 100;
    cout << "Percentage of page faults = " << k << "%" << endl;
}

int main()
{

    string str1 = "";
    int frames = 3;
    str1 = "2 3 2 1 5 2 4 5 3 2 5 2";

    int len = 0;
    string str[100];
    string word = "";
    for (auto x : str1)
    {
        if (x == ' ')
        {
            str[len] = word;
            word = "";
            len++;
        }
        else
        {
            word = word + x;
        }
    }
    str[len] = word;
    len++;
    print(str, frames, len);
    return 0;
}
