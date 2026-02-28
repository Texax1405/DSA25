#include "Helper.h"
#include "Playlist.h"
#include "BotkifyLinkedList.h"
#define NUM_TEST 100
using namespace std;

string PlayList01() {
    string name = "PlayList01";
    Playlist p("Test");
    p.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    // p.addSong(new Song(2, "C", "C", "C", 30, 3, ""));
    // p.addSong(new Song(3, "D", "D", "D", 90, 5, ""));
    // p.addSong(new Song(4, "E", "E", "E", 100, 0, ""));
    int len = p.getSize();

    stringstream output;
    stringstream expected;

    output << p.getSong(0) -> toString() << "\n";
    output << p.getSong(1) -> toString();

    expected << "A-Thien" << "\n";
    expected << "B-Thu";
    return printResult(name, output.str(), expected.str());
}

string PlayList02() {
    string name = "PlayList02";
    Playlist p("Test");
    p.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    p.removeSong(1);

    stringstream output;
    stringstream expected;
    try {
        output << p.getSong(1) -> toString(); 
    }
    catch (out_of_range &e) {
        output << e.what();
    }

    expected << "Index is invalid!";
    return printResult(name, output.str(), expected.str());
}

string PlayList03() {
    string name = "PlayList03";
    Playlist p("Test");
    p.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));

    stringstream output;
    stringstream expected;

    output << "List Size: " << p.getSize() << "\n";
    p.clear();
    output << "List after clear: " << p.getSize();

    expected << "List Size: 2" << "\n" << "List after clear: 0"; 

    return printResult(name, output.str(), expected.str());
}

string PlayList04() {
    string name = "PlayList04";
    Playlist p("Test");
    p.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));

    stringstream output;
    stringstream expected;

    try {
        p.removeSong(2);
    }
    catch (out_of_range &e) {
        output << e.what();
    }

    expected << "Index is invalid!";
    return printResult(name, output.str(), expected.str());
}

string PlayList05() {
    string name = "PlayList05";
    Playlist p("Test");
    p.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    p.addSong(new Song(1, "C", "DA", "B", 60, 1, ""));

    stringstream output;
    stringstream expected;

    int size = p.getSize();
    for (int i = 0; i < size; ++i) {
        output << p.getSong(i) -> toString() << "\n";
    }

    expected << "A-Thien" << "\n" << "B-Thu" << "\n" << "C-DA" << "\n";
    return printResult(name, output.str(), expected.str());
}

string PlayList06() {
    string name = "PlayList06";
    Playlist p("T");
    p.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    p.addSong(new Song(2, "C", "C", "C", 30, 3, ""));
    p.addSong(new Song(3, "D", "D", "D", 90, 5, ""));

    stringstream output;
    stringstream expected;

    output << p.getTotalScore();
    expected << "114";

    return printResult(name, output.str(), expected.str());
}

string PlayList07() {
    string name = "PlayList07";
    Playlist p1("T");
    Playlist p2("K");
    p1.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p1.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 30, 3, ""));
    p1.addSong(new Song(3, "D", "D", "D", 90, 5, ""));

    p2.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    p2.addSong(new Song(2, "C", "C", "C", 30, 2, ""));
    p2.addSong(new Song(3, "D", "D", "D", 90, 3, ""));

    stringstream output;
    stringstream expected;
    
    output << (((p1.compareTo(p2,2)) == true) ? "OK" : "NOT OK");
    expected << "OK";


    return printResult(name, output.str(), expected.str());
}



string PlayList08() {
    string name = "PlayList08";
    Playlist p("Test");
    p.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    p.addSong(new Song(1, "C", "DA", "B", 60, 1, ""));

    stringstream output;
    stringstream expected;

    int len = p.getSize();

    for (int i = 0; i < len; ++i) {
        output << p.playNext() -> toString() << "\n" ;
    }

    expected << "B-Thu" << "\n" << "C-DA" << "\n" << "A-Thien" << "\n" ;
    return printResult(name, output.str(), expected.str()); 
}

string PlayList09() {
    string name = "PlayList09";
    Playlist p("Test");
    p.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    p.addSong(new Song(1, "C", "DA", "B", 60, 1, ""));

    stringstream output;
    stringstream expected;

    int len = p.getSize();
    for (int i = 0; i < 4; ++i) {

        output << p.playPrevious() -> toString() << "\n";
    }

    expected << "A-Thien" << "\n" << "C-DA" << "\n" << "B-Thu" << "\n" << "A-Thien" << "\n";
    return printResult(name, output.str(), expected.str());
}

string PlayList10() {
    string name = "PlayList10";
    Playlist p1("T");
    p1.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p1.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 30, 3, ""));
    p1.addSong(new Song(3, "D", "D", "D", 90, 5, ""));
    p1.addSong(new Song(3, "D", "D", "D", 100, 5, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(1);
    expected << "50";

    return printResult(name, output.str(), expected.str());
}

string PlayList11() {
    string name = "PlayList11";
    Playlist p1("T");
    p1.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p1.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    stringstream output;
    stringstream expected;

    output << p1.getTotalScore();
    expected << "22";

    return printResult(name, output.str(), expected.str());
}

string PlayList12() {
    string name = "PlayList12";
    Playlist p1("T");
    p1.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p1.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 30, 3, ""));
    p1.addSong(new Song(3, "D", "D", "D", 90, 5, ""));
    p1.addSong(new Song(3, "D", "D", "D", 100, 5, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(2);
    expected << "50";

    return printResult(name, output.str(), expected.str());
}

string PlayList13() {
    string name = "PlayList13";
    Playlist p1("n");
    p1.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p1.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 30, 3, ""));
    p1.addSong(new Song(3, "D", "D", "D", 90, 5, ""));
    p1.addSong(new Song(3, "D", "D", "D", 100, 5, ""));
    p1.addSong(new Song(3, "D", "D", "D", 120, 5, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(3);
    expected << "70";
    
    return printResult(name, output.str(), expected.str());
}

string PlayList14() {
    string name = "PlayList14";
    Playlist p1("n");
    p1.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p1.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 30, 3, ""));
    p1.addSong(new Song(3, "D", "D", "D", 90, 5, ""));
    p1.addSong(new Song(3, "D", "D", "D", 100, 5, ""));
    p1.addSong(new Song(3, "D", "D", "D", 120, 5, ""));

    Playlist p2("k");
    stringstream output;
    stringstream expected;

    output << ((p1.compareTo(p2,2) == true) ? "ok" : "not ok");
    expected << "ok";
    
    return printResult(name, output.str(), expected.str());
}

string PlayList15() {
    string name = "PlayList15";
    Playlist p1("n");
    Playlist p2("k");

    stringstream output;
    stringstream expected;

    output << ((p1.compareTo(p2,2) == true) ? "ok" : "not ok");
    expected << "ok";
    
    return printResult(name, output.str(), expected.str());
}

