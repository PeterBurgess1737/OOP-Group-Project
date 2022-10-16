#ifndef OOP_GROUP_PROJECT_SCOREBOARD_H
#define OOP_GROUP_PROJECT_SCOREBOARD_H

#include <vector>
#include <string>

using namespace std;

class ScoreBoard
{
private:
    // A list of all the scores
    vector<int> all_scores;

    // The last score added to all scores
    // Is -1 when undefined
    // Assumes all scores are positive
    int last_score = -1;

    // The high score, I don't think this comment is necessary
    // Is -1 when there is no high score
    int high_score = -1;

public:
    void addScore(int score);

    int getLastScore() const;

    int getHighScore() const;

    int getNumberOfScores() const;

    bool saveToFile(const string &filename);

    bool readFromFile(const string &filename);

    void clearScoreBoard();

    vector<int> getLastNScores(int n) const;
};

#endif // OOP_GROUP_PROJECT_SCOREBOARD_H
