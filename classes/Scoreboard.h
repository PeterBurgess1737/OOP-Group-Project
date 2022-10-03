#ifndef OOP_GROUP_PROJECT_SCOREBOARD_H
#define OOP_GROUP_PROJECT_SCOREBOARD_H

#include <string>
using std::string;

class Scoreboard {
public:
    unsigned int highScore;
    unsigned int currentScore;

    void adjustScore(unsigned int adjustment);

    void resetScore();

    bool saveScoreToFile(string fileName);
};


#endif //OOP_GROUP_PROJECT_SCOREBOARD_H
