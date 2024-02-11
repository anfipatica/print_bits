# Print_bits exercise explanation:

The first exam as a student at 42 has a possible exercise called print_bits that requires certain knowledge of topics that we haven't seen in 42 so far.

It's a simple code that, from what I've heard, many people simply memorize, but I wanted to fully understand it and thought I could write here in a simple way the explanation of the code, in addition to briefly explaining 3 key concepts that are essential:

1. What binary code is and why computers use it.
2. What bitmasking is.
3. What bitwise operators are.

## What is binary code:

Binary is nothing more than a numerical system, just like the decimal system. It is characterized by being base-2:

- Binary [base-2] -> 0, 1.
- Decimal [base-10] -> 0, 1, 2, 3, 4, 5, 6, 7, 8, 9.

The decimal system is a very efficient numerical system; it allows writing very large numbers in a short, simple and effective way.

Binary, on the other hand, fundamentally resembles tally mark: While with the decimal system a single position can have up to 10 values, binary only has two: yes or no.

If we have two apples, we draw two marks. But what happens when we want to represent very large numbers? If we want to write the number 100, having to draw 100 marks is very inefficient. And this is where binary comes into play. Although each position can only be yes or no (1 - 0), the actual value of each position is not constantly 1 as with tally marks, rather it increases exponentially:

| Binary    | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1
| ---      | --- | --- | --- | --- | --- | --- | --- | ---

The value of all positions where there is a 1 will be added together. In this way, with only 8 positions, we can obtain any number between 0 and 255:

| Binary:    | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1
| ---      | --- | --- | --- | --- | --- | --- | --- | ---
| 1:    | 0 | 0 | 0 | 0 | 0 | 0 | 0 | **``1``**
| 2:    | 0 | 0 | 0 | 0 | 0 | 0 | **``1``** | 0
| 3:    | 0 | 0 | 0 | 0 | 0 | 0 | **``1``** | **``1``**
| 5:    | 0 | 0 | 0 | 0 | 0 | **``1``** | 0 | **``1``**
| 10:    | 0 | 0 | 0 | 0 | **``1``** | 0 | **``1``** | 0
| 15:    | 0 | 0 | 0 | 0 | **``1``** | **``1``** | **``1``** | **``1``**
| 50:    | 0 | 0 | **``1``** | **``1``** | 0 | 0 | **``1``** | 0
| 255:    | **``1``** | **``1``** | **``1``** | **``1``** | **``1``** | **``1``** | **``1``** |  **``1``** 

Computers work with microtransistors, small components that either receive a small signal (1) or do not receive it (0). Therefore, they work with binary code.


## What bitmasking and bitwise operators are

Now that we've briefly seen the basics of how binary code works, let's revisit the exercise's subject. It asks us to take a byte (a number from 0 to 255 or a corresponding character in ASCII code) and write its binary code. Since we must use write, there is no direct way to obtain the binary code.

We will use bit masking: It's a way to work with individual bits within a set of them, such as a byte. Let's say it's a filter, a sieve: A byte contains 8 bits, if we want to access the state of a single bit, we have to "filter" it.

The way to do this will depend on the operation we want to perform, that is, the bitwise operator we use. For the exercise, we will use two, one for comparison and one for movement:

- & (AND). Not to be confused with the logical operator &&. & Compares two bits, it will only return 1 if both bits are "1".
  - As for it to return 1 both bits must be 1, in our mask we will place a 1 in those positions we want to compare.

- >> (Right shift). It will shift the value one position to the right.

Taking this into account, we want to check bit by bit of our byte if the corresponding bit is a 0 or a 1, if it finds a 1, it writes "1", and if not, it writes "0".

The code would be:

```c
void	print_bits(unsigned char octet)
{
	int mask = 0b10000000;
	for (int i = 0; i <= 7; i++){
		(octet & mask ? write(1,"1",1) : write(1,"0",1));
		mask >>= 1;
	}
}
```

In each loop iteration I use a ternary conditional (a simplified version of an if else) to filter with the mask and check if *octet* contains a 1 in the position filtered by the mask, then I write the corresponding value to the screen and proceed to filter the next position, thus during the 8 "positions" of the byte.

Also, note that *mask* is written directly as binary. This can be done in C by using 0b before the binary.
  - As a curious fact, if you want to print a number using printf, you can pass it in decimal or also as binary, i.e., ```printf("%d",170);``` is the same as ```printf("%d",0b10101010);```.

I have attached a small image that I hope helps clarifying the filtering, shifting, and comparison process:

<img width=600 alt="bit masking" src="https://imgur.com/SJFTETJ.png">

So this was my explanation of the exercise. I hope it has helped you understand the meaning behind the code; it has certainly helped me to fully understand it. Good luck on the exam!
