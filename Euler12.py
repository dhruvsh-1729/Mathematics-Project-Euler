import math as m
target=500
i=3

while(True):
    num=0
    count=2
    perf_count=0
    for a in range(1,i+1):
        num+=a
    # print(num)    
    for j in range(2,int(m.sqrt(num))+1):
        if(num%j==0 and j*j!=num):
            perf_count+=1
        if(j*j==num):
            count+=1    
    count+=2*perf_count 
    # print(count)       
    if(count>=target):
        print(num,i,count)
        break
    i+=1         