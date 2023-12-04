#include <iostream>
#include "shot.h"
using namespace std;
#ifndef DSAPROJECT3_PLAYER_H
#define DSAPROJECT3_PLAYER_H
// Player class to store shot data of each player
class Player {
private:
    float total_shots;
    float shots_made;

    void findPercentage();
    void findThreePtPercentage();
    void findAvgShotDistance();
    void findGoodDefense();
    void findModerateDefense();
    void findBadDefense();
    void findCloseRange();
    void findMidRange();
    void findLongRange();

public:
    string name;
    float shot_percentage;
    float three_point_percentage;
    float avgMadeShotDistance;
    float goodDefense, moderateDefense, badDefense;
    float closeRange, midRange, longRange;

    float current_stat;


    void initializeStats();
    Player();
    ~Player();
    vector<Shot*> players_shots;
    Player(string name);

    void ShowRow();
    float getPercentage();
    float getThreePtPercentage();
    float getAvgShotDistance();
    float getGoodDefense();
    float getModerateDefense();
    float getBadDefense();
    float getCloseRange();
    float getMidRange();
    float getLongRange();
    float getShotsMade();
    float getTotalShots();
    void SetCurrentStat(string request);

};

// Constructor
Player::Player(string names) {
    name = names;
    total_shots = 0;
}

void Player::initializeStats() {
    // Public function called to initialize all statistics of the player
    total_shots = players_shots.size();
    findPercentage();
    findThreePtPercentage();
    findAvgShotDistance();
    findGoodDefense();
    findBadDefense();
    findModerateDefense();
    findCloseRange();
    findMidRange();
    findLongRange();
}

void Player::SetCurrentStat(string request) {
    //sets the current stat to whatever stat the user wants to sort the players based on
    if (request == "three_percentage") {
        current_stat = three_point_percentage;
    }
    else if (request == "shot_percentage") {
        current_stat = shot_percentage;
    }
    else if (request == "avg_made_shot_dist") {
        current_stat = avgMadeShotDistance;
    }
    else if (request == "good_defense") {
        current_stat = goodDefense;
    }
    else if (request == "moderate_defense") {
        current_stat = moderateDefense;
    }
    else if (request == "bad_defense") {
        current_stat = badDefense;
    }
    else if (request == "close_range") {
        current_stat = closeRange;
    }
    else if (request == "mid_range") {
        current_stat = midRange;
    }
    else if (request == "long_range") {
        current_stat = longRange;
    }
    else if (request == "total_shots") {
        current_stat = total_shots;
    }
    else if (request == "shots_made") {
        current_stat = shots_made;
    }
}

// Find total shooting percentage
void Player::findPercentage(){
    shots_made = 0;
    total_shots = players_shots.size();
    for (int i = 0; i < total_shots; i++) {
        if (!players_shots.at(i)->made) {
            shots_made+=1;
        }
    }
    shot_percentage = ((float)shots_made/(float)total_shots) * 100.0;
}

// Find three point percentage
void Player::findThreePtPercentage(){
    int made_shots = 0;
    int counter = 0;
    for (int i = 0; i < total_shots; i++){
        if(players_shots.at(i)->three) {
            if (players_shots.at(i)->made) {
                made_shots += 1;
            }
            counter += 1;
        }
    }
    if (counter < 10) {
        three_point_percentage = 0.00;
    }
    else {
        three_point_percentage = (float(made_shots) / float(counter)) * 100;
    }
}


//  Find average shot distance
void Player::findAvgShotDistance(){
    float totalDistance = 0.0;
    for(int i = 0; i<total_shots; i++){
        if(players_shots.at(i)->made){
            totalDistance += players_shots.at(i)->shot_distance;
        }
    }
    avgMadeShotDistance = totalDistance / total_shots;
};


//Find well defended shooting percentage
void Player::findGoodDefense() {
    int made_shots = 0;
    int counter = 0;
    for (int i = 0; i < total_shots; i++){
        if(players_shots.at(i)->defense == "good" && players_shots.at(i)->made)
            made_shots += 1;
        counter += 1;
    }
    goodDefense = (float(made_shots)/float(counter)) * 100;
}



// find moderately defended shooting percentage
void Player::findModerateDefense() {
    int made_shots = 0;
    int counter = 0;
    for (int i = 0; i < total_shots; i++){
        if(players_shots.at(i)->defense == "moderate"){
            if(players_shots.at(i)->made)
                made_shots+=1;
            counter += 1;
        }

    }
    moderateDefense = (float(made_shots)/float(counter)) * 100;
}

// Find Poorly defended shooting percentage
void Player::findBadDefense() {
    int made_shots = 0;
    int counter = 0;
    for (int i = 0; i < total_shots; i++){
        if(players_shots.at(i)->defense == "bad"){
            if(players_shots.at(i)->made)
                made_shots += 1;
            counter += 1;
        }

    }
    badDefense = (float(made_shots)/float(counter)) * 100;
}



// Find Close Range Shooting Percentage
void Player::findCloseRange() {
    int made_shots = 0;
    int counter = 0;
    for (int i = 0; i < total_shots; i++){
        if(players_shots.at(i)->type == "close"){
            if(players_shots.at(i)->made)
                made_shots += 1;
            counter += 1;
        }

    }
    closeRange = (float(made_shots)/float(counter)) * 100;
}


// Find Mid range shooting percentage
void Player::findMidRange() {
    int made_shots = 0;
    int counter = 0;
    for (int i = 0; i < total_shots; i++){
        if(players_shots.at(i)->type == "mid") {
            if(players_shots.at(i)->made)
                made_shots += 1;
            counter += 1;
        }
    }
    midRange = (float(made_shots)/float(counter)) * 100;
}

//Find long range shooting percentage (Long + 3pt)
void Player::findLongRange() {
    int made_shots = 0;
    int counter = 0;
    for (int i = 0; i < total_shots; i++){
        if(players_shots.at(i)->type == "long" || players_shots.at(i)->three) {
            if (players_shots.at(i)->made)
                made_shots += 1;
            counter += 1;
        }
    }
    longRange = (float(made_shots)/float(counter)) * 100;
}


// Get functions to return values of all the statistics

float Player::getAvgShotDistance(){
    return avgMadeShotDistance;
}
float Player::getThreePtPercentage() {
    return three_point_percentage;
}
float Player::getCloseRange() {
    return closeRange;
}
float Player::getMidRange() {
    return midRange;
}
float Player::getLongRange() {
    return longRange;
}
float Player::getShotsMade(){
    return shots_made;
}
float Player::getBadDefense() {
    return badDefense;
}
float Player::getTotalShots(){
    return total_shots;
}
float Player::getPercentage() {
    return shot_percentage;
}
float Player::getModerateDefense() {
    return moderateDefense;
}
float Player::getGoodDefense() {
    return goodDefense;
}

Player::~Player() {
    for (int i = 0; i <players_shots.size(); i++) {
        delete players_shots.at(i);
    }
}


#endif //DSAPROJECT3_PLAYER_H
