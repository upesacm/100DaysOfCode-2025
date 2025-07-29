#the bug is in line 
#while stack and prices[stack[-1]] >= prices[i]:

#answer 2
#The current condition removes prices that are greater than or equal to the current day’s price.
#This causes the algorithm to ignore previous smaller prices that should count toward the span. 

#answer 3 correct condition 
while stack and prices[stack[-1]] <= prices[i]:
#We should pop while previous prices are less than or equal to the current price, so we can count those days toward the span.

