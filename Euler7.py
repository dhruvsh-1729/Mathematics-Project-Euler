
# limit=200

# for i in range(3,limit):
#     yes=1
#     for j in range(2,i):
#         if(i%j==0):
#             yes=0
#             break
#     if(yes):
#         print(i)    

def prime(n):
    if n==1:
        return False
    elif n==2:
        return True
    else:
        yes=1
        for i in range(2,n):
            if(n%i==0):
                yes=0
                break
        if(yes):
            return True
        else:
            return False    
target=10001    
count=1
n=3
while(count<target):
    if(prime(n)):
        count+=1
    n+=1
print(n-1,prime(n-1),count)
        
            