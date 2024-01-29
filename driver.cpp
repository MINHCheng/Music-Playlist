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
        string command;
        cin >> command;
        if (command == "done")
        {
            myPlaylist.~Playlist();
            return 0;
        }
        else if (command == "m"&&is_m)
        {
            int size;
            cin >> ws;
            cin >> size;
            cout << (myPlaylist.make(size));
            is_m = false;
        }
        else if (command == "i")
        {
            string t_a;
            getline(cin,t_a);
            cout << myPlaylist.add(t_a);
        }
        else if (command == "p")
        {
            int position;
            cin >> ws;
            cin >> position;
            cout<<myPlaylist.play(position)<<endl;
        }
        else if (command == "e")
        {
            int position;
            cin >> ws;
            cin >> position;
            cout<<myPlaylist.remove(position)<<endl;
        }
        else
        {
            cout<<"men\t";
            // throw std::invalid_argument("please input a proper command");
        }
    }
    myPlaylist.~Playlist();
}
