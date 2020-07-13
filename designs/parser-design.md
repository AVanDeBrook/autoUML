# Parser Basics
* Will parse data line by line, ideally use LL(1) algorithm
* Look ahead 1, no need for back tracking
* Only has to look for function prototypes/signature, rest can be considered a garbage state

# Parser Grammar
Top-level function grammar (suited for C first, plan to be expanded to other languages in the future):
```
[static] <data-type> <name> <parameters> [ ;|{ ]
```

```
<data-type> ::= void     |
                void *   |
                int      |
                int *    |
                float    |
                float *  |
                double   |
                double * |
```

```
<name> ::= [a-zA-Z0-9_-]+
```

```
<parameters> ::= ( <T>
<T> ::= <data-type> <name> <E>
<E> ::= , | )
```
