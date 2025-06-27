#include <string>
#include <iostream>
#include <fstream>

void myReplace(const std::string &searchText, const std::string &replaceText, std::string &line) {
    size_t pos = 0;
    while ((pos = line.find(searchText, pos)) != std::string::npos) {
        size_t start = pos + searchText.length();
        std::string newString = line.substr(start, line.length());
        line = line.substr(0, pos) + replaceText + newString;
        pos += replaceText.length();
    }
}
int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <file> <search_text> <replace_text>" << std::endl;
        return 1;
    }

    std::string file = argv[1];
    std::string searchText = argv[2];
    std::string replaceText = argv[3];

    if (file.empty() || searchText.empty() || replaceText.empty()) {
        std::cerr << "Error: Arguments must be non-empty." << std::endl;
        return 1;
    }

    std::ifstream inputFile(file.c_str());  
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << file << std::endl;
        return 1;
    }
    std::string outputFileName = file + ".replace";
    std::ofstream outputFile(outputFileName.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create output file " << outputFileName << std::endl;
        inputFile.close();
        return 1;
    }
    
    std::string line;
    while (std::getline(inputFile, line)) {
        myReplace(searchText, replaceText, line);
        outputFile << line << std::endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}