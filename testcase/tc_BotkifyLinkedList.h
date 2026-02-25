#include "Playlist.h"
#include "BotkifyLinkedList.h"
#include "Helper.h"
using namespace std;

string LinkedList01() {
    string name = "LinkedList01";
    BotkifyLinkedList <int> lst;
    for (int i = 0; i < 5; ++i) {
        lst.add(i);
    }
    stringstream output;
    string expected = "0,1,2,3,4";
    output << lst.toString();
    return printResult(name, output.str(), expected);
}

string LinkedList02() {
    string name = "LinkedList02";
    BotkifyLinkedList <int> lst;
    for (int i = 0; i < 5; ++i) {
        lst.add(i, i*i);
    }
    lst.add(0, 10);
    stringstream output;
    string expected = "10,0,1,4,9,16";
    output << lst.toString();
    return printResult(name, output.str(), expected);
}

string LinkedList03() {
    string name = "LinkedList03";
    BotkifyLinkedList <int> lst;
    lst.add(1);
    lst.add(2);
    lst.add(3);
    stringstream output;
    stringstream expected;
    output << lst.toString() << "\n";
    output << "List Size: " << lst.size();
    expected << "1,2,3" << "\n" << "List Size: 3";

    return printResult(name, output.str(), expected.str());
}

string LinkedList04() {
    string name = "LinkedList04";
    BotkifyLinkedList <int> lst;
    for (int i = 0; i < 5; ++i) {
        lst.add(i);
    }

    int removeNum = lst.removeAt(1);

    stringstream output;
    stringstream expected;
    output << lst.toString() << "\n" << "Remove Item: " << removeNum;
    expected << "0,2,3,4" << "\n" << "Remove Item: 1";
    return printResult(name, output.str(), expected.str());
}

string LinkedList05() {
    string name = "LinkedList05";
    
    BotkifyLinkedList<int> lst;
    for (int i = 0; i < 5; ++i) {
        lst.add(i);
        //cout << "something" << endl;
    }

    //cout << "somethong 1" << endl;
    stringstream output;
    stringstream expected;
    try {
        output << lst.get(5);
    }
    catch (out_of_range& e){
        output << e.what();
    };
    expected << "Index is invalid!";
    return printResult(name, output.str(), expected.str());
}

string LinkedList06() {
    string name = "LinkedList06";
    BotkifyLinkedList <int> lst;
    for (int i = 0; i < 5; ++i) {
        lst.add(i);
    }

    stringstream output;
    stringstream expected;
    try {
        output << lst.removeAt(-1);
    }
    catch (out_of_range &e) {
        output << e.what();
    }

    expected << "Index is invalid!";
    return printResult(name, output.str(), expected.str());
}

string LinkedList07() {
    string name = "LinkedList07";
    BotkifyLinkedList <int> lst;
    for (int i = 0; i < 5; ++i) {
        lst.add(i);
    }

    stringstream output;
    stringstream expected;
    lst.removeItem(4);
    lst.add(10);

    output << lst.toString();
    expected << "0,1,2,3,10";

    return printResult(name, output.str(), expected.str());
}
string LinkedList08() {
    string name = "LinkedList08";
    BotkifyLinkedList <int> lst;
    for (int i = 0;i < 5; ++i ){
        lst.add(i);
    }

    lst.clear();
    stringstream output;
    stringstream expected;
    output << ((lst.empty()) ? "List is empty" : "List is not empty");
    expected << "List is empty";
    return printResult(name, output.str(), expected.str());
}

string LinkedList09() {
    string name = "LinkedList09";
    BotkifyLinkedList <int> lst;
    for (int i = 0;i < 5; ++i) {
        lst.add(i);
    }
    stringstream output;
    stringstream expected;

    int foundIdx = 2;
    output << foundIdx << " : " << lst.get(foundIdx);
    expected << "2 : 2";
    return printResult(name, output.str(), expected.str());
}

string LinkedList10() {
    string name = "LinkedList10";
    BotkifyLinkedList <int> lst;
    lst.add(2);
    lst.add(2);
    lst.add(2);
    lst.add(2);
    lst.removeItem(2);
    stringstream output;
    stringstream expected;
    output << lst.toString() << "\n" << "List size: " << lst.size();
    expected << "2,2,2" << "\n" << "List size: 3";
    return printResult(name, output.str(), expected.str());
}

string LinkedList11() {
    string name = "LinkedList11";
    BotkifyLinkedList <int> lst;
    for(int i=0; i < 10; ++i) {
        lst.add(0,i);
    }

    stringstream output;
    stringstream expected;

    output << lst.toString();
    expected << "9,8,7,6,5,4,3,2,1,0";

    return printResult(name, output.str(), expected.str());
}

string LinkedList12() {
    string name = "LinkedList12";
    BotkifyLinkedList<int> lst;
    for(int i=0; i < 10; ++i) {
        lst.add(0,i);
    }

    //int len = lst.size();

    stringstream output;
    stringstream expected;
    try {
        lst.add(12,10);
    }
    catch (out_of_range &e) {
        output << e.what();
    }

    expected << "Index is invalid!";
    return printResult(name, output.str(), expected.str());
}

