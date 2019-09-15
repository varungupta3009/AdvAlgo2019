#include "../src/dynamic_array_implementation.cpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_COLORS_WINDOWS
#include "doctest.h"

TEST_CASE("Initialization")
{
    dynamic_array_implementation test_dynamic_array;
    CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
}

TEST_CASE("Insert")
{
    dynamic_array_implementation test_dynamic_array;
    test_dynamic_array.append(5);
    CHECK(test_dynamic_array.get_size() == 1);
    CHECK(test_dynamic_array.get_capacity() == 1);
    CHECK(test_dynamic_array.get(0) == 5);
}

TEST_CASE("Delete")
{
    dynamic_array_implementation test_dynamic_array;
    test_dynamic_array.append(5);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
}

TEST_CASE("Append")
{
    dynamic_array_implementation test_dynamic_array;
    CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
    test_dynamic_array.append(5);
    CHECK(test_dynamic_array.get_size() == 1);
    CHECK(test_dynamic_array.get_capacity() == 1);
    test_dynamic_array.append(10);
    CHECK(test_dynamic_array.get_size() == 2);
    CHECK(test_dynamic_array.get_capacity() == 2);
    test_dynamic_array.append(15);
    CHECK(test_dynamic_array.get_size() == 3);
    CHECK(test_dynamic_array.get_capacity() == 4);
    test_dynamic_array.append(20);
    CHECK(test_dynamic_array.get_size() == 4);
    CHECK(test_dynamic_array.get_capacity() == 4);
    test_dynamic_array.append(25);
    CHECK(test_dynamic_array.get_size() == 5);
    CHECK(test_dynamic_array.get_capacity() == 8);
    test_dynamic_array.append(30);
    CHECK(test_dynamic_array.get_size() == 6);
    CHECK(test_dynamic_array.get_capacity() == 8);
    test_dynamic_array.append(35);
    CHECK(test_dynamic_array.get_size() == 7);
    CHECK(test_dynamic_array.get_capacity() == 8);
    test_dynamic_array.append(40);
    CHECK(test_dynamic_array.get_size() == 8);
    CHECK(test_dynamic_array.get_capacity() == 8);
    test_dynamic_array.append(45);
    CHECK(test_dynamic_array.get_size() == 9);
    CHECK(test_dynamic_array.get_capacity() == 16);
    CHECK(test_dynamic_array.get(0) == 5);
    CHECK(test_dynamic_array.get(1) == 10);
    CHECK(test_dynamic_array.get(2) == 15);
    CHECK(test_dynamic_array.get(3) == 20);
    CHECK(test_dynamic_array.get(4) == 25);
    CHECK(test_dynamic_array.get(5) == 30);
    CHECK(test_dynamic_array.get(6) == 35);
    CHECK(test_dynamic_array.get(7) == 40);
    CHECK(test_dynamic_array.get(8) == 45);
}

