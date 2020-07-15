#include<iostream>
#include<vector>

int partition(std::vector<int>&arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            std::swap(arr[i],arr[j]);
        }
    }
    std::swap(arr[i+1],arr[high]);
    return(i+1);
}
void quickSort(std::vector<int>&arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
         std::cout<<"The pivot index is :"<<pi<<"\n";
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main(){
    std::vector<int> arr{10,40,80,90,200,15};
    int high = arr.size();
    std::cout<<"size is"<<high;
    quickSort(arr,0,high-1);
    for(int i = 0; i < arr.size(); i++)
    std::cout<<arr[i]<<"\t";
    std::cout<<"\n";
    return 0;
}