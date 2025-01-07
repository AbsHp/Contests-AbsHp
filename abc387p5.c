#include <stdio.h>
#include <gmp.h>

void digit_sum(mpz_t result, const mpz_t n)
{
    mpz_t temp, sum, digit;
    mpz_init_set(temp, n);
    mpz_init_set_ui(sum, 0);
    mpz_init(digit);
    while (mpz_cmp_ui(temp, 0) > 0)
    {
        mpz_mod_ui(digit, temp, 10);
        mpz_add(sum, sum, digit);
        mpz_div_ui(temp, temp, 10);
    }
    mpz_set(result, sum);
    mpz_clear(temp);
    mpz_clear(sum);
    mpz_clear(digit);
}

int is_good_integer(const mpz_t n)
{
    mpz_t sum, remainder;
    mpz_init(sum);
    mpz_init(remainder);
    digit_sum(sum, n);
    mpz_mod(remainder, n, sum);
    int is_good = (mpz_cmp_ui(remainder, 0) == 0);
    mpz_clear(sum);
    mpz_clear(remainder);
    return is_good;
}

int main()
{
    char input[100001];
    scanf("%s", input);
    mpz_t N, a, a_plus_1, upper_limit;
    mpz_init_set_str(N, input, 10);
    mpz_init(a);
    mpz_init(a_plus_1);
    mpz_init(upper_limit);
    mpz_set(a, N);
    mpz_mul_ui(upper_limit, N, 2);

    while (mpz_cmp(a, upper_limit) <= 0)
    {
        mpz_add_ui(a_plus_1, a, 1);
        if (is_good_integer(a) && is_good_integer(a_plus_1))
        {
            gmp_printf("%Zd, %Zd\n", a, a_plus_1);
            mpz_clear(N);
            mpz_clear(a);
            mpz_clear(a_plus_1);
            mpz_clear(upper_limit);
            return 0;
        }

        mpz_add_ui(a, a, 1);
    }

    printf("No twin good integers found.\n");
    mpz_clear(N);
    mpz_clear(a);
    mpz_clear(a_plus_1);
    mpz_clear(upper_limit);
    return 0;
}

// GMP not found