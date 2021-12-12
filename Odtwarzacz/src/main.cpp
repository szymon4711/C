#include "../include/Music.h"

using namespace std;

int main() {
    Music odtwarzacz;
    odtwarzacz.addSong("Piosenka_1");
    odtwarzacz.addSong("Piosenka_2");
    odtwarzacz.addSong("Piosenka_3");
    odtwarzacz.addSong("Piosenka_4");
    odtwarzacz.addSong("Piosenka_5");

    odtwarzacz.deleteSong();
    odtwarzacz.previousSong();
    odtwarzacz.nextSong();
    odtwarzacz.showSongs();
}
