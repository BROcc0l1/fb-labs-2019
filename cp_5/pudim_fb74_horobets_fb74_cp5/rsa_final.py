import random  
import math 

#(x^y) % p 
def power(x, y, p): 
      
    res = 1;  
      
    x = x % p;  
    while (y > 0): 
          
        
        if (y & 1): 
            res = (res * x) % p; 
  
        
        y = y>>1; 
        x = (x * x) % p; 
      
    return res; 
  
def miillerTest(d, n): 
      
    
    a = 2 + random.randint(1, n - 4); 
  
    # a^d % n 
    x = power(a, d, n); 
  
    if (x == 1 or x == n - 1): 
        return True; 
  
    while (d != n - 1): 
        x = (x * x) % n; 
        d *= 2; 
  
        if (x == 1): 
            return False; 
        if (x == n - 1): 
            return True; 
  
    return False; 
  
def isPrime( n, k): 
      

    if (n <= 1 or n == 4): 
        return False; 
    if (n <= 3): 
        return True; 
  
    d = n - 1; 
    while (d % 2 == 0): 
        d //= 2; 
  
    for i in range(k): 
        if (miillerTest(d, n) == False): 
            return False; 
  
    return True; 

def generate_ned(bit):  
    p=q=0  
    while(not (isPrime(p,20))):
        p = random.randint(2**(bit-1), 2**bit) #75842885601676576300500163132150530865942493374981881120300052634072283878357

    while(not (isPrime(q,20))):
        q = random.randint(2**(bit-1), 2**bit) #63738451939031325961840482847016348013045118738110702785965932149633377821763
    print('p: ', p)
    print('q: ', q)   
    n = p*q
    phi_n = (p-1)*(q-1)
    e=0
    while(math.gcd(e,phi_n )!=1):
        e = random.randint(2,phi_n-1)
    def ext_euc(a, b):
        u, uu, v, vv = 1, 0, 0, 1
        while b:
            q = a // b
            a, b = b, a % b
            u, uu = uu, u - uu*q
            v, vv = vv, v - vv*q
        return (u, v, a)

    def inverse(a, n):
        '''
        a - число
        n - модуль
        '''
        u, v, a = ext_euc(a, n)
        if a == 1:
            return (u%n)
        else:
            return False
    d = inverse(e, phi_n)
    return n, e, d

#M = random.randint(1,n-1)

def Encrypt(M,e,n):
    C = power(M, e, n)
    return C

def Decrypt(C,d,n):
    M1 = power(C, d, n)
    return M1

def Sign(M,d,n):
    S = power(M, d, n)
    return S

def Verify(M, S, e, n):
    return M == power(S, e, n)

#k = random.randint(1, n-1)
def Sendkey (n,n1,e1,d, k):
    S = power(k,d,n)
    S1 = power(S,e1,n1)
    k1 = power(k, e1, n1)
    return k1, S1

def Receivekey(k1, d1, n1, s1, e, n):
    k = power(k1,d1,n1)
    S = power(S1, d1, n1)
    if k == power(S,e,n):
        return k


n, e, d = generate_ned(256)
print(n, e, d)
M = random.randint(1,n-1)
print('Повідомлення',M)
C = Encrypt(M,e,n)
print('Шифртекст', C)
S = Sign(M,d,n)
print('Підпис' ,S)

ver =  Verify(M, S, e, n)
print(ver)

key = 6548648
n1 = int('80004DA1EB869CB642BB49266ACD89C0D9CFEDD265CFDF3503E7FD92761BF877076EBD58D7915E94EAD526AE3B62CF61C0FA911A5C1D2C783B37E059517B57AF', 16)
e1 = int('10001', 16)
k1,s1 = Sendkey (n,n1,e1,d, key)
print(hex(k1),hex(s1), hex(n))