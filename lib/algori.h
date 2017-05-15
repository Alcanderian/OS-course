#ifndef __LIB_ALGORI_H
#define __LIB_ALGORI_H

/* Macro algorithm functions. */
#define max(a, b, c) (a) = ((b) > (c)) ? (b) : (c)
#define min(a, b, c) (a) = ((b) < (c)) ? (b) : (c)

/* Fixed point number.

     Convert n to fixed point:                     n * f
     Convert x to integer (rounding toward zero):  x / f
     Convert x to integer (rounding to nearest):   (x + f / 2) / f if x >= 0,
                                                   (x - f / 2) / f if x <= 0.
     Add x and y:                                  x + y
     Subtract y from x:                            x - y
     Add x and n:                                  x + n * f
     Subtract n from x:                            x - n * f
     Multiply x by y:                              ((int64_t) x) * y / f
     Multiply x by n:                              x * n
     Divide x by y:                                ((int64_t) x) * f / y
     Divide x by n:                                x / n

   Fixed point is implement for mlfqs, calculating LOAD_AVG and CPU_TIME. */
typedef int64_t fixed_t;
#define FP_PRECISION 16

#define fp_one (i2fp (1))
#define fp_zero (0)

#define i2fp(n) ((fixed_t)((n) << FP_PRECISION))
#define fp2i(x) ((x) >> FP_PRECISION)
#define fp_round(x) (((x) >= 0) ? (fp2i ((x) + (fp_one >> 1)))  \
                                : (fp2i ((x) - (fp_one >> 1))))

#define fp_add(x, y) ((x) + (y))
#define fp_addi(x, n) ((x) + (i2fp (n)))

#define fp_sub(x, y) ((x) - (y))
#define fp_subi(x, n) ((x) - (i2fp (n)))

#define fp_mul(x, y) (fp2i ((x) * (y)))
#define fp_muli(x, n) ((x) * (n))

#define fp_div(x, y) ((i2fp (x)) / (y))
#define fp_divi(x, n) ((x) / (n))

#endif /* lib/algori.h */
