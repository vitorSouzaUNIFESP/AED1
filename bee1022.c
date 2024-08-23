#include <stdio.h>

struct Fracao
{
    int numerador, denominador;
};

struct Fracao soma(struct Fracao f1, struct Fracao f2)
{
    struct Fracao resultado;

    resultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
    resultado.denominador = f1.denominador * f2.denominador;

    return resultado;
}

struct Fracao subtracao(struct Fracao f1, struct Fracao f2)
{
    struct Fracao resultado;

    resultado.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
    resultado.denominador = f1.denominador * f2.denominador;

    return resultado;
}

struct Fracao multiplicacao(struct Fracao f1, struct Fracao f2)
{
    struct Fracao resultado;

    resultado.numerador = f1.numerador * f2.numerador;
    resultado.denominador = f1.denominador * f2.denominador;

    return resultado;
}

struct Fracao divisao(struct Fracao f1, struct Fracao f2)
{
    struct Fracao resultado;

    resultado.numerador = f1.numerador * f2.denominador;
    resultado.denominador = f2.numerador * f1.denominador;

    return resultado;
}

int MDC(int a, int b)
{
    return (b == 0) ? a : MDC(b, a % b);
}

struct Fracao irredutivel(struct Fracao f)
{
    int mdc = (f.numerador < 0) ? MDC(-f.numerador, f.denominador) : MDC(f.numerador, f.denominador);

    f.numerador /= mdc;
    f.denominador /= mdc;

    return f;
}

int main()
{
    int quantidade;
    char operador;
    struct Fracao f1, f2, resultado;

    scanf("%d\n", &quantidade);

    for (int i = 0; i < quantidade; ++i)
    {
        scanf("%d / %d %c %d / %d\n", &f1.numerador, &f1.denominador, &operador, &f2.numerador, &f2.denominador);

        switch (operador)
        {
        case '+':
            resultado = soma(f1, f2);
            break;
        case '-':
            resultado = subtracao(f1, f2);
            break;
        case '*':
            resultado = multiplicacao(f1, f2);
            break;
        case '/':
            resultado = divisao(f1, f2);
            break;
        }

        printf("%d/%d = ", resultado.numerador, resultado.denominador);
        resultado = irredutivel(resultado);
        printf("%d/%d\n", resultado.numerador, resultado.denominador);
    }

    return 0;
}
