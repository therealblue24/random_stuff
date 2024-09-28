/*
 * The following code is under the MIT license.
 *
 * MIT License
 *
 * Copyright (c) 2024 therealblue24
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <stdio.h>
#include <stdlib.h>

static const char *reduce_table[1001] = {
    [1] = "I",   [4] = "IV",   [5] = "V",    [9] = "IX",  [10] = "X",
    [40] = "XL", [50] = "L",   [90] = "XC",  [100] = "C", [400] = "CD",
    [500] = "D", [900] = "CM", [1000] = "M",
};

static const int opts[] = {
    1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000
};

int main(int argc, char *argv[])
{
    if(argc != 2) {
        fprintf(stderr, "usage: %s <integer>\n", argv[0]);
        return 1;
    }
    int num = atoi(argv[1]);
    int work = num;
    while(work) {
        int opt = 12;
        while(opts[opt] > work)
            opt--;
        printf("%s", reduce_table[opts[opt]]);
        work -= opts[opt];
    }
    putchar('\n');
    return 0;
}