string LinkedList13() {
    string name = "LinkedList13";
    BotkifyLinkedList<int> lst;
    for(int i=0; i < 10; ++i) {
        lst.add(0,i);
    }

    stringstream output;
    stringstream expected;

    bool removeResult = lst.removeItem(129);
    output << ((removeResult == true) ? "ok" : "not ok");
    expected << "not ok";

    return printResult(name, output.str(), expected.str());
}

string LinkedList14() {
    string name = "LinkedList14";
    BotkifyLinkedList<int> lst;
    for (int i=0; i < 10; ++i) {
        lst.add(i*i);
    }

    for (int i=0; i < 10; ++i) {
        lst.removeAt(0);
    }

    stringstream output;
    stringstream expected;
    
    output << ((lst.empty()) ? "Empty" : "Non empty");
    expected << "Empty";
    
    return printResult(name, output.str(), expected.str());
}

string LinkedList15() {
    string name = "LinkedList15";
    BotkifyLinkedList<int> lst;
    for (int i=0; i < 10; ++i) {
        lst.add(i*i);
    }

    stringstream output;
    stringstream expected;

    try {
        lst.add(10, 200);
        output << lst.toString();
    }
    catch(out_of_range &e) {
        output << e.what();
    }

    expected << "0,1,4,9,16,25,36,49,64,81,200";

    return printResult(name, output.str(), expected.str());
}

string LinkedList16() {
    string name = "LinkedList16";

    BotkifyLinkedList<char> lst;
    lst.add('A');
    lst.add('B');
    
    stringstream output;
    stringstream expected;

    try {
        lst.removeAt(2);
    }

    catch (out_of_range &e) {
        output << e.what();
    }

    expected << "Index is invalid!";

    return printResult(name, output.str(), expected.str());
}

string LinkedList17() {
    string name = "LinkedList17";
    BotkifyLinkedList <char> lst;

    lst.add('A');
    lst.add('B');
    lst.add('C');
    lst.add(1, 'D');
    stringstream output;
    stringstream expected;

    output << lst.toString();
    expected << "A,D,B,C";

    return printResult(name, output.str(), expected.str());
}

string LinkedList18() {
    string name = "LinkedList18";

    BotkifyLinkedList<char> lst;
    lst.add('A');
    lst.add('B');
    lst.add('C');
    lst.add(1, 'D');

    stringstream output;
    stringstream expected;

    int len = lst.size();
    for (int i=0; i < len; ++i) {
        output << i << "-" << lst.get(i) << "\n";
    }

    expected << "0-A" << "\n" << "1-D" << "\n" << "2-B" << "\n" << "3-C" << "\n";
    
    return printResult(name, output.str(), expected.str());
}

string LinkedList19() {
    string name = "LinkedList19";

    BotkifyLinkedList<char> lst;
    stringstream output;
    stringstream expected;
    int foundIdx = 1;
    lst.add('A');
    lst.add('B');
    lst.add('C');
    output << foundIdx << "-" << lst.get(foundIdx) << "\n";
    lst.add(1, 'D');
    output << foundIdx << "-" << lst.get(foundIdx);

    expected << "1-B" << "\n" << "1-D";

    return printResult(name, output.str(), expected.str());
}

string LinkedList20() {
    string name = "LinkedList20";

    BotkifyLinkedList<int> lst;

    bool removeItem = lst.removeItem(2);
    stringstream output;
    stringstream expected;

    output << ((removeItem == true) ? "Found" : "Not found");
    expected << "Not found";

    return printResult(name, output.str(), expected.str());
}

string LinkedList21() {
    string name = "LinkedList21";

    BotkifyLinkedList<int> lst;
    lst.clear();

    stringstream output;
    stringstream expected;

    output << ((lst.empty()) ? "Empty" : "Non empty");
    expected << "Empty";

    return printResult(name, output.str(), expected.str());
}

string LinkedList22() {
    string name = "LinkedList22";

    BotkifyLinkedList<int> lst;
    lst.add(0,1);
    lst.add(1,20);

    stringstream output;
    stringstream expected;

    output << lst.toString();
    expected << "1,20";

    return printResult(name, output.str(), expected.str());
}

string LinkedList23() {
    string name = "LinkedList23";
    BotkifyLinkedList<int> lst;
    stringstream output;
    stringstream expected;

    try {
        lst.add(-1,10);
    }
    catch(out_of_range &e) {
        output << e.what();
    }

    expected << "Index is invalid!";
    return printResult(name, output.str(), expected.str());
}

string LinkedList24() {
    string name = "LinkedList24";
    BotkifyLinkedList<int> lst;
    for (int i = 0; i < 10; ++i) lst.add(i);
    for (int i = 0; i < 10; ++i) {
        lst.removeItem(lst.get(0));
    }
    stringstream output;
    stringstream expected;

    output << lst.toString();
    expected << "";
    return printResult(name, output.str(), expected.str());
}

