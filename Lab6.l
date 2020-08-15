%{
void comentario (void);
char tratachar (char *c);
%}
delim			[ \t\n\r]
ws				{delim}+
letra			[A-Za-z]
digito			[0-9]
id				{letra}({letra}|{digito})*
ctint			{digito}+
ctreal			{digito}+\.{digito}*([Ee][+-]?{digito}+)?
carac1			\\.|[^\\']
ctcarac	   	 	'{carac1}'
carac2	   		\\.|[^\\\"]
string	 		\"{carac2}*\"
%%	
{ws}            { ;}
carac			{strcpy(yylval.cadeia, "carac"); return CARAC;}
funcao			{strcpy(yylval.cadeia, "funcao"); return FUNCAO;}
procedimento	{strcpy(yylval.cadeia, "procedimento"); return PROCEDIMENTO;}
senao			{strcpy(yylval.cadeia, "senao"); return SENAO;}
chamar			{strcpy(yylval.cadeia, "chamar"); return CHAMAR;}
int				{strcpy(yylval.cadeia, "int"); return INT;}
programa		{strcpy(yylval.cadeia, "programa"); return PROGRAMA;}
var				{strcpy(yylval.cadeia, "var"); return VAR;}
comandos		{strcpy(yylval.cadeia, "comandos"); return COMANDOS;}
ler				{strcpy(yylval.cadeia, "ler"); return LER;}
real			{strcpy(yylval.cadeia, "real"); return REAL;}
verdade			{strcpy(yylval.cadeia, "verdade"); return VERDADE;}
enquanto		{strcpy(yylval.cadeia, "enquanto"); return ENQUANTO;}
logic			{strcpy(yylval.cadeia, "logic"); return LOGIC;}
repetir			{strcpy(yylval.cadeia, "repetir"); return REPETIR;}
escrever		{strcpy(yylval.cadeia, "escrever"); return ESCREVER;}
para			{strcpy(yylval.cadeia, "para"); return PARA;}
retornar		{strcpy(yylval.cadeia, "retornar"); return RETORNAR;}
falso			{strcpy(yylval.cadeia, "falso"); return FALSO;}
principal		{strcpy(yylval.cadeia, "principal"); return PRINCIPAL;}
se				{strcpy(yylval.cadeia, "se"); return SE;}
"{{{"			{strcpy(yylval.cadeia, "{{{"); return ABTRIP;}
"}}}"			{strcpy(yylval.cadeia, "}}}"); return FTRIP;}
"||"			{strcpy(yylval.cadeia, "||"); return OR;}
"&&"			{strcpy(yylval.cadeia, "&&"); return AND;}
"<"				{yylval.atr = MENOR; return OPREL;}
">"				{yylval.atr = MAIOR; return OPREL;}
"<="			{yylval.atr = MENIG; return OPREL;}
">="			{yylval.atr = MAIG; return OPREL;}
"=="			{yylval.atr = IGUAL; return OPREL;}
"!="			{yylval.atr = DIFERENTE; return OPREL;}
"+"				{yylval.atr = MAIS; return OPAD;}
"-"				{yylval.atr = MENOS; return OPAD;}
"*"				{yylval.atr = VEZES; return OPMULT;}
"/"				{yylval.atr = DIV; return OPMULT;}
"%"				{yylval.atr = MODULO; return OPMULT;}
"!"				{yylval.carac = '!'; return NOT;}
"~"				{yylval.carac = '~'; return NEG;}
"="				{yylval.carac = '='; return ATRIB;}
"("				{yylval.carac = '('; return ABPAR;}
")"				{yylval.carac = ')'; return FPAR;}
"["				{yylval.carac = '['; return ABCOL;}
"]"				{yylval.carac = ']'; return FCOL;}
"{"				{yylval.carac = '{'; return ABCHAV;}
"}"				{yylval.carac = '}'; return FCHAV;}
";"				{yylval.carac = ';'; return PVIRG;}
","				{yylval.carac = ','; return VIRG;}
{id}			{strcpy(yylval.cadeia, yytext); return ID;}
{ctint}			{strcpy(yylval.cadeia, yytext); return CTINT;}
{ctcarac}		{strcpy(yylval.cadeia, yytext); return CTCARAC;}
{ctreal}		{strcpy(yylval.cadeia, yytext); return CTREAL;}
{string}		{strcpy(yylval.cadeia, yytext); return CADEIA;}
"/*"			{comentario();}
.				{strcpy(yylval.cadeia, yytext); return OTHER;}
%%

void comentario() {
	char c;
	int estado;
	estado = 1;
	while (estado != 3) {
		switch(estado) {
			case 1:
			c = input();
			if(c == EOF)
				estado = 3;
			else if(c == '*')
				estado = 2;
			break;
		case 2:
			c = input();
			if(c == '/' || c == EOF)
				estado = 3;
			else if(c != '*')
				estado = 1;
			break;
		}	
	}
}

char tratachar (char *s) {
	if (s[1] != '\\') return s[1];
	else switch (s[2]) {
		case 'a': 	return 7;		case '\\': 	return 92;
		case 'b': 	return 8;		case 'r': 	return 13;
		case '\"': 	return 34;		case 'f': 	return 12;
		case 't': 	return 9;		case 'n': 	return 10;
		case '0': 	return 0;		case '\'': 	return 39;
		case 'v': 	return 11;
		default:	return s[2];
	}
}
