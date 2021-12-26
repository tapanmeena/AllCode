from pythonds.basic.stack import Stack

def maxSum_NStack(stacks,M):
    database = []
    #sum = 0
    for i in range(M):
        toPop = 0
        for j in range(1,len(stacks)):
            if stacks[j].peek()>stacks[toPop].peek():
                toPop = j
        if i==0:
            database.append(stacks[toPop].pop())
        else:
            database.append(database[-1] + stacks[toPop].pop())
    return(database[-1])

x = [
        [30,100,10,10],
        [50,10,50,8x0],
        [10,10,1000,10]
    ]
# x = [
#     [80,80],
#     [15,50],
#     [20,10]
# ]
stacks = []
for i in range(len(x)):
    stacks.append(Stack())
    for j in range(len(x[i])):
        stacks[i].push(x[i][j])
        # print(x[i][j])
print(maxSum_NStack(stacks,2))