#include "Playlist.h"

// =======================
// Song implementation
// =======================

Song::Song(int id,
           string title,
           string artist,
           string album,
           int duration,
           int score,
           string url)
{
    // TODO: Student implementation
    this->id = id;
    this-> title = title;
    this->artist = artist;
    this->album = album;
    this->duration = duration;
    this->score = score;
    this->url = url;
}

int Song::getID() const
{
    // TODO: Student implementation
    return this->id;
}

int Song::getDuration() const
{
    // TODO: Student implementation
    return this->duration;
}

int Song::getScore() const
{
    // TODO: Student implementation
    return this->score;
}

string Song::toString() const
{
    // TODO: Student implementation
    return this->title + "-" + this->artist;
}

// =======================
// Playlist implementation
// =======================

Playlist::Playlist(string name)
{
    // TODO: Student implementation
    this->name = name;
    this->currentIndex = 0;
}

int Playlist::size() const
{
    // TODO: Student implementation
    return this->lstSong.size();
}

bool Playlist::empty() const
{
    // TODO: Student implementation
    return this->lstSong.empty();
}

void Playlist::clear()
{
    // TODO: Student implementation
    this->lstSong.empty();
}

void Playlist::addSong(Song* s)
{
    // TODO: Student implementation
    this->lstSong.add(s);
}

void Playlist::removeSong(int index)
{
    // TODO: Student implementation
    this->lstSong.removeAt(index);
}

Song* Playlist::getSong(int index) const
{
    // TODO: Student implementation
    return this->lstSong.get(index);
}

// =======================
// Playing control
// =======================

Song* Playlist::playNext()
{
    // TODO: Student implementation
    
    return nullptr;
}

Song* Playlist::playPrevious()
{
    // TODO: Student implementation
    return nullptr;
}

// =======================
// Score-related
// =======================

int Playlist::getTotalScore()
{
    // TODO: Student implementation
    return 0;
}

bool Playlist::compareTo(Playlist p, int numSong)
{
    // TODO: Student implementation
    return false;
}

// =======================
// Advanced playing modes
// =======================

void Playlist::playRandom(int index)
{
    // TODO: Student implementation
}

int Playlist::playApproximate(int step)
{
    // TODO: Student implementation
    return 0;
}
