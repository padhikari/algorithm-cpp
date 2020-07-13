#include<iostream>
#include<vector>
bool binarySearch(int target, const std::vector<int>&nums){
    size_t startIndex = 0;
    size_t endIndex = nums.size();

    while(startIndex < endIndex){
        size_t distance = endIndex - startIndex;
        size_t midIndex = startIndex + distance/2;

        int midValue = nums[midIndex];
        if(midValue == target){
            return true;
        }
        if(midValue > target){
            endIndex = midIndex;
        }
        else{
            startIndex = midIndex + 1;
        }
    }
    return false;
}

int main(){
    std::vector<int> nums {10,20,30,40,50,60,70,80};
    int target = 90;
    if(binarySearch(target,nums)){
        std::cout<<"Target is found\n";
    }
    else{
        std::cout<<"Target is not in the list\n";
    }
    return 0;
}