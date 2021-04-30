快速排序

快速排序partition函数的思路

(1)先将A[1]存至某个临时变量temp，并令两个下标left, right分别指向序列首尾（如令left=l, right=n）。
(2)只要right指向的元素A[right]大于temp，就将right不断左移；当A[right]<=temp时，将元素A[left]挪到left指向的元素A[left]处。
(3)只要left指向的元素A[left]不超过temp，就将left不断右移；当某个时候A[left]>temp时，将元素A[left]挪到right指向的元素A[right]处。
(4)重复(2)(3)直到left与right相遇，把temp(即原A[1])放到相遇的地方
