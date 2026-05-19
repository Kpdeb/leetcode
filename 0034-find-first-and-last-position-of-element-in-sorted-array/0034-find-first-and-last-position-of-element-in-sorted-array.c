/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int findfirst(int *nums ,int target , int numsSize){
    int left =0;
    int right= numsSize-1;
    int ans =-1;
    while (left <=right  ){
        int mid = left +(right -left )/2;

        if (nums[mid]== target){
        ans = mid  ;
        right = mid -1 ;
        }
        else if 
        (nums[mid]<target ){
        left  = mid+1;
        }
        else {
        right =mid-1 ;
        }
    } 
return ans;
}

int findlast  (int*nums, int numsSize , int target ){
    int left =0;
    int right =numsSize -1 ;
    int ans =-1;

    while (left <=right ){
        int mid = left+(right -left )/2;

        if (nums[mid] == target ){
            ans= mid ;
            left = mid +1 ;
        }
        else if (nums[mid] <target ){
            left = mid+1;
        }
        else {
            right = mid -1;
        }
    }
 return ans;   
}


int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));

    result[0] = findfirst(nums, target, numsSize);
    result[1] = findlast(nums, numsSize, target);

    return result;
}