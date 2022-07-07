#include <iostream>

#include <time.h>
#include "class/Solution.cpp"

int main()
{
      Solution s;
      vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      int target = 5;
      int index = s.search(nums, target);
      cout << index << endl;
      return 0;

      // clock_t start = clock();
      // int index = s.largestIndex(nums);
      // clock_t end = clock();
      // cout << index << endl;
      // cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
      // return 0;


}