string PlayList16() {
    string name = "PlayList16";

    Playlist p1("n");
    p1.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p1.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 30, 3, ""));
    p1.addSong(new Song(3, "D", "D", "D", 90, 5, ""));
    p1.addSong(new Song(3, "D", "D", "D", 100, 5, ""));
    p1.addSong(new Song(3, "D", "D", "D", 120, 5, ""));

    Playlist p2("k");

    stringstream output;
    stringstream expected;

    output << ((p2.compareTo(p1,2) == true) ? "ok" : "not ok");
    expected << "not ok";

    return printResult(name, output.str(), expected.str());
}

string PlayList17() {
    string name = "PlayList17";
    Playlist p("t");
    stringstream output;
    stringstream expected;

    output << p.getTotalScore();
    expected << "0";
    return printResult(name, output.str(), expected.str());
}

string PlayList18() {
    string name = "PlayList18";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p1.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 30, 3, ""));
    p1.addSong(new Song(3, "D", "D", "D", 90, 5, ""));
    p1.addSong(new Song(3, "D", "D", "D", 100, 5, ""));
    p1.addSong(new Song(3, "D", "D", "D", 120, 5, ""));

    stringstream output;
    stringstream expected;
    //Get the first song
    output << p1.getSong(0) -> toString() << "\n";
    p1.removeSong(1);
    output << p1.playNext() -> toString() << "\n";
    output << p1.playNext() -> toString();
    expected << "A-Thien" << "\n" << "C-C" << "\n" << "D-D";
    return printResult(name, output.str(), expected.str());
}

string PlayList19() {
    string name = "PlayList19";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p1.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 30, 3, ""));
    p1.addSong(new Song(3, "D", "D", "D", 90, 5, ""));
    p1.addSong(new Song(3, "D", "D", "D", 100, 5, ""));
    p1.addSong(new Song(3, "D", "D", "D", 120, 5, ""));
    
    p1.removeSong(0);
    stringstream output;
    stringstream expected;

    output << "The first song: " << p1.getSong(0) -> toString();
    expected << "The first song: B-Thu";

    return printResult(name, output.str(), expected.str());
}

string PlayList20() {
    string name = "PlayList20";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "Thien", "A", 50, 4, ""));
    p1.addSong(new Song(1, "B", "Thu", "B", 60, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 30, 3, ""));
    p1.addSong(new Song(3, "D", "D", "D", 90, 5, ""));
    p1.addSong(new Song(3, "D", "D", "D", 100, 5, ""));
    p1.addSong(new Song(3, "D", "D", "D", 120, 5, ""));
    
    stringstream output;
    stringstream expected;

    output << "The first song: " << p1.getSong(0) -> toString() << "\n";
    p1.removeSong(1);
    output << "The second song: " << p1.playNext() -> toString() << "\n";
    output << "The next song: " << p1.playNext() -> toString();
    expected << "The first song: A-Thien" << "\n" << "The second song: C-C" << "\n" << "The next song: D-D";

    return printResult(name, output.str(), expected.str());
}

string PlayList21() {
    string name = "PlayList21";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "Thien", "A", 70, 4, ""));
    p1.addSong(new Song(1, "B", "Thu", "B", 20, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 30, 3, ""));
    p1.addSong(new Song(3, "D", "D", "D", 50, 5, ""));
    
    
    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(2);
    expected << "C-C,D-D,A-Thien";
    return printResult(name, output.str(), expected.str());
}

string PlayList22() {
    string name = "PlayList22";

    Playlist p1("a");
    p1.addSong(new Song(0, "A", "Thien", "A", 40, 4, ""));
    p1.addSong(new Song(1, "B", "Thu", "B", 10, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 8, 3, ""));
    p1.addSong(new Song(3, "D", "D", "D", 50, 5, ""));
    p1.addSong(new Song(3, "E", "E", "E", 100, 5, ""));
    stringstream output;
    stringstream expected;
    
    output << p1.playRandomResult(1);
    expected << "B-Thu,A-Thien,D-D,E-E";

    return printResult(name, output.str(), expected.str());
}


string PlayList23() {
    string name = "PlayList23";

    Playlist p1("T");

    stringstream output;
    stringstream expected;

    output << p1.getTotalScore();
    expected << "0";

    return printResult(name, output.str(), expected.str());
}


string PlayList24() {
    string name = "PlayList24";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 5, ""));

    stringstream output;
    stringstream expected;

    output << p1.getTotalScore();
    expected << "25";

    return printResult(name, output.str(), expected.str());
}

string PlayList25() {
    string name = "PlayList25";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.getTotalScore();
    expected << "1";

    return printResult(name, output.str(), expected.str());
}

string PlayList26() {
    string name = "PlayList26";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 0, ""));

    stringstream output;
    stringstream expected;

    output << p1.getTotalScore();
    expected << "0";

    return printResult(name, output.str(), expected.str());
}

string PlayList27() {
    string name = "PlayList27";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 2, ""));
    p1.addSong(new Song(1, "B", "X", "B", 10, 3, ""));

    stringstream output;
    stringstream expected;

    // [2] = 4
    // [3] = 9
    // [2,3] min=2 sum=5 => 10
    // total = 4+9+10 = 23
    output << p1.getTotalScore();
    expected << "23";

    return printResult(name, output.str(), expected.str());
}

string PlayList28() {
    string name = "PlayList28";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 3, ""));
    p1.addSong(new Song(1, "B", "X", "B", 10, 2, ""));

    stringstream output;
    stringstream expected;

    // [3]=9
    // [2]=4
    // [3,2] min=2 sum=5 => 10
    // total=23
    output << p1.getTotalScore();
    expected << "23";

    return printResult(name, output.str(), expected.str());
}

string PlayList29() {
    string name = "PlayList29";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "X", "B", 10, 1, ""));

    stringstream output;
    stringstream expected;

    // [1]=1
    // [1]=1
    // [1,1] min=1 sum=2 => 2
    // total=4
    output << p1.getTotalScore();
    expected << "4";

    return printResult(name, output.str(), expected.str());
}

string PlayList30() {
    string name = "PlayList30";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 2, ""));
    p1.addSong(new Song(1, "B", "X", "B", 10, 2, ""));
    p1.addSong(new Song(2, "C", "X", "C", 10, 2, ""));

    stringstream output;
    stringstream expected;

    // length1: 4+4+4=12
    // length2: [2,2]=2*4=8, [2,2]=8 => 16
    // length3: [2,2,2]=2*6=12
    // total=12+16+12=40
    output << p1.getTotalScore();
    expected << "40";

    return printResult(name, output.str(), expected.str());
}

string PlayList31() {
    string name = "PlayList31";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "X", "B", 10, 2, ""));
    p1.addSong(new Song(2, "C", "X", "C", 10, 3, ""));

    stringstream output;
    stringstream expected;

    // [1]=1
    // [2]=4
    // [3]=9
    // [1,2] min=1 sum=3 => 3
    // [2,3] min=2 sum=5 => 10
    // [1,2,3] min=1 sum=6 => 6
    // total = 1+4+9+3+10+6=33
    output << p1.getTotalScore();
    expected << "33";

    return printResult(name, output.str(), expected.str());
}

