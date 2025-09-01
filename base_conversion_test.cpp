#include "base_conversion.cpp"

int main() {
    // Test case 1
    std::string input_json1 = R"({...})"; // paste your first JSON here

    // Test case 2
    std::string input_json2 = R"({...})"; // paste your second JSON here

    std::cout << "Test Case 1:\n";
    process_json(input_json1); // You need to refactor your code to put the logic in a function

    std::cout << "\nTest Case 2:\n";
    process_json(input_json2);

    return 0;
}