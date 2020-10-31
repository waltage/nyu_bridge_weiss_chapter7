/* Copyright 2020 walt@danielwalt.io
 * Author: Daniel Walt
 * NYU Email: dw2789@nyu.edu
 *
 * Weiss Figure 7.16 and 7.17
 */
#ifndef INCLUDE_QUICKSORT_717_H_
#define INCLUDE_QUICKSORT_717_H_
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <utility>

#define print(_var) std::cout << _var;
#define println(_var) std::cout << _var << std::endl;



template <typename T>
const T& median3(std::vector<T>& a, int left, int right, bool debug = false);

template <typename T>
int book_partition(std::vector<T>& a, int left, int right, bool debug = false);

template <typename T>
int corrected_partition(std::vector<T>& a, int left, int right, bool debug = false);

template <typename T>
bool check_partition(std::vector<T> invec, T checkval, bool debug = false);

std::vector<int> generate_random_list(int n, int low, int high);


template <typename T>
void print_vec(std::vector<T> invec);

#endif  // INCLUDE_QUICKSORT_717_H_


#include "quicksort_717.cpp"
