class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        m = {}
        for number in arr:
            m[number] = arr.count(number)
        mylist = list(m.values())
        return len(mylist) == len(set(mylist))
        