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
    this->songCache = nullptr;
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
    this->updateCache();
}

void Playlist::removeSong(int index)
{
    // TODO: Student implementation
    if (index < 0 || index >= this->size()) {
        throw out_of_range("Index is invalid!");
    }
    for (int i = 0; i < this->lstSong.size(); i++) {
        if (this->getSong(index)->getID() == index) {
            this->lstSong.removeAt(i);
        }

        if (index < this->currentIndex) {
            this->currentIndex--;
        }

        if (this->currentIndex >= this->lstSong.size() && !lstSong.empty()) {
            this->currentIndex = 0;
        }
    
        this->updateCache();
        return;
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
    this->currentIndex = (this->currentIndex + 1) % this->lstSong.size();
    return this->songCache[this->currentIndex];
}

Song* Playlist::playPrevious()
{
    // TODO: Student implementation
    if (this->empty()) throw out_of_range("Index is invalid!");
    this->currentIndex = (this->currentIndex - 1 + this->lstSong.size()) % this->lstSong.size(); 
    return this->songCache[this->currentIndex];
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
    double Avg1 = 0.0;
    double Avg2 = 0.0;
    int n1 = this->getSize();
    int n2 = p.getSize();

    if (n1 == 0 && n2 == 0) return true;
    if (n1 == 0) return false;
    if (n2 == 0) return true;

    int* list1 = new int [n1];
    int* list2 = new int [n2];
    
    int idx = 0;
    BotkifyLinkedList<Song*>::Node* curr1 = this->lstSong.head->next; // Giả sử head là dummy node
    while (curr1 != nullptr && idx < n1) {
        list1[idx++] = curr1->data->getScore();
        curr1 = curr1->next;
    }

    idx = 0;
    BotkifyLinkedList<Song*>::Node* curr2 = p.lstSong.head->next;
    while (curr2 != nullptr && idx < n2) {
        list2[idx++] = curr2->data->getScore();
        curr2 = curr2->next;
    }
    
    if (numSong >= n1) {
        int maxScore = -1e6;
        for (int i = 0; i < n1; ++i) maxScore = ((list1[i] > maxScore) ? list1[i] : maxScore);
        Avg1 += maxScore; 
    }

    if (numSong >= n2) {
        int maxScore = -1e6;
        for (int i = 0; i < n2; ++i) maxScore = ((list2[i] > maxScore) ? list2[i] : maxScore);
        Avg2 += maxScore;
    }

    if (numSong < n1) {
        int* left = new int[n1];
        int* right = new int [n1];

        for (int i = 0; i < n1; i++) {
            if (i % numSong == 0) left[i] = list1[i];
            else left[i] = (left[i-1] > list1[i]) ? left[i-1] : list1[i];
        }

        for (int i = n1 - 1; i >= 0; i--) {
            if (i == n1-1 || (i + 1) % numSong == 0) right[i] = list1[i];
            else right[i] = (right[i+1] > list1[i]) ? right[i+1] : list1[i];
        }

        int sum = 0;
        for (int i = 0; i + numSong - 1 < n1; i++) {
            sum += (right[i] > left[i+numSong-1]) ? right[i] : left[i+numSong-1];
        }
        Avg1 = sum / (n1 - numSong + 1);
        delete[] left;
        delete[] right;
    }

    if (numSong < n2) {
        int* left = new int[n2];
        int* right = new int [n2];

        for (int i = 0; i < n2; i++) {
            if (i % numSong == 0) left[i] = list2[i];
            else left[i] = (left[i-1] > list2[i]) ? left[i-1] : list2[i];
        }

        for (int i = n2 - 1; i >= 0; i--) {
            if (i == n2-1 || (i + 1) % numSong == 0) right[i] = list2[i];
            else right[i] = (right[i+1] > list2[i]) ? right[i+1] : list2[i];
        }

        int sum = 0;
        for (int i = 0; i + numSong - 1 < n2; i++) {
            sum += (right[i] > left[i+numSong-1]) ? right[i] : left[i+numSong-1];
        }
        Avg2 = sum / (n2 - numSong + 1);
        delete[] left;
        delete[] right;
    }

    delete[] list1;
    delete[] list2;
    
    return Avg1 >= Avg2;
}
// =======================
// Advanced playing modes
// =======================

string Playlist::playRandomResult(int index)
{
    int n = this->size();
    if (index < 0 || index >= this->size()) return "";
    stringstream ss;
    bool* visited = new bool[n];

    for (int i = 0; i < n; i++) visited[i] = false;

    Song* curr = this->getSong(index);
    ss << curr->toString();
    visited[index] = true;

    while (true) {
        int bestIdx = -1;
        int minDis = n + 1;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                Song* temp = this->getSong(i);

                if (temp->getDuration() > curr->getDuration()) {
                    int distance = abs(i - index);
                    if (distance < minDis) {
                        minDis = distance;
                        bestIdx = i;
                    } else if (distance == minDis) {
                        if (bestIdx == -1 || i < bestIdx) bestIdx = i;
                    }
                }
            }
        }

        if (bestIdx != -1) {
            curr = this->getSong(bestIdx);
            ss << "," << curr->toString();
            visited[bestIdx] = true;
        } else {
            break;
        }
    }

    delete[] visited;
    return ss.str();
}

void Playlist::playRandom(int index)
{
    cout << this->playRandomResult(index) << endl;
}

int Playlist::playApproximate(int step)
{
    int n = this->size();
    if (n <= 1) return 0;

    int* durations = new int[n];
    for (int i = 0; i < n; i++) {
        durations[i] = this->getSong(i)->getDuration();
    }

    const long long INF = 1e15;

    long long** dp = new long long*[n];
    for (int i = 0; i < n; i++) {
        dp[i] = new long long[step + 1];
        for (int s = 0; s <= step; s++) dp[i][s] = INF;
    }

    for (int s = 0; s <= step; s++) dp[0][s] = 0;

    for (int i = 1; i < n; i++) {
        for (int s = 0; s <= step; s++) {
            for (int j = 0; j < i; j++) {
                int skipped = i - j - 1; 
                if (s >= skipped && dp[j][s - skipped] != INF) {
                    long long diff = abs(durations[i] - durations[j]);
                    if (dp[j][s - skipped] + diff < dp[i][s]) {
                        dp[i][s] = dp[j][s - skipped] + diff;
                    }
                }
            }
        }
    }

    long long minTotalDiff = INF;
    for (int s = 0; s <= step; s++) {
        if (dp[n - 1][s] < minTotalDiff) {
            minTotalDiff = dp[n - 1][s];
        }
    }

    for (int i = 0; i < n; i++) delete[] dp[i];
    delete[] dp;
    delete[] durations;

    return (minTotalDiff == INF) ? 0 : (int)minTotalDiff;
}

// HELPER FUNCTION

void Playlist::updateCache() {
    if (this->songCache != nullptr) {
        delete[] this->songCache;
        this->songCache = nullptr;
    } 

    int n = this->lstSong.size();
    if (n == 0) return;

    this->songCache = new Song*[n];
    for (int i = 0; i < n; i++) {
        this->songCache[i] = this->lstSong.get(i);
    }
}