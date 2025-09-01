#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
#include <cctype>
#include "json.hpp"  // Include nlohmann/json header

using json = nlohmann::json;

// Convert a single digit character to its numeric value
int charToDigit(char c) {
    if (isdigit(c)) return c - '0';
    else if (isalpha(c)) return std::tolower(c) - 'a' + 10;
    else throw std::invalid_argument("Invalid digit character");
}

// Convert a string in given base to decimal integer (using long long)
long long baseToDecimal(const std::string& value, int base) {
    long long result = 0;
    for (char c : value) {
        int digit = charToDigit(c);
        if (digit >= base) {
            throw std::invalid_argument("Digit out of base range");
        }
        result = result * base + digit;
    }
    return result;
}

int main() {
    // Example JSON input as string
    std::string input_json = R"({
        "keys": { "n": 4, "k": 3 },
        "1": { "base": "10", "value": "4" },
        "2": { "base": "2", "value": "111" },
        "3": { "base": "10", "value": "12" },
        "6": { "base": "4", "value": "213" }
    })";

    // Parse JSON
    json j = json::parse(input_json);

    int n = j["keys"]["n"];
    int k = j["keys"]["k"];

    std::cout << "Number of roots (n): " << n << std::endl;
    std::cout << "Minimum roots required (k): " << k << std::endl;

    // Iterate through keys in JSON
    for (auto it = j.begin(); it != j.end(); ++it) {
        std::string key = it.key();
        if (key == "keys") continue;  // skip keys object

        // Parse base and value
        int base = std::stoi(it.value()["base"].get<std::string>());
        std::string value = it.value()["value"];

        try {
            long long decimal_value = baseToDecimal(value, base);
            std::cout << "Root " << key << " in decimal: " << decimal_value << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error parsing root " << key << ": " << e.what() << std::endl;
        }
    }

    return 0;
}