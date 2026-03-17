int majorityElement(int* nums, int numsSize) {
int character =nums[0];
 int count =1;
 for (int i=1;i<numsSize;i++){
     if (nums[i]==character){
        count++;
     }
     else {
        count--;
     }
     if (count ==0){
        character =nums[i];
        count =1;
     }}
     return character ;
}