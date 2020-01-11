import secrets
import random
import math

def generate_random_num(bit_len):
    random_num = secrets.randbits(bit_len) #generate random int of length bit_len bits
    random_num |= 1 << (bit_len - 1)
    return random_num
    
def egcd(a, b):
    '''ax + by = g = gcd(a, b)
       returns (g, x, y)'''
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)
def modinv(a, n):
    '''Finding inverse of a mod n'''
    g, x, y = egcd(a, n)
    if abs(g) != 1:
        raise ModuloError("Inverse doesn't exist")
    else:
        return x % n


def power(x, y, p): 
    
    res = 1;  
    x = x % p;  
    while (y > 0):  
        if (y & 1): 
            res = (res * x) % p; 
 
        y = y>>1; # y = y/2 
        x = (x * x) % p; 
      
    return res; 

def miillerTest(d, n): 
       
    a = 2 + random.randint(1, n - 4); 
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
      
    # Corner cases 
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
k = 128;  
def generate_prime(bit_leng):
    
    #print(random_num)
    t = 0 
    while t < 1:
        random_num = generate_random_num(bit_leng)
        if isPrime(random_num, k)==True:
            t+=1
    return random_num


def generate_key(length):
    prim1 = generate_prime(256)
    prim2 = generate_prime(256)
    n1 = prim1*prim2
    fn = (prim1-1)*(prim2-1)
    e = 65537
    d = egcd(e, fn)[1]
    d = d%fn
    #print('d = ' + str(d%fn) + ' e = ' + str(e) + ' n1 = ' + str(n1) + ' fn = ' + str(fn))
    return e,n1,d,fn

e,n1,d,fn = generate_key(64)

print(e)
#e = 65537
#d = 2655813927330309302132254585891751382684779507803837569351113908673073032278533655883331021053367768293434937900518320652606838272056980974273241831798273
#n = 'b812ff855396cbb1bc8cebb08e17ad5b17deae8f2605b6fbd633120aabc5a7839be5c911cab7ef440dd94a137873d8fd5c9ccb40fcde040d1fb3ca53b9f5ac47'
nn=hex(n1)
print(nn)
m=123
def encrypt(m,e,n1):
    c = (m**e)%n1
    print ('c = ' + hex(c))
    return c
c = encrypt(123,e,n1)   

def decrypt(d,c1,n1):
    d1 = d%fn
    m = c1**d1%n1
    print ('m = ' + str(m))
    return m
    
m = decrypt(d,c,n1)

def sign(m,d,n1):
    d1=d%fn
    s = (m**d1)%n1
    return s
    
s = sign(m,d,n1) 
  
def verify(s,e,n1):
    m11=(s**e)%n1
    if m11 == m:     
        return True
    else:
        return False
        
verifying = verify(s,e,n1)
print(verifying)
def sendKey2(k, e1, n, d, n1):
    k1 = (k**e1)%n1
    s=(k**d)%n
    s1=(s**e1)%n1
    return hex(k1),hex(s1),k1,s1
    
sendKey2(123,e,int(AADA3F0F4B77BA7E9D4AF0CAE7BAD0FA0E217ACAD87A64A8CAD602AC59986665E3CD6EA7BE62DC77EE031173E862F06183A75A037D156839D923CB8AE3ECD8F1,16),d, n1)

def recieveKey(k1,s1,d1,n1,e,n):
	k = k1**s1%n1
	s=s1**d1%n1
	if k == s**e%n:
        return True

#print(sendKey2(123, 65537, int("AADA3F0F4B77BA7E9D4AF0CAE7BAD0FA0E217ACAD87A64A8CAD602AC59986665E3CD6EA7BE62DC77EE031173E862F06183A75A037D156839D923CB8AE3ECD8F1",16), d, int(n,16)))
