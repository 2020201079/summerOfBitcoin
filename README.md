# summerOfBitcoin

Solution approach (greedy)

 - Select the transactions with highest value of fee/weight
 - Check if the selected transaction is valid. That is all its parents are already included in the block. For this purpose using a set.
 - If the transaction is valid include the transaction and update fee and weight and erase it from curr set. If it is not valid go to next highest transaction.
 - For getting the highest value of fee/weight use a set. (implementing a heap using set)
 
