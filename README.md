# DHKE_BruteForcer

This tool is used to uncover the secret number (s) chosen by Alice or Bob in Diffie-Hellman key exchange protocol by brute forcing all possible (s) candidates from 0 to infinite. The script stops running when the valid candidate (s) is found that satisfies g^s MOD p = A where (g), (p) and (A) are public information.  

I wrote this tool in C language and realized that the modulo operator % in C is only for integers. Unfortunately integer in C is a data type that only holds 32 bits, hence the integer data type quickly runs out of capacity in a brute force attack like this when g^s grows exponentially larger. I circumvented this issue by using the double data type and instead of using modulo operator %, I decided to compare the decimal remainders of A / p and g^s MOD p to see whether they match. Matching decimal remainders means that the secret number (s) has been found.

Arguments explained:

1. argv[1]: Generator (g).
2. argv[2]: Primitive (p).
3. argv[3]: Calulated public number (A) exchanged from Alice to Bob or vice versa.
4. argv[4]: How many decimals should be compared between the A / p and g^s MOD p remainders? This is the sensitivity of the remainder comparison. One way to find this parameter is by using a calculator to calculate A / p and check how many decimals the solution has. 

This tool only utilizes C standard library. 
