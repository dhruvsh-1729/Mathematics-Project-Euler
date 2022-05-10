import math as m
limit=2000000
sum=2

for i in range(3,limit):
    yes=1
    for j in range(2,int(m.sqrt(i))+1):
        if(i%j==0):
            yes=0
            break
    if(yes):
        sum+=i
        
print(sum)            
