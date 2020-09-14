/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
         
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
         /*
         Notes:
         = not(x or y)
         Return true if x and y are both false
         False otherwise
         The bitwise AND operator (&) compares each bit of the first operand to the corresponding bit of the second operand. 
         If both bits are 1, the corresponding result bit is set to 1. Otherwise, the corresponding result bit is set to 0.
         */
int bitNor(int x, int y) {
  return (~x & ~y); //returns true only when x and y are 0 (false) where the the negation changes 0->1 and 1->0
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
    int y;
    int ans;
    y = x << 16; //shift left 16 bits
    y = y >> 16; //shift right 16 bits
    ans = !(y^x); //if the number is the same, the exclusive or (^) returns 0 
  return (ans); //negation makes the same number return as true 
}
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
    int byte1 = 0x49; //                                     0100 1001
    int byte2 = byte1 << 9; //                     1001 0010 0000 0000
    int bit16 = byte1 | byte2;//                   1001 0010 0100 1001
    int bit32 = bit16 << 18;// 1001 0010 0100 1001 0000 0000 0000 0000
    int ans = bit32 | bit16;// 1001 0010 0100 1001 1001 0010 0100 1001
  return (ans);
}
/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x){
    int byte1 = 0x55; //                                     0101 0101
    int byte2 = byte1 << 8; //                     0101 0101 0101 0101
    int bit16 = byte1 | byte2;//                   0101 0101 0101 0101
    int bit32 = bit16 << 16;// 0101 0101 0101 0101 0000 0000 0000 0000
    int mask = bit32 | bit16;//0101 0101 0101 0101 0101 0101 0101 0101
    int ans = (x & mask); //mask carries all even-numbered bit values over to ans
  return !!(ans); //returns 0 if value is 0, 1 if not
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x){
    x = x << 31; //shift to the left 31 places so LSB becomes MSB
    x = x >> 31; //if 1, the one will carry over all the spots, if 0, it won't (arithmetic shift)
  return (x);
}
/* 
 * implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: implication(1,1) = 1 //returns true because y is 1
 *            implication(1,0) = 0 //returns false becase x is 1 and y isn't 1
              implication(0,1) = 1 //returns true when x is 0
              implication(0,0) = 1 //returns true when x is 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y) {
    return ((!x) | y);
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
    /*
    int x = 0x1 << 31;
    int low = x >> (31 - lowbit);
    int high = x >> (30 - highbit);
    int ans = (low ^ high);
    */
    int i, high, low, ans;
    i = ~0; //sets all bits to 1: 1111 1111 1111 1111 1111 1111 1111 1111
    high = i << highbit; //       1111 1111 1111 1111 1111 1111 1110 0000
    high = high << 1;//           1111 1111 1111 1111 1111 1111 1100 0000
    high =  ~(high);//            0000 0000 0000 0000 0000 0000 0011 1111
    low = i << lowbit;//          1111 1111 1111 1111 1111 1111 1111 1000
    ans = (high & low);//         0000 0000 0000 0000 0000 0000 0011 1000
  return (ans);
}
/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x) {    
    int threeTimes = (x+ (x << 1)); //multiply by 3 and then use pwrof2
    int whatSign = threeTimes >> 31; //all 1s if negative, 0s if positive
    int negFix = 3 & whatSign; //3 if negative, 0 if positive (moves 1s up 2 bits so shift works)
    int divByFour = ((threeTimes + negFix) >> 2); //add 3 if negative number so shift is chill
    return divByFour;
}
/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x) {
    int max = 0;
	int min = 0;
	int originalSign = 0;
	int by3Sign = 0;
	int by2Sign = 0;
	int sat = 0;
    int xby2 = 0;
    int xby3 = 0;
    int ans = 0;
    
    min = 1 << 31; //sets minimum value (equal to 0x80000000) 1000 0000 0000 0000 0000 0000 0000 0000
	max = ~min; //sets max value (equal to 0x7FFFFFFF) 0111 1111 1111 1111 1111 1111 1111 1111
    
    originalSign = x >> 31; //takes orignal sign value of x before multiplications (all 1s if neg, all 0s if pos)
	
    xby2 = (x << 1); //multiplies x by two 
	by2Sign = xby2 >> 31; //takes sign of the value of two times x (all 1s if neg, all 0s if pos)
	
    xby3 = xby2 + x; //adds x to two times x value to get three times x
	by3Sign = xby3 >> 31; //takes sign of value after multiplying by 3 (all 1s if neg, all 0s if pos)
		
	/*checks to see if any of the steps of multiplying by 3 cause an overflow*/
	sat = (by2Sign ^ by3Sign) | (originalSign ^ by3Sign); //all 0s if no sign change (no overflow), all 1s if sign change (overflow)
	//1. (xby3 & ~sat): if no saturation needed, return xby3 value (0 if overflow occured; moves to next step)
    //2. (sat & ((originalSign & min): set to min if negative overflow
    //3. (~originalSign & max))): set to max if positive overflow
	ans = (xby3 & ~sat) | (sat & ((originalSign & min) | (~originalSign & max)));
	return ans;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */

//x = 5: 0000 0000 0000 0101
//x>>16: 0000 0000 0000 0000 -> x = 5 -> 0101
//x>>8:  0000 0000 0000 0000 -> x = 5 -> 0101
//x>>4:  0000 0000 0000 0000 -> x = 5 -> 0101
//x>>2:  0000 0000 0000 0001 -> x = 4 -> 0100
//x>>1:  0000 0000 0000 0010 -> x = 6 -> 0110
//x&1:   return = 0

//x = 7: 0000 0000 0000 0111
//x>>16: 0000 0000 0000 0000 -> x = 7 -> 0111
//x>>8:  0000 0000 0000 0000 -> x = 7 -> 0111
//x>>4:  0000 0000 0000 0000 -> x = 7 -> 0111
//x>>2:  0000 0000 0000 0001 -> x = 6 -> 0110
//x>>1:  0000 0000 0000 0011 -> x = 1 -> 0001
//x&1:   return = 1

//accumulates all the bits in the original word, XOR'd together, in the least-significant bit
//given xor functions, even number of bits will cause final bit to cancel out and be 0
//odd number of bits won't cancel out and will return a value of 1
//folding in half, sees if even or odd "folds"
int bitParity(int x) {   
    x ^= (x >> 16);
    x ^= (x >> 8);
    x ^= (x >> 4);  
    x ^= (x >> 2);  
    x ^= (x >> 1);    
    return x & 1;        
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
//using a search method where you continually cut the search in half until the place of the MSB is located where log2 = place of MSB (starting with 0)
int ilog2(int x) {
    
    int ans = 0; //intialize starting point as 0 

    // if MSB is in right half, halfSearch is false (0), if in left 16 bits halfSearch is true
    int halfSearch = (!!(x>>16))<<31>>31; //all 0s if false, all 1s if true
    ans += halfSearch & 16; //out is 16 if MSB is in the left half
    x = x>>(halfSearch & 16); //shift 16 if is on left side (a is true) 

    // if MSB is in right 8 bits, halfSearch is false (0), if in left 8 bits halfSearch is true
    halfSearch = (!!(x>>8))<<31>>31; 
    ans += halfSearch & 8; 
    x = x>> (halfSearch & 8); 

    // if MSB is in right 4 bits, halfSearch is false (0), if in left 4 bits halfSearch is true
    halfSearch = (!!(x>>4))<<31>>31;   
    ans += halfSearch & 4;
    x = x>> (halfSearch & 4);
    
    // if MSB is in right 2 bits, halfSearch is false (0), if in left 2 bits halfSearch is true
    halfSearch = (!!(x>>2))<<31>>31;   
    ans += halfSearch & 2;
    x = x >> (halfSearch & 2);

   // if MSB is in right 2 bits, halfSearch is false (0), if in left 2 bits halfSearch is true
    halfSearch = (!!(x>>1))<<31>>31;   
    ans += halfSearch & 1;

  return ans;
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
//return 3*(x/4)+(3*remainder) to avoid overflow errors
//to avoid rounding towards negative infinity when right shifting negative numbers, add 3 to it if there is a remainder after division
int trueThreeFourths(int x)
{
    int xby4 = x >> 2; //divides x by 4 
    int xRem = x & 0x3; //0x3 = 0011: any value stored in last two bits is remainder of x after being divided by 4 using right shift

    int xby4mul3 = (xby4 << 1) + xby4; //multiply by 2 and add value of x for 3 * xby4

    int xSign = x >> 31; //all 0s if positive, 1s if negative 
    int xRemMul3 = (xRem << 1) + xRem; //multiplies any remainder by 3
    int remFix = (xRemMul3 + (xSign & 0x3)) >> 2; //adds 3 if negative and divides by 4
    
    //adds on remainder or negative adjuster to prevent rounding error
    return xby4mul3 + remFix; 
}

/*
 * Extra credit
 */
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 return 2;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  return 2;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  return 2;
}
