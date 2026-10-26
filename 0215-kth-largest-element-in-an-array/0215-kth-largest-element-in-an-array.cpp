class Solution {
public:

    void heapify(vector<int> &arr, int i, int n){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if(left < n && arr[largest] < arr[left]){
            
            largest = left;
        }
        if(right < n && arr[largest] < arr[right]){
            
            largest = right;
        }

        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr,largest,n);
        }
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();
        for(int i = n/2 - 1; i>=0; i--){
        heapify(nums,i,n);
            }

        
        
         for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, 0, i);
        }

        return nums[n-k];        
    }
};