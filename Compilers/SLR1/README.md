# SLR(1)

A simple SLR1 parser.

## Development Environment

CLion 2023.1.3 Build #CL-231.9011.31, built on May 16, 2023

gcc version 12.2.0 (Debian 12.2.0-14)

cmake version 3.23.0

## Sample Input

```c
int add(int x, int y) {
    return (x + y*x*99) / 10 + 10000 - 23333 + (6666 - 9999) * 1111;
}

string qaqaq() {
    return "qaqaq";
}

string qwqwqwqwqwq(string x) {
    return x;
}

int main() {
    int a = 1;
    int b = 2;
    int c = add(a, b);
    string d = "string";
    if(a == 1) {
        a = 2;
        if(a == 2) {
            while(a == 2) {
                a = 3;
                if(a != 10) {
                    a = add(b, c);
                }
                while(a == 20) {
                    if(b != 10000) {
                        int e = add(b, c);
                    }
                    else {
                        int f = add(e, d);
                        string s = "int f = add(e, d);";
                    }
                }
            }
        }
        else {
            a = 4;
        }
    }
    else {
        a = 3;
    }
    while(b == 2) {
        b = b + 1;
    }
    if(d == "string") {
        d = "QAQ";
        string qwq = "QWQ";
    }
    string qaq = qaqaq();
    string qwq = qwqwqwqwqwq();
    return 0;
}
```

