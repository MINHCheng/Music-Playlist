#include "playlist.h"
#include <iostream>
#include <string>
using namespace std;
// implement classes' member functions here...


////////////////////        Playlist           //////////////////////


Playlist::Playlist()
{
    this->size = 0;
    this->numOfsongs = 0;
    this->arr = nullptr;
}

string Playlist::make(int size)
{
    this->size = size;
    this->arr = new Songs[size];
    return "success";
}

string Playlist::add(string t_a)
{
    Songs newSong(t_a);
    if (t_a == "Baby;Justin Beiber" || newSong.name == "My Heart Will Go On" || this->numOfsongs == this->size)
    {

        return "can not insert " + t_a;
    }
    for (unsigned int i = 0; i < this->size; i++)
    {
        if (*(this->arr + 1) == newSong)
        {
            return "can not insert " + t_a;
        }
        else
        {
            arr[this->numOfsongs++] = newSong;
            return "success";
        }
    }
    return "success";
}

string Playlist::play(int position)
{
    if(position >= this->size){
        return "can not play " + position;
    }
    else{
        return ("played " + to_string(position) + " " + arr[position].name + ";" + arr[position].artist);
    }
}

string Playlist::remove(int position){
    if(numOfsongs <= position){
        return "can not erase " + to_string(position);
    }
    else{
        int count = position;
        while(count<((this->numOfsongs)-1)){
            arr[count] = arr[++count];
        }
        arr[(this->numOfsongs)-1].reset();
    }
}

Playlist::~Playlist()
{
    delete this->arr;
    this->arr = nullptr;
}


////////////////////        Playlist           //////////////////////



////////////////////              Songs              /////////////////////////////////

Playlist::Songs::Songs() {}

Playlist::Songs::Songs(string t_a)
{
    string substring[2];
    string tempstrng;
    int count = 0;

    for (char ch : t_a)
    {
        if (ch == ';')
        {
            substring[count++] = tempstrng;
            tempstrng.clear();
        }
        else
        {
            tempstrng += ch;
        }
    }
    this->name = substring[0];
    this->artist = substring[1];
}

bool Playlist::Songs::operator==(Songs current) const
{
    if (this->artist == current.artist && this->name == current.name)
    {
        return true;
    }
    return false;
}

void Playlist::Songs::reset(){
    this->artist = "";
    this->name = "";
}


////////////////////              Songs              /////////////////////////////////