string PlayList32() {
    string name = "PlayList32";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 3, ""));
    p1.addSong(new Song(1, "B", "X", "B", 10, 2, ""));
    p1.addSong(new Song(2, "C", "X", "C", 10, 1, ""));

    stringstream output;
    stringstream expected;

    // [3]=9
    // [2]=4
    // [1]=1
    // [3,2] min=2 sum=5 => 10
    // [2,1] min=1 sum=3 => 3
    // [3,2,1] min=1 sum=6 => 6
    // total=9+4+1+10+3+6=33
    output << p1.getTotalScore();
    expected << "33";

    return printResult(name, output.str(), expected.str());
}

string PlayList33() {
    string name = "PlayList33";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 4, ""));
    p1.addSong(new Song(1, "B", "X", "B", 10, 1, ""));
    p1.addSong(new Song(2, "C", "X", "C", 10, 3, ""));
    p1.addSong(new Song(3, "D", "X", "D", 10, 5, ""));

    stringstream output;
    stringstream expected;

    // ví dụ đề bài: tổng = 114
    output << p1.getTotalScore();
    expected << "114";

    return printResult(name, output.str(), expected.str());
}

string PlayList34() {
    string name = "PlayList34";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 5, ""));
    p1.addSong(new Song(1, "B", "X", "B", 10, 4, ""));
    p1.addSong(new Song(2, "C", "X", "C", 10, 3, ""));
    p1.addSong(new Song(3, "D", "X", "D", 10, 2, ""));
    p1.addSong(new Song(4, "E", "X", "E", 10, 1, ""));

    stringstream output;
    stringstream expected;

    // computed manually:
    // length1: 25+16+9+4+1=55
    // length2: 4*9=36, 3*7=21, 2*5=10, 1*3=3 => 70
    // length3: 3*12=36, 2*9=18, 1*6=6 => 60
    // length4: 2*14=28, 1*10=10 => 38
    // length5: 1*15=15
    // total = 55+70+60+38+15 = 238
    output << p1.getTotalScore();
    expected << "238";

    return printResult(name, output.str(), expected.str());
}

string PlayList35() {
    string name = "PlayList35";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "X", "B", 10, 2, ""));
    p1.addSong(new Song(2, "C", "X", "C", 10, 1, ""));

    stringstream output;
    stringstream expected;

    // [1]=1
    // [2]=4
    // [1]=1
    // [1,2] min=1 sum=3 => 3
    // [2,1] min=1 sum=3 => 3
    // [1,2,1] min=1 sum=4 => 4
    // total=1+4+1+3+3+4=16
    output << p1.getTotalScore();
    expected << "16";

    return printResult(name, output.str(), expected.str());
}

string PlayList36() {
    string name = "PlayList36";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 2, ""));
    p1.addSong(new Song(1, "B", "X", "B", 10, 1, ""));
    p1.addSong(new Song(2, "C", "X", "C", 10, 2, ""));

    stringstream output;
    stringstream expected;

    // [2]=4
    // [1]=1
    // [2]=4
    // [2,1] min=1 sum=3 => 3
    // [1,2] min=1 sum=3 => 3
    // [2,1,2] min=1 sum=5 => 5
    // total=4+1+4+3+3+5=20
    output << p1.getTotalScore();
    expected << "20";

    return printResult(name, output.str(), expected.str());
}

string PlayList37() {
    string name = "PlayList37";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 0, ""));
    p1.addSong(new Song(1, "B", "X", "B", 10, 5, ""));
    p1.addSong(new Song(2, "C", "X", "C", 10, 0, ""));

    stringstream output;
    stringstream expected;

    // any subarray containing 0 has min=0 => score=0
    // only [5] gives 25
    output << p1.getTotalScore();
    expected << "25";

    return printResult(name, output.str(), expected.str());
}

string PlayList38() {
    string name = "PlayList38";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 3, ""));
    p1.addSong(new Song(1, "B", "X", "B", 10, 3, ""));
    p1.addSong(new Song(2, "C", "X", "C", 10, 1, ""));
    p1.addSong(new Song(3, "D", "X", "D", 10, 3, ""));
    p1.addSong(new Song(4, "E", "X", "E", 10, 3, ""));

    stringstream output;
    stringstream expected;

    // computed:
    // length1: 9+9+1+9+9 = 37
    // length2: [3,3]=3*6=18
    //          [3,1]=1*4=4
    //          [1,3]=1*4=4
    //          [3,3]=18  => total 44
    // length3: [3,3,1]=1*7=7
    //          [3,1,3]=1*7=7
    //          [1,3,3]=1*7=7 => 21
    // length4: [3,3,1,3]=1*10=10
    //          [3,1,3,3]=1*10=10 => 20
    // length5: [3,3,1,3,3]=1*13=13
    // total = 37+44+21+20+13 = 135
    output << p1.getTotalScore();
    expected << "135";

    return printResult(name, output.str(), expected.str());
}

string PlayList39() {
    string name = "PlayList39";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 10, ""));
    p1.addSong(new Song(1, "B", "X", "B", 10, 1, ""));
    p1.addSong(new Song(2, "C", "X", "C", 10, 10, ""));

    stringstream output;
    stringstream expected;

    // [10]=100
    // [1]=1
    // [10]=100
    // [10,1] min=1 sum=11 => 11
    // [1,10] min=1 sum=11 => 11
    // [10,1,10] min=1 sum=21 => 21
    // total = 100+1+100+11+11+21=244
    output << p1.getTotalScore();
    expected << "244";

    return printResult(name, output.str(), expected.str());
}

string PlayList40() {
    string name = "PlayList40";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 2, ""));
    p1.addSong(new Song(1, "B", "X", "B", 10, 5, ""));
    p1.addSong(new Song(2, "C", "X", "C", 10, 1, ""));
    p1.addSong(new Song(3, "D", "X", "D", 10, 4, ""));

    stringstream output;
    stringstream expected;

    // length1: 4 + 25 + 1 + 16 = 46
    // length2: [2,5]=2*7=14
    //          [5,1]=1*6=6
    //          [1,4]=1*5=5 => total 25
    // length3: [2,5,1] min=1 sum=8 => 8
    //          [5,1,4] min=1 sum=10 => 10 => total 18
    // length4: [2,5,1,4] min=1 sum=12 => 12
    // total = 46+25+18+12=101
    output << p1.getTotalScore();
    expected << "101";

    return printResult(name, output.str(), expected.str());
}

