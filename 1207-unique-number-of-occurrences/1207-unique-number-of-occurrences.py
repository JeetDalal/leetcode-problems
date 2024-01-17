class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        m = {}
        for number in arr:
            if number in m.keys():
                m[number] += 1
            else:
                m[number] = 1
        mylist = list(m.values())
        return len(mylist) == len(set(mylist))
        