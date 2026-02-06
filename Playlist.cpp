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
    this->currentIndex = -1;
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
    this->lstSong.clear();
    this->currentIndex = -1;
}

void Playlist::addSong(Song* s)
{
    // TODO: Student implementation
    this->lstSong.add(s);
}

void Playlist::removeSong(int index)
{
    // TODO: Student implementation
    this->checkIndex(index);
    this->lstSong.removeAt(index);
    if (this->empty()) this->currentIndex = -1;
    else if (index <= this->currentIndex) {
        this->currentIndex--;
        if (this->currentIndex < 0) this->currentIndex = 0;
    }
}

Song* Playlist::getSong(int index) const
{
    // TODO: Student implementation
    if (index < 0 || index >= this->size()) {
        throw out_of_range("Index is invalid!");
    }

    return this->lstSong.get(index);
}

// =======================
// Playing control
// =======================

Song* Playlist::playNext()
{
    // TODO: Student implementation
    if (this->empty()) throw out_of_range("Index is invalid!");
    this->currentIndex = (this->currentIndex + 1) % this->size();
    return this->getSong(this->currentIndex);
}

Song* Playlist::playPrevious()
{
    // TODO: Student implementation
    if (this->empty()) throw out_of_range("Index is invalid!");
    if (this->currentIndex <= 0) this->currentIndex = this->size() - 1;
    this->currentIndex = this->currentIndex--;
    return this->getSong(this->currentIndex);
}

// =======================
// Score-related
// =======================

int Playlist::getTotalScore()
{
    // TODO: Student implementation
    int n = this->size();
    if (n == 0) return 0;
    long long* scores = new long long[n];
    long long* S = new long long[n + 1]; S[0] = 0;

    BotkifyLinkedList<Song*>::Node* curr = this->lstSong.head->next;
    for (int i = 0; i < n && curr; i++) {
        scores[i] = curr->data->getScore();
        S[i+1] = S[i] + scores[i];
        curr = curr->next;
    }

    long long* PSS = new long long[n + 1]; PSS[0] = 0;
    for (int i = 0; i < n; i++) PSS[i+1] = PSS[i] + S[i+1];

    int* L = new int[n]; int* R = new int[n]; int* st = new int[n]; int top = -1;
    for (int i = 0; i < n; i++) {
        while (top >= 0 && scores[st[top]] >= scores[i]) top--;
        L[i] = (top == -1) ? -1 : st[top]; st[++top] = i;
    }
    top = -1;
    for (int i = n - 1; i >= 0; i--) {
        while (top >= 0 && scores[st[top]] > scores[i]) top--;
        R[i] = (top == -1) ? n : st[top]; st[++top] = i;
    }

    long long total = 0;
    for (int k = 0; k < n; k++) {
        long long sumS_R = PSS[R[k]] - PSS[k];
        long long sumS_L = (L[k] == -1) ? PSS[k] : (PSS[k] - PSS[L[k]]);
        total += scores[k] * ((k - L[k]) * sumS_R - (R[k] - k) * sumS_L);
    }

    delete[] scores; delete[] S; delete[] PSS; delete[] L; delete[] R; delete[] st;
    return (int)total;
}

bool Playlist::compareTo(Playlist p, int numSong)
{
    // TODO: Student implementation
    auto calcAvg = [&](Playlist& pl) {
        int n = pl.size();
        if (n < numSong) return 0.0;
        double totalMax = 0;
        int count = n - numSong + 1;
        for (int i = 0; i < count; i++) {
            int maxS = 0;
            for (int j = 0; j < numSong; j++) 
                maxS = max(maxS, pl.getSong(i + j)->getScore());
            totalMax += maxS;
        }
        return totalMax / count; 
    };
    return calcAvg(*this) >= calcAvg(p);
}

// =======================
// Advanced playing modes
// =======================

void Playlist::playRandom(int index)
{
    if (index < 0 || index >= this->size()) return;
    Song* curr = this->getSong(index);
    cout << curr->toString();
    for (int i = index + 1; i < this->size(); i++) {
        Song* nextS = this->getSong(i);
        if (nextS->getDuration() > curr->getDuration()) {
            cout << "," << nextS->toString();
            curr = nextS;
        }
    }
    cout << endl;
}

int Playlist::playApproximate(int step)
{
    // TODO: Student implementation
    int n = this->size();
    if (n < 2) return 0;
    int* dp = new int[n];
    for (int i = 0; i < n; i++) dp[i] = 1e9;
    dp[0] = 0; 
    for (int i = 0; i < n; i++) {
        for (int s = 1; s <= step + 1 && i + s < n; s++) {
            int diff = abs(this->getSong(i)->getDuration() - this->getSong(i+s)->getDuration());
            dp[i+s] = min(dp[i+s], dp[i] + diff); 
        }
    }
    int res = dp[n-1];
    delete[] dp;
    return res;
}

// HELPER FUNCTION 

void Playlist::checkIndex(int index) 
{
    if (index < 0 || index >= this->size() || this->empty()) {
        throw out_of_range("Index is invalid!");
    }
}
