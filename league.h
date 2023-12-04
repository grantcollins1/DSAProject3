//
// Created by Grant Collins on 12/1/23.
//
#include "player.h"
#include <vector>
#include <ctime>
#include <cmath>
#ifndef DSAPROJECT3CONTINUED_LEAGUE_H
#define DSAPROJECT3CONTINUED_LEAGUE_H

using namespace std;
class League {
public:
    vector<Player*> players;
    vector<Player*> merge_sorted_players;
    vector<Player*> quick_sorted_players;
    League();
    void quickSort(vector<Player*> &sort_players, int low, int high);
    int partition(vector<Player*> &sort_players, int low, int high);
    void print_sorted(int len);
    void Desired_Stat(string wanted);
    void mergeSort(vector<Player*> &sort_players, int const begin, int const end);
    void merge(vector<Player*> &sort_players, int const left, int const mid, int const right);
    void Sort(string get_stat);
    ~League();
};

League::League() {
}

void League::Sort(string get_stat) {
    //calls the sort functions and gets the time that each function took
    clock_t time_req;
    quick_sorted_players = players;
    merge_sorted_players = players;
    Desired_Stat(get_stat);
    time_req = clock();
    quickSort(quick_sorted_players, 0, quick_sorted_players.size() - 1);
    time_req = clock() - time_req;
    cout<<"Quick Sort took: "<<((float)time_req/CLOCKS_PER_SEC)*1000000<<" microseconds"<<endl;
    time_req = clock();
    mergeSort(merge_sorted_players, 0, merge_sorted_players.size()-1);
    time_req = clock() - time_req;
    cout<<"Merge Sort took: "<<((float)time_req/CLOCKS_PER_SEC)*1000000<<" microseconds"<<endl;

}

void League::quickSort(vector<Player*> &sort_players, int low, int high) {
    if(low<high)
    {

        int pivot = partition(sort_players, low, high);
        // sets a new index for pivot and then sorts each side of the pivot
        quickSort(sort_players, low, pivot - 1);
        quickSort(sort_players, pivot+ 1, high);
        //calls quickSort for each side of the vector until low is not less than high
    }



}



void League::print_sorted(int len) {
    //prints out the sorted player vector
    int rank = 1;
    for (int i = merge_sorted_players.size()-1; i>=merge_sorted_players.size()-len; i--) {
        cout<<rank<<". "<<merge_sorted_players.at(i)->name<< ": " ;
        printf("%.2f\n", merge_sorted_players.at(i)->current_stat);
        rank+=1;
    }
}

int League::partition(vector<Player*> &sort_players, int low, int high) {

    float pivot=sort_players.at(high)->current_stat;
    int i=(low-1);

    for(int j=low;j<=high;j++)
    {
        if(sort_players.at(j)->current_stat<pivot)
        {
            i++;
            //increases i if the current stat is less than the pivot's stat
            Player* temp = sort_players.at(j);
            sort_players.at(j) = sort_players.at(i);
            sort_players.at(i) = temp;
            //swaps elements at i and at j indexes
        }
    }
    //swaps elements at i+1 and at high indexes
    Player* temp = sort_players.at(high);
    sort_players.at(high) = sort_players.at(i+1);
    sort_players.at(i+1) = temp;
    return (i+1);
}

void League::mergeSort(vector<Player*> &sort_players, int const begin, int const end) {
    //Base case: if the size of the array is 1 or less, it is already sorted
    if (begin >= end)
        return;

    //Calculate the middle index of the array
    int mid = begin + (end - begin) / 2;


    mergeSort(sort_players, begin, mid);
    mergeSort(sort_players, mid + 1, end);
    merge(sort_players, begin, mid, end);
}

void League::merge(vector<Player*> &sort_players, int const left, int const mid, int const right) {

    //Calculate the size of the two subarrays
    int const size_left = mid - left + 1;
    int const size_right  = right - mid;

    // Create temporary arrays to hold the two subarrays
    vector<Player *> left_array(size_left), right_array(size_right );

    // Copy data from 'sort_players' to the temporary arrays
    for (auto i = 0; i < size_left; i++) {
        left_array[i] = sort_players[left + i];
    }
    for (auto j = 0; j < size_right ; j++) {
        right_array[j] = sort_players[mid + 1 + j];
    }

    // Merge the two subarrays back into 'sort_players'
    auto index_left = 0, index_right = 0;
    int index_merged = left;

    //Compare elements from the two subarrays and merge in sorted order
    while (index_left < size_left && index_right < size_right ) {
        if (left_array[index_left] -> current_stat <= right_array[index_right] ->current_stat) {
            sort_players[index_merged] = left_array[index_left];
            index_left++;
        } else {
            sort_players[index_merged] = right_array[index_right];
            index_right++;
        }
        index_merged++;
    }

    // If there are any reaming elements from left subarray
    while (index_left < size_left) {
        sort_players[index_merged] = left_array[index_left];
        index_left++;
        index_merged++;
    }

    // If there are any reaming elements from right subarray
    while (index_right < size_right ) {
        sort_players[index_merged] = right_array[index_right];
        index_right++;
        index_merged++;
    }
}


void League::Desired_Stat(string wanted) {
    //sets the players' current stats to whatever stat the user wants to sort based on
    for (int i = 0; i <players.size(); i++) {
        players.at(i)->SetCurrentStat(wanted);
    }
}


League::~League() {
    for (int i = 0; i < players.size(); i++) {
        delete players.at(i);
    }
}

#endif //DSAPROJECT3CONTINUED_LEAGUE_H