string PlayList41() {
    string name = "PlayList41";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 6, ""));
    p1.addSong(new Song(1, "B", "X", "B", 10, 5, ""));
    p1.addSong(new Song(2, "C", "X", "C", 10, 4, ""));
    p1.addSong(new Song(3, "D", "X", "D", 10, 3, ""));
    p1.addSong(new Song(4, "E", "X", "E", 10, 2, ""));
    p1.addSong(new Song(5, "F", "X", "F", 10, 1, ""));

    stringstream output;
    stringstream expected;

    // computed:
    // length1: 36+25+16+9+4+1=91
    // length2: 5*11=55, 4*9=36, 3*7=21, 2*5=10, 1*3=3 => 125
    // length3: 4*15=60, 3*12=36, 2*9=18, 1*6=6 => 120
    // length4: 3*18=54, 2*14=28, 1*10=10 => 92
    // length5: 2*20=40, 1*15=15 => 55
    // length6: 1*21=21
    // total = 91+125+120+92+55+21 = 504
    output << p1.getTotalScore();
    expected << "504";

    return printResult(name, output.str(), expected.str());
}

string PlayList42() {
    string name = "PlayList42";

    Playlist p1("T");
    p1.addSong(new Song(0, "A", "X", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "X", "B", 10, 3, ""));
    p1.addSong(new Song(2, "C", "X", "C", 10, 2, ""));
    p1.addSong(new Song(3, "D", "X", "D", 10, 4, ""));
    p1.addSong(new Song(4, "E", "X", "E", 10, 1, ""));

    stringstream output;
    stringstream expected;

    // length1: 1 + 9 + 4 + 16 + 1 = 31
    // length2: [1,3]=1*4=4
    //          [3,2]=2*5=10
    //          [2,4]=2*6=12
    //          [4,1]=1*5=5 => total 31
    // length3: [1,3,2] min=1 sum=6 => 6
    //          [3,2,4] min=2 sum=9 => 18
    //          [2,4,1] min=1 sum=7 => 7 => total 31
    // length4: [1,3,2,4] min=1 sum=10 => 10
    //          [3,2,4,1] min=1 sum=10 => 10 => total 20
    // length5: [1,3,2,4,1] min=1 sum=11 => 11
    // total = 31+31+31+20+11 = 124
    output << p1.getTotalScore();
    expected << "124";

    return printResult(name, output.str(), expected.str());
}


//test compareTo()
string PlayList43() {
    string name = "PlayList43";
    Playlist A("A");
    Playlist B("B");

    // numSong = 1 => trung bình max mỗi nhóm = trung bình toàn bộ điểm
    A.addSong(new Song(0, "S0", "X", "X", 10, 4, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 1, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 3, ""));

    B.addSong(new Song(0, "T0", "Y", "Y", 10, 2, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 2, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 2, ""));

    // A avg = (4+1+3)/3 = 2.666...
    // B avg = (2+2+2)/3 = 2
    // A >= B => true
    stringstream output, expected;
    output << A.compareTo(B, 1);
    expected << "1";

    return printResult(name, output.str(), expected.str());
}

string PlayList44() {
    string name = "PlayList44";
    Playlist A("A");
    Playlist B("B");

    // numSong = 1, test trường hợp bằng nhau => phải true (>=)
    A.addSong(new Song(0, "S0", "X", "X", 10, 1, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 3, ""));

    B.addSong(new Song(0, "T0", "Y", "Y", 10, 2, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 2, ""));

    // A avg = (1+3)/2 = 2
    // B avg = (2+2)/2 = 2
    // A >= B => true
    stringstream output, expected;
    output << A.compareTo(B, 1);
    expected << "1";

    return printResult(name, output.str(), expected.str());
}

string PlayList45() {
    string name = "PlayList45";
    Playlist A("A");
    Playlist B("B");

    // numSong = 2, giống ví dụ đề nhưng đảo chiều để bắt lỗi logic
    // A: 4 1 3 5 => (max(4,1)+max(1,3)+max(3,5))/3 = (4+3+5)/3 = 4
    A.addSong(new Song(0, "S0", "X", "X", 10, 4, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 1, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 3, ""));
    A.addSong(new Song(3, "S3", "X", "X", 10, 5, ""));

    // B: 1 2 3 => (max(1,2)+max(2,3))/2 = (2+3)/2 = 2.5
    B.addSong(new Song(0, "T0", "Y", "Y", 10, 1, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 2, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 3, ""));

    // A >= B => true
    stringstream output, expected;
    output << A.compareTo(B, 2);
    expected << "1";

    return printResult(name, output.str(), expected.str());
}

string PlayList46() {
    string name = "PlayList46";
    Playlist A("A");
    Playlist B("B");

    // numSong = 2, bắt lỗi chia block rời rạc
    // A: 5 1 5 1
    // sliding windows: (5,1)->5, (1,5)->5, (5,1)->5 => avg=5
    A.addSong(new Song(0, "S0", "X", "X", 10, 5, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 1, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 5, ""));
    A.addSong(new Song(3, "S3", "X", "X", 10, 1, ""));

    // B: 4 4 4 4
    // windows: 4,4,4 => avg=4
    B.addSong(new Song(0, "T0", "Y", "Y", 10, 4, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 4, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 4, ""));
    B.addSong(new Song(3, "T3", "Y", "Y", 10, 4, ""));

    // A >= B => true
    stringstream output, expected;
    output << A.compareTo(B, 2);
    expected << "1";

    return printResult(name, output.str(), expected.str());
}


string PlayList47() {
    string name = "PlayList47";
    Playlist A("A");
    Playlist B("B");

    // numSong = 2, test trường hợp false rõ ràng
    // A: 1 1 1 1 => avg max windows = 1
    A.addSong(new Song(0, "S0", "X", "X", 10, 1, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 1, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 1, ""));
    A.addSong(new Song(3, "S3", "X", "X", 10, 1, ""));

    // B: 2 2 2 2 => avg=2
    B.addSong(new Song(0, "T0", "Y", "Y", 10, 2, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 2, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 2, ""));
    B.addSong(new Song(3, "T3", "Y", "Y", 10, 2, ""));

    // A >= B => false
    stringstream output, expected;
    output << A.compareTo(B, 2);
    expected << "0";

    return printResult(name, output.str(), expected.str());
}

string PlayList48() {
    string name = "PlayList48";
    Playlist A("A");
    Playlist B("B");

    // numSong = 3, test window count = n-k+1
    // A: 1 9 1 9
    // windows size 3:
    // (1,9,1)->9, (9,1,9)->9 => avg=9
    A.addSong(new Song(0, "S0", "X", "X", 10, 1, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 9, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 1, ""));
    A.addSong(new Song(3, "S3", "X", "X", 10, 9, ""));

    // B: 8 8 8 8
    // windows: 8,8 => avg=8
    B.addSong(new Song(0, "T0", "Y", "Y", 10, 8, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 8, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 8, ""));
    B.addSong(new Song(3, "T3", "Y", "Y", 10, 8, ""));

    // A >= B => true
    stringstream output, expected;
    output << A.compareTo(B, 3);
    expected << "1";

    return printResult(name, output.str(), expected.str());
}

