limit=900

def palindrome(num):
    n=num
    temp=0
    while(n>0):
        temp=(temp*10)+(n%10)
        # print(temp)
        n=int(n/10)
        # print(n)
    if temp==num:
        return True
    else:
        return False    

# print(palindrome(374))

for i in range(999,limit,-1):
    yes=0
    for j in range(998,limit,-1):
        if(i%11==0 or j%11==0):
            num=i*j
            if(palindrome(num)):
                print(num,i,j)
                yes=1
                break
    if(yes):
        break        