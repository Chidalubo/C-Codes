/*The logic will be to keep 2 pointers for both the list and then transverse the list depending upon the numbers read from the list.

Pseudocode:
let the arrarys be x and y
x<-sorted array
y <- sorted array
i <- 0
j <- 0

repeat while i <length(x) and j <length(y):
if x[i]= y[j]: output x[i] and increase i and j
else if x[i] > b[j]: increase j
else: increase i

At each step, we will use i++, j++ or both. So at most, i++ m times and j++ n times. Therefore, number of comparison is <=(m+n)
Maximum will be n or m comparisons depending on which one is smaller.