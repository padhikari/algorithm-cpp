#include<iostream>
#include<vector>

void printVector(std::vector<int>& nums){
    for(int i = 0; i < nums.size(); i++){
        std::cout<<nums[i]<<" ";
    }
}
void mergeSort(std::vector<int>& nums){

    //base case, fewer that 2 elements
    if(nums.size() < 2){
        return;
    }
    size_t midIndex = nums.size()/2;
    
    //creat two vectors for two half vectors
    std::vector<int> left(nums.begin(),nums.begin() + midIndex);
    std::vector<int> right(midIndex + nums.begin(), nums.end());

    //step 1: sort the vector
    mergeSort(left);
    mergeSort(right);

    //step 2: merge two vectors
    size_t leftIndex = 0;
    size_t rightIndex = 0;
    
    for(size_t currentIndex = 0; currentIndex < nums.size(); ++currentIndex){
        if(leftIndex < left.size() 
        && (rightIndex >= right.size()
        || left[leftIndex] < right[rightIndex])){
            nums[currentIndex] = left[leftIndex];
            leftIndex++;
        }
        else{
            nums[currentIndex] = right[rightIndex];
            rightIndex++;
        }
    }  
}

int main(){
    std::vector<int>nums {12,17,10,3,7,19,1,120};
    mergeSort(nums);
    printVector(nums);
    std::cout<<"\n";
    return 0;
}
