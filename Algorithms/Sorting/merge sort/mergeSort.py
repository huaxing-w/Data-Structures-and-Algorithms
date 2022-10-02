def mergeSort(nums):
    if len(nums)<=1:
        return
    mid=len(nums)//2
    left=nums[:mid]
    right=nums[mid:]
    mergeSort(left)
    mergeSort(right)
    cur=i=j=0
    while True:
        if i==len(left):
            nums[cur:]=right[j:]
            break
        if j==len(right):
            nums[cur:]=left[i:]
            break
        if left[i]<right[j]:
            nums[cur]=left[i]
            i+=1
        else:
            nums[cur]=right[j]
            j+=1
        cur+=1
