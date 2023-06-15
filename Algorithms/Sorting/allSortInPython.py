def quickSort(nums):
    if len(nums) <= 1:
        return nums
    pivot = nums[0]
    left = [x for x in nums[1:] if x < pivot]
    right = [x for x in nums[1:] if x >= pivot]
    return quickSort(left) + [pivot] + quickSort(right)


def mergeSort(nums):
    if len(nums)<=1:
        return
    mid=(len(nums))//2
    left=nums[:mid]
    right=nums[mid:]
    mergeSort(left)
    mergeSort(right)
    l=r=cur=0
    while True:
        if l>=len(left):
            nums[cur:]=right[r:]
            break
        if r>=len(right):
            nums[cur:]=left[l:]
            break
        if left[l]<right[r]:
            nums[cur]=left[l]
            l+=1
        else:
            nums[cur]=right[r]
            r+=1
        cur+=1

def bubbleSort(nums):
    N=len(nums)
    for i in range(N):
        for j in range(N-i-1):
            if nums[j]>nums[j+1]:
                nums[j],nums[j+1]=nums[j+1],nums[j]

def selectionSort(nums):
    N=len(nums)
    for i in range(N):
        for j in range(i+1,N):
            if nums[i]>nums[j]:
                nums[i],nums[j]=nums[j],nums[i]

def insertionSort(nums):
    N=len(nums)
    for i in range(N):
        j=i-1
        key=nums[i]
        while j>=0 and nums[j]>key:
            nums[j+1]=nums[j]
            j-=1
        nums[j+1]=key


nums=[5, 3, 8, 6, 7, 2]
insertionSort(nums)
print(nums)