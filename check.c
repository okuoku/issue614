#include <chibi/eval.h>

int main(int argc, char *argv[])
{
	sexp ctx;

	ctx = sexp_make_eval_context(NULL, NULL, NULL, 0, 0);

	sexp_load_standard_env(ctx, NULL, SEXP_SEVEN);
	sexp_load_standard_ports(ctx, NULL, stdin, stdout, stderr, 1);

	sexp_current_error_port(ctx);

	return 0;
}
