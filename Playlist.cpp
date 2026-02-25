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
    this->lstSong.clear();
    this->currentIndex = 0;
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
    if (this->currentIndex <= 0) {
        this->currentIndex = this->size() - 1;
    } else {
        this->currentIndex--;
    }
    return this->getSong(this->currentIndex);
}

// =======================
// Score-related
// =======================
int Playlist::getTotalScore() {
    // TODO: Student implementation

    int n = this->size();
    if (n == 0) return 0;

    long long* h = new long long[n + 1];
    long long* S = new long long[n + 1]; 
    long long* SS = new long long[n + 2]; 
    S[0] = 0;
    SS[0] = 0;
    BotkifyLinkedList<Song*>::Node* curr = this->lstSong.head->next;
    for (int i = 0; i < n; i++) {
        h[i] = curr->data->getScore();
        S[i + 1] = S[i] + h[i];
        curr = curr->next;
    }
    for (int i = 0; i <= n; i++) {
        SS[i + 1] = SS[i] + S[i];
    }

    int* L = new int[n];
    int* R = new int[n];
    int* st = new int[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top >= 0 && h[st[top]] >= h[i]) top--;
        L[i] = (top == -1) ? -1 : st[top];
        st[++top] = i;
    }

    top = -1;
    for (int i = n - 1; i >= 0; i--) {
        while (top >= 0 && h[st[top]] > h[i]) top--;
        R[i] = (top == -1) ? n : st[top];
        st[++top] = i;
    }

    long long totalResult = 0;
    for (int i = 0; i < n; i++) {
        long long left_count = i - L[i];
        long long right_count = R[i] - i;
        
        long long sum_term = left_count * (SS[R[i] + 1] - SS[i + 1]) 
                           - right_count * (SS[i + 1] - SS[L[i] + 1]);
        
        totalResult += h[i] * sum_term;
    }

    delete[] h; delete[] S; delete[] SS;
    delete[] L; delete[] R; delete[] st;

    return (int)totalResult;
}

bool Playlist::compareTo(Playlist p, int numSong)
{
    // TODO: Student implementation
    auto getAvgMax = [](Playlist& pl, int k) -> double {
        int n = pl.size();
        if (n < k || k <= 0) return 0.0;

        // Trích xuất scores ra mảng để truy cập O(1)
        int* scores = new int[n];
        BotkifyLinkedList<Song*>::Node* curr = pl.lstSong.head->next;
        for (int i = 0; i < n && curr; i++) {
            scores[i] = curr->data->getScore();
            curr = curr->next;
        }

        int* dq = new int[n]; 
        int head = 0, tail = -1;
        double sumMax = 0;

        for (int i = 0; i < n; i++) {
            if (head <= tail && dq[head] <= i - k) head++;
            while (head <= tail && scores[dq[tail]] <= scores[i]) tail--;
            dq[++tail] = i;
            if (i >= k - 1) sumMax += scores[dq[head]];
        }

        delete[] scores; delete[] dq;
        return sumMax / (n - k + 1);
    };
    return getAvgMax(*this, numSong) >= getAvgMax(p, numSong);
}

// =======================
// Advanced playing modes
// =======================

string Playlist::playRandomResult(int index)
{
    if (index < 0 || index >= this->size()) return "";
    stringstream ss;
    Song* curr = this->getSong(index);
    ss << curr->toString();
    for (int i = index + 1; i < this->size(); i++) {
        Song* nextS = this->getSong(i);
        if (nextS->getDuration() < curr->getDuration()) {
            ss << "," << nextS->toString();
            curr = nextS;
        }
    }
    return ss.str();
}

void Playlist::playRandom(int index)
{
    cout << this->playRandomResult(index) << endl;
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
