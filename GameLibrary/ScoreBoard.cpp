#include "ScoreBoard.h"

#include <fstream>
using std::endl;
using std::ifstream; // Read from files
using std::ofstream; // Write to files

#include <string>
using std::getline;

/*
 * Add a score
 */
void ScoreBoard::addScore(int score)
{
    all_scores.push_back(score);
    last_score = score;

    if (score > high_score)
        high_score = score;
}

/*
 * Get the last added score
 */
int ScoreBoard::getLastScore() const
{
    return last_score;
}

/*
 * Get the current high score
 */
int ScoreBoard::getHighScore() const
{
    return high_score;
}

/*
 * Get the total number of scores currently stored
 */
int ScoreBoard::getNumberOfScores() const
{
    return (int)all_scores.size();
}

/*
 * Saves all scores to the given filename.
 * Filename does not include the file type, e.g. ".txt".
 */
bool ScoreBoard::saveToFile(const string &filename)
{
    // Open the file
    ofstream save_file;
    save_file.open(filename + ".savefile");

    // If opening failed
    if (!save_file.is_open())
        return false;

    // If opening succeeded

    // Write every score to the file
    for (int i = 0; i < all_scores.size(); i++)
    {
        save_file << all_scores[i];
        if (i != all_scores.size() - 1)
        {
            save_file << endl;
        }
    }

    // Close the file
    save_file.close();

    // Return true because I think everything worked
    return true;
}

/*
 * Reads all scores from a savefile.
 * Calling this removes any scores that are currently stored
 * Filename does not include the file type, e.g. ".txt".
 */
bool ScoreBoard::readFromFile(const string &filename)
{
    // Clear the scoreboard
    clearScoreBoard();

    // Open the file
    ifstream save_file;
    save_file.open(filename + ".savefile");

    // If opening failed
    if (!save_file.is_open())
        return false;

    // If opening succeeded

    // Where the current reading score is stored
    int score;
    // While not at the end of the file
    while (save_file.peek() != EOF)
    {
        // Grab the score
        save_file >> score;

        // Add the score
        addScore(score);
    }

    // Return true because I think everything worked
    return true;
}

/*
 * Clears all entries from the scoreboard
 */
void ScoreBoard::clearScoreBoard()
{
    // Reset scores vector
    all_scores.clear();

    // Reset high score and last score
    high_score = -1;
    last_score = -1;
}

/*
 * If n is more than the amount of saved scores then all saved scores will be returned.
 */
vector<int> ScoreBoard::getLastNScores(int n) const
{
    // Making sure n is a valid number
    if (n > all_scores.size())
        n = (int)all_scores.size();

    // Get the last n scores
    vector<int> last_n_scores(all_scores.end() - n, all_scores.end());

    return last_n_scores;
}
