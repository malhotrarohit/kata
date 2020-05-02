// AttendingWorkshops.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Refer to problem at -
// https://www.hackerrank.com/challenges/attending-workshops/problem
//

#include <algorithm>
#include <iostream>

struct Workshop
{
    int startTime;
    int endTime;
    int duration;

    bool operator < (const Workshop& wrkshp) const
    {
        return endTime < wrkshp.endTime;
    }
};

struct Available_Workshops
{
    int numWorkshops;
    Workshop* workshops;
};

Available_Workshops* initialize(int* startTime, int* duration, int n)
{
    int i = 0;
    Available_Workshops* ptr = new Available_Workshops();

    if (n > 0) 
    {
        ptr->numWorkshops = n;
        ptr->workshops = new Workshop[n];
        while (i < n)
        {
            ptr->workshops[i].startTime = startTime[i];
            ptr->workshops[i].duration = duration[i];
            ptr->workshops[i].endTime = ptr->workshops[i].startTime + ptr->workshops[i].duration;
            i++;
        }
    }

    return ptr;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    // TODO put algorithm to solve the problem here
    std::sort(ptr->workshops, ptr->workshops + ptr->numWorkshops);
    int i = ptr->numWorkshops;

    Workshop* workshops = ptr->workshops;
    int recentEndTime = -1;
    int countWorkshops = 0;

    while (i > 0)
    {
        if (workshops->startTime >= recentEndTime)
        {
            countWorkshops++;
            recentEndTime = workshops->endTime;
        }
        i--;
        workshops++;
    }
    return countWorkshops;
}

void FreeMemory(Available_Workshops* availableWorkshops)
{
    delete availableWorkshops->workshops;

    delete availableWorkshops;
}

int main()
{
    int n; // number of workshops
    std::cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> duration[i];
    }

    Available_Workshops* ptr;
    ptr = initialize(start_time, duration, n);
    std::cout << CalculateMaxWorkshops(ptr) << std::endl;

    FreeMemory(ptr);
    return 0;
}
