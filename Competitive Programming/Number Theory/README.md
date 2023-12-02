## Modular Arithmetic

- (a+b) % M = ((a % M) + (b % M)) % M
- (a*b) % M = ((a % M) * (b % M)) % M
- (a-b) % M = ((a % M) - (b % M) + M) % M
- (a/b) % M = ((a % M) * ((b^-1) % M)) % M

#### NOTE: The result of ( a % b ) will always be less than b.


## Binary Numbers and Bits

- Every Even decimal number has 0 as its LSB in the binary representation
- Every Odd decimal number has 1 as its LSB in the binary representation
- For **4 bits**, the Maximum number that can be stored is: **2^4 - 1** = 15
- Therefore, the **32bits** (4 bytes) Integer can store the Maximum value of **2^32 - 1** *(if unsigned int)*
- 1<<0 = 1, 1<<1 = 10 (2), 1<<2 = 100 (4)

#### Left Shift : x<<n = x*(2^n), Right Shift : x>>n = x/(2^n)

### Set, Unset, Count Bits
- The bit count starts with 0 to n-th Bit for any binary number from Right to Left counting
- Set - when the bit is 1
- Unset - when the bit is 0
- Any number just before a power-of-2 has its binary representation as all bits being Set(1)
    * Example: 11 (3 = 2^1-1), 111 (7 = 2^3-1), 1111 (15 = 2^4-1)
- The changing of a 0 bit to 1 or of a 1 bit to 0, is often represented with a tilde (~)

* **To check if i-th Bit of a number is Set or Not**:
    1. Take a binary number with only its i-th Bit being Set(1)
    2. Do AND(&) operation with the given number
    3. If the result is 0, then the i-th Bit of the number is Unset(0), otherwise it is Set(1)
    - *Example*: To check 2nd Bit of 9(1001), we take binary 100(by 1<<2) and doing AND(&) between them will result in 0000, so it indicates the 2nd Bit of 9 is Unset.

* **To Set any i-th Bit of a number**:
    1. Take a binary number with only its i-th Bit being Set(1)
    2. Do OR(|) operartion with the given number to Set that Bit value to 1
    - *Example*: To Set 2nd Bit of 9(1001), we take binary 100(by 1<<2) and doing OR(|) between them will result in 1101; hence the 2nd Bit becomes 1(Set).

* **To Unset the i-th Bit of a number**:
    1. Take a binary number with only its i-th Bit being Unset(0)
    2. Do AND(&) operation with the given number to Unset that Bit value to 0 

* **To Toggle the i-th Bit of a number**:
    1. Take a binary number with only its i-th Bit being Set(1)
    2. Do XOR(^) operation with the given number to Togale that Bit value from 0 to 1 or 1 to 0 [as, 1^1 = 0, 0^1 = 1]


* **To Count no. of Set Bits present in a number**:
    1. For every bit, AND(&) the number with a binary of the particular bit being 1(Set)
    2. If that results a 0, then don't count. Otherwise, count that as Set(1) Bit. [Because, only 1&1 == 1]
    3. Repeat the steps from the number of bits of an Integer (31-signedInt or 32-unsignedInt) till 0-bit
    
- **__builtin_popcount()** *function* can also be used to count the no. of Set Bits present in a number (Int). Otherwise for long integer value, you can use **__builtin_popcountll()**
