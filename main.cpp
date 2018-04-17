#include <cstdlib>
#include "TCPClient.h"
#include "json.hpp"

TCPClient tcp;

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    tcp.setup("127.0.0.1", 1955);

    // create an empty structure (null)
    nlohmann::json j;

    // add a number that is stored as double (note the implicit conversion of j to an object)
    j["temp"] = 22.5;


    // serialization (turn json into a string)
    string s = j.dump();


    tcp.Send(s);
    string rec = tcp.receive();
    if (rec != "") {
        cout << "Server Response:" << rec << endl;
    }
    return 0;
}

