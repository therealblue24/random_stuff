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
#include <string.h>
#include <ctype.h>

static const int tab[256] = { ['I'] = 1,   ['V'] = 5,   ['X'] = 10,  ['L'] = 50,
                              ['C'] = 100, ['D'] = 500, ['M'] = 1000 };

int isnumeral(char x)
{
    return isupper(x) && tab[x] > 0;
}

int main(int argc, char *argv[])
{
    if(argc != 2) {
        fprintf(stderr, "usage: %s <roman numeral>\n", argv[0]);
        return 1;
    }
    char *numeral = argv[1];
    int numeral_len = strlen(numeral);
    int res = 0;
    for(int i = 0; i < numeral_len; i++) {
        if(!isnumeral(numeral[i]))
            return 1;
        if(i == numeral_len - 1) {
            res += tab[numeral[i]];
        } else {
            char now = numeral[i];
            char ahead = numeral[i + 1];
            if(tab[ahead] > tab[now]) {
                res += tab[ahead] - tab[now];
                i++;
            } else {
                res += tab[now];
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
