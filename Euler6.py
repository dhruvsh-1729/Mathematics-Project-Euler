limit=100

sum_of_squares=0
sum=0

for i in range(1,limit+1):
    sum_of_squares+=i*i
    sum+=i
print(sum**2-sum_of_squares)    
