#include "Header.h" 

#include <cassert> 

void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({ 1, 2, 3 }, min, max);
    assert(min == 1);
    assert(max == 3);
}
void test_negative() {
    double min = 0;
    double max = 0;
    find_minmax({ -1, -2, -3 }, min, max);
    assert(min == -3);
    assert(max == -1);
}

void test_same() {
    double min = 0;
    double max = 0;
    find_minmax({ 5, 5, 5 }, min, max);
    assert(min == 5);
    assert(max == 5);
}

void test_one() {
    double min = 0;
    double max = 0;
    find_minmax({ 7 }, min, max);
    assert(min == 7);
    assert(max == 7);
}

void test_empty() {
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}
void test_size() {
    bool res = 0;
    int BLOCK_WIDTH = 25;
    checking_block_width(BLOCK_WIDTH, res);
    assert(res == 1);
}

int main() {
    test_positive();
    test_negative();
    test_same();
    test_one();
    test_empty();
    test_size();
}