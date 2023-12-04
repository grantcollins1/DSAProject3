#include <iostream>
using namespace std;
#ifndef DSAPROJECT3_SHOT_H
#define DSAPROJECT3_SHOT_H
class Shot {
public:
    string type;
    string defense;
    int defender_distance;
    int shot_distance;
    bool three;
    bool made;
    Shot();
    Shot(bool made, string type, string defense, int defender_distance, int shot_distance, bool three);
};
Shot::Shot(bool made_, string type_, string defense_, int defender_distance_, int shot_distance_, bool three_) {
    //initializes each shot with the proper variable values based on the data
    made = made_;
    type = type_;
    defense = defense_;
    defender_distance = defender_distance_;
    shot_distance = shot_distance_;
    three = three_;
}
#endif //DSAPROJECT3_SHOT_H
