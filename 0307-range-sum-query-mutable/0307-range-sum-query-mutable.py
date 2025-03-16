class SegmentTree:
    def __init__(self, nums):
        self.n = len(nums)
        self.tree = [0] * 4 * self.n
        self.buildTree(nums, 0, self.n-1, 0)

    def buildTree(self, nums, left, right, index):
        if left == right:
            self.tree[index] = nums[left]
            return

        mid = (left + right) // 2
        self.buildTree(nums, left, mid, 2 * index + 1)
        self.buildTree(nums, mid+1, right, 2 * index + 2)
        self.tree[index] = self.tree[2*index+1] + self.tree[2*index+2]

    def sumRange(self, left, right, index, qleft, qright):
        if qright < left or qleft > right:
            return 0

        if qleft <= left and right <= qright:
            return self.tree[index]

        mid = (left + right) // 2
        return self.sumRange(left, mid, 2*index+1, qleft, qright) + self.sumRange(mid+1, right, 2*index+2, qleft, qright)
    
    def update(self, left, right, index, pos, val):
        if left == right:
            self.tree[index] = val
            return

        mid = (left + right) // 2
        if pos <= mid:
            self.update(left, mid, 2*index+1, pos, val)
        else:
            self.update(mid+1, right, 2*index+2, pos, val)

        self.tree[index] = self.tree[2*index+1] + self.tree[2*index+2]


class NumArray:

    def __init__(self, nums: List[int]):
        self.segTree = SegmentTree(nums)

    def update(self, index: int, val: int) -> None:
        self.segTree.update(0, self.segTree.n-1, 0, index, val)

    def sumRange(self, left: int, right: int) -> int:
        return self.segTree.sumRange(0, self.segTree.n-1, 0, left, right)