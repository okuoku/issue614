#include <stdio.h>
#include <chibi/eval.h>

sexp sexp_hello(sexp ctx, sexp self, sexp_sint_t n)
{
    printf("Hello, World\n");
    return SEXP_VOID;
}

void dostuff(sexp ctx) {
    sexp_gc_var1(res);
    sexp_gc_preserve1(ctx, res);

    res = sexp_eval_string(ctx, "(hello)", -1, NULL);

    if (sexp_exceptionp(res)) {
        sexp_debug(ctx, "Hello", res);
    }

    sexp_gc_release1(ctx);
}

int main(int argc, char *argv[])
{
    sexp ctx;

    ctx = sexp_make_eval_context(NULL, NULL, NULL, 0, 0);

    sexp_load_standard_env(ctx, NULL, SEXP_SEVEN);
    sexp_load_standard_ports(ctx, NULL, stdin, stdout, stderr, 1);

    sexp_define_foreign(ctx, sexp_context_env(ctx), "hello",
            0, sexp_hello);

    dostuff(ctx);

    sexp_destroy_context(ctx);

    return 0;
}

