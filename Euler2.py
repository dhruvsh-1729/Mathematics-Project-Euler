def fib(n):
    if n==0:
        return 1
    elif n==1:
        return 2
    else:
        return fib(n-1)+fib(n-2)
   
limit=4000000
sum=2
n=2
while(fib(n)<limit):
    fibo=fib(n)
    if(fibo%2==0):
        print(fibo)
        sum+=fibo
    # print(fibo)
    n+=1
    
print(sum)
    