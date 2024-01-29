// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include "playlist.h"

int main()
{
    Playlist myPlaylist;
    while (true)
    {
        string command;
        cin >> command;
        if (command == "done")
        {
            myPlaylist.~Playlist();
            return 0;
        }
        else if (command == "m")
        {
            int size;
            cin >> ws;
            cin >> size;
            cout << (myPlaylist.make(size));
        }
        else if (command == "i")
        {
            string t_a;
            getline(cin, t_a);
            cout << myPlaylist.add(t_a);
        }
        else if (command == "p")
        {
            int position;
            cin >> ws;
            cin >> position;
            myPlaylist.play(position);
        }
        else if (command == "e")
        {
            int position;
            cin >> ws;
            cin >> position;
            myPlaylist.remove(position);
        }
        else
        {
            throw std::invalid_argument("please input a proper command");
        }
    }
}
