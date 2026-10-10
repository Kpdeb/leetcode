class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int n=nums1.length;
        int diff[]=new int[n];
        int maxDiff=0;
        for(int i=0;i<n;i++){
            diff[i]=Math.abs(nums1[i]-nums2[i]);
            maxDiff=Math.max(maxDiff,diff[i]);
        }
        int countDiff[]=new int[maxDiff+1];
        for(int d:diff){
            countDiff[d]++;
        }
        int  k=k1+k2;
        for(int currDiff=maxDiff;currDiff>0 && k>0;currDiff--){
            int countOps=Math.min(countDiff[currDiff],k);
            countDiff[currDiff]-=countOps;
            countDiff[currDiff-1]+=countOps;
            k-=countOps;
        }
        long result=0;
        for(int d=1;d<=maxDiff;d++){
            result+=(long)countDiff[d]*d*d;
        }
        return result;
    }
}