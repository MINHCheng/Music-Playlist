#include "playlist.h"
#include <iostream>
#include <string>
using namespace std;
// implement classes' member functions here...

////////////////////        Playlist           //////////////////////

// default constructor to set all variables to default values
Playlist::Playlist()
{
    this->size = 0;
    this->numOfsongs = 0;
    this->arr = nullptr;
}

// if method is called, creates of playlist of size m
string Playlist::make(int size)
{
    this->size = size;           // obtains size which is arr.length
    this->arr = new Songs[size]; // dynamically allocates array so it can update array during run time...allows to update as program progresses
    return "success\n";
}

// a method that first sees if new song meets conditions and if it does it creates new song, else it rejects and says no
string Playlist::add(string t_a)
{
    Songs newSong(t_a);
    // cannot equal Baby by Justin Beiber, MY Heart, and if the number of songs is equal to size then there is no space
    if ((newSong.name == " Baby" && newSong.artist=="Justin Bieber")|| (newSong.name == " My Heart Will Go On") || (this->numOfsongs == this->size))
    {

        return "can not insert" + t_a + "\n";
    } 

    // loops through all songs in array to see if it already added to the playlist
    for (unsigned int i = 0; i < this->size; i++)
    {
        if (*(this->arr + i) == newSong) // obtaining song within the array using pointer syntax and check if it is equal to the current song
        {
            return "can not insert" + t_a + "\n";
        }
    }
    arr[this->numOfsongs++] = newSong; // if clears all condition then adds the new song
    return "success\n";
}

// method to check if song is able to be played and if it is able to, it plays it; else it return cant play
string Playlist::play(int position)
{
    if (position >= this->numOfsongs) // if requested song is out of array size then rejects
    {
        return ("can not play " + to_string(position));
    }
    else
    {
        return ("played " + to_string(position) + "" + arr[position].name + ";" + arr[position].artist); // plays the song
    }
}

// method to remove a song if it exist and shift everything up/down; else return a statement that says it can't
string Playlist::remove(int position)
{
    if (numOfsongs <= position) // if the position is greater or not in the domain of array size
    {
        return "can not erase " + to_string(position);
    }
    else
    {
        int count = position + 1;            // takes position of the song that is above, so that it can be shifted down
        while (count < ((this->numOfsongs))) // a conidtional to check if the counter is greater than the number of songs if not then loop
        {
            arr[position++] = arr[count++]; // sets current array to the one above then increments both position and count after this lone executes
        }
        if (this->numOfsongs > 0)
        {
            arr[(this->numOfsongs) - 1].reset(); // resets the previous position of the top of the stack to default values
        }
        --(this->numOfsongs); // decrements teh amount of songs in playlist
    }
    return "success";
}

// deallocates pointer array arr
Playlist::~Playlist()
{
    delete[] this->arr;
    this->arr = nullptr;
}

////////////////////        Playlist           //////////////////////

////////////////////              Songs              /////////////////////////////////

// creates defualt contructor of default values
Playlist::Songs::Songs() {}

// tkaes a string with a ; in it and creates a song and artist with it
Playlist::Songs::Songs(string t_a)
{
    string substring[2]; // variable to store the artist and song name when string is split
    string tempstrng;    // temp string to hold the split string
    int count = 0;

    for (char ch : t_a) // looping through every char in the string
    {
        if (ch == ';')
        {
            substring[count++] = tempstrng; // if ';' is seen then assign the array the value seen then increments count so it can set the next value of array
            tempstrng.clear();              // clears the temp string to create a new one oncse it sees a ';'
        }
        else
        {
            tempstrng += ch;
        }
    }
    substring[count++] = tempstrng; //obtain the name of the song
    this->name = substring[0];
    this->artist = substring[1];
}

// a method to compare songs for add to see if song already exist
bool Playlist::Songs::operator==(Songs current) const
{
    if (this->artist == current.artist && this->name == current.name) //check if arist AND name are the same for both operands
    {
        return true;
    }
    return false;
}

// a method to set song to default values for the method of erase to reset last value in number of songs
void Playlist::Songs::reset()
{
    this->artist = "";
    this->name = "";
}

////////////////////              Songs              /////////////////////////////////