TEST_CASE("Pop")
{
    dynamic_array_implementation test_dynamic_array;
    CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
    test_dynamic_array.append(5);
    CHECK(test_dynamic_array.get_size() == 1);
    CHECK(test_dynamic_array.get_capacity() == 1);
    test_dynamic_array.append(10);
    CHECK(test_dynamic_array.get_size() == 2);
    CHECK(test_dynamic_array.get_capacity() == 2);
    test_dynamic_array.append(15);
    CHECK(test_dynamic_array.get_size() == 3);
    CHECK(test_dynamic_array.get_capacity() == 4);
    test_dynamic_array.append(20);
    CHECK(test_dynamic_array.get_size() == 4);
    CHECK(test_dynamic_array.get_capacity() == 4);
    test_dynamic_array.append(25);
    CHECK(test_dynamic_array.get_size() == 5);
    CHECK(test_dynamic_array.get_capacity() == 8);
    test_dynamic_array.append(30);
    CHECK(test_dynamic_array.get_size() == 6);
    CHECK(test_dynamic_array.get_capacity() == 8);
    test_dynamic_array.append(35);
    CHECK(test_dynamic_array.get_size() == 7);
    CHECK(test_dynamic_array.get_capacity() == 8);
    test_dynamic_array.append(40);
    CHECK(test_dynamic_array.get_size() == 8);
    CHECK(test_dynamic_array.get_capacity() == 8);
    test_dynamic_array.append(45);
    CHECK(test_dynamic_array.get_size() == 9);
    CHECK(test_dynamic_array.get_capacity() == 16);
    CHECK(test_dynamic_array.get(0) == 5);
    CHECK(test_dynamic_array.get(1) == 10);
    CHECK(test_dynamic_array.get(2) == 15);
    CHECK(test_dynamic_array.get(3) == 20);
    CHECK(test_dynamic_array.get(4) == 25);
    CHECK(test_dynamic_array.get(5) == 30);
    CHECK(test_dynamic_array.get(6) == 35);
    CHECK(test_dynamic_array.get(7) == 40);
    CHECK(test_dynamic_array.get(8) == 45);

    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 8);
    CHECK(test_dynamic_array.get_capacity() == 16);
    CHECK(test_dynamic_array.get(7) == 40);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 7);
    CHECK(test_dynamic_array.get_capacity() == 16);
    CHECK(test_dynamic_array.get(6) == 35);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 6);
    CHECK(test_dynamic_array.get_capacity() == 16);
    CHECK(test_dynamic_array.get(5) == 30);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 5);
    CHECK(test_dynamic_array.get_capacity() == 16);
    CHECK(test_dynamic_array.get(4) == 25);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 4);
    CHECK(test_dynamic_array.get_capacity() == 8);
    CHECK(test_dynamic_array.get(3) == 20);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 3);
    CHECK(test_dynamic_array.get_capacity() == 8);
    CHECK(test_dynamic_array.get(2) == 15);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 2);
    CHECK(test_dynamic_array.get_capacity() == 4);
    CHECK(test_dynamic_array.get(1) == 10);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 1);
    CHECK(test_dynamic_array.get_capacity() == 2);
    CHECK(test_dynamic_array.get(0) == 5);
}

TEST_CASE("Underflow")
{
    dynamic_array_implementation test_dynamic_array;
    CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
    test_dynamic_array.append(5);
    CHECK(test_dynamic_array.get_size() == 1);
    CHECK(test_dynamic_array.get_capacity() == 1);
    test_dynamic_array.append(10);
    CHECK(test_dynamic_array.get_size() == 2);
    CHECK(test_dynamic_array.get_capacity() == 2);
    CHECK(test_dynamic_array.get(0) == 5);
    CHECK(test_dynamic_array.get(1) == 10);

    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 1);
    CHECK(test_dynamic_array.get_capacity() == 2);
    CHECK(test_dynamic_array.get(0) == 5);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
    CHECK(test_dynamic_array.get(0) == -1);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
    CHECK(test_dynamic_array.get(0) == -1);
}

TEST_CASE("Random Access")
{
    dynamic_array_implementation test_dynamic_array;
    CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
    test_dynamic_array.append(5);
    CHECK(test_dynamic_array.get_size() == 1);
    CHECK(test_dynamic_array.get_capacity() == 1);
    test_dynamic_array.append(10);
    CHECK(test_dynamic_array.get_size() == 2);
    CHECK(test_dynamic_array.get_capacity() == 2);
    CHECK(test_dynamic_array.get(0) == 5);
    CHECK(test_dynamic_array.get(1) == 10);

    CHECK(test_dynamic_array.get(-1) == -1);
    CHECK(test_dynamic_array.get(2) == -1);
    CHECK(test_dynamic_array.get(3) == -1);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get(1) == -1);
}

