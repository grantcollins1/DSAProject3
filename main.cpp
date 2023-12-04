#include <iostream>
//#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>
#include "player.h"
#include "shot.h"
#include "league.h"
#include <set>
using namespace std;
void inputFile(League& nba);
void GetInputs(League &nba);

int main() {

    League nba;
    inputFile(nba);
    GetInputs(nba);
}

//this function reads in the user inputs and runs functions according to the user inputs
void GetInputs(League& nba) {

    //main menu displayed
    int selection;
    cout << "Welcome to The NBA Data Center!" << endl << "This data center allows you to determine the stats of NBA players during the 2014-15 NBA season"<<endl<<endl;
    cout << "Menu: Select a number" << endl;
    cout << "Player Stats:          1" << endl;
    cout << "Leaderboard:           2" << endl;
    cin >> selection;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (selection == 1){
        //allows a user to search for a player and show their statistics
        int index = -1;
        while(index == -1){
            string name;
            cout << "Enter player name: ";
            getline(cin, name);

            transform(name.begin(), name.end(), name.begin(), ::tolower);
            for(int i = 0; i<nba.players.size(); i++){
                if(name == nba.players.at(i)->name) {
                    index = i;
                    break;
                }
            }
            if(index == -1){
                cout << "Player not found. Please try again" << endl;
            }
        }
        cout << endl << "Choose the statistics you want to see and seperate with a comma, ex: 1,4,3..." << endl;
        cout<<"1. Average Shooting Percentage"<<endl;
        cout<<"2. Three-Point Percentage"<<endl;
        cout<<"3. Average Distance of Made Shots"<<endl;
        cout<<"4. Shooting Percentage with Good Defense"<<endl;
        cout<<"5. Shooting Percentage with Moderate Defense"<<endl;
        cout<<"6. Shooting Percentage with Bad Defense"<<endl;
        cout<<"7. Close Range Shooting Percentage"<<endl;
        cout<<"8. Mid Range Shooting Percentage"<<endl;
        cout<<"9. Long Range Shooting Percentage"<<endl;
        cout<<"10. Shots Taken" << endl;
        cout<<"11. Shots Made" << endl;
        std::string input;
        std::cout << "Enter numerical values separated by commas: ";
        std::getline(std::cin, input);

        std::istringstream ss(input);
        std::vector<int> values;

        std::string token;
        while (std::getline(ss, token, ',')) {
            int value = std::stoi(token);
            values.push_back(value);
        }

        // Pulling and display the requested values
        float stat;
        cout<<nba.players.at(index)->name<<" 2014-15 Season Stats:"<<endl;
        for (int val : values) {
            if (val == 1) {
                stat = nba.players.at(index)->getPercentage();
                printf("Average shooting percentage: %.2f\n", stat);
            }
            else if (val == 2) {
                stat = nba.players.at(index)->getThreePtPercentage();
                printf("3pt shooting percentage: %.2f\n", stat);
            }
            else if (val == 3){
                stat = nba.players.at(index)->getAvgShotDistance();
                printf("Average made shot distance: %.2f\n", stat);
            }
            else if (val == 4) {
                stat = nba.players.at(index)->getGoodDefense();
                printf("Shooting Percentage with Good Defense: %.2f\n", stat);
            }
            else if (val == 5){
                stat = nba.players.at(index)->getModerateDefense();
                printf("Shooting Percentage with Moderate Defense: %.2f\n", stat);
            }
            else if (val == 6) {
                stat = nba.players.at(index)->getBadDefense();
                printf("Shooting Percentage with Bad Defense: %.2f\n", stat);
            }
            else if (val == 7){
                stat = nba.players.at(index)->getCloseRange();
                printf("Close Range Shooting Percentage: %.2f\n", stat);
            }
            else if (val == 8) {
                stat = nba.players.at(index)->getMidRange();
                printf("Mid Range Shooting Percentage: %.2f\n", stat);
            }
            else if (val == 9){
                stat = nba.players.at(index)->getLongRange();
                printf("Long Range Shooting Percentage: %.2f\n", stat);
            }
            else if (val == 10){
                stat = nba.players.at(index)->getTotalShots();
                printf("Total Shots Taken: %.0f\n", stat);
            }
            else if (val == 11){
                stat = nba.players.at(index)->getShotsMade();
                printf("Total Shots Made: %.0f\n", stat);
            }
            else{
                cout << "Invalid Input" << endl;
            }
        }
        cout<<"Enter y to return to the main menu. Enter any other key to exit the program."<<endl;
        string ending;
        cin>>ending;
        if (ending == "y") {
            GetInputs(nba);
        }

    }
    if (selection == 2) {
        //allows a user to choose a stat and displays a leaderboard of players sorted by that stat
        cout<<"Choose a stat :"<<endl;
        cout<<"1. Total Shooting Percentage"<<endl;
        cout<<"2. Three-Point Percentage"<<endl;
        cout<<"3. Average Distance of Made Shots"<<endl;
        cout<<"4. Shooting Percentage with Good Defense"<<endl;
        cout<<"5. Shooting Percentage with Moderate Defense"<<endl;
        cout<<"6. Shooting Percentage with Bad Defense"<<endl;
        cout<<"7. Close Range Shooting Percentage"<<endl;
        cout<<"8. Mid Range Shooting Percentage"<<endl;
        cout<<"9. Long Range Shooting Percentage"<<endl;
        cout<<"10. Shots Taken"<<endl;
        cout<<"11. Shots Made"<<endl;
        int choice;
        cin >> choice;
        cout<<"How many players do you want to display on the leaderboard?"<<endl;
        int leaderboard_length;
        cin >> leaderboard_length;
        while (leaderboard_length > nba.players.size()) {
            // Validate input
            cout<<"Please enter a smaller number of players."<<endl;
            cin >> leaderboard_length;
        }
        if (choice == 1) {
            nba.Sort("shot_percentage");
        }
        else if (choice == 2) {
            nba.Sort("three_percentage");
        }
        else if (choice == 3) {
            nba.Sort("avg_made_shot_dist");
        }
        else if (choice == 4) {
            nba.Sort("good_defense");
        }
        else if (choice == 5) {
            nba.Sort("moderate_defense");
        }
        else if (choice == 6) {
            nba.Sort("bad_defense");
        }
        else if (choice == 7) {
            nba.Sort("close_range");
        }
        else if (choice == 8) {
            nba.Sort("mid_range");
        }
        else if (choice == 9) {
            nba.Sort("long_range");
        }
        else if (choice == 10) {
            nba.Sort("total_shots");
        }
        else if (choice == 11) {
            nba.Sort("shots_made");
        }

        //prints out the sorted leaderboard of however many players the user desires
        nba.print_sorted(leaderboard_length);
        cout<<"Enter y to return to the main menu. Enter any other key to exit the program."<<endl;
        string ending;
        cin>>ending;
        if (ending == "y") {
            GetInputs(nba);
        }
    }



};

