import math as ma
import numpy as np
target=40
m=2
while(True):
    n=int(((target/2)/m)-m)
    if(n>0):
        a=np.abs(m**2-n**2)
        b=2*m*n
        c=m**2+n**2
        if(a**2+b**2==c**2 and c-b==2):
            print(a,b,c,m,n)
            break
    m+=1    

    