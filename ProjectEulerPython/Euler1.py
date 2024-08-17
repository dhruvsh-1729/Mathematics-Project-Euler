limit=10
sum=0
m,n=3,5

for i in range(1,limit):
    if(i%m==0 or i%n==0):
        sum+=i

print(sum)        