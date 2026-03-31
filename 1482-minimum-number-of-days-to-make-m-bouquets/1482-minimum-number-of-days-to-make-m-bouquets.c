int minDays(int* bloomDay, int bloomDaySize, int m, int k) {
    if ((long long )m*k>bloomDaySize )
    return -1;

    int low = bloomDay [0];
    int high = bloomDay[0];

    for (int i=1 ; i<bloomDaySize ;i++){
        if (bloomDay[i]<low )
        low = bloomDay[i];
        if (bloomDay[i]>high )
        high = bloomDay[i];

    }
    int ans =-1;

    while (low <=high ){
        int mid = low +(high-low )/2;

        int bouquets=0;
        int flowers =0;

        for (int i=0;i< bloomDaySize ;i++){
            if (bloomDay[i]<=mid){
                flowers++;
                if (flowers ==k){
                    bouquets++;
                    flowers =0;
                }
            }else {
                flowers = 0;
            }
        }

        if (bouquets >=m){
            ans =mid ;
            high =mid -1 ;
        
        }else {
            low = mid +1;
        }
    }
    return ans ;

}//done 