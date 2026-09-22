class Solution(object):
    def buildArray(self, target, n):
      ans=[]

      for i in range (1,n+1):
        ans.append ("Push")

        if i not in target :
            ans.append ("Pop")
        
        if i == target[-1]:
            break 
      return ans 