## Sample OutPut
```
Grammar: 
S: Program
V: Program FunctionDeclaration ArgumentList BlockStatement Type ArithmeticExpression BoolExpression ArithmeticOperator ComparisonOperator FunctionId ActualArgumentList 
T: identifier literal ( ) { } , ; = while if else return int string == != - + * / 
P: 
0 Program -> FunctionDeclaration 
1 FunctionDeclaration -> FunctionDeclaration FunctionDeclaration 
2 FunctionDeclaration -> Type identifier ( ) { BlockStatement } 
3 FunctionDeclaration -> Type identifier ( ArgumentList ) { BlockStatement } 
4 ArgumentList -> Type identifier 
5 ArgumentList -> Type identifier , ArgumentList 
6 FunctionId -> identifier ( ) 
7 FunctionId -> identifier ( ActualArgumentList ) 
8 ActualArgumentList -> ArithmeticExpression 
9 ActualArgumentList -> ArithmeticExpression , ActualArgumentList 
10 BlockStatement -> BlockStatement BlockStatement 
11 BlockStatement -> Type identifier ; 
12 BlockStatement -> Type identifier = ArithmeticExpression ; 
13 BlockStatement -> identifier = ArithmeticExpression ; 
14 BlockStatement -> Type identifier = FunctionId ; 
15 BlockStatement -> identifier = FunctionId ; 
16 BlockStatement -> while ( BoolExpression ) { BlockStatement } 
17 BlockStatement -> if ( BoolExpression ) { BlockStatement } 
18 BlockStatement -> if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
19 BlockStatement -> return ; 
20 BlockStatement -> return ArithmeticExpression ; 
21 Type -> int 
22 Type -> string 
23 ArithmeticExpression -> ArithmeticExpression ArithmeticOperator ArithmeticExpression 
24 ArithmeticExpression -> - ArithmeticExpression 
25 ArithmeticExpression -> ( ArithmeticExpression ) 
26 ArithmeticExpression -> identifier 
27 ArithmeticExpression -> literal 
28 BoolExpression -> ArithmeticExpression ComparisonOperator ArithmeticExpression 
29 BoolExpression -> ( BoolExpression ) 
30 ComparisonOperator -> == 
31 ComparisonOperator -> != 
32 ArithmeticOperator -> + 
33 ArithmeticOperator -> - 
34 ArithmeticOperator -> * 
35 ArithmeticOperator -> / 
FIRST set: 
FIRST["*"]: { "*" }
FIRST["+"]: { "+" }
FIRST["ArithmeticOperator"]: { "*" "+" "-" "/" }
FIRST["identifier"]: { "identifier" }
FIRST["("]: { "(" }
FIRST["return"]: { "return" }
FIRST["BoolExpression"]: { "(" "-" "identifier" "literal" }
FIRST["FunctionId"]: { "identifier" }
FIRST["BlockStatement"]: { "identifier" "if" "int" "return" "string" "while" }
FIRST["ArithmeticExpression"]: { "(" "-" "identifier" "literal" }
FIRST[")"]: { ")" }
FIRST["Type"]: { "int" "string" }
FIRST["}"]: { "}" }
FIRST["FunctionDeclaration"]: { "int" "string" }
FIRST["literal"]: { "literal" }
FIRST["ArgumentList"]: { "int" "string" }
FIRST[","]: { "," }
FIRST["="]: { "=" }
FIRST["string"]: { "string" }
FIRST["ComparisonOperator"]: { "!=" "==" }
FIRST["-"]: { "-" }
FIRST["while"]: { "while" }
FIRST[";"]: { ";" }
FIRST["if"]: { "if" }
FIRST["{"]: { "{" }
FIRST["else"]: { "else" }
FIRST["ActualArgumentList"]: { "(" "-" "identifier" "literal" }
FIRST["int"]: { "int" }
FIRST["/"]: { "/" }
FIRST["=="]: { "==" }
FIRST["Program"]: { "int" "string" }
FIRST["!="]: { "!=" }
FOLLOW set: 
FOLLOW["ComparisonOperator"]: { "(" "-" "identifier" "literal" }
FOLLOW["ActualArgumentList"]: { ")" }
FOLLOW["ArithmeticOperator"]: { "(" "-" "identifier" "literal" }
FOLLOW["BoolExpression"]: { ")" }
FOLLOW["FunctionId"]: { ";" }
FOLLOW["BlockStatement"]: { "identifier" "if" "int" "return" "string" "while" "}" }
FOLLOW["ArithmeticExpression"]: { "!=" ")" "*" "+" "," "-" "/" ";" "==" }
FOLLOW["Type"]: { "identifier" }
FOLLOW["FunctionDeclaration"]: { "$" "int" "string" }
FOLLOW["ArgumentList"]: { ")" }
FOLLOW["Program"]: { "$" }
C = {I1, I2, ..., In}: 
I0: | 0 0 | 1 0 | 2 0 | 3 0 | 21 0 | 22 0 | 36 0 | 
Program -> · FunctionDeclaration 
FunctionDeclaration -> · FunctionDeclaration FunctionDeclaration 
FunctionDeclaration -> · Type identifier ( ) { BlockStatement } 
FunctionDeclaration -> · Type identifier ( ArgumentList ) { BlockStatement } 
Type -> · int 
Type -> · string 
Program' -> · Program 
I1: | 0 1 | 1 0 | 1 1 | 2 0 | 3 0 | 21 0 | 22 0 | 
Program -> FunctionDeclaration ·
FunctionDeclaration -> · FunctionDeclaration FunctionDeclaration 
FunctionDeclaration -> FunctionDeclaration · FunctionDeclaration 
FunctionDeclaration -> · Type identifier ( ) { BlockStatement } 
FunctionDeclaration -> · Type identifier ( ArgumentList ) { BlockStatement } 
Type -> · int 
Type -> · string 
I2: | 1 0 | 1 1 | 1 2 | 2 0 | 3 0 | 21 0 | 22 0 | 
FunctionDeclaration -> · FunctionDeclaration FunctionDeclaration 
FunctionDeclaration -> FunctionDeclaration · FunctionDeclaration 
FunctionDeclaration -> FunctionDeclaration FunctionDeclaration ·
FunctionDeclaration -> · Type identifier ( ) { BlockStatement } 
FunctionDeclaration -> · Type identifier ( ArgumentList ) { BlockStatement } 
Type -> · int 
Type -> · string 
I3: | 2 1 | 3 1 | 
FunctionDeclaration -> Type · identifier ( ) { BlockStatement } 
FunctionDeclaration -> Type · identifier ( ArgumentList ) { BlockStatement } 
I4: | 2 2 | 3 2 | 
FunctionDeclaration -> Type identifier · ( ) { BlockStatement } 
FunctionDeclaration -> Type identifier · ( ArgumentList ) { BlockStatement } 
I5: | 2 3 | 3 3 | 4 0 | 5 0 | 21 0 | 22 0 | 
FunctionDeclaration -> Type identifier ( · ) { BlockStatement } 
FunctionDeclaration -> Type identifier ( · ArgumentList ) { BlockStatement } 
ArgumentList -> · Type identifier 
ArgumentList -> · Type identifier , ArgumentList 
Type -> · int 
Type -> · string 
I6: | 2 4 | 
FunctionDeclaration -> Type identifier ( ) · { BlockStatement } 
I7: | 2 5 | 10 0 | 11 0 | 12 0 | 13 0 | 14 0 | 15 0 | 16 0 | 17 0 | 18 0 | 19 0 | 20 0 | 21 0 | 22 0 | 
FunctionDeclaration -> Type identifier ( ) { · BlockStatement } 
BlockStatement -> · BlockStatement BlockStatement 
BlockStatement -> · Type identifier ; 
BlockStatement -> · Type identifier = ArithmeticExpression ; 
BlockStatement -> · identifier = ArithmeticExpression ; 
BlockStatement -> · Type identifier = FunctionId ; 
BlockStatement -> · identifier = FunctionId ; 
BlockStatement -> · while ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
BlockStatement -> · return ; 
BlockStatement -> · return ArithmeticExpression ; 
Type -> · int 
Type -> · string 
I8: | 2 6 | 10 0 | 10 1 | 11 0 | 12 0 | 13 0 | 14 0 | 15 0 | 16 0 | 17 0 | 18 0 | 19 0 | 20 0 | 21 0 | 22 0 | 
FunctionDeclaration -> Type identifier ( ) { BlockStatement · } 
BlockStatement -> · BlockStatement BlockStatement 
BlockStatement -> BlockStatement · BlockStatement 
BlockStatement -> · Type identifier ; 
BlockStatement -> · Type identifier = ArithmeticExpression ; 
BlockStatement -> · identifier = ArithmeticExpression ; 
BlockStatement -> · Type identifier = FunctionId ; 
BlockStatement -> · identifier = FunctionId ; 
BlockStatement -> · while ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
BlockStatement -> · return ; 
BlockStatement -> · return ArithmeticExpression ; 
Type -> · int 
Type -> · string 
I9: | 2 7 | 
FunctionDeclaration -> Type identifier ( ) { BlockStatement } ·
I10: | 3 4 | 
FunctionDeclaration -> Type identifier ( ArgumentList · ) { BlockStatement } 
I11: | 3 5 | 
FunctionDeclaration -> Type identifier ( ArgumentList ) · { BlockStatement } 
I12: | 3 6 | 10 0 | 11 0 | 12 0 | 13 0 | 14 0 | 15 0 | 16 0 | 17 0 | 18 0 | 19 0 | 20 0 | 21 0 | 22 0 | 
FunctionDeclaration -> Type identifier ( ArgumentList ) { · BlockStatement } 
BlockStatement -> · BlockStatement BlockStatement 
BlockStatement -> · Type identifier ; 
BlockStatement -> · Type identifier = ArithmeticExpression ; 
BlockStatement -> · identifier = ArithmeticExpression ; 
BlockStatement -> · Type identifier = FunctionId ; 
BlockStatement -> · identifier = FunctionId ; 
BlockStatement -> · while ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
BlockStatement -> · return ; 
BlockStatement -> · return ArithmeticExpression ; 
Type -> · int 
Type -> · string 
I13: | 3 7 | 10 0 | 10 1 | 11 0 | 12 0 | 13 0 | 14 0 | 15 0 | 16 0 | 17 0 | 18 0 | 19 0 | 20 0 | 21 0 | 22 0 | 
FunctionDeclaration -> Type identifier ( ArgumentList ) { BlockStatement · } 
BlockStatement -> · BlockStatement BlockStatement 
BlockStatement -> BlockStatement · BlockStatement 
BlockStatement -> · Type identifier ; 
BlockStatement -> · Type identifier = ArithmeticExpression ; 
BlockStatement -> · identifier = ArithmeticExpression ; 
BlockStatement -> · Type identifier = FunctionId ; 
BlockStatement -> · identifier = FunctionId ; 
BlockStatement -> · while ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
BlockStatement -> · return ; 
BlockStatement -> · return ArithmeticExpression ; 
Type -> · int 
Type -> · string 
I14: | 3 8 | 
FunctionDeclaration -> Type identifier ( ArgumentList ) { BlockStatement } ·
I15: | 4 0 | 5 0 | 5 3 | 21 0 | 22 0 | 
ArgumentList -> · Type identifier 
ArgumentList -> · Type identifier , ArgumentList 
ArgumentList -> Type identifier , · ArgumentList 
Type -> · int 
Type -> · string 
I16: | 4 1 | 5 1 | 
ArgumentList -> Type · identifier 
ArgumentList -> Type · identifier , ArgumentList 
I17: | 4 2 | 5 2 | 
ArgumentList -> Type identifier ·
ArgumentList -> Type identifier · , ArgumentList 
I18: | 5 4 | 
ArgumentList -> Type identifier , ArgumentList ·
I19: | 6 0 | 7 0 | 12 3 | 14 3 | 23 0 | 24 0 | 25 0 | 26 0 | 27 0 | 
FunctionId -> · identifier ( ) 
FunctionId -> · identifier ( ActualArgumentList ) 
BlockStatement -> Type identifier = · ArithmeticExpression ; 
BlockStatement -> Type identifier = · FunctionId ; 
ArithmeticExpression -> · ArithmeticExpression ArithmeticOperator ArithmeticExpression 
ArithmeticExpression -> · - ArithmeticExpression 
ArithmeticExpression -> · ( ArithmeticExpression ) 
ArithmeticExpression -> · identifier 
ArithmeticExpression -> · literal 
I20: | 6 0 | 7 0 | 13 2 | 15 2 | 23 0 | 24 0 | 25 0 | 26 0 | 27 0 | 
FunctionId -> · identifier ( ) 
FunctionId -> · identifier ( ActualArgumentList ) 
BlockStatement -> identifier = · ArithmeticExpression ; 
BlockStatement -> identifier = · FunctionId ; 
ArithmeticExpression -> · ArithmeticExpression ArithmeticOperator ArithmeticExpression 
ArithmeticExpression -> · - ArithmeticExpression 
ArithmeticExpression -> · ( ArithmeticExpression ) 
ArithmeticExpression -> · identifier 
ArithmeticExpression -> · literal 
I21: | 6 1 | 7 1 | 26 1 | 
FunctionId -> identifier · ( ) 
FunctionId -> identifier · ( ActualArgumentList ) 
ArithmeticExpression -> identifier ·
I22: | 6 2 | 7 2 | 8 0 | 9 0 | 23 0 | 24 0 | 25 0 | 26 0 | 27 0 | 
FunctionId -> identifier ( · ) 
FunctionId -> identifier ( · ActualArgumentList ) 
ActualArgumentList -> · ArithmeticExpression 
ActualArgumentList -> · ArithmeticExpression , ActualArgumentList 
ArithmeticExpression -> · ArithmeticExpression ArithmeticOperator ArithmeticExpression 
ArithmeticExpression -> · - ArithmeticExpression 
ArithmeticExpression -> · ( ArithmeticExpression ) 
ArithmeticExpression -> · identifier 
ArithmeticExpression -> · literal 
I23: | 6 3 | 
FunctionId -> identifier ( ) ·
I24: | 7 3 | 
FunctionId -> identifier ( ActualArgumentList · ) 
I25: | 7 4 | 
FunctionId -> identifier ( ActualArgumentList ) ·
I26: | 8 0 | 9 0 | 9 2 | 23 0 | 24 0 | 25 0 | 26 0 | 27 0 | 
ActualArgumentList -> · ArithmeticExpression 
ActualArgumentList -> · ArithmeticExpression , ActualArgumentList 
ActualArgumentList -> ArithmeticExpression , · ActualArgumentList 
ArithmeticExpression -> · ArithmeticExpression ArithmeticOperator ArithmeticExpression 
ArithmeticExpression -> · - ArithmeticExpression 
ArithmeticExpression -> · ( ArithmeticExpression ) 
ArithmeticExpression -> · identifier 
ArithmeticExpression -> · literal 
I27: | 8 1 | 9 1 | 23 1 | 32 0 | 33 0 | 34 0 | 35 0 | 
ActualArgumentList -> ArithmeticExpression ·
ActualArgumentList -> ArithmeticExpression · , ActualArgumentList 
ArithmeticExpression -> ArithmeticExpression · ArithmeticOperator ArithmeticExpression 
ArithmeticOperator -> · + 
ArithmeticOperator -> · - 
ArithmeticOperator -> · * 
ArithmeticOperator -> · / 
I28: | 9 3 | 
ActualArgumentList -> ArithmeticExpression , ActualArgumentList ·
I29: | 10 0 | 10 1 | 10 2 | 11 0 | 12 0 | 13 0 | 14 0 | 15 0 | 16 0 | 17 0 | 18 0 | 19 0 | 20 0 | 21 0 | 22 0 | 
BlockStatement -> · BlockStatement BlockStatement 
BlockStatement -> BlockStatement · BlockStatement 
BlockStatement -> BlockStatement BlockStatement ·
BlockStatement -> · Type identifier ; 
BlockStatement -> · Type identifier = ArithmeticExpression ; 
BlockStatement -> · identifier = ArithmeticExpression ; 
BlockStatement -> · Type identifier = FunctionId ; 
BlockStatement -> · identifier = FunctionId ; 
BlockStatement -> · while ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
BlockStatement -> · return ; 
BlockStatement -> · return ArithmeticExpression ; 
Type -> · int 
Type -> · string 
I30: | 10 0 | 10 1 | 11 0 | 12 0 | 13 0 | 14 0 | 15 0 | 16 0 | 16 6 | 17 0 | 18 0 | 19 0 | 20 0 | 21 0 | 22 0 | 
BlockStatement -> · BlockStatement BlockStatement 
BlockStatement -> BlockStatement · BlockStatement 
BlockStatement -> · Type identifier ; 
BlockStatement -> · Type identifier = ArithmeticExpression ; 
BlockStatement -> · identifier = ArithmeticExpression ; 
BlockStatement -> · Type identifier = FunctionId ; 
BlockStatement -> · identifier = FunctionId ; 
BlockStatement -> · while ( BoolExpression ) { BlockStatement } 
BlockStatement -> while ( BoolExpression ) { BlockStatement · } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
BlockStatement -> · return ; 
BlockStatement -> · return ArithmeticExpression ; 
Type -> · int 
Type -> · string 
I31: | 10 0 | 10 1 | 11 0 | 12 0 | 13 0 | 14 0 | 15 0 | 16 0 | 17 0 | 17 6 | 18 0 | 18 6 | 19 0 | 20 0 | 21 0 | 22 0 | 
BlockStatement -> · BlockStatement BlockStatement 
BlockStatement -> BlockStatement · BlockStatement 
BlockStatement -> · Type identifier ; 
BlockStatement -> · Type identifier = ArithmeticExpression ; 
BlockStatement -> · identifier = ArithmeticExpression ; 
BlockStatement -> · Type identifier = FunctionId ; 
BlockStatement -> · identifier = FunctionId ; 
BlockStatement -> · while ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } 
BlockStatement -> if ( BoolExpression ) { BlockStatement · } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
BlockStatement -> if ( BoolExpression ) { BlockStatement · } else { BlockStatement } 
BlockStatement -> · return ; 
BlockStatement -> · return ArithmeticExpression ; 
Type -> · int 
Type -> · string 
I32: | 10 0 | 10 1 | 11 0 | 12 0 | 13 0 | 14 0 | 15 0 | 16 0 | 17 0 | 18 0 | 18 10 | 19 0 | 20 0 | 21 0 | 22 0 | 
BlockStatement -> · BlockStatement BlockStatement 
BlockStatement -> BlockStatement · BlockStatement 
BlockStatement -> · Type identifier ; 
BlockStatement -> · Type identifier = ArithmeticExpression ; 
BlockStatement -> · identifier = ArithmeticExpression ; 
BlockStatement -> · Type identifier = FunctionId ; 
BlockStatement -> · identifier = FunctionId ; 
BlockStatement -> · while ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
BlockStatement -> if ( BoolExpression ) { BlockStatement } else { BlockStatement · } 
BlockStatement -> · return ; 
BlockStatement -> · return ArithmeticExpression ; 
Type -> · int 
Type -> · string 
I33: | 10 0 | 11 0 | 12 0 | 13 0 | 14 0 | 15 0 | 16 0 | 16 5 | 17 0 | 18 0 | 19 0 | 20 0 | 21 0 | 22 0 | 
BlockStatement -> · BlockStatement BlockStatement 
BlockStatement -> · Type identifier ; 
BlockStatement -> · Type identifier = ArithmeticExpression ; 
BlockStatement -> · identifier = ArithmeticExpression ; 
BlockStatement -> · Type identifier = FunctionId ; 
BlockStatement -> · identifier = FunctionId ; 
BlockStatement -> · while ( BoolExpression ) { BlockStatement } 
BlockStatement -> while ( BoolExpression ) { · BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
BlockStatement -> · return ; 
BlockStatement -> · return ArithmeticExpression ; 
Type -> · int 
Type -> · string 
I34: | 10 0 | 11 0 | 12 0 | 13 0 | 14 0 | 15 0 | 16 0 | 17 0 | 17 5 | 18 0 | 18 5 | 19 0 | 20 0 | 21 0 | 22 0 | 
BlockStatement -> · BlockStatement BlockStatement 
BlockStatement -> · Type identifier ; 
BlockStatement -> · Type identifier = ArithmeticExpression ; 
BlockStatement -> · identifier = ArithmeticExpression ; 
BlockStatement -> · Type identifier = FunctionId ; 
BlockStatement -> · identifier = FunctionId ; 
BlockStatement -> · while ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } 
BlockStatement -> if ( BoolExpression ) { · BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
BlockStatement -> if ( BoolExpression ) { · BlockStatement } else { BlockStatement } 
BlockStatement -> · return ; 
BlockStatement -> · return ArithmeticExpression ; 
Type -> · int 
Type -> · string 
I35: | 10 0 | 11 0 | 12 0 | 13 0 | 14 0 | 15 0 | 16 0 | 17 0 | 18 0 | 18 9 | 19 0 | 20 0 | 21 0 | 22 0 | 
BlockStatement -> · BlockStatement BlockStatement 
BlockStatement -> · Type identifier ; 
BlockStatement -> · Type identifier = ArithmeticExpression ; 
BlockStatement -> · identifier = ArithmeticExpression ; 
BlockStatement -> · Type identifier = FunctionId ; 
BlockStatement -> · identifier = FunctionId ; 
BlockStatement -> · while ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } 
BlockStatement -> · if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
BlockStatement -> if ( BoolExpression ) { BlockStatement } else { · BlockStatement } 
BlockStatement -> · return ; 
BlockStatement -> · return ArithmeticExpression ; 
Type -> · int 
Type -> · string 
I36: | 11 1 | 12 1 | 14 1 | 
BlockStatement -> Type · identifier ; 
BlockStatement -> Type · identifier = ArithmeticExpression ; 
BlockStatement -> Type · identifier = FunctionId ; 
I37: | 11 2 | 12 2 | 14 2 | 
BlockStatement -> Type identifier · ; 
BlockStatement -> Type identifier · = ArithmeticExpression ; 
BlockStatement -> Type identifier · = FunctionId ; 
I38: | 11 3 | 
BlockStatement -> Type identifier ; ·
I39: | 12 4 | 23 1 | 32 0 | 33 0 | 34 0 | 35 0 | 
BlockStatement -> Type identifier = ArithmeticExpression · ; 
ArithmeticExpression -> ArithmeticExpression · ArithmeticOperator ArithmeticExpression 
ArithmeticOperator -> · + 
ArithmeticOperator -> · - 
ArithmeticOperator -> · * 
ArithmeticOperator -> · / 
I40: | 12 5 | 
BlockStatement -> Type identifier = ArithmeticExpression ; ·
I41: | 13 1 | 15 1 | 
BlockStatement -> identifier · = ArithmeticExpression ; 
BlockStatement -> identifier · = FunctionId ; 
I42: | 13 3 | 23 1 | 32 0 | 33 0 | 34 0 | 35 0 | 
BlockStatement -> identifier = ArithmeticExpression · ; 
ArithmeticExpression -> ArithmeticExpression · ArithmeticOperator ArithmeticExpression 
ArithmeticOperator -> · + 
ArithmeticOperator -> · - 
ArithmeticOperator -> · * 
ArithmeticOperator -> · / 
I43: | 13 4 | 
BlockStatement -> identifier = ArithmeticExpression ; ·
I44: | 14 4 | 
BlockStatement -> Type identifier = FunctionId · ; 
I45: | 14 5 | 
BlockStatement -> Type identifier = FunctionId ; ·
I46: | 15 3 | 
BlockStatement -> identifier = FunctionId · ; 
I47: | 15 4 | 
BlockStatement -> identifier = FunctionId ; ·
I48: | 16 1 | 
BlockStatement -> while · ( BoolExpression ) { BlockStatement } 
I49: | 16 2 | 23 0 | 24 0 | 25 0 | 26 0 | 27 0 | 28 0 | 29 0 | 
BlockStatement -> while ( · BoolExpression ) { BlockStatement } 
ArithmeticExpression -> · ArithmeticExpression ArithmeticOperator ArithmeticExpression 
ArithmeticExpression -> · - ArithmeticExpression 
ArithmeticExpression -> · ( ArithmeticExpression ) 
ArithmeticExpression -> · identifier 
ArithmeticExpression -> · literal 
BoolExpression -> · ArithmeticExpression ComparisonOperator ArithmeticExpression 
BoolExpression -> · ( BoolExpression ) 
I50: | 16 3 | 
BlockStatement -> while ( BoolExpression · ) { BlockStatement } 
I51: | 16 4 | 
BlockStatement -> while ( BoolExpression ) · { BlockStatement } 
I52: | 16 7 | 
BlockStatement -> while ( BoolExpression ) { BlockStatement } ·
I53: | 17 1 | 18 1 | 
BlockStatement -> if · ( BoolExpression ) { BlockStatement } 
BlockStatement -> if · ( BoolExpression ) { BlockStatement } else { BlockStatement } 
I54: | 17 2 | 18 2 | 23 0 | 24 0 | 25 0 | 26 0 | 27 0 | 28 0 | 29 0 | 
BlockStatement -> if ( · BoolExpression ) { BlockStatement } 
BlockStatement -> if ( · BoolExpression ) { BlockStatement } else { BlockStatement } 
ArithmeticExpression -> · ArithmeticExpression ArithmeticOperator ArithmeticExpression 
ArithmeticExpression -> · - ArithmeticExpression 
ArithmeticExpression -> · ( ArithmeticExpression ) 
ArithmeticExpression -> · identifier 
ArithmeticExpression -> · literal 
BoolExpression -> · ArithmeticExpression ComparisonOperator ArithmeticExpression 
BoolExpression -> · ( BoolExpression ) 
I55: | 17 3 | 18 3 | 
BlockStatement -> if ( BoolExpression · ) { BlockStatement } 
BlockStatement -> if ( BoolExpression · ) { BlockStatement } else { BlockStatement } 
I56: | 17 4 | 18 4 | 
BlockStatement -> if ( BoolExpression ) · { BlockStatement } 
BlockStatement -> if ( BoolExpression ) · { BlockStatement } else { BlockStatement } 
I57: | 17 7 | 18 7 | 
BlockStatement -> if ( BoolExpression ) { BlockStatement } ·
BlockStatement -> if ( BoolExpression ) { BlockStatement } · else { BlockStatement } 
I58: | 18 8 | 
BlockStatement -> if ( BoolExpression ) { BlockStatement } else · { BlockStatement } 
I59: | 18 11 | 
BlockStatement -> if ( BoolExpression ) { BlockStatement } else { BlockStatement } ·
I60: | 19 1 | 20 1 | 23 0 | 24 0 | 25 0 | 26 0 | 27 0 | 
BlockStatement -> return · ; 
BlockStatement -> return · ArithmeticExpression ; 
ArithmeticExpression -> · ArithmeticExpression ArithmeticOperator ArithmeticExpression 
ArithmeticExpression -> · - ArithmeticExpression 
ArithmeticExpression -> · ( ArithmeticExpression ) 
ArithmeticExpression -> · identifier 
ArithmeticExpression -> · literal 
I61: | 19 2 | 
BlockStatement -> return ; ·
I62: | 20 2 | 23 1 | 32 0 | 33 0 | 34 0 | 35 0 | 
BlockStatement -> return ArithmeticExpression · ; 
ArithmeticExpression -> ArithmeticExpression · ArithmeticOperator ArithmeticExpression 
ArithmeticOperator -> · + 
ArithmeticOperator -> · - 
ArithmeticOperator -> · * 
ArithmeticOperator -> · / 
I63: | 20 3 | 
BlockStatement -> return ArithmeticExpression ; ·
I64: | 21 1 | 
Type -> int ·
I65: | 22 1 | 
Type -> string ·
I66: | 23 0 | 23 2 | 24 0 | 25 0 | 26 0 | 27 0 | 
ArithmeticExpression -> · ArithmeticExpression ArithmeticOperator ArithmeticExpression 
ArithmeticExpression -> ArithmeticExpression ArithmeticOperator · ArithmeticExpression 
ArithmeticExpression -> · - ArithmeticExpression 
ArithmeticExpression -> · ( ArithmeticExpression ) 
ArithmeticExpression -> · identifier 
ArithmeticExpression -> · literal 
I67: | 23 0 | 24 0 | 24 1 | 25 0 | 26 0 | 27 0 | 
ArithmeticExpression -> · ArithmeticExpression ArithmeticOperator ArithmeticExpression 
ArithmeticExpression -> · - ArithmeticExpression 
ArithmeticExpression -> - · ArithmeticExpression 
ArithmeticExpression -> · ( ArithmeticExpression ) 
ArithmeticExpression -> · identifier 
ArithmeticExpression -> · literal 
I68: | 23 0 | 24 0 | 25 0 | 25 1 | 26 0 | 27 0 | 
ArithmeticExpression -> · ArithmeticExpression ArithmeticOperator ArithmeticExpression 
ArithmeticExpression -> · - ArithmeticExpression 
ArithmeticExpression -> · ( ArithmeticExpression ) 
ArithmeticExpression -> ( · ArithmeticExpression ) 
ArithmeticExpression -> · identifier 
ArithmeticExpression -> · literal 
I69: | 23 0 | 24 0 | 25 0 | 25 1 | 26 0 | 27 0 | 28 0 | 29 0 | 29 1 | 
ArithmeticExpression -> · ArithmeticExpression ArithmeticOperator ArithmeticExpression 
ArithmeticExpression -> · - ArithmeticExpression 
ArithmeticExpression -> · ( ArithmeticExpression ) 
ArithmeticExpression -> ( · ArithmeticExpression ) 
ArithmeticExpression -> · identifier 
ArithmeticExpression -> · literal 
BoolExpression -> · ArithmeticExpression ComparisonOperator ArithmeticExpression 
BoolExpression -> · ( BoolExpression ) 
BoolExpression -> ( · BoolExpression ) 
I70: | 23 0 | 24 0 | 25 0 | 26 0 | 27 0 | 28 2 | 
ArithmeticExpression -> · ArithmeticExpression ArithmeticOperator ArithmeticExpression 
ArithmeticExpression -> · - ArithmeticExpression 
ArithmeticExpression -> · ( ArithmeticExpression ) 
ArithmeticExpression -> · identifier 
ArithmeticExpression -> · literal 
BoolExpression -> ArithmeticExpression ComparisonOperator · ArithmeticExpression 
I71: | 23 1 | 23 3 | 32 0 | 33 0 | 34 0 | 35 0 | 
ArithmeticExpression -> ArithmeticExpression · ArithmeticOperator ArithmeticExpression 
ArithmeticExpression -> ArithmeticExpression ArithmeticOperator ArithmeticExpression ·
ArithmeticOperator -> · + 
ArithmeticOperator -> · - 
ArithmeticOperator -> · * 
ArithmeticOperator -> · / 
I72: | 23 1 | 24 2 | 32 0 | 33 0 | 34 0 | 35 0 | 
ArithmeticExpression -> ArithmeticExpression · ArithmeticOperator ArithmeticExpression 
ArithmeticExpression -> - ArithmeticExpression ·
ArithmeticOperator -> · + 
ArithmeticOperator -> · - 
ArithmeticOperator -> · * 
ArithmeticOperator -> · / 
I73: | 23 1 | 25 2 | 28 1 | 30 0 | 31 0 | 32 0 | 33 0 | 34 0 | 35 0 | 
ArithmeticExpression -> ArithmeticExpression · ArithmeticOperator ArithmeticExpression 
ArithmeticExpression -> ( ArithmeticExpression · ) 
BoolExpression -> ArithmeticExpression · ComparisonOperator ArithmeticExpression 
ComparisonOperator -> · == 
ComparisonOperator -> · != 
ArithmeticOperator -> · + 
ArithmeticOperator -> · - 
ArithmeticOperator -> · * 
ArithmeticOperator -> · / 
I74: | 23 1 | 25 2 | 32 0 | 33 0 | 34 0 | 35 0 | 
ArithmeticExpression -> ArithmeticExpression · ArithmeticOperator ArithmeticExpression 
ArithmeticExpression -> ( ArithmeticExpression · ) 
ArithmeticOperator -> · + 
ArithmeticOperator -> · - 
ArithmeticOperator -> · * 
ArithmeticOperator -> · / 
I75: | 23 1 | 28 1 | 30 0 | 31 0 | 32 0 | 33 0 | 34 0 | 35 0 | 
ArithmeticExpression -> ArithmeticExpression · ArithmeticOperator ArithmeticExpression 
BoolExpression -> ArithmeticExpression · ComparisonOperator ArithmeticExpression 
ComparisonOperator -> · == 
ComparisonOperator -> · != 
ArithmeticOperator -> · + 
ArithmeticOperator -> · - 
ArithmeticOperator -> · * 
ArithmeticOperator -> · / 
I76: | 23 1 | 28 3 | 32 0 | 33 0 | 34 0 | 35 0 | 
ArithmeticExpression -> ArithmeticExpression · ArithmeticOperator ArithmeticExpression 
BoolExpression -> ArithmeticExpression ComparisonOperator ArithmeticExpression ·
ArithmeticOperator -> · + 
ArithmeticOperator -> · - 
ArithmeticOperator -> · * 
ArithmeticOperator -> · / 
I77: | 25 3 | 
ArithmeticExpression -> ( ArithmeticExpression ) ·
I78: | 26 1 | 
ArithmeticExpression -> identifier ·
I79: | 27 1 | 
ArithmeticExpression -> literal ·
I80: | 29 2 | 
BoolExpression -> ( BoolExpression · ) 
I81: | 29 3 | 
BoolExpression -> ( BoolExpression ) ·
I82: | 30 1 | 
ComparisonOperator -> == ·
I83: | 31 1 | 
ComparisonOperator -> != ·
I84: | 32 1 | 
ArithmeticOperator -> + ·
I85: | 33 1 | 
ArithmeticOperator -> - ·
I86: | 34 1 | 
ArithmeticOperator -> * ·
I87: | 35 1 | 
ArithmeticOperator -> / ·
I88: | 36 1 | 
Program' -> Program ·
GOTO: 
#    Program             FunctionDeclaration ArgumentList        BlockStatement      Type                ArithmeticExpressionBoolExpression      ArithmeticOperator  ComparisonOperator  FunctionId          ActualArgumentList  
0    88                  1                                                           3                                                                                                                                           
1                        2                                                           3                                                                                                                                           
2                        2                                                           3                                                                                                                                           
3                                                                                                                                                                                                                                
4                                                                                                                                                                                                                                
5                                            10                                      16                                                                                                                                          
6                                                                                                                                                                                                                                
7                                                                8                   36                                                                                                                                          
8                                                                29                  36                                                                                                                                          
9                                                                                                                                                                                                                                
10                                                                                                                                                                                                                               
11                                                                                                                                                                                                                               
12                                                               13                  36                                                                                                                                          
13                                                               29                  36                                                                                                                                          
14                                                                                                                                                                                                                               
15                                           18                                      16                                                                                                                                          
16                                                                                                                                                                                                                               
17                                                                                                                                                                                                                               
18                                                                                                                                                                                                                               
19                                                                                                       39                                                                              44                                      
20                                                                                                       42                                                                              46                                      
21                                                                                                                                                                                                                               
22                                                                                                       27                                                                                                  24                  
23                                                                                                                                                                                                                               
24                                                                                                                                                                                                                               
25                                                                                                                                                                                                                               
26                                                                                                       27                                                                                                  28                  
27                                                                                                                                               66                                                                              
28                                                                                                                                                                                                                               
29                                                               29                  36                                                                                                                                          
30                                                               29                  36                                                                                                                                          
31                                                               29                  36                                                                                                                                          
32                                                               29                  36                                                                                                                                          
33                                                               30                  36                                                                                                                                          
34                                                               31                  36                                                                                                                                          
35                                                               32                  36                                                                                                                                          
36                                                                                                                                                                                                                               
37                                                                                                                                                                                                                               
38                                                                                                                                                                                                                               
39                                                                                                                                               66                                                                              
40                                                                                                                                                                                                                               
41                                                                                                                                                                                                                               
42                                                                                                                                               66                                                                              
43                                                                                                                                                                                                                               
44                                                                                                                                                                                                                               
45                                                                                                                                                                                                                               
46                                                                                                                                                                                                                               
47                                                                                                                                                                                                                               
48                                                                                                                                                                                                                               
49                                                                                                       75                  50                                                                                                  
50                                                                                                                                                                                                                               
51                                                                                                                                                                                                                               
52                                                                                                                                                                                                                               
53                                                                                                                                                                                                                               
54                                                                                                       75                  55                                                                                                  
55                                                                                                                                                                                                                               
56                                                                                                                                                                                                                               
57                                                                                                                                                                                                                               
58                                                                                                                                                                                                                               
59                                                                                                                                                                                                                               
60                                                                                                       62                                                                                                                      
61                                                                                                                                                                                                                               
62                                                                                                                                               66                                                                              
63                                                                                                                                                                                                                               
64                                                                                                                                                                                                                               
65                                                                                                                                                                                                                               
66                                                                                                       71                                                                                                                      
67                                                                                                       72                                                                                                                      
68                                                                                                       74                                                                                                                      
69                                                                                                       73                  80                                                                                                  
70                                                                                                       76                                                                                                                      
71                                                                                                                                               66                                                                              
72                                                                                                                                               66                                                                              
73                                                                                                                                               66                  70                                                          
74                                                                                                                                               66                                                                              
75                                                                                                                                               66                  70                                                          
76                                                                                                                                               66                                                                              
77                                                                                                                                                                                                                               
78                                                                                                                                                                                                                               
79                                                                                                                                                                                                                               
80                                                                                                                                                                                                                               
81                                                                                                                                                                                                                               
82                                                                                                                                                                                                                               
83                                                                                                                                                                                                                               
84                                                                                                                                                                                                                               
85                                                                                                                                                                                                                               
86                                                                                                                                                                                                                               
87                                                                                                                                                                                                                               
88                                                                                                                                                                                                                               
ACTION: 
#    identifierliteral   (         )         {         }         ,         ;         =         while     if        else      return    int       string    ==        !=        -         +         *         /         $         
0                                                                                                                                      s64       s65                                                                             
1                                                                                                                                      s64       s65                                                                   r0        
2                                                                                                                                      s64       s65                                                                   r1        
3    s4                                                                                                                                                                                                                          
4                        s5                                                                                                                                                                                                      
5                                  s6                                                                                                  s64       s65                                                                             
6                                            s7                                                                                                                                                                                  
7    s41                                                                                       s48       s53                 s60       s64       s65                                                                             
8    s41                                               s9                                      s48       s53                 s60       s64       s65                                                                             
9                                                                                                                                      r2        r2                                                                    r2        
10                                 s11                                                                                                                                                                                           
11                                           s12                                                                                                                                                                                 
12   s41                                                                                       s48       s53                 s60       s64       s65                                                                             
13   s41                                               s14                                     s48       s53                 s60       s64       s65                                                                             
14                                                                                                                                     r3        r3                                                                    r3        
15                                                                                                                                     s64       s65                                                                             
16   s17                                                                                                                                                                                                                         
17                                 r4                            s15                                                                                                                                                             
18                                 r5                                                                                                                                                                                            
19   s21       s79       s68                                                                                                                                                   s67                                               
20   s21       s79       s68                                                                                                                                                   s67                                               
21                       s22       r26                           r26       r26                                                                             r26       r26       r26       r26       r26       r26                 
22   s78       s79       s68       s23                                                                                                                                         s67                                               
23                                                                         r6                                                                                                                                                    
24                                 s25                                                                                                                                                                                           
25                                                                         r7                                                                                                                                                    
26   s78       s79       s68                                                                                                                                                   s67                                               
27                                 r8                            s26                                                                                                           s85       s84       s86       s87                 
28                                 r9                                                                                                                                                                                            
29   s41                                               r10                                     s48       s53                 s60       s64       s65                                                                             
30   s41                                               s52                                     s48       s53                 s60       s64       s65                                                                             
31   s41                                               s57                                     s48       s53                 s60       s64       s65                                                                             
32   s41                                               s59                                     s48       s53                 s60       s64       s65                                                                             
33   s41                                                                                       s48       s53                 s60       s64       s65                                                                             
34   s41                                                                                       s48       s53                 s60       s64       s65                                                                             
35   s41                                                                                       s48       s53                 s60       s64       s65                                                                             
36   s37                                                                                                                                                                                                                         
37                                                                         s38       s19                                                                                                                                         
38   r11                                               r11                                     r11       r11                 r11       r11       r11                                                                             
39                                                                         s40                                                                                                 s85       s84       s86       s87                 
40   r12                                               r12                                     r12       r12                 r12       r12       r12                                                                             
41                                                                                   s20                                                                                                                                         
42                                                                         s43                                                                                                 s85       s84       s86       s87                 
43   r13                                               r13                                     r13       r13                 r13       r13       r13                                                                             
44                                                                         s45                                                                                                                                                   
45   r14                                               r14                                     r14       r14                 r14       r14       r14                                                                             
46                                                                         s47                                                                                                                                                   
47   r15                                               r15                                     r15       r15                 r15       r15       r15                                                                             
48                       s49                                                                                                                                                                                                     
49   s78       s79       s69                                                                                                                                                   s67                                               
50                                 s51                                                                                                                                                                                           
51                                           s33                                                                                                                                                                                 
52   r16                                               r16                                     r16       r16                 r16       r16       r16                                                                             
53                       s54                                                                                                                                                                                                     
54   s78       s79       s69                                                                                                                                                   s67                                               
55                                 s56                                                                                                                                                                                           
56                                           s34                                                                                                                                                                                 
57   r17                                               r17                                     r17       r17       s58       r17       r17       r17                                                                             
58                                           s35                                                                                                                                                                                 
59   r18                                               r18                                     r18       r18                 r18       r18       r18                                                                             
60   s78       s79       s68                                               s61                                                                                                 s67                                               
61   r19                                               r19                                     r19       r19                 r19       r19       r19                                                                             
62                                                                         s63                                                                                                 s85       s84       s86       s87                 
63   r20                                               r20                                     r20       r20                 r20       r20       r20                                                                             
64   r21                                                                                                                                                                                                                         
65   r22                                                                                                                                                                                                                         
66   s78       s79       s68                                                                                                                                                   s67                                               
67   s78       s79       s68                                                                                                                                                   s67                                               
68   s78       s79       s68                                                                                                                                                   s67                                               
69   s78       s79       s69                                                                                                                                                   s67                                               
70   s78       s79       s68                                                                                                                                                   s67                                               
71                                 r23                           r23       r23                                                                             r23       r23       s85       s84       s86       s87                 
72                                 r24                           r24       r24                                                                             r24       r24       s85       s84       s86       s87                 
73                                 s77                                                                                                                     s82       s83       s85       s84       s86       s87                 
74                                 s77                                                                                                                                         s85       s84       s86       s87                 
75                                                                                                                                                         s82       s83       s85       s84       s86       s87                 
76                                 r28                                                                                                                                         s85       s84       s86       s87                 
77                                 r25                           r25       r25                                                                             r25       r25       r25       r25       r25       r25                 
78                                 r26                           r26       r26                                                                             r26       r26       r26       r26       r26       r26                 
79                                 r27                           r27       r27                                                                             r27       r27       r27       r27       r27       r27                 
80                                 s81                                                                                                                                                                                           
81                                 r29                                                                                                                                                                                           
82   r30       r30       r30                                                                                                                                                   r30                                               
83   r31       r31       r31                                                                                                                                                   r31                                               
84   r32       r32       r32                                                                                                                                                   r32                                               
85   r33       r33       r33                                                                                                                                                   r33                                               
86   r34       r34       r34                                                                                                                                                   r34                                               
87   r35       r35       r35                                                                                                                                                   r35                                               
88                                                                                                                                                                                                                     acc       
Tokens:
[int keywords] [add identifier] [( delimiters] [int keywords] [x identifier] [, delimiters] [int keywords] [y identifier] [) delimiters] [{ delimiters] [return keywords] [( delimiters] [x identifier] [+ operators] [y identifier] [* operators] [x identifier] [* operators] [99 literal] [) delimiters] [/ operators] [10 literal] [+ operators] [10000 literal] [- operators] [23333 literal] [+ operators] [( delimiters] [6666 literal] [- operators] [9999 literal] [) delimiters] [* operators] [1111 literal] [; delimiters] [} delimiters] [string keywords] [qaqaq identifier] [( delimiters] [) delimiters] [{ delimiters] [return keywords] [qaqaq literal] [; delimiters] [} delimiters] [string keywords] [qwqwqwqwqwq identifier] [( delimiters] [string keywords] [x identifier] [) delimiters] [{ delimiters] [return keywords] [x identifier] [; delimiters] [} delimiters] [int keywords] [main identifier] [( delimiters] [) delimiters] [{ delimiters] [int keywords] [a identifier] [= operators] [1 literal] [; delimiters] [int keywords] [b identifier] [= operators] [2 literal] [; delimiters] [int keywords] [c identifier] [= operators] [add identifier] [( delimiters] [a identifier] [, delimiters] [b identifier] [) delimiters] [; delimiters] [string keywords] [d identifier] [= operators] [string literal] [; delimiters] [if keywords] [( delimiters] [a identifier] [== operators] [1 literal] [) delimiters] [{ delimiters] [a identifier] [= operators] [2 literal] [; delimiters] [if keywords] [( delimiters] [a identifier] [== operators] [2 literal] [) delimiters] [{ delimiters] [while keywords] [( delimiters] [a identifier] [== operators] [2 literal] [) delimiters] [{ delimiters] [a identifier] [= operators] [3 literal] [; delimiters] [if keywords] [( delimiters] [a identifier] [!= operators] [10 literal] [) delimiters] [{ delimiters] [a identifier] [= operators] [add identifier] [( delimiters] [b identifier] [, delimiters] [c identifier] [) delimiters] [; delimiters] [} delimiters] [while keywords] [( delimiters] [a identifier] [== operators] [20 literal] [) delimiters] [{ delimiters] [if keywords] [( delimiters] [b identifier] [!= operators] [10000 literal] [) delimiters] [{ delimiters] [int keywords] [e identifier] [= operators] [add identifier] [( delimiters] [b identifier] [, delimiters] [c identifier] [) delimiters] [; delimiters] [} delimiters] [else keywords] [{ delimiters] [int keywords] [f identifier] [= operators] [add identifier] [( delimiters] [e identifier] [, delimiters] [d identifier] [) delimiters] [; delimiters] [string keywords] [s identifier] [= operators] [int f = add(e, d); literal] [; delimiters] [} delimiters] [} delimiters] [} delimiters] [} delimiters] [else keywords] [{ delimiters] [a identifier] [= operators] [4 literal] [; delimiters] [} delimiters] [} delimiters] [else keywords] [{ delimiters] [a identifier] [= operators] [3 literal] [; delimiters] [} delimiters] [while keywords] [( delimiters] [b identifier] [== operators] [2 literal] [) delimiters] [{ delimiters] [b identifier] [= operators] [b identifier] [+ operators] [1 literal] [; delimiters] [} delimiters] [if keywords] [( delimiters] [d identifier] [== operators] [string literal] [) delimiters] [{ delimiters] [d identifier] [= operators] [QAQ literal] [; delimiters] [string keywords] [qwq identifier] [= operators] [QWQ literal] [; delimiters] [} delimiters] [string keywords] [qaq identifier] [= operators] [qaqaq identifier] [( delimiters] [) delimiters] [; delimiters] [string keywords] [qwq identifier] [= operators] [qwqwqwqwqwq identifier] [( delimiters] [) delimiters] [; delimiters] [return keywords] [0 literal] [; delimiters] [} delimiters] [$ $] 
Syntax Analysis: 
----------------------------------------
Step: 1
Status: 0 
Symbol: $ 
Input: int identifier ( int identifier , int identifier ) { return ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s64: Shift int
----------------------------------------
Step: 2
Status: 0 64 
Symbol: $ int 
Input: identifier ( int identifier , int identifier ) { return ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r21: Reduce Product 21: Type -> int 
----------------------------------------
Step: 3
Status: 0 3 
Symbol: $ Type 
Input: identifier ( int identifier , int identifier ) { return ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s4: Shift identifier
----------------------------------------
Step: 4
Status: 0 3 4 
Symbol: $ Type identifier 
Input: ( int identifier , int identifier ) { return ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s5: Shift (
----------------------------------------
Step: 5
Status: 0 3 4 5 
Symbol: $ Type identifier ( 
Input: int identifier , int identifier ) { return ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s64: Shift int
----------------------------------------
Step: 6
Status: 0 3 4 5 64 
Symbol: $ Type identifier ( int 
Input: identifier , int identifier ) { return ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r21: Reduce Product 21: Type -> int 
----------------------------------------
Step: 7
Status: 0 3 4 5 16 
Symbol: $ Type identifier ( Type 
Input: identifier , int identifier ) { return ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s17: Shift identifier
----------------------------------------
Step: 8
Status: 0 3 4 5 16 17 
Symbol: $ Type identifier ( Type identifier 
Input: , int identifier ) { return ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s15: Shift ,
----------------------------------------
Step: 9
Status: 0 3 4 5 16 17 15 
Symbol: $ Type identifier ( Type identifier , 
Input: int identifier ) { return ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s64: Shift int
----------------------------------------
Step: 10
Status: 0 3 4 5 16 17 15 64 
Symbol: $ Type identifier ( Type identifier , int 
Input: identifier ) { return ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r21: Reduce Product 21: Type -> int 
----------------------------------------
Step: 11
Status: 0 3 4 5 16 17 15 16 
Symbol: $ Type identifier ( Type identifier , Type 
Input: identifier ) { return ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s17: Shift identifier
----------------------------------------
Step: 12
Status: 0 3 4 5 16 17 15 16 17 
Symbol: $ Type identifier ( Type identifier , Type identifier 
Input: ) { return ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r4: Reduce Product 4: ArgumentList -> Type identifier 
----------------------------------------
Step: 13
Status: 0 3 4 5 16 17 15 18 
Symbol: $ Type identifier ( Type identifier , ArgumentList 
Input: ) { return ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r5: Reduce Product 5: ArgumentList -> Type identifier , ArgumentList 
----------------------------------------
Step: 14
Status: 0 3 4 5 10 
Symbol: $ Type identifier ( ArgumentList 
Input: ) { return ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s11: Shift )
----------------------------------------
Step: 15
Status: 0 3 4 5 10 11 
Symbol: $ Type identifier ( ArgumentList ) 
Input: { return ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s12: Shift {
----------------------------------------
Step: 16
Status: 0 3 4 5 10 11 12 
Symbol: $ Type identifier ( ArgumentList ) { 
Input: return ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s60: Shift return
----------------------------------------
Step: 17
Status: 0 3 4 5 10 11 12 60 
Symbol: $ Type identifier ( ArgumentList ) { return 
Input: ( identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s68: Shift (
----------------------------------------
Step: 18
Status: 0 3 4 5 10 11 12 60 68 
Symbol: $ Type identifier ( ArgumentList ) { return ( 
Input: identifier + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 19
Status: 0 3 4 5 10 11 12 60 68 78 
Symbol: $ Type identifier ( ArgumentList ) { return ( identifier 
Input: + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 20
Status: 0 3 4 5 10 11 12 60 68 74 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression 
Input: + identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s84: Shift +
----------------------------------------
Step: 21
Status: 0 3 4 5 10 11 12 60 68 74 84 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression + 
Input: identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r32: Reduce Product 32: ArithmeticOperator -> + 
----------------------------------------
Step: 22
Status: 0 3 4 5 10 11 12 60 68 74 66 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression ArithmeticOperator 
Input: identifier * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 23
Status: 0 3 4 5 10 11 12 60 68 74 66 78 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression ArithmeticOperator identifier 
Input: * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 24
Status: 0 3 4 5 10 11 12 60 68 74 66 71 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression ArithmeticOperator ArithmeticExpression 
Input: * identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s86: Shift *
----------------------------------------
Step: 25
Status: 0 3 4 5 10 11 12 60 68 74 66 71 86 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression ArithmeticOperator ArithmeticExpression * 
Input: identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r34: Reduce Product 34: ArithmeticOperator -> * 
----------------------------------------
Step: 26
Status: 0 3 4 5 10 11 12 60 68 74 66 71 66 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator 
Input: identifier * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 27
Status: 0 3 4 5 10 11 12 60 68 74 66 71 66 78 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator identifier 
Input: * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 28
Status: 0 3 4 5 10 11 12 60 68 74 66 71 66 71 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression 
Input: * literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s86: Shift *
----------------------------------------
Step: 29
Status: 0 3 4 5 10 11 12 60 68 74 66 71 66 71 86 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression * 
Input: literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r34: Reduce Product 34: ArithmeticOperator -> * 
----------------------------------------
Step: 30
Status: 0 3 4 5 10 11 12 60 68 74 66 71 66 71 66 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator 
Input: literal ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 31
Status: 0 3 4 5 10 11 12 60 68 74 66 71 66 71 66 79 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator literal 
Input: ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 32
Status: 0 3 4 5 10 11 12 60 68 74 66 71 66 71 66 71 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression 
Input: ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r23: Reduce Product 23: ArithmeticExpression -> ArithmeticExpression ArithmeticOperator ArithmeticExpression 
----------------------------------------
Step: 33
Status: 0 3 4 5 10 11 12 60 68 74 66 71 66 71 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression 
Input: ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r23: Reduce Product 23: ArithmeticExpression -> ArithmeticExpression ArithmeticOperator ArithmeticExpression 
----------------------------------------
Step: 34
Status: 0 3 4 5 10 11 12 60 68 74 66 71 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression ArithmeticOperator ArithmeticExpression 
Input: ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r23: Reduce Product 23: ArithmeticExpression -> ArithmeticExpression ArithmeticOperator ArithmeticExpression 
----------------------------------------
Step: 35
Status: 0 3 4 5 10 11 12 60 68 74 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression 
Input: ) / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s77: Shift )
----------------------------------------
Step: 36
Status: 0 3 4 5 10 11 12 60 68 74 77 
Symbol: $ Type identifier ( ArgumentList ) { return ( ArithmeticExpression ) 
Input: / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r25: Reduce Product 25: ArithmeticExpression -> ( ArithmeticExpression ) 
----------------------------------------
Step: 37
Status: 0 3 4 5 10 11 12 60 62 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression 
Input: / literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s87: Shift /
----------------------------------------
Step: 38
Status: 0 3 4 5 10 11 12 60 62 87 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression / 
Input: literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r35: Reduce Product 35: ArithmeticOperator -> / 
----------------------------------------
Step: 39
Status: 0 3 4 5 10 11 12 60 62 66 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator 
Input: literal + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 40
Status: 0 3 4 5 10 11 12 60 62 66 79 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator literal 
Input: + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 41
Status: 0 3 4 5 10 11 12 60 62 66 71 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression 
Input: + literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s84: Shift +
----------------------------------------
Step: 42
Status: 0 3 4 5 10 11 12 60 62 66 71 84 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression + 
Input: literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r32: Reduce Product 32: ArithmeticOperator -> + 
----------------------------------------
Step: 43
Status: 0 3 4 5 10 11 12 60 62 66 71 66 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator 
Input: literal - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 44
Status: 0 3 4 5 10 11 12 60 62 66 71 66 79 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator literal 
Input: - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 45
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression 
Input: - literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s85: Shift -
----------------------------------------
Step: 46
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 85 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression - 
Input: literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r33: Reduce Product 33: ArithmeticOperator -> - 
----------------------------------------
Step: 47
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator 
Input: literal + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 48
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 79 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator literal 
Input: + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 49
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression 
Input: + ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s84: Shift +
----------------------------------------
Step: 50
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 84 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression + 
Input: ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r32: Reduce Product 32: ArithmeticOperator -> + 
----------------------------------------
Step: 51
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 66 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator 
Input: ( literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s68: Shift (
----------------------------------------
Step: 52
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 66 68 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ( 
Input: literal - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 53
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 66 68 79 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ( literal 
Input: - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 54
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 66 68 74 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ( ArithmeticExpression 
Input: - literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s85: Shift -
----------------------------------------
Step: 55
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 66 68 74 85 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ( ArithmeticExpression - 
Input: literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r33: Reduce Product 33: ArithmeticOperator -> - 
----------------------------------------
Step: 56
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 66 68 74 66 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ( ArithmeticExpression ArithmeticOperator 
Input: literal ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 57
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 66 68 74 66 79 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ( ArithmeticExpression ArithmeticOperator literal 
Input: ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 58
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 66 68 74 66 71 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ( ArithmeticExpression ArithmeticOperator ArithmeticExpression 
Input: ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r23: Reduce Product 23: ArithmeticExpression -> ArithmeticExpression ArithmeticOperator ArithmeticExpression 
----------------------------------------
Step: 59
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 66 68 74 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ( ArithmeticExpression 
Input: ) * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s77: Shift )
----------------------------------------
Step: 60
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 66 68 74 77 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ( ArithmeticExpression ) 
Input: * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r25: Reduce Product 25: ArithmeticExpression -> ( ArithmeticExpression ) 
----------------------------------------
Step: 61
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 66 71 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression 
Input: * literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s86: Shift *
----------------------------------------
Step: 62
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 66 71 86 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression * 
Input: literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r34: Reduce Product 34: ArithmeticOperator -> * 
----------------------------------------
Step: 63
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 66 71 66 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator 
Input: literal ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 64
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 66 71 66 79 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator literal 
Input: ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 65
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 66 71 66 71 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression 
Input: ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r23: Reduce Product 23: ArithmeticExpression -> ArithmeticExpression ArithmeticOperator ArithmeticExpression 
----------------------------------------
Step: 66
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 66 71 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression 
Input: ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r23: Reduce Product 23: ArithmeticExpression -> ArithmeticExpression ArithmeticOperator ArithmeticExpression 
----------------------------------------
Step: 67
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 66 71 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression 
Input: ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r23: Reduce Product 23: ArithmeticExpression -> ArithmeticExpression ArithmeticOperator ArithmeticExpression 
----------------------------------------
Step: 68
Status: 0 3 4 5 10 11 12 60 62 66 71 66 71 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression ArithmeticOperator ArithmeticExpression 
Input: ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r23: Reduce Product 23: ArithmeticExpression -> ArithmeticExpression ArithmeticOperator ArithmeticExpression 
----------------------------------------
Step: 69
Status: 0 3 4 5 10 11 12 60 62 66 71 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ArithmeticOperator ArithmeticExpression 
Input: ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r23: Reduce Product 23: ArithmeticExpression -> ArithmeticExpression ArithmeticOperator ArithmeticExpression 
----------------------------------------
Step: 70
Status: 0 3 4 5 10 11 12 60 62 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression 
Input: ; } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s63: Shift ;
----------------------------------------
Step: 71
Status: 0 3 4 5 10 11 12 60 62 63 
Symbol: $ Type identifier ( ArgumentList ) { return ArithmeticExpression ; 
Input: } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r20: Reduce Product 20: BlockStatement -> return ArithmeticExpression ; 
----------------------------------------
Step: 72
Status: 0 3 4 5 10 11 12 13 
Symbol: $ Type identifier ( ArgumentList ) { BlockStatement 
Input: } string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s14: Shift }
----------------------------------------
Step: 73
Status: 0 3 4 5 10 11 12 13 14 
Symbol: $ Type identifier ( ArgumentList ) { BlockStatement } 
Input: string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r3: Reduce Product 3: FunctionDeclaration -> Type identifier ( ArgumentList ) { BlockStatement } 
----------------------------------------
Step: 74
Status: 0 1 
Symbol: $ FunctionDeclaration 
Input: string identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s65: Shift string
----------------------------------------
Step: 75
Status: 0 1 65 
Symbol: $ FunctionDeclaration string 
Input: identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r22: Reduce Product 22: Type -> string 
----------------------------------------
Step: 76
Status: 0 1 3 
Symbol: $ FunctionDeclaration Type 
Input: identifier ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s4: Shift identifier
----------------------------------------
Step: 77
Status: 0 1 3 4 
Symbol: $ FunctionDeclaration Type identifier 
Input: ( ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s5: Shift (
----------------------------------------
Step: 78
Status: 0 1 3 4 5 
Symbol: $ FunctionDeclaration Type identifier ( 
Input: ) { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s6: Shift )
----------------------------------------
Step: 79
Status: 0 1 3 4 5 6 
Symbol: $ FunctionDeclaration Type identifier ( ) 
Input: { return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s7: Shift {
----------------------------------------
Step: 80
Status: 0 1 3 4 5 6 7 
Symbol: $ FunctionDeclaration Type identifier ( ) { 
Input: return literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s60: Shift return
----------------------------------------
Step: 81
Status: 0 1 3 4 5 6 7 60 
Symbol: $ FunctionDeclaration Type identifier ( ) { return 
Input: literal ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 82
Status: 0 1 3 4 5 6 7 60 79 
Symbol: $ FunctionDeclaration Type identifier ( ) { return literal 
Input: ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 83
Status: 0 1 3 4 5 6 7 60 62 
Symbol: $ FunctionDeclaration Type identifier ( ) { return ArithmeticExpression 
Input: ; } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s63: Shift ;
----------------------------------------
Step: 84
Status: 0 1 3 4 5 6 7 60 62 63 
Symbol: $ FunctionDeclaration Type identifier ( ) { return ArithmeticExpression ; 
Input: } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r20: Reduce Product 20: BlockStatement -> return ArithmeticExpression ; 
----------------------------------------
Step: 85
Status: 0 1 3 4 5 6 7 8 
Symbol: $ FunctionDeclaration Type identifier ( ) { BlockStatement 
Input: } string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s9: Shift }
----------------------------------------
Step: 86
Status: 0 1 3 4 5 6 7 8 9 
Symbol: $ FunctionDeclaration Type identifier ( ) { BlockStatement } 
Input: string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r2: Reduce Product 2: FunctionDeclaration -> Type identifier ( ) { BlockStatement } 
----------------------------------------
Step: 87
Status: 0 1 2 
Symbol: $ FunctionDeclaration FunctionDeclaration 
Input: string identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s65: Shift string
----------------------------------------
Step: 88
Status: 0 1 2 65 
Symbol: $ FunctionDeclaration FunctionDeclaration string 
Input: identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r22: Reduce Product 22: Type -> string 
----------------------------------------
Step: 89
Status: 0 1 2 3 
Symbol: $ FunctionDeclaration FunctionDeclaration Type 
Input: identifier ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s4: Shift identifier
----------------------------------------
Step: 90
Status: 0 1 2 3 4 
Symbol: $ FunctionDeclaration FunctionDeclaration Type identifier 
Input: ( string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s5: Shift (
----------------------------------------
Step: 91
Status: 0 1 2 3 4 5 
Symbol: $ FunctionDeclaration FunctionDeclaration Type identifier ( 
Input: string identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s65: Shift string
----------------------------------------
Step: 92
Status: 0 1 2 3 4 5 65 
Symbol: $ FunctionDeclaration FunctionDeclaration Type identifier ( string 
Input: identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r22: Reduce Product 22: Type -> string 
----------------------------------------
Step: 93
Status: 0 1 2 3 4 5 16 
Symbol: $ FunctionDeclaration FunctionDeclaration Type identifier ( Type 
Input: identifier ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s17: Shift identifier
----------------------------------------
Step: 94
Status: 0 1 2 3 4 5 16 17 
Symbol: $ FunctionDeclaration FunctionDeclaration Type identifier ( Type identifier 
Input: ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r4: Reduce Product 4: ArgumentList -> Type identifier 
----------------------------------------
Step: 95
Status: 0 1 2 3 4 5 10 
Symbol: $ FunctionDeclaration FunctionDeclaration Type identifier ( ArgumentList 
Input: ) { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s11: Shift )
----------------------------------------
Step: 96
Status: 0 1 2 3 4 5 10 11 
Symbol: $ FunctionDeclaration FunctionDeclaration Type identifier ( ArgumentList ) 
Input: { return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s12: Shift {
----------------------------------------
Step: 97
Status: 0 1 2 3 4 5 10 11 12 
Symbol: $ FunctionDeclaration FunctionDeclaration Type identifier ( ArgumentList ) { 
Input: return identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s60: Shift return
----------------------------------------
Step: 98
Status: 0 1 2 3 4 5 10 11 12 60 
Symbol: $ FunctionDeclaration FunctionDeclaration Type identifier ( ArgumentList ) { return 
Input: identifier ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 99
Status: 0 1 2 3 4 5 10 11 12 60 78 
Symbol: $ FunctionDeclaration FunctionDeclaration Type identifier ( ArgumentList ) { return identifier 
Input: ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 100
Status: 0 1 2 3 4 5 10 11 12 60 62 
Symbol: $ FunctionDeclaration FunctionDeclaration Type identifier ( ArgumentList ) { return ArithmeticExpression 
Input: ; } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s63: Shift ;
----------------------------------------
Step: 101
Status: 0 1 2 3 4 5 10 11 12 60 62 63 
Symbol: $ FunctionDeclaration FunctionDeclaration Type identifier ( ArgumentList ) { return ArithmeticExpression ; 
Input: } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r20: Reduce Product 20: BlockStatement -> return ArithmeticExpression ; 
----------------------------------------
Step: 102
Status: 0 1 2 3 4 5 10 11 12 13 
Symbol: $ FunctionDeclaration FunctionDeclaration Type identifier ( ArgumentList ) { BlockStatement 
Input: } int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s14: Shift }
----------------------------------------
Step: 103
Status: 0 1 2 3 4 5 10 11 12 13 14 
Symbol: $ FunctionDeclaration FunctionDeclaration Type identifier ( ArgumentList ) { BlockStatement } 
Input: int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r3: Reduce Product 3: FunctionDeclaration -> Type identifier ( ArgumentList ) { BlockStatement } 
----------------------------------------
Step: 104
Status: 0 1 2 2 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration 
Input: int identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s64: Shift int
----------------------------------------
Step: 105
Status: 0 1 2 2 64 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration int 
Input: identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r21: Reduce Product 21: Type -> int 
----------------------------------------
Step: 106
Status: 0 1 2 2 3 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type 
Input: identifier ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s4: Shift identifier
----------------------------------------
Step: 107
Status: 0 1 2 2 3 4 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier 
Input: ( ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s5: Shift (
----------------------------------------
Step: 108
Status: 0 1 2 2 3 4 5 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( 
Input: ) { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s6: Shift )
----------------------------------------
Step: 109
Status: 0 1 2 2 3 4 5 6 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) 
Input: { int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s7: Shift {
----------------------------------------
Step: 110
Status: 0 1 2 2 3 4 5 6 7 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { 
Input: int identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s64: Shift int
----------------------------------------
Step: 111
Status: 0 1 2 2 3 4 5 6 7 64 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { int 
Input: identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r21: Reduce Product 21: Type -> int 
----------------------------------------
Step: 112
Status: 0 1 2 2 3 4 5 6 7 36 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { Type 
Input: identifier = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s37: Shift identifier
----------------------------------------
Step: 113
Status: 0 1 2 2 3 4 5 6 7 36 37 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { Type identifier 
Input: = literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s19: Shift =
----------------------------------------
Step: 114
Status: 0 1 2 2 3 4 5 6 7 36 37 19 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { Type identifier = 
Input: literal ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 115
Status: 0 1 2 2 3 4 5 6 7 36 37 19 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { Type identifier = literal 
Input: ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 116
Status: 0 1 2 2 3 4 5 6 7 36 37 19 39 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { Type identifier = ArithmeticExpression 
Input: ; int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s40: Shift ;
----------------------------------------
Step: 117
Status: 0 1 2 2 3 4 5 6 7 36 37 19 39 40 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { Type identifier = ArithmeticExpression ; 
Input: int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r12: Reduce Product 12: BlockStatement -> Type identifier = ArithmeticExpression ; 
----------------------------------------
Step: 118
Status: 0 1 2 2 3 4 5 6 7 8 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement 
Input: int identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s64: Shift int
----------------------------------------
Step: 119
Status: 0 1 2 2 3 4 5 6 7 8 64 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement int 
Input: identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r21: Reduce Product 21: Type -> int 
----------------------------------------
Step: 120
Status: 0 1 2 2 3 4 5 6 7 8 36 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement Type 
Input: identifier = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s37: Shift identifier
----------------------------------------
Step: 121
Status: 0 1 2 2 3 4 5 6 7 8 36 37 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement Type identifier 
Input: = literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s19: Shift =
----------------------------------------
Step: 122
Status: 0 1 2 2 3 4 5 6 7 8 36 37 19 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement Type identifier = 
Input: literal ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 123
Status: 0 1 2 2 3 4 5 6 7 8 36 37 19 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement Type identifier = literal 
Input: ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 124
Status: 0 1 2 2 3 4 5 6 7 8 36 37 19 39 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement Type identifier = ArithmeticExpression 
Input: ; int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s40: Shift ;
----------------------------------------
Step: 125
Status: 0 1 2 2 3 4 5 6 7 8 36 37 19 39 40 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement Type identifier = ArithmeticExpression ; 
Input: int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r12: Reduce Product 12: BlockStatement -> Type identifier = ArithmeticExpression ; 
----------------------------------------
Step: 126
Status: 0 1 2 2 3 4 5 6 7 8 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement 
Input: int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s64: Shift int
----------------------------------------
Step: 127
Status: 0 1 2 2 3 4 5 6 7 8 29 64 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement int 
Input: identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r21: Reduce Product 21: Type -> int 
----------------------------------------
Step: 128
Status: 0 1 2 2 3 4 5 6 7 8 29 36 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement Type 
Input: identifier = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s37: Shift identifier
----------------------------------------
Step: 129
Status: 0 1 2 2 3 4 5 6 7 8 29 36 37 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement Type identifier 
Input: = identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s19: Shift =
----------------------------------------
Step: 130
Status: 0 1 2 2 3 4 5 6 7 8 29 36 37 19 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement Type identifier = 
Input: identifier ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s21: Shift identifier
----------------------------------------
Step: 131
Status: 0 1 2 2 3 4 5 6 7 8 29 36 37 19 21 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement Type identifier = identifier 
Input: ( identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s22: Shift (
----------------------------------------
Step: 132
Status: 0 1 2 2 3 4 5 6 7 8 29 36 37 19 21 22 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement Type identifier = identifier ( 
Input: identifier , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 133
Status: 0 1 2 2 3 4 5 6 7 8 29 36 37 19 21 22 78 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement Type identifier = identifier ( identifier 
Input: , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 134
Status: 0 1 2 2 3 4 5 6 7 8 29 36 37 19 21 22 27 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement Type identifier = identifier ( ArithmeticExpression 
Input: , identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s26: Shift ,
----------------------------------------
Step: 135
Status: 0 1 2 2 3 4 5 6 7 8 29 36 37 19 21 22 27 26 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement Type identifier = identifier ( ArithmeticExpression , 
Input: identifier ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 136
Status: 0 1 2 2 3 4 5 6 7 8 29 36 37 19 21 22 27 26 78 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement Type identifier = identifier ( ArithmeticExpression , identifier 
Input: ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 137
Status: 0 1 2 2 3 4 5 6 7 8 29 36 37 19 21 22 27 26 27 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement Type identifier = identifier ( ArithmeticExpression , ArithmeticExpression 
Input: ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r8: Reduce Product 8: ActualArgumentList -> ArithmeticExpression 
----------------------------------------
Step: 138
Status: 0 1 2 2 3 4 5 6 7 8 29 36 37 19 21 22 27 26 28 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement Type identifier = identifier ( ArithmeticExpression , ActualArgumentList 
Input: ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r9: Reduce Product 9: ActualArgumentList -> ArithmeticExpression , ActualArgumentList 
----------------------------------------
Step: 139
Status: 0 1 2 2 3 4 5 6 7 8 29 36 37 19 21 22 24 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement Type identifier = identifier ( ActualArgumentList 
Input: ) ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s25: Shift )
----------------------------------------
Step: 140
Status: 0 1 2 2 3 4 5 6 7 8 29 36 37 19 21 22 24 25 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement Type identifier = identifier ( ActualArgumentList ) 
Input: ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r7: Reduce Product 7: FunctionId -> identifier ( ActualArgumentList ) 
----------------------------------------
Step: 141
Status: 0 1 2 2 3 4 5 6 7 8 29 36 37 19 44 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement Type identifier = FunctionId 
Input: ; string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s45: Shift ;
----------------------------------------
Step: 142
Status: 0 1 2 2 3 4 5 6 7 8 29 36 37 19 44 45 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement Type identifier = FunctionId ; 
Input: string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r14: Reduce Product 14: BlockStatement -> Type identifier = FunctionId ; 
----------------------------------------
Step: 143
Status: 0 1 2 2 3 4 5 6 7 8 29 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement 
Input: string identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s65: Shift string
----------------------------------------
Step: 144
Status: 0 1 2 2 3 4 5 6 7 8 29 29 65 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement string 
Input: identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r22: Reduce Product 22: Type -> string 
----------------------------------------
Step: 145
Status: 0 1 2 2 3 4 5 6 7 8 29 29 36 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement Type 
Input: identifier = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s37: Shift identifier
----------------------------------------
Step: 146
Status: 0 1 2 2 3 4 5 6 7 8 29 29 36 37 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement Type identifier 
Input: = literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s19: Shift =
----------------------------------------
Step: 147
Status: 0 1 2 2 3 4 5 6 7 8 29 29 36 37 19 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement Type identifier = 
Input: literal ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 148
Status: 0 1 2 2 3 4 5 6 7 8 29 29 36 37 19 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement Type identifier = literal 
Input: ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 149
Status: 0 1 2 2 3 4 5 6 7 8 29 29 36 37 19 39 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement Type identifier = ArithmeticExpression 
Input: ; if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s40: Shift ;
----------------------------------------
Step: 150
Status: 0 1 2 2 3 4 5 6 7 8 29 29 36 37 19 39 40 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement Type identifier = ArithmeticExpression ; 
Input: if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r12: Reduce Product 12: BlockStatement -> Type identifier = ArithmeticExpression ; 
----------------------------------------
Step: 151
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement 
Input: if ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s53: Shift if
----------------------------------------
Step: 152
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if 
Input: ( identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s54: Shift (
----------------------------------------
Step: 153
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( 
Input: identifier == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 154
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 78 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( identifier 
Input: == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 155
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 75 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( ArithmeticExpression 
Input: == literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s82: Shift ==
----------------------------------------
Step: 156
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 75 82 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( ArithmeticExpression == 
Input: literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r30: Reduce Product 30: ComparisonOperator -> == 
----------------------------------------
Step: 157
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 75 70 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( ArithmeticExpression ComparisonOperator 
Input: literal ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 158
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 75 70 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( ArithmeticExpression ComparisonOperator literal 
Input: ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 159
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 75 70 76 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( ArithmeticExpression ComparisonOperator ArithmeticExpression 
Input: ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r28: Reduce Product 28: BoolExpression -> ArithmeticExpression ComparisonOperator ArithmeticExpression 
----------------------------------------
Step: 160
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression 
Input: ) { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s56: Shift )
----------------------------------------
Step: 161
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) 
Input: { identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s34: Shift {
----------------------------------------
Step: 162
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { 
Input: identifier = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s41: Shift identifier
----------------------------------------
Step: 163
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 41 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { identifier 
Input: = literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s20: Shift =
----------------------------------------
Step: 164
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 41 20 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { identifier = 
Input: literal ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 165
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 41 20 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { identifier = literal 
Input: ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 166
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 41 20 42 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { identifier = ArithmeticExpression 
Input: ; if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s43: Shift ;
----------------------------------------
Step: 167
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 41 20 42 43 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { identifier = ArithmeticExpression ; 
Input: if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r13: Reduce Product 13: BlockStatement -> identifier = ArithmeticExpression ; 
----------------------------------------
Step: 168
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement 
Input: if ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s53: Shift if
----------------------------------------
Step: 169
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if 
Input: ( identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s54: Shift (
----------------------------------------
Step: 170
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( 
Input: identifier == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 171
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 78 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( identifier 
Input: == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 172
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 75 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( ArithmeticExpression 
Input: == literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s82: Shift ==
----------------------------------------
Step: 173
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 75 82 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( ArithmeticExpression == 
Input: literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r30: Reduce Product 30: ComparisonOperator -> == 
----------------------------------------
Step: 174
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 75 70 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( ArithmeticExpression ComparisonOperator 
Input: literal ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 175
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 75 70 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( ArithmeticExpression ComparisonOperator literal 
Input: ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 176
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 75 70 76 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( ArithmeticExpression ComparisonOperator ArithmeticExpression 
Input: ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r28: Reduce Product 28: BoolExpression -> ArithmeticExpression ComparisonOperator ArithmeticExpression 
----------------------------------------
Step: 177
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression 
Input: ) { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s56: Shift )
----------------------------------------
Step: 178
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) 
Input: { while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s34: Shift {
----------------------------------------
Step: 179
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { 
Input: while ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s48: Shift while
----------------------------------------
Step: 180
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while 
Input: ( identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s49: Shift (
----------------------------------------
Step: 181
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( 
Input: identifier == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 182
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 78 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( identifier 
Input: == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 183
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 75 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( ArithmeticExpression 
Input: == literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s82: Shift ==
----------------------------------------
Step: 184
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 75 82 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( ArithmeticExpression == 
Input: literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r30: Reduce Product 30: ComparisonOperator -> == 
----------------------------------------
Step: 185
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 75 70 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( ArithmeticExpression ComparisonOperator 
Input: literal ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 186
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 75 70 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( ArithmeticExpression ComparisonOperator literal 
Input: ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 187
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 75 70 76 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( ArithmeticExpression ComparisonOperator ArithmeticExpression 
Input: ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r28: Reduce Product 28: BoolExpression -> ArithmeticExpression ComparisonOperator ArithmeticExpression 
----------------------------------------
Step: 188
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression 
Input: ) { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s51: Shift )
----------------------------------------
Step: 189
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) 
Input: { identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s33: Shift {
----------------------------------------
Step: 190
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { 
Input: identifier = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s41: Shift identifier
----------------------------------------
Step: 191
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 41 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { identifier 
Input: = literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s20: Shift =
----------------------------------------
Step: 192
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 41 20 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { identifier = 
Input: literal ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 193
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 41 20 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { identifier = literal 
Input: ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 194
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 41 20 42 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { identifier = ArithmeticExpression 
Input: ; if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s43: Shift ;
----------------------------------------
Step: 195
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 41 20 42 43 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { identifier = ArithmeticExpression ; 
Input: if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r13: Reduce Product 13: BlockStatement -> identifier = ArithmeticExpression ; 
----------------------------------------
Step: 196
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement 
Input: if ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s53: Shift if
----------------------------------------
Step: 197
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if 
Input: ( identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s54: Shift (
----------------------------------------
Step: 198
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( 
Input: identifier != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 199
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 78 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( identifier 
Input: != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 200
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 75 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( ArithmeticExpression 
Input: != literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s83: Shift !=
----------------------------------------
Step: 201
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 75 83 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( ArithmeticExpression != 
Input: literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r31: Reduce Product 31: ComparisonOperator -> != 
----------------------------------------
Step: 202
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 75 70 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( ArithmeticExpression ComparisonOperator 
Input: literal ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 203
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 75 70 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( ArithmeticExpression ComparisonOperator literal 
Input: ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 204
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 75 70 76 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( ArithmeticExpression ComparisonOperator ArithmeticExpression 
Input: ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r28: Reduce Product 28: BoolExpression -> ArithmeticExpression ComparisonOperator ArithmeticExpression 
----------------------------------------
Step: 205
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression 
Input: ) { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s56: Shift )
----------------------------------------
Step: 206
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) 
Input: { identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s34: Shift {
----------------------------------------
Step: 207
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { 
Input: identifier = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s41: Shift identifier
----------------------------------------
Step: 208
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 41 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { identifier 
Input: = identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s20: Shift =
----------------------------------------
Step: 209
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 41 20 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { identifier = 
Input: identifier ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s21: Shift identifier
----------------------------------------
Step: 210
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 41 20 21 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { identifier = identifier 
Input: ( identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s22: Shift (
----------------------------------------
Step: 211
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 41 20 21 22 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { identifier = identifier ( 
Input: identifier , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 212
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 41 20 21 22 78 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { identifier = identifier ( identifier 
Input: , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 213
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 41 20 21 22 27 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { identifier = identifier ( ArithmeticExpression 
Input: , identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s26: Shift ,
----------------------------------------
Step: 214
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 41 20 21 22 27 26 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { identifier = identifier ( ArithmeticExpression , 
Input: identifier ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 215
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 41 20 21 22 27 26 78 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { identifier = identifier ( ArithmeticExpression , identifier 
Input: ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 216
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 41 20 21 22 27 26 27 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { identifier = identifier ( ArithmeticExpression , ArithmeticExpression 
Input: ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r8: Reduce Product 8: ActualArgumentList -> ArithmeticExpression 
----------------------------------------
Step: 217
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 41 20 21 22 27 26 28 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { identifier = identifier ( ArithmeticExpression , ActualArgumentList 
Input: ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r9: Reduce Product 9: ActualArgumentList -> ArithmeticExpression , ActualArgumentList 
----------------------------------------
Step: 218
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 41 20 21 22 24 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { identifier = identifier ( ActualArgumentList 
Input: ) ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s25: Shift )
----------------------------------------
Step: 219
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 41 20 21 22 24 25 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { identifier = identifier ( ActualArgumentList ) 
Input: ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r7: Reduce Product 7: FunctionId -> identifier ( ActualArgumentList ) 
----------------------------------------
Step: 220
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 41 20 46 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { identifier = FunctionId 
Input: ; } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s47: Shift ;
----------------------------------------
Step: 221
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 41 20 46 47 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { identifier = FunctionId ; 
Input: } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r15: Reduce Product 15: BlockStatement -> identifier = FunctionId ; 
----------------------------------------
Step: 222
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 31 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { BlockStatement 
Input: } while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s57: Shift }
----------------------------------------
Step: 223
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 53 54 55 56 34 31 57 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement if ( BoolExpression ) { BlockStatement } 
Input: while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r17: Reduce Product 17: BlockStatement -> if ( BoolExpression ) { BlockStatement } 
----------------------------------------
Step: 224
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement 
Input: while ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s48: Shift while
----------------------------------------
Step: 225
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while 
Input: ( identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s49: Shift (
----------------------------------------
Step: 226
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( 
Input: identifier == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 227
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 78 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( identifier 
Input: == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 228
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 75 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( ArithmeticExpression 
Input: == literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s82: Shift ==
----------------------------------------
Step: 229
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 75 82 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( ArithmeticExpression == 
Input: literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r30: Reduce Product 30: ComparisonOperator -> == 
----------------------------------------
Step: 230
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 75 70 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( ArithmeticExpression ComparisonOperator 
Input: literal ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 231
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 75 70 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( ArithmeticExpression ComparisonOperator literal 
Input: ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 232
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 75 70 76 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( ArithmeticExpression ComparisonOperator ArithmeticExpression 
Input: ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r28: Reduce Product 28: BoolExpression -> ArithmeticExpression ComparisonOperator ArithmeticExpression 
----------------------------------------
Step: 233
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression 
Input: ) { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s51: Shift )
----------------------------------------
Step: 234
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) 
Input: { if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s33: Shift {
----------------------------------------
Step: 235
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { 
Input: if ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s53: Shift if
----------------------------------------
Step: 236
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if 
Input: ( identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s54: Shift (
----------------------------------------
Step: 237
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( 
Input: identifier != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 238
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 78 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( identifier 
Input: != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 239
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 75 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( ArithmeticExpression 
Input: != literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s83: Shift !=
----------------------------------------
Step: 240
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 75 83 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( ArithmeticExpression != 
Input: literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r31: Reduce Product 31: ComparisonOperator -> != 
----------------------------------------
Step: 241
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 75 70 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( ArithmeticExpression ComparisonOperator 
Input: literal ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 242
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 75 70 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( ArithmeticExpression ComparisonOperator literal 
Input: ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 243
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 75 70 76 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( ArithmeticExpression ComparisonOperator ArithmeticExpression 
Input: ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r28: Reduce Product 28: BoolExpression -> ArithmeticExpression ComparisonOperator ArithmeticExpression 
----------------------------------------
Step: 244
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression 
Input: ) { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s56: Shift )
----------------------------------------
Step: 245
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) 
Input: { int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s34: Shift {
----------------------------------------
Step: 246
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { 
Input: int identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s64: Shift int
----------------------------------------
Step: 247
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 64 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { int 
Input: identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r21: Reduce Product 21: Type -> int 
----------------------------------------
Step: 248
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 36 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { Type 
Input: identifier = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s37: Shift identifier
----------------------------------------
Step: 249
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 36 37 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { Type identifier 
Input: = identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s19: Shift =
----------------------------------------
Step: 250
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 36 37 19 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { Type identifier = 
Input: identifier ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s21: Shift identifier
----------------------------------------
Step: 251
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 36 37 19 21 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { Type identifier = identifier 
Input: ( identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s22: Shift (
----------------------------------------
Step: 252
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 36 37 19 21 22 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { Type identifier = identifier ( 
Input: identifier , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 253
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 36 37 19 21 22 78 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { Type identifier = identifier ( identifier 
Input: , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 254
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 36 37 19 21 22 27 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { Type identifier = identifier ( ArithmeticExpression 
Input: , identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s26: Shift ,
----------------------------------------
Step: 255
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 36 37 19 21 22 27 26 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { Type identifier = identifier ( ArithmeticExpression , 
Input: identifier ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 256
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 36 37 19 21 22 27 26 78 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { Type identifier = identifier ( ArithmeticExpression , identifier 
Input: ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 257
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 36 37 19 21 22 27 26 27 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { Type identifier = identifier ( ArithmeticExpression , ArithmeticExpression 
Input: ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r8: Reduce Product 8: ActualArgumentList -> ArithmeticExpression 
----------------------------------------
Step: 258
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 36 37 19 21 22 27 26 28 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { Type identifier = identifier ( ArithmeticExpression , ActualArgumentList 
Input: ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r9: Reduce Product 9: ActualArgumentList -> ArithmeticExpression , ActualArgumentList 
----------------------------------------
Step: 259
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 36 37 19 21 22 24 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { Type identifier = identifier ( ActualArgumentList 
Input: ) ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s25: Shift )
----------------------------------------
Step: 260
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 36 37 19 21 22 24 25 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { Type identifier = identifier ( ActualArgumentList ) 
Input: ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r7: Reduce Product 7: FunctionId -> identifier ( ActualArgumentList ) 
----------------------------------------
Step: 261
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 36 37 19 44 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { Type identifier = FunctionId 
Input: ; } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s45: Shift ;
----------------------------------------
Step: 262
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 36 37 19 44 45 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { Type identifier = FunctionId ; 
Input: } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r14: Reduce Product 14: BlockStatement -> Type identifier = FunctionId ; 
----------------------------------------
Step: 263
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement 
Input: } else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s57: Shift }
----------------------------------------
Step: 264
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } 
Input: else { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s58: Shift else
----------------------------------------
Step: 265
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else 
Input: { int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s35: Shift {
----------------------------------------
Step: 266
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { 
Input: int identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s64: Shift int
----------------------------------------
Step: 267
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 64 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { int 
Input: identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r21: Reduce Product 21: Type -> int 
----------------------------------------
Step: 268
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 36 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { Type 
Input: identifier = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s37: Shift identifier
----------------------------------------
Step: 269
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 36 37 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { Type identifier 
Input: = identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s19: Shift =
----------------------------------------
Step: 270
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 36 37 19 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { Type identifier = 
Input: identifier ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s21: Shift identifier
----------------------------------------
Step: 271
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 36 37 19 21 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { Type identifier = identifier 
Input: ( identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s22: Shift (
----------------------------------------
Step: 272
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 36 37 19 21 22 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { Type identifier = identifier ( 
Input: identifier , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 273
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 36 37 19 21 22 78 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { Type identifier = identifier ( identifier 
Input: , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 274
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 36 37 19 21 22 27 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { Type identifier = identifier ( ArithmeticExpression 
Input: , identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s26: Shift ,
----------------------------------------
Step: 275
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 36 37 19 21 22 27 26 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { Type identifier = identifier ( ArithmeticExpression , 
Input: identifier ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 276
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 36 37 19 21 22 27 26 78 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { Type identifier = identifier ( ArithmeticExpression , identifier 
Input: ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 277
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 36 37 19 21 22 27 26 27 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { Type identifier = identifier ( ArithmeticExpression , ArithmeticExpression 
Input: ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r8: Reduce Product 8: ActualArgumentList -> ArithmeticExpression 
----------------------------------------
Step: 278
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 36 37 19 21 22 27 26 28 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { Type identifier = identifier ( ArithmeticExpression , ActualArgumentList 
Input: ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r9: Reduce Product 9: ActualArgumentList -> ArithmeticExpression , ActualArgumentList 
----------------------------------------
Step: 279
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 36 37 19 21 22 24 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { Type identifier = identifier ( ActualArgumentList 
Input: ) ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s25: Shift )
----------------------------------------
Step: 280
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 36 37 19 21 22 24 25 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { Type identifier = identifier ( ActualArgumentList ) 
Input: ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r7: Reduce Product 7: FunctionId -> identifier ( ActualArgumentList ) 
----------------------------------------
Step: 281
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 36 37 19 44 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { Type identifier = FunctionId 
Input: ; string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s45: Shift ;
----------------------------------------
Step: 282
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 36 37 19 44 45 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { Type identifier = FunctionId ; 
Input: string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r14: Reduce Product 14: BlockStatement -> Type identifier = FunctionId ; 
----------------------------------------
Step: 283
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 32 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { BlockStatement 
Input: string identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s65: Shift string
----------------------------------------
Step: 284
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 32 65 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { BlockStatement string 
Input: identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r22: Reduce Product 22: Type -> string 
----------------------------------------
Step: 285
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 32 36 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { BlockStatement Type 
Input: identifier = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s37: Shift identifier
----------------------------------------
Step: 286
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 32 36 37 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { BlockStatement Type identifier 
Input: = literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s19: Shift =
----------------------------------------
Step: 287
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 32 36 37 19 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { BlockStatement Type identifier = 
Input: literal ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 288
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 32 36 37 19 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { BlockStatement Type identifier = literal 
Input: ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 289
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 32 36 37 19 39 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { BlockStatement Type identifier = ArithmeticExpression 
Input: ; } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s40: Shift ;
----------------------------------------
Step: 290
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 32 36 37 19 39 40 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { BlockStatement Type identifier = ArithmeticExpression ; 
Input: } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r12: Reduce Product 12: BlockStatement -> Type identifier = ArithmeticExpression ; 
----------------------------------------
Step: 291
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 32 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { BlockStatement BlockStatement 
Input: } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r10: Reduce Product 10: BlockStatement -> BlockStatement BlockStatement 
----------------------------------------
Step: 292
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 32 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { BlockStatement 
Input: } } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s59: Shift }
----------------------------------------
Step: 293
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 53 54 55 56 34 31 57 58 35 32 59 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
Input: } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r18: Reduce Product 18: BlockStatement -> if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
----------------------------------------
Step: 294
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 30 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { BlockStatement 
Input: } } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s52: Shift }
----------------------------------------
Step: 295
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 48 49 50 51 33 30 52 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement while ( BoolExpression ) { BlockStatement } 
Input: } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r16: Reduce Product 16: BlockStatement -> while ( BoolExpression ) { BlockStatement } 
----------------------------------------
Step: 296
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement BlockStatement 
Input: } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r10: Reduce Product 10: BlockStatement -> BlockStatement BlockStatement 
----------------------------------------
Step: 297
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement BlockStatement 
Input: } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r10: Reduce Product 10: BlockStatement -> BlockStatement BlockStatement 
----------------------------------------
Step: 298
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement 
Input: } } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s52: Shift }
----------------------------------------
Step: 299
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 48 49 50 51 33 30 52 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { while ( BoolExpression ) { BlockStatement } 
Input: } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r16: Reduce Product 16: BlockStatement -> while ( BoolExpression ) { BlockStatement } 
----------------------------------------
Step: 300
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 31 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { BlockStatement 
Input: } else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s57: Shift }
----------------------------------------
Step: 301
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 31 57 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { BlockStatement } 
Input: else { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s58: Shift else
----------------------------------------
Step: 302
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 31 57 58 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { BlockStatement } else 
Input: { identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s35: Shift {
----------------------------------------
Step: 303
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 31 57 58 35 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { BlockStatement } else { 
Input: identifier = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s41: Shift identifier
----------------------------------------
Step: 304
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 31 57 58 35 41 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { BlockStatement } else { identifier 
Input: = literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s20: Shift =
----------------------------------------
Step: 305
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 31 57 58 35 41 20 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { BlockStatement } else { identifier = 
Input: literal ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 306
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 31 57 58 35 41 20 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { BlockStatement } else { identifier = literal 
Input: ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 307
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 31 57 58 35 41 20 42 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { BlockStatement } else { identifier = ArithmeticExpression 
Input: ; } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s43: Shift ;
----------------------------------------
Step: 308
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 31 57 58 35 41 20 42 43 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { BlockStatement } else { identifier = ArithmeticExpression ; 
Input: } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r13: Reduce Product 13: BlockStatement -> identifier = ArithmeticExpression ; 
----------------------------------------
Step: 309
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 31 57 58 35 32 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { BlockStatement } else { BlockStatement 
Input: } } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s59: Shift }
----------------------------------------
Step: 310
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 53 54 55 56 34 31 57 58 35 32 59 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
Input: } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r18: Reduce Product 18: BlockStatement -> if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
----------------------------------------
Step: 311
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement BlockStatement 
Input: } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r10: Reduce Product 10: BlockStatement -> BlockStatement BlockStatement 
----------------------------------------
Step: 312
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement 
Input: } else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s57: Shift }
----------------------------------------
Step: 313
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 57 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement } 
Input: else { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s58: Shift else
----------------------------------------
Step: 314
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 57 58 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement } else 
Input: { identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s35: Shift {
----------------------------------------
Step: 315
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 57 58 35 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement } else { 
Input: identifier = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s41: Shift identifier
----------------------------------------
Step: 316
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 57 58 35 41 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement } else { identifier 
Input: = literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s20: Shift =
----------------------------------------
Step: 317
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 57 58 35 41 20 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement } else { identifier = 
Input: literal ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 318
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 57 58 35 41 20 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement } else { identifier = literal 
Input: ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 319
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 57 58 35 41 20 42 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement } else { identifier = ArithmeticExpression 
Input: ; } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s43: Shift ;
----------------------------------------
Step: 320
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 57 58 35 41 20 42 43 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement } else { identifier = ArithmeticExpression ; 
Input: } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r13: Reduce Product 13: BlockStatement -> identifier = ArithmeticExpression ; 
----------------------------------------
Step: 321
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 57 58 35 32 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement } else { BlockStatement 
Input: } while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s59: Shift }
----------------------------------------
Step: 322
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 53 54 55 56 34 31 57 58 35 32 59 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
Input: while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r18: Reduce Product 18: BlockStatement -> if ( BoolExpression ) { BlockStatement } else { BlockStatement } 
----------------------------------------
Step: 323
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement 
Input: while ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s48: Shift while
----------------------------------------
Step: 324
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while 
Input: ( identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s49: Shift (
----------------------------------------
Step: 325
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( 
Input: identifier == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 326
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 78 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( identifier 
Input: == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 327
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 75 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( ArithmeticExpression 
Input: == literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s82: Shift ==
----------------------------------------
Step: 328
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 75 82 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( ArithmeticExpression == 
Input: literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r30: Reduce Product 30: ComparisonOperator -> == 
----------------------------------------
Step: 329
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 75 70 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( ArithmeticExpression ComparisonOperator 
Input: literal ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 330
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 75 70 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( ArithmeticExpression ComparisonOperator literal 
Input: ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 331
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 75 70 76 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( ArithmeticExpression ComparisonOperator ArithmeticExpression 
Input: ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r28: Reduce Product 28: BoolExpression -> ArithmeticExpression ComparisonOperator ArithmeticExpression 
----------------------------------------
Step: 332
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 50 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( BoolExpression 
Input: ) { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s51: Shift )
----------------------------------------
Step: 333
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 50 51 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( BoolExpression ) 
Input: { identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s33: Shift {
----------------------------------------
Step: 334
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 50 51 33 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( BoolExpression ) { 
Input: identifier = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s41: Shift identifier
----------------------------------------
Step: 335
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 50 51 33 41 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( BoolExpression ) { identifier 
Input: = identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s20: Shift =
----------------------------------------
Step: 336
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 50 51 33 41 20 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( BoolExpression ) { identifier = 
Input: identifier + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s21: Shift identifier
----------------------------------------
Step: 337
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 50 51 33 41 20 21 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( BoolExpression ) { identifier = identifier 
Input: + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 338
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 50 51 33 41 20 42 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( BoolExpression ) { identifier = ArithmeticExpression 
Input: + literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s84: Shift +
----------------------------------------
Step: 339
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 50 51 33 41 20 42 84 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( BoolExpression ) { identifier = ArithmeticExpression + 
Input: literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r32: Reduce Product 32: ArithmeticOperator -> + 
----------------------------------------
Step: 340
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 50 51 33 41 20 42 66 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( BoolExpression ) { identifier = ArithmeticExpression ArithmeticOperator 
Input: literal ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 341
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 50 51 33 41 20 42 66 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( BoolExpression ) { identifier = ArithmeticExpression ArithmeticOperator literal 
Input: ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 342
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 50 51 33 41 20 42 66 71 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( BoolExpression ) { identifier = ArithmeticExpression ArithmeticOperator ArithmeticExpression 
Input: ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r23: Reduce Product 23: ArithmeticExpression -> ArithmeticExpression ArithmeticOperator ArithmeticExpression 
----------------------------------------
Step: 343
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 50 51 33 41 20 42 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( BoolExpression ) { identifier = ArithmeticExpression 
Input: ; } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s43: Shift ;
----------------------------------------
Step: 344
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 50 51 33 41 20 42 43 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( BoolExpression ) { identifier = ArithmeticExpression ; 
Input: } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r13: Reduce Product 13: BlockStatement -> identifier = ArithmeticExpression ; 
----------------------------------------
Step: 345
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 50 51 33 30 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( BoolExpression ) { BlockStatement 
Input: } if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s52: Shift }
----------------------------------------
Step: 346
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 48 49 50 51 33 30 52 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement while ( BoolExpression ) { BlockStatement } 
Input: if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r16: Reduce Product 16: BlockStatement -> while ( BoolExpression ) { BlockStatement } 
----------------------------------------
Step: 347
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement 
Input: if ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s53: Shift if
----------------------------------------
Step: 348
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if 
Input: ( identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s54: Shift (
----------------------------------------
Step: 349
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( 
Input: identifier == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s78: Shift identifier
----------------------------------------
Step: 350
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 78 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( identifier 
Input: == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r26: Reduce Product 26: ArithmeticExpression -> identifier 
----------------------------------------
Step: 351
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 75 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( ArithmeticExpression 
Input: == literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s82: Shift ==
----------------------------------------
Step: 352
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 75 82 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( ArithmeticExpression == 
Input: literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r30: Reduce Product 30: ComparisonOperator -> == 
----------------------------------------
Step: 353
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 75 70 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( ArithmeticExpression ComparisonOperator 
Input: literal ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 354
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 75 70 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( ArithmeticExpression ComparisonOperator literal 
Input: ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 355
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 75 70 76 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( ArithmeticExpression ComparisonOperator ArithmeticExpression 
Input: ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r28: Reduce Product 28: BoolExpression -> ArithmeticExpression ComparisonOperator ArithmeticExpression 
----------------------------------------
Step: 356
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression 
Input: ) { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s56: Shift )
----------------------------------------
Step: 357
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) 
Input: { identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s34: Shift {
----------------------------------------
Step: 358
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { 
Input: identifier = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s41: Shift identifier
----------------------------------------
Step: 359
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 41 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { identifier 
Input: = literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s20: Shift =
----------------------------------------
Step: 360
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 41 20 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { identifier = 
Input: literal ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 361
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 41 20 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { identifier = literal 
Input: ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 362
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 41 20 42 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { identifier = ArithmeticExpression 
Input: ; string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s43: Shift ;
----------------------------------------
Step: 363
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 41 20 42 43 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { identifier = ArithmeticExpression ; 
Input: string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r13: Reduce Product 13: BlockStatement -> identifier = ArithmeticExpression ; 
----------------------------------------
Step: 364
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 31 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement 
Input: string identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s65: Shift string
----------------------------------------
Step: 365
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 31 65 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement string 
Input: identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r22: Reduce Product 22: Type -> string 
----------------------------------------
Step: 366
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 31 36 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement Type 
Input: identifier = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s37: Shift identifier
----------------------------------------
Step: 367
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 31 36 37 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement Type identifier 
Input: = literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s19: Shift =
----------------------------------------
Step: 368
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 31 36 37 19 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement Type identifier = 
Input: literal ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 369
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 31 36 37 19 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement Type identifier = literal 
Input: ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 370
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 31 36 37 19 39 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement Type identifier = ArithmeticExpression 
Input: ; } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s40: Shift ;
----------------------------------------
Step: 371
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 31 36 37 19 39 40 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement Type identifier = ArithmeticExpression ; 
Input: } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r12: Reduce Product 12: BlockStatement -> Type identifier = ArithmeticExpression ; 
----------------------------------------
Step: 372
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 31 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement BlockStatement 
Input: } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r10: Reduce Product 10: BlockStatement -> BlockStatement BlockStatement 
----------------------------------------
Step: 373
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 31 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement 
Input: } string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s57: Shift }
----------------------------------------
Step: 374
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 53 54 55 56 34 31 57 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement if ( BoolExpression ) { BlockStatement } 
Input: string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r17: Reduce Product 17: BlockStatement -> if ( BoolExpression ) { BlockStatement } 
----------------------------------------
Step: 375
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement 
Input: string identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s65: Shift string
----------------------------------------
Step: 376
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 65 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement string 
Input: identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
r22: Reduce Product 22: Type -> string 
----------------------------------------
Step: 377
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 36 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement Type 
Input: identifier = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s37: Shift identifier
----------------------------------------
Step: 378
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 36 37 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement Type identifier 
Input: = identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s19: Shift =
----------------------------------------
Step: 379
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 36 37 19 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement Type identifier = 
Input: identifier ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s21: Shift identifier
----------------------------------------
Step: 380
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 36 37 19 21 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement Type identifier = identifier 
Input: ( ) ; string identifier = identifier ( ) ; return literal ; } $ 
s22: Shift (
----------------------------------------
Step: 381
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 36 37 19 21 22 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement Type identifier = identifier ( 
Input: ) ; string identifier = identifier ( ) ; return literal ; } $ 
s23: Shift )
----------------------------------------
Step: 382
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 36 37 19 21 22 23 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement Type identifier = identifier ( ) 
Input: ; string identifier = identifier ( ) ; return literal ; } $ 
r6: Reduce Product 6: FunctionId -> identifier ( ) 
----------------------------------------
Step: 383
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 36 37 19 44 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement Type identifier = FunctionId 
Input: ; string identifier = identifier ( ) ; return literal ; } $ 
s45: Shift ;
----------------------------------------
Step: 384
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 36 37 19 44 45 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement Type identifier = FunctionId ; 
Input: string identifier = identifier ( ) ; return literal ; } $ 
r14: Reduce Product 14: BlockStatement -> Type identifier = FunctionId ; 
----------------------------------------
Step: 385
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement 
Input: string identifier = identifier ( ) ; return literal ; } $ 
s65: Shift string
----------------------------------------
Step: 386
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 65 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement string 
Input: identifier = identifier ( ) ; return literal ; } $ 
r22: Reduce Product 22: Type -> string 
----------------------------------------
Step: 387
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 36 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement Type 
Input: identifier = identifier ( ) ; return literal ; } $ 
s37: Shift identifier
----------------------------------------
Step: 388
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 36 37 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement Type identifier 
Input: = identifier ( ) ; return literal ; } $ 
s19: Shift =
----------------------------------------
Step: 389
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 36 37 19 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement Type identifier = 
Input: identifier ( ) ; return literal ; } $ 
s21: Shift identifier
----------------------------------------
Step: 390
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 36 37 19 21 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement Type identifier = identifier 
Input: ( ) ; return literal ; } $ 
s22: Shift (
----------------------------------------
Step: 391
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 36 37 19 21 22 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement Type identifier = identifier ( 
Input: ) ; return literal ; } $ 
s23: Shift )
----------------------------------------
Step: 392
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 36 37 19 21 22 23 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement Type identifier = identifier ( ) 
Input: ; return literal ; } $ 
r6: Reduce Product 6: FunctionId -> identifier ( ) 
----------------------------------------
Step: 393
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 36 37 19 44 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement Type identifier = FunctionId 
Input: ; return literal ; } $ 
s45: Shift ;
----------------------------------------
Step: 394
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 36 37 19 44 45 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement Type identifier = FunctionId ; 
Input: return literal ; } $ 
r14: Reduce Product 14: BlockStatement -> Type identifier = FunctionId ; 
----------------------------------------
Step: 395
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement 
Input: return literal ; } $ 
s60: Shift return
----------------------------------------
Step: 396
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 29 60 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement return 
Input: literal ; } $ 
s79: Shift literal
----------------------------------------
Step: 397
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 29 60 79 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement return literal 
Input: ; } $ 
r27: Reduce Product 27: ArithmeticExpression -> literal 
----------------------------------------
Step: 398
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 29 60 62 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement return ArithmeticExpression 
Input: ; } $ 
s63: Shift ;
----------------------------------------
Step: 399
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 29 60 62 63 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement return ArithmeticExpression ; 
Input: } $ 
r20: Reduce Product 20: BlockStatement -> return ArithmeticExpression ; 
----------------------------------------
Step: 400
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 29 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement 
Input: } $ 
r10: Reduce Product 10: BlockStatement -> BlockStatement BlockStatement 
----------------------------------------
Step: 401
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement 
Input: } $ 
r10: Reduce Product 10: BlockStatement -> BlockStatement BlockStatement 
----------------------------------------
Step: 402
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement 
Input: } $ 
r10: Reduce Product 10: BlockStatement -> BlockStatement BlockStatement 
----------------------------------------
Step: 403
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement 
Input: } $ 
r10: Reduce Product 10: BlockStatement -> BlockStatement BlockStatement 
----------------------------------------
Step: 404
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement 
Input: } $ 
r10: Reduce Product 10: BlockStatement -> BlockStatement BlockStatement 
----------------------------------------
Step: 405
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement BlockStatement 
Input: } $ 
r10: Reduce Product 10: BlockStatement -> BlockStatement BlockStatement 
----------------------------------------
Step: 406
Status: 0 1 2 2 3 4 5 6 7 8 29 29 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement BlockStatement 
Input: } $ 
r10: Reduce Product 10: BlockStatement -> BlockStatement BlockStatement 
----------------------------------------
Step: 407
Status: 0 1 2 2 3 4 5 6 7 8 29 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement BlockStatement 
Input: } $ 
r10: Reduce Product 10: BlockStatement -> BlockStatement BlockStatement 
----------------------------------------
Step: 408
Status: 0 1 2 2 3 4 5 6 7 8 29 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement BlockStatement 
Input: } $ 
r10: Reduce Product 10: BlockStatement -> BlockStatement BlockStatement 
----------------------------------------
Step: 409
Status: 0 1 2 2 3 4 5 6 7 8 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement 
Input: } $ 
s9: Shift }
----------------------------------------
Step: 410
Status: 0 1 2 2 3 4 5 6 7 8 9 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration Type identifier ( ) { BlockStatement } 
Input: $ 
r2: Reduce Product 2: FunctionDeclaration -> Type identifier ( ) { BlockStatement } 
----------------------------------------
Step: 411
Status: 0 1 2 2 2 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration FunctionDeclaration 
Input: $ 
r1: Reduce Product 1: FunctionDeclaration -> FunctionDeclaration FunctionDeclaration 
----------------------------------------
Step: 412
Status: 0 1 2 2 
Symbol: $ FunctionDeclaration FunctionDeclaration FunctionDeclaration 
Input: $ 
r1: Reduce Product 1: FunctionDeclaration -> FunctionDeclaration FunctionDeclaration 
----------------------------------------
Step: 413
Status: 0 1 2 
Symbol: $ FunctionDeclaration FunctionDeclaration 
Input: $ 
r1: Reduce Product 1: FunctionDeclaration -> FunctionDeclaration FunctionDeclaration 
----------------------------------------
Step: 414
Status: 0 1 
Symbol: $ FunctionDeclaration 
Input: $ 
r0: Reduce Product 0: Program -> FunctionDeclaration 
----------------------------------------
Step: 415
Status: 0 88 
Symbol: $ Program 
Input: $ 
acc: Accept! Syntax analysis completed.
```
