
def collatz(num):
    if num==1:
        return 1
    elif num==2:
        return 2
    else:
        count=1
        while(num!=1):
            if(num%2==0):
                num=int(num/2)
                count+=1
            else:
                num=3*num+1
                count+=1
        return count 
    
limit=1000000
largest=0
target_num=2

for n in range(3,limit):
    if(collatz(n)>largest):
        largest=collatz(n)
        target_num=n
    
print(target_num,collatz(target_num))        
           