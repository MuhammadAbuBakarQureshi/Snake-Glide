#include <iostream>
#include <fstream>

using namespace std;

string file_address = "High Score/High-Score.txt";

void writeFile(int score)
{

    fstream file_write(file_address, ios::out);

    if (file_write.is_open())
    {

        file_write << score;

        file_write.close();
    }
}

int readFile()
{

    fstream file_read(file_address, ios::in);

    int score = 0;

    if (file_read.is_open())
    {

        file_read >> score;

        file_read.close();
    }
    else
    {

        cout << "File created" << endl;
        fstream create_file(file_address, ios::out);
        create_file.close();
        writeFile(score);
    }

    return score;
}

void setHighScore(int score)
{

    if (score > readFile())
    {

        writeFile(score);
    }
}

int getHighScore()
{
    return readFile();
}
