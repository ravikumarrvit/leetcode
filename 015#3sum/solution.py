DEBUG = 0
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        result_set = set()
        result = []
        three_sum_map = {}
        if DEBUG:
            print("NUMS: ", nums)
        for i in range(0, len(nums)-1):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            for j in range(i+1, len(nums)):
                target = 0 - (nums[i] + nums[j])
                if three_sum_map.get(target) != None:
                    three_sum_map[target].add((i, j))
                elif not three_sum_map.get(target):
                    three_sum_map[target] = set()
                    three_sum_map[target].add((i, j))
        if DEBUG:
            print(three_sum_map)
                    
        for i in range(0, len(nums)):
            if three_sum_map.get(nums[i]):
                index_tuple_list = three_sum_map[nums[i]]
                for indices in index_tuple_list:
                    if i not in indices:
                        index1, index2 = indices
                        temp_list = [nums[i], nums[index1], nums[index2]]
                        temp_list.sort()
                        result_set.add((temp_list[0], temp_list[1], temp_list[2]))
        
        result = list(result_set)
        return result
                    
                