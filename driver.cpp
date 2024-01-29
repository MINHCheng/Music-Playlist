// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include "playlist.h"

int main()
{
    Playlist myPlaylist;
    bool is_m = true;
    while (true)
    {
        // i/p command from user which is either m,i,p,e and done
        string command;
        cin >> command;

        // if done exits the code by returning
        if (command == "done")
        {
            myPlaylist.~Playlist();
            return 0;
        }

        // if cmd = m, ask for a size and calls a function to createplaylist, make
        else if (command == "m"&&is_m)
        {
            int size;
            cin >> ws;
            cin >> size;
            cout << (myPlaylist.make(size));
            is_m = false; //if m is called, changes is_m to false so it cant be called again
        }

        // if cmd = i, ask for a string and calls function to add a song to playlist
        else if (command == "i")
        {
            string t_a;
            getline(cin,t_a); //method to spaces within artist and song names
            cout << myPlaylist.add(t_a);
        }

        // if cmd = p, ask for a position to play and calls play
        else if (command == "p")
        {
            int position;
            cin >> ws;
            cin >> position;
            cout<<myPlaylist.play(position)<<endl;
        }

        // if cmd is e, ask for a position to erase then calls remove function
        else if (command == "e")
        {
            int position;
            cin >> ws;
            cin >> position;
            cout<<myPlaylist.remove(position)<<endl;
        }
    }
}
