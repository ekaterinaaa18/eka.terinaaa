#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct TPair {
    unsigned key;
    char data[11];
};

void writeOrderedFile(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);

    TPair data[] = {
        {10, "ABCDEF1234"},
        {20, "XYZ7890123"},
        {30, "PQRST67890"},
        {40, "LMNO456789"},
        {50, "GHIJKL2345"}
    };

    for (const auto& record : data) {
        outFile.write(reinterpret_cast<const char*>(&record), sizeof(TPair));
    }

    outFile.close();
}

void writeUnorderedFile(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);

    TPair data[] = {
        {30, "PQRST67890"},
        {10, "ABCDEF1234"},
        {50, "GHIJKL2345"},
        {40, "LMNO456789"},
        {20, "XYZ7890123"}
    };

    for (const auto& record : data) {
        outFile.write(reinterpret_cast<const char*>(&record), sizeof(TPair));
    }

    outFile.close();
}

std::vector<TPair> readFromFile(const std::string& filename) {
    std::ifstream inputFile(filename, std::ios::binary);
    std::vector<TPair> records;

    TPair record;
    while (inputFile.read(reinterpret_cast<char*>(&record), sizeof(TPair))) {
        records.push_back(record);
    }

    inputFile.close();
    return records;
}

void writeToFile(const std::string& filename, const std::vector<TPair>& records) {
    std::ofstream outputFile(filename, std::ios::binary);

    for (const auto& record : records) {
        outputFile.write(reinterpret_cast<const char*>(&record), sizeof(TPair));
    }

    outputFile.close();
}


int searchRecordByKey(const std::vector<TPair>& records, unsigned targetKey) {
    for (size_t i = 0; i < records.size(); i++) {
        if (records[i].key == targetKey) {
            return i;
        }
    }
    return -1;
}
int searchRecordByKeyBinary(const std::vector<TPair>& records, unsigned targetKey) {
    int low = 0;
    int high = static_cast<int>(records.size()) - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (records[mid].key == targetKey) {
            return mid;
        }
        else if (records[mid].key < targetKey) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

void deleteRecordFromFile(std::vector<TPair>& records, unsigned targetKey, bool fileOrdered) {
    int index;
    if (fileOrdered) {
        index = searchRecordByKeyBinary(records, targetKey);
    }
    else {
        index = searchRecordByKey(records, targetKey);
    }
    

    if (index != -1) {
        records.erase(records.begin() + index);
    }
    else {
        std::cout << "Record with key " << targetKey << " not found in file." << std::endl;
    }
}

int main() {
    writeOrderedFile("ordered_file.bin");
    writeUnorderedFile("unordered_file.bin");


    std::vector<TPair> orderedRecords = readFromFile("ordered_file.bin");
    std::vector<TPair> unorderedRecords = readFromFile("unordered_file.bin");
    unsigned targetKey;
    std::cout << "Enter the key to delete: ";
    std::cin >> targetKey;

    deleteRecordFromFile(orderedRecords, targetKey, true);
    deleteRecordFromFile(unorderedRecords, targetKey, false);

    writeToFile("ordered_file.bin", orderedRecords);
    writeToFile("unordered_file.bin", unorderedRecords);

    return 0;
}

