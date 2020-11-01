/* Copyright 2020 walt@danielwalt.io
 * Author: Daniel Walt
 * NYU Email: dw2789@nyu.edu
 *
 * quicksort_717 implementations
 */
#ifndef IMPL_QUICKSORT_717_
#define IMPL_QUICKSORT_717_
#include "quicksort_717.h"

/* note that 'print()' and 'println()' are macros defined in
 * the header to assist in stdout printing
 */

template <typename T>
const T& median3(std::vector<T>& a, int left, int right, bool debug) {
    // weiss figure 7.16.
    // indented sections added for debug.
    //
    // Expected result is a list:
    // [0....m.....e]
    // reordered to
    // [l,......p,h] (where p is the middle value between 0, m, e)
    //
    // this code works as intended.

    int center = (left + right) / 2;

            if (debug) {
                print("(median3) left, center, right:\t");
                println(a[left] << "\t" << a[center] << "\t" << a[right]);
            }

    if (a[center] < a[left]) {
        std::swap(a[left], a[center]);
    }
    if (a[right] < a[left]) {
        std::swap(a[left], a[right]);
    }
    if (a[right] < a[center]) {
        std::swap(a[center], a[right]);
    }

            if (debug) {
                print("(median3) sorted l, p, r:\t\t");
                println(a[left] << "\t" << a[center] << "\t" << a[right]);
            }

    std::swap(a[center], a[right - 1]);

            if (debug) {
                println("(median3) pivot:\t\t\t\t" << a[right - 1]);
                println("(median3) reordered list [l,.....p,r]:");
                print_vec(a);
                print(std::endl);
            }

    return a[right - 1];
}

template <typename T>
int book_partition(std::vector<T>& a, int left, int right, bool debug) {
    // weiss figure 7.17.
    // implements lines 13 through 27.
    // indented sections added for debug.  added an int return value
    //   (pivot value) to assist with debugging whether the partition worked.
    //
    // Expected result is a single pass partition with items greater
    //   than the pivot value on the right side of the vector.
    //
    // this code does not work.

    const T& pivot = median3(a, left, right, debug);

            if (debug) {
                println("(partition) starting pivot:\t\t" << pivot);
            }

            // pivot is a reference that stays pointing to the
            // second-to-the last element of the list; copy it here:
            int ret_pvt = pivot;

    int i = left, j = right - 1;
    for (;;) {

            if (debug) {
                println("(partition) --inner &pvt:\t\t" << pivot);
            }

        while (a[++i] < pivot) {}
        while (pivot < a[--j]) {}
        if (i < j) {
            std::swap(a[i], a[j]);
        } else {
            break;
        }
    }
    std::swap(a[i], a[right-1]);
            if (debug) {
                println("(partition) last &pvt:\t\t\t" << pivot);
            }
    return ret_pvt;

}

template <typename T>
bool check_partition(std::vector<T> invec, T checkval, bool debug) {
    bool start_partition = false;
    bool ok = true;
    for (auto i : invec) {
        if (i < checkval) {
            if (start_partition) {
                ok = false;
            }

            if (debug) {
                print("0");
            }
        } else {
            start_partition = true;

            if (debug) {
                print("1");
            }
        }
    }
    if (debug) {
        print(std::endl);
    }
    return ok;
}


template <typename T>
int corrected_partition(std::vector<T>& a, int left, int right, bool debug) {
    // Earlier, we were given a homework assignment where we were asked to
    // describe what a mystery algorithm from Zybooks did.
    // This is what it did.

    const T& pivot = median3(a, left, right, debug);

    int pvt_ret = pivot;

    // Contrary to 7.18, we must start with i = left in case our
    // left-most item == pivot value;
    // Additionally, we do not need to move right - 2 if we use
    // a non-reference for the pivot value.
    int i = left;
    int j = right - 2;

    while (true) {
        while (a[i] < pivot) {
            ++i;
        }
        while (a[j] >= pivot) {
            --j;
        }
        if (i >= j) {
            break;
        }
        std::swap(a[i], a[j]);
        ++i;
        --j;
    }
    std::swap(a[i], a[right-1]);

    return pvt_ret;
}

std::vector<int> generate_random_list(int n, int low, int high) {
    // Helper to generate chapter7 lists.
    namespace ch = std::chrono;
    typedef std::mt19937 mt;

    std::vector<int> _return;
    _return.reserve(n);

    std::random_device rd;

    ch::seconds s = ch::duration_cast<ch::seconds>(
            ch::system_clock::now().time_since_epoch());
    ch::microseconds ms = ch::duration_cast<ch::microseconds>(
            ch::system_clock::now().time_since_epoch());

    mt::result_type seed = rd()
                           ^ (static_cast<mt::result_type>(s.count()) +
                              static_cast<mt::result_type>(ms.count()));

    mt gen(seed);
    std::uniform_int_distribution<int> distrib(low, high);

    for (int i = 0; i < n; ++i) {
        _return.push_back(distrib(gen));
    }
    return _return;
}

template <typename T>
void print_vec(typename std::vector<T> invec) {
    print("{");
    int len = invec.size();
    int cnt = 0;
    for (auto i : invec) {
        ++cnt;
        print(i);
        if (cnt != len) {
            print(", ");
        }
    }
    print("}" << std::endl);
}

#endif  // IMPL_QUICKSORT_717_
