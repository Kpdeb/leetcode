class Solution {
public:
    bool canship(vector<int>& weights, int days , int capacity ) {
        int curr =0;
        int d =1;
        for (int w:weights ){
            if (curr+w>capacity ){
                d++;
                curr =0;
            }
            curr +=w;
        }
        return d<= days ;
    }

    int shipWithinDays (vector<int>& weight ,int days ){
        int left = *max_element(weight.begin(),weight.end ()) ;
        int right =0;

        for (int w : weight)
        right +=w ;

        while (left <right ){
            int mid = left +(right -left )/2;

            if (canship (weight, days ,mid ))
            right = mid ;
            else 
            left = mid +1;
        }
        return left ;

    }
};