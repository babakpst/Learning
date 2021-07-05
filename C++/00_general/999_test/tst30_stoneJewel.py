# AMD interview

class Solution:
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        return sum([s in J for s in S])

J = "aAD"
S = "aaAzdDTAb"

AA = Solution()
print(AA.numJewelsInStones(J,S))
