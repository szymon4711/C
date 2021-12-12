//
// Created by szymo on 12.12.2021.
//

#ifndef ODTWARZACZ_MUSIC_H
#define ODTWARZACZ_MUSIC_H


#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

class Music
{
    int tmp = 0;
    list<string> lista;
    list<string>::iterator x;

public:
    void addSong(string tytul);

    void deleteSong();

    void nextSong();

    void previousSong();

    void showSongs();
};

#endif //ODTWARZACZ_MUSIC_H