TEST_CASE("Factor Change")
{
    dynamic_array_implementation test_dynamic_array;
    test_dynamic_array.set_increase_factor_table_size(3);
    test_dynamic_array.set_load_factor_reduction(0.3);

    CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
    test_dynamic_array.append(5);
    CHECK(test_dynamic_array.get_size() == 1);
    CHECK(test_dynamic_array.get_capacity() == 1);
    test_dynamic_array.append(10);
    CHECK(test_dynamic_array.get_size() == 2);
    CHECK(test_dynamic_array.get_capacity() == 3);
    test_dynamic_array.append(15);
    CHECK(test_dynamic_array.get_size() == 3);
    CHECK(test_dynamic_array.get_capacity() == 3);
    test_dynamic_array.append(20);
    CHECK(test_dynamic_array.get_size() == 4);
    CHECK(test_dynamic_array.get_capacity() == 9);
    test_dynamic_array.append(25);
    CHECK(test_dynamic_array.get_size() == 5);
    CHECK(test_dynamic_array.get_capacity() == 9);
    test_dynamic_array.append(30);
    CHECK(test_dynamic_array.get_size() == 6);
    CHECK(test_dynamic_array.get_capacity() == 9);
    test_dynamic_array.append(35);
    CHECK(test_dynamic_array.get_size() == 7);
    CHECK(test_dynamic_array.get_capacity() == 9);
    test_dynamic_array.append(40);
    CHECK(test_dynamic_array.get_size() == 8);
    CHECK(test_dynamic_array.get_capacity() == 9);
    test_dynamic_array.append(45);
    CHECK(test_dynamic_array.get_size() == 9);
    CHECK(test_dynamic_array.get_capacity() == 9);
    test_dynamic_array.append(50);
    CHECK(test_dynamic_array.get_size() == 10);
    CHECK(test_dynamic_array.get_capacity() == 27);
    CHECK(test_dynamic_array.get(0) == 5);
    CHECK(test_dynamic_array.get(1) == 10);
    CHECK(test_dynamic_array.get(2) == 15);
    CHECK(test_dynamic_array.get(3) == 20);
    CHECK(test_dynamic_array.get(4) == 25);
    CHECK(test_dynamic_array.get(5) == 30);
    CHECK(test_dynamic_array.get(6) == 35);
    CHECK(test_dynamic_array.get(7) == 40);
    CHECK(test_dynamic_array.get(8) == 45);
    CHECK(test_dynamic_array.get(9) == 50);

    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 9);
    CHECK(test_dynamic_array.get_capacity() == 27);
    CHECK(test_dynamic_array.get(8) == 45);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 8);
    CHECK(test_dynamic_array.get_capacity() == 24);
    CHECK(test_dynamic_array.get(7) == 40);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 7);
    CHECK(test_dynamic_array.get_capacity() == 21);
    CHECK(test_dynamic_array.get(6) == 35);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 6);
    CHECK(test_dynamic_array.get_capacity() == 18);
    CHECK(test_dynamic_array.get(5) == 30);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 5);
    CHECK(test_dynamic_array.get_capacity() == 16);
    CHECK(test_dynamic_array.get(4) == 25);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 4);
    CHECK(test_dynamic_array.get_capacity() == 14);
    CHECK(test_dynamic_array.get(3) == 20);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 3);
    CHECK(test_dynamic_array.get_capacity() == 12);
    CHECK(test_dynamic_array.get(2) == 15);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 2);
    CHECK(test_dynamic_array.get_capacity() == 10);
    CHECK(test_dynamic_array.get(1) == 10);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 1);
    CHECK(test_dynamic_array.get_capacity() == 9);
    CHECK(test_dynamic_array.get(0) == 5);
    test_dynamic_array.pop();
    CHECK(test_dynamic_array.get_size() == 0);
    CHECK(test_dynamic_array.get_capacity() == 0);
    CHECK(test_dynamic_array.get(-1) == -1);
    CHECK(test_dynamic_array.get(0) == -1);
    CHECK(test_dynamic_array.get(9) == -1);
}