#Quick Sort - partitioning


[Proposed Partitioning Correction](chapter7/quicksort_717.cpp#L135)

Upon further review, it appears that the quicksort implementation in Weiss is incorrect.  
1. Pick a partition value (pivot) - OK
2. Partition the list around the pivot - BROKEN
3. Recurse on new pivots - Depends on #2, so BROKEN


## Figure 7.16 [OK]
### Code to perform median-of-three partitioning
```
1 /**  
2 * Return median of left, center, and right.  
3 * Order these and hide the pivot.  
4 */  
5 template <typename Comparable>  
6 const Comparable & median3( vector<Comparable> & a, int left, int right )  
7 {  
8   int center = ( left + right ) / 2;  
9  
10  if( a[ center ] < a[ left ] )  
11      std::swap( a[ left ], a[ center ] );  
12  if( a[ right ] < a[ left ] )  
13      std::swap( a[ left ], a[ right ] );  
14  if( a[ right ] < a[ center ] )  
15      std::swap( a[ center ], a[ right ] );  
16  
17      // Place pivot at position right - 1  
18  std::swap( a[ center ], a[ right - 1 ] );  
19  return a[ right - 1 ];  
20 }  
```
Weiss, Mark A.. Data Structures and Algorithm Analysis in C++ (2-downloads) (p. 316). Pearson Education. Kindle Edition. 

## Figure 7.17 [Partitioning is wrong]
### Main quicksort routine
```
1 /**  
2 * Internal quicksort method that makes recursive calls.  
3 * Uses median-of-three partitioning and a cutoff of 10.  
4 * a is an array of Comparable items.  
5 * left is the left-most index of the subarray.  
6 * right is the right-most index of the subarray.  
7 */  

...
13      const Comparable & pivot = median3( a, left, right );  
14  
15          // Begin partitioning  
16      int i = left, j = right - 1;  
17      for( ; ; )  
18      {  
19          while( a[ ++i ] < pivot ) { }  
20          while( pivot < a[ --j ] ) { }  
21          if( i < j )  
22              std::swap( a[ i ], a[ j ] );  
23          else  
24              break;  
25      }  
26  
27      std::swap( a[ i ], a[ right - 1 ] ); // Restore pivot  

...
```
Weiss, Mark A.. Data Structures and Algorithm Analysis in C++ (2-downloads) (p. 317). Pearson Education. Kindle Edition. 