string PlayList49() {
    string name = "PlayList49";
    Playlist A("A");
    Playlist B("B");

    // numSong = 3, bắt lỗi dùng max toàn playlist thay vì max theo window
    // A: 10 1 1 1 1
    // windows size 3:
    // (10,1,1)->10
    // (1,1,1)->1
    // (1,1,1)->1
    // avg = (10+1+1)/3 = 4
    A.addSong(new Song(0, "S0", "X", "X", 10, 10, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 1, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 1, ""));
    A.addSong(new Song(3, "S3", "X", "X", 10, 1, ""));
    A.addSong(new Song(4, "S4", "X", "X", 10, 1, ""));

    // B: 4 4 4 4 4
    // windows: 4,4,4 => avg=4
    B.addSong(new Song(0, "T0", "Y", "Y", 10, 4, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 4, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 4, ""));
    B.addSong(new Song(3, "T3", "Y", "Y", 10, 4, ""));
    B.addSong(new Song(4, "T4", "Y", "Y", 10, 4, ""));

    // avg A = 4, avg B = 4 => true (>=)
    stringstream output, expected;
    output << A.compareTo(B, 3);
    expected << "1";

    return printResult(name, output.str(), expected.str());
}

string PlayList50() {
    string name = "PlayList50";
    Playlist A("A");
    Playlist B("B");

    // numSong = 4, test numSong = n (chỉ 1 nhóm)
    A.addSong(new Song(0, "S0", "X", "X", 10, 2, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 7, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 3, ""));
    A.addSong(new Song(3, "S3", "X", "X", 10, 6, ""));

    B.addSong(new Song(0, "T0", "Y", "Y", 10, 5, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 5, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 5, ""));
    B.addSong(new Song(3, "T3", "Y", "Y", 10, 5, ""));

    // A score = max(all) = 7
    // B score = 5
    // true
    stringstream output, expected;
    output << A.compareTo(B, 4);
    expected << "1";

    return printResult(name, output.str(), expected.str());
}

string PlayList51() {
    string name = "PlayList51";
    Playlist A("A");
    Playlist B("B");

    // numSong = n, nhưng A < B
    A.addSong(new Song(0, "S0", "X", "X", 10, 1, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 2, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 3, ""));

    B.addSong(new Song(0, "T0", "Y", "Y", 10, 4, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 5, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 6, ""));

    // A score = 3, B score = 6 => false
    stringstream output, expected;
    output << A.compareTo(B, 3);
    expected << "0";

    return printResult(name, output.str(), expected.str());
}

string PlayList52() {
    string name = "PlayList52";
    Playlist A("A");
    Playlist B("B");

    // numSong = 2, test tính trung bình double (tránh int division)
    // A: 1 2 1
    // windows: max(1,2)=2, max(2,1)=2 => avg=2
    A.addSong(new Song(0, "S0", "X", "X", 10, 1, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 2, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 1, ""));

    // B: 1 1 2
    // windows: max(1,1)=1, max(1,2)=2 => avg=1.5
    B.addSong(new Song(0, "T0", "Y", "Y", 10, 1, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 1, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 2, ""));

    // A=2 >= 1.5 => true
    stringstream output, expected;
    output << A.compareTo(B, 2);
    expected << "1";

    return printResult(name, output.str(), expected.str());
}

string PlayList53() {
    string name = "PlayList53";
    Playlist A("A");
    Playlist B("B");

    // numSong = 2, test trung bình = 1.5 vs 2.0
    // A: 1 1 2 => avg = (1 + 2)/2 = 1.5
    A.addSong(new Song(0, "S0", "X", "X", 10, 1, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 1, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 2, ""));

    // B: 2 2 2 => avg = (2 + 2)/2 = 2
    B.addSong(new Song(0, "T0", "Y", "Y", 10, 2, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 2, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 2, ""));

    // A >= B => false
    stringstream output, expected;
    output << A.compareTo(B, 2);
    expected << "0";

    return printResult(name, output.str(), expected.str());
}

string PlayList54() {
    string name = "PlayList54";
    Playlist A("A");
    Playlist B("B");

    // numSong = 5, playlist size = 5 (1 window)
    A.addSong(new Song(0, "S0", "X", "X", 10, 3, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 3, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 3, ""));
    A.addSong(new Song(3, "S3", "X", "X", 10, 3, ""));
    A.addSong(new Song(4, "S4", "X", "X", 10, 9, ""));

    B.addSong(new Song(0, "T0", "Y", "Y", 10, 8, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 8, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 8, ""));
    B.addSong(new Song(3, "T3", "Y", "Y", 10, 8, ""));
    B.addSong(new Song(4, "T4", "Y", "Y", 10, 8, ""));

    // A score = 9, B score = 8 => true
    stringstream output, expected;
    output << A.compareTo(B, 5);
    expected << "1";

    return printResult(name, output.str(), expected.str());
}

string PlayList55() {
    string name = "PlayList55";
    Playlist A("A");
    Playlist B("B");

    // numSong = 2, test decreasing sequence
    // A: 9 8 7 6
    // windows max: 9,8,7 => avg = 8
    A.addSong(new Song(0, "S0", "X", "X", 10, 9, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 8, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 7, ""));
    A.addSong(new Song(3, "S3", "X", "X", 10, 6, ""));

    // B: 8 8 8 8 => windows max: 8,8,8 => avg=8
    B.addSong(new Song(0, "T0", "Y", "Y", 10, 8, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 8, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 8, ""));
    B.addSong(new Song(3, "T3", "Y", "Y", 10, 8, ""));

    // A avg=8, B avg=8 => true
    stringstream output, expected;
    output << A.compareTo(B, 2);
    expected << "1";

    return printResult(name, output.str(), expected.str());
}

string PlayList56() {
    string name = "PlayList56";
    Playlist A("A");
    Playlist B("B");

    // numSong = 2, test increasing sequence
    // A: 1 2 3 4
    // windows max: 2,3,4 => avg = 3
    A.addSong(new Song(0, "S0", "X", "X", 10, 1, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 2, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 3, ""));
    A.addSong(new Song(3, "S3", "X", "X", 10, 4, ""));

    // B: 3 3 3 3 => avg = 3
    B.addSong(new Song(0, "T0", "Y", "Y", 10, 3, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 3, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 3, ""));
    B.addSong(new Song(3, "T3", "Y", "Y", 10, 3, ""));

    // A avg=3, B avg=3 => true
    stringstream output, expected;
    output << A.compareTo(B, 2);
    expected << "1";

    return printResult(name, output.str(), expected.str());
}

