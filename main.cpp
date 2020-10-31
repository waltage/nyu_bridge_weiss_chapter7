/* Copyright 2020 walt@danielwalt.io
 * Author: Daniel Walt
 * NYU Email: dw2789@nyu.edu
 */
#include "./chapter7/quicksort_717.h"

int main() {

    /*
     * This is an example that breaks Weiss's 7.17:
     * std::vector<int> BAD{10, 1, 1, 4, 2, 2, 4, 7, 4, 4};
     */

    int cases = 1000;
    int bad_cnt = 0;
    for (int i = 0; i < cases; ++i) {
        std::vector<int> test_case = generate_random_list(200, -50, 50);
        int partition_val = book_partition(test_case, 0, test_case.size() - 1, false);
        if (!check_partition(test_case, partition_val, false)) {
            ++bad_cnt;
        }
    }

    println("Book method:");
    println(bad_cnt << " out of " << cases << " are not partitioned correctly");



    bad_cnt = 0;
    for (int i = 0; i < cases; ++i) {
        std::vector<int> test_case = generate_random_list(200, -50, 50);
        int partition_val = corrected_partition(test_case, 0, test_case.size() - 1);
        if (!check_partition(test_case, partition_val)) {
            ++bad_cnt;
        }
    }

    print(std::endl);
    println("Corrected method:");
    println(bad_cnt << " out of " << cases << " are not partitioned correctly");


    return 0;
}
