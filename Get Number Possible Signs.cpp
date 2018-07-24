/** Get Number Possible Sign
 * DATE : 5/12/2018
 * PROGRAMMER: Yu-Min Chen
 * MEMBER FUNCTION NAME:
 *    getNumPossibleSigns
 * PURPOSE:
 *    The function takes in a series of addresses in a string array and compares each of them with the available
 *    letterInventory, returning the number of addresses that are POSSIBLE to form from the given letterInventory
 * PARAMETER:
 *    string* letterInventory
 *    string* addresses
 *    int length: length of the array, addresses[]
 * RETURN VALUE:
 *    int: the number of possible addresses that can be formed from your inventory of letters
 */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class CIS14 {
public:
    int getNumPossibleSigns(string* letterInventory, string* addresses, int length);
};

int CIS14::getNumPossibleSigns(string* letterInventory, string* addresses, int length) {
    int counter = 0;

    for (int i = 0; i < length; i++) {
        unordered_map<char, int> map;
        for (int j = 0; j < addresses[i].size(); j++) {
            char letter = addresses[i][j];
            auto it = map.find(letter);

            if (it != map.end()) {
                it->second += 1;
            } else if (letter != ' ') {
                map.insert({letter, 1});
            }
        }

    string c = *letterInventory;
    for (int j = 0; j < c.length(); j++) {
        char letter = c[j];
        auto it = map.find(letter);

        if (it != map.end()) {
            it->second -= 1;
            if (it->second == 0) {
                map.erase(letter);
            }
        }
    }
        if (map.empty()) {
            counter++;
        }
    }
    return counter;
}

int main() {

    string addresses[] = {"999 S ST", "A BAD ST", "B BAD ST"};
    string Inventory = "ABCDAAST";

    CIS14 cis;
    int i = cis.getNumPossibleSigns(&Inventory, addresses, sizeof(addresses)/sizeof(addresses[0]));
    cout << i << endl;

    return 0;
}



/** TEST RESULT
* input:  addresees: {"123C","123A","123 ADA"}
          string Inventory: "AAAABCCC123456789"
* output: 2
*/
