class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_num = matrix.size(), col_num;
    	int begin = 0, end;
    	
    	if (row_num == 0)
    	    return false;
    	
    	col_num = matrix[0].size(), end = row_num * col_num - 1;
    	
    	while(begin <= end){
    		int mid = (begin + end) / 2;
    		int mid_value = matrix[mid/col_num][mid%col_num];
    		
    		if( mid_value == target){
    			return true;
    		
    		}else if(mid_value < target){
    			//Should move a bit further, otherwise dead loop.
    			begin = mid+1;
    		}else{
    			end = mid-1;
    		}
    	}
    	
    	return false;
    }
};