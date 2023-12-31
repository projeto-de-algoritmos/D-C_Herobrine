#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  struct elem {
    int pos;
    int val;
    bool operator< (const elem & right) const {
      return val < right.val;
    }
  };

  int exoteric_select(vector<elem> elems, int l, int r) {
    if (l == r) return l;
    else {
      vector<elem> medians;
      int i = l;

      for (; i <= r; i += 5) {
        if (i + 4 <= r) {
          sort(&elems[i], &elems[i+4]);
          medians.push_back(elems[i+2]);
        }
      }

      if (medians.size() >= 2) return exoteric_select(medians, 0, (int)medians.size() - 1);
      else if (medians.size() == 1) {
        return medians[0].pos;
      }
      else {
        sort(&elems[l], &elems[r]);
        return elems[(r + l) / 2].pos;
      }
    }
  }

  int select(vector<elem>& nums, int pivot, int l, int r){
    if (l == r) return l;

    int k = nums[pivot].val;
    swap(nums[pivot].pos, nums[r].pos);
    swap(nums[pivot], nums[r]);
    int i = l - 1;

    for(int j = l; j <= r - 1; ++j) {
      if (nums[j].val > k) {
        swap(nums[++i], nums[j]);
        swap(nums[i].pos, nums[j].pos);
      }
    }

    swap(nums[i+1].pos, nums[r].pos);
    swap(nums[i+1], nums[r]);
    return i+1;
  }

  int quick_select(vector<elem>& nums, int k, int l, int r) {
    if (l < r) {
      int pivot = exoteric_select(nums, l, r); 
      

      int pos = select(nums, pivot, l, r);


      if (pos == k) return nums[pos].val;
      else if (pos > k)return quick_select(nums, k, l, pos  - 1);
      else return quick_select(nums, k, pos + 1, r);
    } else {
      return nums[l].val;
    }
  }

  int findKthLargest(vector<int>& nums, int k) {
    vector<elem> elems(nums.size());
    for (int i = 0; i < (int) nums.size(); ++i) {
      elems[i].pos = i;
      elems[i].val = nums[i];
    }
     return quick_select(elems, k - 1, 0, (int) nums.size() - 1);
  }
};

int main(){

  vector<int> result;
  int k,aux;
  cin >> k;
  while(cin >> aux){
    result.push_back(aux);
  }

  Solution solution;
  cout << solution.findKthLargest(result,k) << endl;
}