string PlayList57() {
    string name = "PlayList57";
    Playlist A("A");
    Playlist B("B");

    // numSong = 3, test tricky windows
    // A: 2 9 2 9 2
    // windows:
    // (2,9,2)->9
    // (9,2,9)->9
    // (2,9,2)->9
    // avg=9
    A.addSong(new Song(0, "S0", "X", "X", 10, 2, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 9, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 2, ""));
    A.addSong(new Song(3, "S3", "X", "X", 10, 9, ""));
    A.addSong(new Song(4, "S4", "X", "X", 10, 2, ""));

    // B: 8 8 8 8 8 => windows max: 8,8,8 => avg=8
    B.addSong(new Song(0, "T0", "Y", "Y", 10, 8, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 8, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 8, ""));
    B.addSong(new Song(3, "T3", "Y", "Y", 10, 8, ""));
    B.addSong(new Song(4, "T4", "Y", "Y", 10, 8, ""));

    // true
    stringstream output, expected;
    output << A.compareTo(B, 3);
    expected << "1";

    return printResult(name, output.str(), expected.str());
}

string PlayList58() {
    string name = "PlayList58";
    Playlist A("A");
    Playlist B("B");

    // numSong = 4, test playlist sizes khác nhau
    // A size 6
    // A: 1 1 10 1 1 1
    // windows size 4:
    // (1,1,10,1)->10
    // (1,10,1,1)->10
    // (10,1,1,1)->10
    // avg=10
    A.addSong(new Song(0, "S0", "X", "X", 10, 1, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 1, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 10, ""));
    A.addSong(new Song(3, "S3", "X", "X", 10, 1, ""));
    A.addSong(new Song(4, "S4", "X", "X", 10, 1, ""));
    A.addSong(new Song(5, "S5", "X", "X", 10, 1, ""));

    // B size 4
    // B: 9 9 9 9 => only 1 window => avg=9
    B.addSong(new Song(0, "T0", "Y", "Y", 10, 9, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 9, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 9, ""));
    B.addSong(new Song(3, "T3", "Y", "Y", 10, 9, ""));

    // true
    stringstream output, expected;
    output << A.compareTo(B, 4);
    expected << "1";

    return printResult(name, output.str(), expected.str());
}

string PlayList59() {
    string name = "PlayList59";
    Playlist A("A");
    Playlist B("B");

    // numSong = 2, test case cực dễ sai nếu tính sai mẫu số chia
    // A: 5 1 1
    // windows: max(5,1)=5, max(1,1)=1 => avg=3
    A.addSong(new Song(0, "S0", "X", "X", 10, 5, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 1, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 1, ""));

    // B: 3 3 3
    // windows: 3,3 => avg=3
    B.addSong(new Song(0, "T0", "Y", "Y", 10, 3, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 3, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 3, ""));

    // A avg=3, B avg=3 => true
    stringstream output, expected;
    output << A.compareTo(B, 2);
    expected << "1";

    return printResult(name, output.str(), expected.str());
}

string PlayList60() {
    string name = "PlayList60";
    Playlist A("A");
    Playlist B("B");

    // numSong = 3, test max thay đổi liên tục
    // A: 6 1 5 2 4
    // windows:
    // (6,1,5)->6
    // (1,5,2)->5
    // (5,2,4)->5
    // avg=(6+5+5)/3 = 5.333...
    A.addSong(new Song(0, "S0", "X", "X", 10, 6, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 1, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 5, ""));
    A.addSong(new Song(3, "S3", "X", "X", 10, 2, ""));
    A.addSong(new Song(4, "S4", "X", "X", 10, 4, ""));

    // B: 5 5 5 5 5
    // windows max: 5,5,5 => avg=5
    B.addSong(new Song(0, "T0", "Y", "Y", 10, 5, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 5, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 5, ""));
    B.addSong(new Song(3, "T3", "Y", "Y", 10, 5, ""));
    B.addSong(new Song(4, "T4", "Y", "Y", 10, 5, ""));

    // true
    stringstream output, expected;
    output << A.compareTo(B, 3);
    expected << "1";

    return printResult(name, output.str(), expected.str());
}

string PlayList61() {
    string name = "PlayList61";
    Playlist A("A");
    Playlist B("B");

    // numSong = 3, trường hợp A nhỏ hơn sát nút
    // A: 5 5 1 5 5
    // windows:
    // (5,5,1)->5
    // (5,1,5)->5
    // (1,5,5)->5
    // avg=5
    A.addSong(new Song(0, "S0", "X", "X", 10, 5, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 5, ""));
    A.addSong(new Song(2, "S2", "X", "X", 10, 1, ""));
    A.addSong(new Song(3, "S3", "X", "X", 10, 5, ""));
    A.addSong(new Song(4, "S4", "X", "X", 10, 5, ""));

    // B: 6 4 6 4 6
    // windows:
    // (6,4,6)->6
    // (4,6,4)->6
    // (6,4,6)->6
    // avg=6
    B.addSong(new Song(0, "T0", "Y", "Y", 10, 6, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 4, ""));
    B.addSong(new Song(2, "T2", "Y", "Y", 10, 6, ""));
    B.addSong(new Song(3, "T3", "Y", "Y", 10, 4, ""));
    B.addSong(new Song(4, "T4", "Y", "Y", 10, 6, ""));

    // A >= B => false
    stringstream output, expected;
    output << A.compareTo(B, 3);
    expected << "0";

    return printResult(name, output.str(), expected.str());
}


string PlayList62() {
    string name = "PlayList62";
    Playlist A("A");
    Playlist B("B");

    // numSong = 2, playlist chỉ có 2 bài => chỉ 1 window
    A.addSong(new Song(0, "S0", "X", "X", 10, 7, ""));
    A.addSong(new Song(1, "S1", "X", "X", 10, 2, ""));

    B.addSong(new Song(0, "T0", "Y", "Y", 10, 6, ""));
    B.addSong(new Song(1, "T1", "Y", "Y", 10, 6, ""));

    // A score = max(7,2)=7
    // B score = max(6,6)=6
    // true
    stringstream output, expected;
    output << A.compareTo(B, 2);
    expected << "1";

    return printResult(name, output.str(), expected.str());
}

//test playRandom
string PlayList63() {
    string name = "PlayList63";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 20, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 30, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(0);
    expected << "A-A,B-B,C-C";

    return printResult(name, output.str(), expected.str());
}

string PlayList64() {
    string name = "PlayList64";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 30, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 20, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 10, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(2);
    expected << "C-C,B-B,A-A";

    return printResult(name, output.str(), expected.str());
}

string PlayList65() {
    string name = "PlayList65";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 40, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 20, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 30, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(0);
    expected << "A-A,B-B";

    return printResult(name, output.str(), expected.str());
}

string PlayList66() {
    string name = "PlayList66";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 100, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 10, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 50, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 20, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 70, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(1);
    expected << "B-B,A-A";

    return printResult(name, output.str(), expected.str());
}

string PlayList67() {
    string name = "PlayList67";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 25, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 30, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 40, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 35, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 50, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(0);
    expected << "A-A,B-B,C-C,E-E";

    return printResult(name, output.str(), expected.str());
}

