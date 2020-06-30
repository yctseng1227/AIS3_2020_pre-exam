from pwn import *
from string import *

table = list(ascii_letters+digits+punctuation)
#flag = "AIS3{A1r1ght_U_4r3_my_3n3nnies}"
flag = "AIS3{"
flag_val = 0

while True:
    d = {}
    for i in range(10):
        max_val = 0
        target = ''
        for i in table:
            conn = remote("60.250.197.227", 11001)
            conn.recvuntil('Flag:')
            payload = flag + i
            conn.sendline(payload)
            res = int(conn.recvline().split()[-2])
            #print(res)
            if res > max_val:
                max_val = res
                target = i
            conn.close()

        if target in d:
           d[target] += 1
        else:
           d[target] = 1
    d = sorted(d.items(),key = operator.itemgetter(1),reverse = True)
    print(d)
    flag = flag + d[0][0]
    print(flag)
