#include <vector>
#include <iostream>

using namespace std;

void sort(vector<int> & nums);
void mergeSort(vector<int>&left,vector<int>& right,vector<int>& nums);

int main() {
    vector<int> nums;
    for (size_t i = 0; i < 11; i++)
        nums.push_back(rand() % 1000);

    sort(nums);

    for (size_t i = 0; i < nums.size(); i++)
        cout << nums[i] <<endl;
}

void mergeSort(vector<int>& nums){
        
        if (nums.size() <= 1){
            return;
        }
        
    
        int mid = nums.size() / 2;
        vector<int> left;
        vector<int> right;
        
        
        left.reserve(mid);
        right.reserve(nums.size() - mid);
        
        std::copy(std::begin(nums), std::begin(nums) + mid, std::back_inserter(left));
        std::copy(std::begin(nums) + mid, std::end(nums), std::back_inserter(right));
        
        mergeSort(left);
        mergeSort(right);
        merge(left, right, nums);
        
    }

void merge(vector<int>& left, vector<int>& right, vector<int>& nums) {

        int nL = left.size();
        int nR = right.size();
        
        int leftPointer = 0;
        int rightPointer = 0;
        int numsPointer = 0;
        
        
        while(leftPointer < nL && rightPointer < nR){
            if (left[leftPointer] <= right[rightPointer]){
                nums[numsPointer] = left[leftPointer++];
            }else{
                nums[numsPointer] = right[rightPointer++];
            }
            numsPointer++;
        }
        
        
        while(leftPointer < nL){
            nums[numsPointer++] = left[leftPointer++];     
        }
        while(rightPointer < nR){
            nums[numsPointer++] = right[rightPointer++];
        }
        
}