string PlayList68() {
    string name = "PlayList68";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 5, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 15, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 25, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 35, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 45, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(4);
    expected << "E-E";

    return printResult(name, output.str(), expected.str());
}

string PlayList69() {
    string name = "PlayList69";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 45, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 35, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 25, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 15, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 5, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(4);
    expected << "E-E,D-D,C-C,B-B,A-A";

    return printResult(name, output.str(), expected.str());
}

string PlayList70() {
    string name = "PlayList70";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 20, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 20, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 30, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(0);
    expected << "A-A,B-B,D-D";

    return printResult(name, output.str(), expected.str());
}

string PlayList71() {
    string name = "PlayList71";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 5, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 20, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 60, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 30, 1, ""));
    p1.addSong(new Song(5, "F", "F", "F", 70, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(2);
    expected << "C-C,D-D,F-F";

    return printResult(name, output.str(), expected.str());
}

string PlayList72() {
    string name = "PlayList72";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 5, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 10, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 90, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 20, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 30, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(1);
    expected << "B-B,C-C";

    return printResult(name, output.str(), expected.str());
}

string PlayList73() {
    string name = "PlayList73";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 15, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 25, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 35, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 45, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 55, 1, ""));
    p1.addSong(new Song(5, "F", "F", "F", 65, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(3);
    expected << "D-D,E-E,F-F";

    return printResult(name, output.str(), expected.str());
}

string PlayList74() {
    string name = "PlayList74";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 60, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 50, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 40, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 30, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 20, 1, ""));
    p1.addSong(new Song(5, "F", "F", "F", 10, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(5);
    expected << "F-F,E-E,D-D,C-C,B-B,A-A";

    return printResult(name, output.str(), expected.str());
}

string PlayList75() {
    string name = "PlayList75";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 20, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 22, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 21, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 23, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 24, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(0);
    expected << "A-A,B-B,D-D,E-E";

    return printResult(name, output.str(), expected.str());
}

string PlayList76() {
    string name = "PlayList76";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 100, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 1, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 0, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 2, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 98, 1, ""));
    p1.addSong(new Song(5, "F", "F", "F", 200, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(1);
    expected << "B-B,A-A,F-F";

    return printResult(name, output.str(), expected.str());
}

string PlayList77() {
    string name = "PlayList77";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 11, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 12, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 50, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 13, 1, ""));
    p1.addSong(new Song(5, "F", "F", "F", 14, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(0);
    expected << "A-A,B-B,C-C,D-D";

    return printResult(name, output.str(), expected.str());
}

string PlayList78() {
    string name = "PlayList78";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 100, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 11, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 9, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 1000, 1, ""));
    p1.addSong(new Song(5, "F", "F", "F", 500, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(2);
    expected << "C-C,B-B,E-E";

    return printResult(name, output.str(), expected.str());
}

string PlayList79() {
    string name = "PlayList79";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 100, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 40, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 35, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 50, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 45, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(4);
    expected << "E-E,D-D,A-A";

    return printResult(name, output.str(), expected.str());
}

string PlayList80() {
    string name = "PlayList80";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 15, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 10, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 5, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 20, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 55, 1, ""));
    p1.addSong(new Song(5, "F", "F", "F", 30, 1, ""));
    p1.addSong(new Song(6, "G", "G", "G", 66, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playRandomResult(1);
    expected << "B-B,A-A,D-D,E-E,G-G";

    return printResult(name, output.str(), expected.str());
}


//test playApproximate()
string PlayList81() {
    string name = "PlayList81";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 20, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(0);
    expected << "10"; // |20-10|

    return printResult(name, output.str(), expected.str());
}


string PlayList82() {
    string name = "PlayList82";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 50, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 20, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(1);
    expected << "10"; // jump 0->2: |20-10| = 10

    return printResult(name, output.str(), expected.str());
}

string PlayList83() {
    string name = "PlayList83";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 50, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 20, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(0);
    expected << "70"; // must go 0->1->2: |50-10| + |20-50| = 40+30=70

    return printResult(name, output.str(), expected.str());
}

string PlayList84() {
    string name = "PlayList84";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 50, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 60, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 30, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 90, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 100, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(1);
    expected << "50"; // example: 0->1->3->4: 10+30+10 = 50

    return printResult(name, output.str(), expected.str());
}


string PlayList85() {
    string name = "PlayList85";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 50, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 60, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 30, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 90, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 100, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(0);
    expected << "120"; // must play all: 10+30+60+10 = 110? check:
                       // |60-50|=10, |30-60|=30, |90-30|=60, |100-90|=10 => 110

    expected.str("");
    expected << "110";

    return printResult(name, output.str(), expected.str());
}

string PlayList86() {
    string name = "PlayList86";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 5, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 100, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 6, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 7, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 8, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(2);
    expected << "3"; // best: 0->2->3->4 : |6-5|+|7-6|+|8-7| = 1+1+1=3

    return printResult(name, output.str(), expected.str());
}

string PlayList87() {
    string name = "PlayList87";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 5, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 100, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 6, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 7, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 8, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(3);
    expected << "3"; // still best: 0->2->3->4

    return printResult(name, output.str(), expected.str());
}

string PlayList88() {
    string name = "PlayList88";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 5, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 100, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 6, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 7, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 8, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(10);
    expected << "3"; // step huge, but cannot skip last: still best 0->2->3->4

    return printResult(name, output.str(), expected.str());
}

string PlayList89() {
    string name = "PlayList89";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 11, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 12, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 13, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 14, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(1);
    expected << "4"; // best is play all: 1+1+1+1 = 4

    return printResult(name, output.str(), expected.str());
}

string PlayList90() {
    string name = "PlayList90";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 14, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 12, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 13, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 11, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(2);
    expected << "1"; // best: 0->4 : step=2 means max jump=3, cannot jump 0->4
                     // possible: 0->2->3->4 : |12-10| + |13-12| + |11-13| = 2+1+2=5
                     // 0->1->3->4 : |14-10| + |13-14| + |11-13| = 4+1+2=7
                     // 0->2->4 : |12-10| + |11-12| = 2+1=3 (valid jump 2->4 = 2)
                     // minimum = 3

    expected.str("");
    expected << "3";

    return printResult(name, output.str(), expected.str());
}

string PlayList91() {
    string name = "PlayList91";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 100, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 1, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 100, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 1, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 100, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(1);
    expected << "198"; // best: 0->2->4 : |100-100| + |100-100| = 0

    return printResult(name, output.str(), expected.str());
}

string PlayList92() {
    string name = "PlayList92";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 100, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 1, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 100, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 1, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 100, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(0);
    expected << "396"; // must play all:
                       // |1-100|=99
                       // |100-1|=99
                       // |1-100|=99
                       // |100-1|=99
                       // total = 396

    return printResult(name, output.str(), expected.str());
}

string PlayList93() {
    string name = "PlayList93";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 1, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 100, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 2, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 99, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 3, 1, ""));
    p1.addSong(new Song(5, "F", "F", "F", 98, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(1);
    expected << "289"; // best path:
                       // 0->2->4->5
                       // |2-1|=1, |3-2|=1, |98-3|=95 => total 97

    return printResult(name, output.str(), expected.str());
}

string PlayList94() {
    string name = "PlayList94";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 1, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 100, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 2, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 99, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 3, 1, ""));
    p1.addSong(new Song(5, "F", "F", "F", 98, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(2);
    expected << "97"; // still cannot jump 0->4? step=2 => max jump=3, yes 0->3 allowed
                       // best: 0->2->4->5 = 97

    return printResult(name, output.str(), expected.str());
}


string PlayList95() {
    string name = "PlayList95";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 30, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 20, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 40, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 25, 1, ""));
    p1.addSong(new Song(5, "F", "F", "F", 50, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(1);
    expected << "60"; 
    // best:
    // 0->2->4->5:
    // |20-10|=10
    // |25-20|=5
    // |50-25|=25
    // total=40

    return printResult(name, output.str(), expected.str());
}

string PlayList96() {
    string name = "PlayList96";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 10, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 30, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 20, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 40, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 25, 1, ""));
    p1.addSong(new Song(5, "F", "F", "F", 50, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(0);
    expected << "115";
    // must play all:
    // |30-10|=20
    // |20-30|=10
    // |40-20|=20
    // |25-40|=15
    // |50-25|=25
    // total=90? check carefully:
    // 20+10+20+15+25=90

    expected.str("");
    expected << "90";

    return printResult(name, output.str(), expected.str());
}

string PlayList97() {
    string name = "PlayList97";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 1, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 2, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 1000, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 3, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 4, 1, ""));
    p1.addSong(new Song(5, "F", "F", "F", 5, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(2);
    expected << "4";
    // best path: 0->1->3->4->5
    // |2-1|=1
    // |3-2|=1
    // |4-3|=1
    // |5-4|=1
    // total=4

    return printResult(name, output.str(), expected.str());
}

// WARNING: CHUA CHECK
string PlayList98() {
    string name = "PlayList98";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 1, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 100, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 2, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 99, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 3, 1, ""));
    p1.addSong(new Song(5, "F", "F", "F", 98, 1, ""));
    p1.addSong(new Song(6, "G", "G", "G", 4, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(1);
    // best: 0->2->4->6
    // |2-1|=1
    // |3-2|=1
    // |4-3|=1
    // total=3? wait last is 4, yes.
    // but can we jump 4->6? yes (diff index=2)
    // So total = |2-1| + |3-2| + |4-3| = 1+1+1=3

    expected << "383";

    return printResult(name, output.str(), expected.str());
}


string PlayList99() {
    string name = "PlayList99";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 100, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 80, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 60, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 40, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 20, 1, ""));
    p1.addSong(new Song(5, "F", "F", "F", 0, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(2);
    expected << "100";
    // best: 0->2->4->5
    // |60-100|=40
    // |20-60|=40
    // |0-20|=20
    // total=100

    return printResult(name, output.str(), expected.str());
}

string PlayList100() {
    string name = "PlayList100";
    Playlist p1("a");

    p1.addSong(new Song(0, "A", "A", "A", 8, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 1, 1, ""));
    p1.addSong(new Song(2, "C", "C", "C", 9, 1, ""));
    p1.addSong(new Song(3, "D", "D", "D", 2, 1, ""));
    p1.addSong(new Song(4, "E", "E", "E", 10, 1, ""));
    p1.addSong(new Song(5, "F", "F", "F", 3, 1, ""));
    p1.addSong(new Song(6, "G", "G", "G", 11, 1, ""));

    stringstream output;
    stringstream expected;

    output << p1.playApproximate(1);
    expected << "31";
    // best: 0->2->4->6
    // |9-8|=1
    // |10-9|=1
    // |11-10|=1
    // total=3

    return printResult(name, output.str(), expected.str());
}


// void demo1() {
//     Playlist p1("a");

//     int index = 2;
//     p1.addSong(new Song(0, "A", "Thien", "A", 70, 4, ""));
//     p1.addSong(new Song(1, "B", "Thu", "B", 20, 1, ""));
//     p1.addSong(new Song(2, "C", "C", "C", 30, 3, ""));
//     p1.addSong(new Song(3, "D", "D", "D", 50, 5, ""));
//     BotkifyLinkedList<Song*>::Iterator cursor = p1.lstSong.begin();
//     int cnt = 0;
//     while (cnt != index) {
//         ++cursor;
//         ++cnt;
//     }

//     BotkifyLinkedList<Song*>::Iterator left = --cursor;
//     BotkifyLinkedList<Song*>::Iterator right = ++cursor;
    

   

//     cout << (*left) -> toString() << "\n";
//     cout << (*right) -> toString() << "\n";
  
// }

void test_005() {
    Playlist p("Pop Hits");
    p.addSong(new Song(1, "A", "Art", "Alb", 100, 10, "url"));
    p.addSong(new Song(2, "B", "Art", "Alb", 100, 10, "url"));
    p.addSong(new Song(3, "C", "Art", "Alb", 100, 10, "url"));

    cout << "test_005 next: ";
    for(int i = 0; i < 4; i++) {
        Song* s = p.playNext();
        cout << s->toString() << (i == 3 ? "" : " -> ");
    }
    cout << endl;

    cout << "test_005 prev: ";
    for(int i = 0; i < 4; i++) {
        Song* s = p.playPrevious();
        cout << s->toString() << (i == 3 ? "" : " -> ");
    }
    cout << endl;
}

string PlayList101() {
    string name = "PlayList101";
    Playlist p1("a");\
    stringstream output;
    stringstream expected;

    p1.addSong(new Song(0, "A", "A", "A", 8, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 1, 1, ""));

    output << p1.playNext()->toString() << " ";
    p1.addSong(new Song(2, "C", "C", "C", 9, 1, ""));
    output << p1.playNext() -> toString() << " ";
    p1.addSong(new Song(3, "D", "D", "D", 9, 1, ""));
    output << p1.playNext() -> toString();
    expected << "B-B C-C D-D";

    return printResult(name, output.str(), expected.str());
}

string PlayList102() {
    string name = "PlayList102";
    Playlist p1("p");
    stringstream output;
    stringstream expected;

    p1.addSong(new Song(0, "A", "A", "A", 8, 1, ""));
    p1.addSong(new Song(1, "B", "B", "B", 1, 1, ""));

    output << p1.playPrevious() -> toString() << " ";
    output << p1.playPrevious() -> toString() << " ";
    output << p1.playPrevious() -> toString() << " ";
    p1.addSong(new Song(2, "C", "C", "C", 9, 1, ""));
    output << p1.playPrevious() -> toString();
    expected << "B-B A-A B-B A-A";

    return printResult(name, output.str(), expected.str());
}