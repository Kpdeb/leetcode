int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int maxcount =0;
    int count =0;
   
    for (int i = 0;i<numsSize;i++){
        if (nums[i]==1){
            count = count +1;
        }
        else {
            if (count > maxcount)
                maxcount = count;
            count = 0;
        }
    }

    if (maxcount <count ){
        maxcount = count ;
    }
    return maxcount ;
}