void inputFile(League& nba){
    //this function goes through the players_shots.csv file and adds the data to Shot and Player classes
    ifstream players_file("players_shots.csv");

    if (!players_file.is_open()) {
        cout << "Failed to open the file." << std::endl;
        return;
    }
    string discard;
    string info;
    string defense;
    string type;
    string line;
    set<string> player_names;
    Player* current_player;
    Shot* current_shot;
    bool three;
    bool made;
    int iteration = 0;
    getline(players_file, discard);
    while (getline(players_file, line)) {
        stringstream ss(line);
        string id_;
        getline(ss, id_, ',');
        string name_;
        getline(ss, name_, ',');
        getline(ss, info, ',');
        int shot_distance = stoi(info);
        getline(ss, info, ',');
        int defender_distance = stoi(info);
        getline(ss, info, ',');
        int shot_result = stoi(info);
        getline(ss, info, ',');
        int close_range = stoi(info);
        getline(ss, info, ',');
        int mid_range = stoi(info);
        getline(ss, info, ',');
        int long_range = stoi(info);
        getline(ss, info, ',');
        int three_ = stoi(info);
        getline(ss, info, ',');
        int bad_def = stoi(info);
        getline(ss, info, ',');
        int moderate_def = stoi(info);
        getline(ss, info);
        int good_def = stoi(info);
        // sets variable values based on the information in the data
        if (shot_result == 1) {
            made = true;
        }
        else {
            made = false;
        }
        if (good_def == 1) {
            defense = "good";
        }
        else if (moderate_def == 1) {
            defense = "moderate";
        }
        else if (bad_def == 1) {
            defense = "bad";
        }
        if (close_range == 1) {
            type = "close";
        }
        else if (mid_range == 1) {
            type = "mid";
        }
        else if (long_range == 1) {
            type = "long";
        }
        if (three_ == 1) {
            three = true;
        }
        else {
            three = false;
        }
        auto it = player_names.find(name_);
        if (it == player_names.end()) {
            // if a player is not in the players vector yet, add them to it
            if (iteration > 0) {
                current_player->initializeStats();
                nba.players.push_back(current_player);
            }
            player_names.insert(name_);
            current_player = new Player(name_);
            iteration += 1;

        }
        // initializes a new Shot object based on the information about the shot in the data
        current_shot = new Shot(made, type, defense, defender_distance, shot_distance, three);
        current_player->players_shots.push_back(current_shot);
    }


};
