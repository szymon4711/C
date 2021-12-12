//
// Created by szymo on 12.12.2021.
//
#include "../include/Music.h"

void Music::addSong(string tytul) {
    lista.push_back(tytul);
}

void Music::deleteSong() {
    lista.pop_front();
}


void Music::previousSong() {
    x = lista.end();
    x--;
    cout << "Poprzednia:" << (*x) << endl;
}

void Music::nextSong()
{
    x = lista.begin();
    x++;
    cout << "Nastepna:" << (*x) << endl;
}

void Music::showSongs() {
    for (x = lista.begin(); x != lista.end(); ++x, ++tmp) {
        cout << "[" << tmp + 1 << "] - " << (*x) << endl;
    }
    tmp = 0;
}