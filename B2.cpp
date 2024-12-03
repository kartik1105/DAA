#include <bits/stdc++.h>
using namespace std;

// Function to check if it's possible to complete all tasks in at most 'd' days
// with the work limit per day as 'per_day'
bool valid(int per_day, vector<int> task, int d)
{
    int cur_day = 0;
    
    // Loop through each task to calculate the required days
    for (int index = 0; index < task.size(); index++)
    {
        // Calculate the number of days required for the current task
        int day_req = ceil((double)(task[index]) / (double)(per_day));
        cur_day += day_req;
        
        // If the total days exceed 'd', return false
        if (cur_day > d)
        {
            return false;
        }
    }
    // Return true if all tasks can be completed in 'd' days
    return cur_day <= d;
}

// Function to find the minimum work per day that allows completion within 'd' days
int minimumTask(vector<int> task, int d)
{
    // Set the range for binary search: from 1 to the maximum task size
    int left = 1;
    int right = INT_MAX;

    // Find the maximum task size to set the upper bound for binary search
    for (int index = 0; index < task.size(); index++)
    {
        right = max(right, task[index]);
    }

    // Variable to store the minimum work per day
    int per_day_task = 0;

    // Perform binary search to find the minimum work per day
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        // If the current work per day is valid, try to minimize it further
        if (valid(mid, task, d))
        {
            per_day_task = mid;
            right = mid - 1;
        }
        // If the current work per day is not valid, increase the work per day
        else
        {
            left = mid + 1;
        }
    }
    return per_day_task;
}

int main()
{
    vector<int> task;
    int num, temp, days;

    // Input number of tasks
    cout << "Enter the number of tasks to be completed" << endl;
    cin >> num;

    // Input the size of each task
    cout << "Enter the size of each task" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        task.push_back(temp);
    }

    // Input the number of days available to complete the tasks
    cout << "Enter the number of days for the task" << endl;
    cin >> days;

    // Output the minimum work per day required
    cout << "The minimum amount of work to be done each day is ";
    cout << minimumTask(task, days) << endl;
}
