#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

const uint16_t NUM_ARG = 3;
const std::string INPUT_FILE = "input.txt";
const std::string REPORT_FILE = "report.txt";

bool checkingExtArg(const int, const char **);
std::vector<std::string> readContent();
std::map<std::string, uint64_t> wordParsing(std::vector<std::string>);
bool writeReport(const std::map<std::string, uint64_t> *,
                 bool (*)(std::pair<std::string, uint64_t> &,
                          std::pair<std::string, uint64_t> &));
bool order(std::pair<std::string, uint64_t> &a,
           std::pair<std::string, uint64_t> &b);

int main(const int argc, const char **argv) {
  if (!checkingExtArg(argc, argv)) {
    std::cout << "[!] Error in arguments! Program exit!" << std::endl;
    return 1;
  }

  std::vector<std::string> constent = readContent();
  if (constent.size() == 0) {
    std::string error = "[!] Error " + INPUT_FILE + " file is empty";
    std::cout << error << std::endl;
    return 1;
  }

  std::map<std::string, uint64_t> report = wordParsing(constent);
  if (report.size() == 0) {
    std::cout << "[!] Error unable to write source content 0" << std::endl;
    return 1;
  }

  if (writeReport(&report, order)) {
    std::cout << "Success, statistics collected!" << std::endl;
  }
  return 0;
}

bool checkingExtArg(const int argc, const char **argv) {
  if (argc == NUM_ARG && argv[1] == INPUT_FILE && argv[2] == REPORT_FILE) {
    return true;
  }

  return false;
}

std::vector<std::string> readContent() {
  std::vector<std::string> content;
  std::string currentLine = "";
  std::ifstream file(INPUT_FILE);

  while (std::getline(file, currentLine)) {
    content.push_back(currentLine);
  }
  file.close();

  return content;
}

std::map<std::string, uint64_t> wordParsing(std::vector<std::string> content) {
  std::map<std::string, uint64_t> report;
  std::string word;

  for (uint64_t i = 0; i < content.size(); ++i) {
    for (uint64_t j = 0; j < content[i].size(); ++j) {
      if (content[i][j] == ',' || content[i][j] == '.') {
        continue;
      }

      if (content[i][j] != ' ') {
        word.append(1, content[i][j]);
      } else {
        if (!word.empty()) {
          std::map<std::string, uint64_t>::iterator it = report.find(word);
          it != report.end() ? it->second += 1 : report[word] += 1;
          word.clear();
        }
      }
    }
  }

  return report;
}

bool writeReport(const std::map<std::string, uint64_t> *ptr,
                 bool (*cbForSort)(std::pair<std::string, uint64_t> &,
                                   std::pair<std::string, uint64_t> &)) {

  bool isWrite = false;
  std::vector<std::pair<std::string, uint64_t>> box;
  for (const std::pair<std::string, uint64_t> kv : *ptr) {
    box.push_back(kv);
  }

  std::sort(box.begin(), box.end(), cbForSort);

  std::ofstream file(REPORT_FILE);
  if (file.is_open()) {
    for (const std::pair<std::string, uint64_t> kv : box) {
      file << kv.first << ": " << kv.second << "\n";
    }
    isWrite = !isWrite;
  }
  file.close();

  return isWrite;
}

bool order(std::pair<std::string, uint64_t> &a,
           std::pair<std::string, uint64_t> &b) {
  return a.second > b.second;
}
