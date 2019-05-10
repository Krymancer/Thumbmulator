using namespace std;

#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <vector>

size_t split(const std::string &txt, std::vector<std::string> &strs, char ch);
bool isValidHexa(const std::string &str);

int main(const int argc, const char *argv[]) {
    ifstream input;
    std::ofstream output("code.lst");

    string line, inst1, inst2, delimiter = ":";
    size_t pos = 0;
    int i = 0;

    if (chdir("./arm-assembly") == -1) {
        return -1;
    }
    system("make");
    input.open("startup.lst");

    if (!input) {
        std::cerr << "Unable to open file" << std::endl;
        return -1;
    } else {
        while (getline(input, line)) {
            vector<std::string> buffer, instruction;
            if (i++ > 18) {
                if (line == "") {
                    break;
                }
                split(line, buffer, ' ');                                            //split the entire line in every space
                split(buffer[3], instruction, '\t');                                 //buffer[3] contains "[MEM]:    INSTRUCTION" so we remove this tab
                if (isValidHexa(instruction[1])) {                                   //Final check to only put instructions
                    output << instruction[0] << " " << instruction[1] << std::endl;  // Final format [MEM]: INSTRUCTION
                }
            }
        }
    }

    input.close();
    output.close();

    return 0;
}

size_t split(const std::string &txt, std::vector<std::string> &strs, char ch) {
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while (pos != std::string::npos) {
        strs.push_back(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;
        pos = txt.find(ch, initialPos);
    }

    // Add the last one
    strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos));

    return strs.size();
}

bool isValidHexa(const std::string &str) {
    for (size_t i = 0; i < str.length(); i++) {
        char current = str[i];
        if (current >= '0' && current <= '9') {
            continue;
        } else if (current >= 'A' && current <= 'F') {
            continue;
        } else if (current >= 'a' && current <= 'f') {
            continue;
        } else {
            return false;
        }
    }
    return true;
}