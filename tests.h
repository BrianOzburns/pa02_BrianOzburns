// cs24, Mirza
// Brian Ozawa Burns, 05/24/2021

// contains test code for all classes and methods

#include <iostream>
#include <string>
using namespace std;

void START_TEST();
void END_TEST();

void TEST_INSERT();
void test_insert_empty();
void test_insert_min();
void test_insert_max();
void test_insert_already_existing();

void TEST_COUNTMOVIES_AND_SUMRATING();
void test_sum_empty();
void test_sum();
void test_count_empty();
void test_count();

void TEST_CONTAINS();
void test_does_not_contain();
void test_does_contain();

void TEST_GET_SUCCESSOR();
void test_no_successor();
void test_successor();
void test_successor_with_large_tree();
void test_last_is_successor();

void TEST_GET_PREDECESSOR();
void test_no_predecessor();
void test_predecessor();
void test_predecessor_with_large_tree();
void test_first_is_predecessor();

void TEST_FIND_INSTANCES_OF_PREFIX();
void test_no_instance_of_prefix();
void test_one_instance_of_prefix();
void test_multiple_instances();

void TEST_PRINT_BEST_MOVIE();
void test_no_instance_of_movie();
void test_one_instance_of_movie();
void test_multiple_movies_with_prefix();