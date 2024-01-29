// define your classes here.
#include <iostream>
#include <string>
using namespace std;

class Songs;
class Playlist
{
private:
    /* data */

    int size;
    int numOfsongs;
    class Songs
    {
    public:
        string name;
        string artist;
        Songs();
        Songs(string t_a);
        bool operator==(Songs current) const;
        void reset();
    };
    Songs *arr;

public:
    Playlist();
    string add(string t_a);
    string make(int size);
    Songs *getSongs();
    string play(int position);
    string remove(int position);
    ~Playlist();
};
