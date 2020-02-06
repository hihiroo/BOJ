def exGcd(a,b):
    if b == 0: return a,1,0
    gcd, x, y = exGcd(b,a%b)
    return gcd, y, x-(a//b)*y

def main():
    a,b,s = input().split()
    a = int(a)
    b = int(b)
    s = int(s)

    if a == s or b == s: return True
    elif a > s or b > s: return False
    elif a == 0 or b == 0:
        if a == 0 and b == 0: return s == 0
        elif a == 0 and s % b == 0: return True
        elif b == 0 and s % a == 0: return True
        else: return False
    else:
        gcd, x, y = exGcd(a,b)
        if s % gcd: return False
        x *= (s//gcd)
        y *= (s//gcd)
        q = b // gcd
        t = a // gcd

    for k in range(-gcd*x//b+1, gcd*y//a+1):
        if exGcd(x + k*q, y - k*t)[0] == 1:
            return True
    return False
        
    
            
if main(): print("YES")
else: print("NO")



