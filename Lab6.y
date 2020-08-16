%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define     OPOR          1
#define     OPAND         2
#define     OPNOT         3
#define     OPLT          4
#define     OPLE          5
#define     OPGT          6
#define     OPGE          7
#define     OPMAIS        8
#define     OPMENOS       9
#define     OPVEZES       10
#define     OPDIV         11
#define     OPMODULO      12
#define     OPNEG         13
#define     OPATRIB       14
#define     PARAM         15
#define     CALLOP        16
#define     OPENMOD       17
#define     OPRETURN      18
#define     OPLER         19
#define     OPWRITE       20
#define     OPJUMP        21
#define     OPJF          22
#define		OPEXIT		  23
#define     OPINDEX       24
#define     ATRIBPONT     25
#define     CONTPONT      26
#define     NOP           27
#define     OPIGUAL       28
#define     OPDIF         29
#define     OPIND         30

#define     IDLEOPND    0
#define     VAROPND     1
#define     INTOPND     2
#define     REALOPND    3
#define     CHAROPND    4
#define     LOGICOPND   5
#define     CADOPND     6
#define     ROTOPND     7
#define     MODOPND     8
#define     FUNCPND     9
#define     PROCPND     10

#define MENOR           1
#define MAIOR           2
#define MENIG           3
#define MAIG            4
#define IGUAL           5
#define DIFERENTE       6
#define MAIS            7
#define MENOS           8
#define VEZES           9
#define DIV             10
#define MODULO          11


#define NCLASSHASH      23
#define MAXDIMS         100
#define TRUE            1
#define FALSE           0


#define NOTVAR          0
#define CHAR            1
#define INTEGER         2
#define FLOAT           3
#define LOGICAL         4
#define PTRCHAR         5
#define PTRINT          6
#define PTRFLOAT        7
#define PTRLOG          8 

#define IDPROG          1
#define IDVAR           2
#define IDFUNC          3
#define IDPROC          4
#define SCOPE           5

#define CMDLER          1
#define CMDPARA         2
#define CMDATRIB        3


char *nometipid[6]  =  {"", "IDPROG", "IDVAR","IDFUNC","IDPROC", "SCOPE"};
char *nometipvar[9] = {"NOTVAR","CHAR","INTEGER","FLOAT","LOGICAL", "PTRCHAR", "PTRINT", "PTRFLOAT", "PTRLOG"};
char *nomeoperquad[31] = {"",
    "OPOR", "OPAND", "OPNOT", "OPLT", "OPLE", "OPGT", "OPGE", "OPMAIS", "OPMENOS", 
    "OPVEZES", "OPDIV", "OPMODULO", "OPNEG", "OPATRIB", "PARAM", "CALLOP", 
    "OPENMOD", "OPRETURN", "OPREAD", "OPWRITE", "OPJUMP", "OPJF", "OPEXIT",
    "INDEX", "ATRIBPONT", "CONTPONT", "NOP", "OPIGUAL", "OPDIF", "IND"
};

char *nometipoopndquad[11] = {"IDLE",
	"VAR", "INT", "REAL", "CARAC", "LOGIC", "CADEIA", "ROTULO", "MODULO", 
    "FUNCAO", "PROCEDIMENTO"
};

FILE *finput;


typedef struct elemlistsimb elemlistsimb;
typedef elemlistsimb *pontelemlistsimb;
typedef elemlistsimb *listsimb;
typedef struct celmodhead celmodhead;
typedef celmodhead *modhead;
typedef struct celquad celquad;
typedef celquad* quadrupla;

typedef struct celsimb celsimb;
typedef celsimb *simbolo;
struct celsimb{
    char* cadeia;
    int tid, tvar, nparams, ndims;
    int dims[MAXDIMS+1];
    char inic, ref;
    listsimb listparamc, listparamf;
    simbolo prox, escopo;
    int *valint;
	float *valfloat;
  	char *valchar, *vallogic;
};

typedef union atribopnd atribopnd;
union atribopnd {
    simbolo simb;
    int valint;
    float valfloat;
    char valchar;
    char vallogic;
    char *valcad;
    quadrupla rotulo;
    modhead modulo;
};

typedef struct operando operando;
struct operando {
    int tipo;
    atribopnd atr;
};

struct celquad{
    int num;
    int oper;
    operando opnd1, opnd2;
    operando result;
    quadrupla prox;
};

struct celmodhead{
    simbolo modname;
    modhead prox;
    quadrupla listquad;
};

typedef struct nohPilha nohPilha;
typedef struct nohPilha* pilhaPtr;
struct nohPilha{
    int num;
    nohPilha * prox;
};

typedef struct nohopnd nohopnd;
struct nohopnd {
	operando opnd;
	nohopnd *prox;
};
typedef nohopnd *pilhaoperando;
pilhaoperando pilhaopnd;

pilhaPtr pilhaTopo;
struct elemlistsimb {
	simbolo simb; 
	pontelemlistsimb prox;
};

typedef struct infoexpressao infoexpressao;
struct infoexpressao {
    int tipo;
    operando opnd;
};

typedef struct contexto contexto;
struct contexto{
    modhead moduloAtual;
    quadrupla quadruplaAtual;
    operando result;
};

typedef struct nohcontexto nohcontexto;
struct nohcontexto {
	contexto context;
	nohcontexto *prox;
};
typedef nohcontexto* pilhacontexto;
pilhacontexto pilhacontext;


typedef struct infovariavel infovariavel;
struct infovariavel {
    simbolo simb;
    operando opnd;
};

simbolo tabsimb[NCLASSHASH];
simbolo moduloChamado = NULL;
pontelemlistsimb paramAtual = NULL;
simbolo global;
quadrupla quadcorrente, quadaux;
modhead codintermed, modcorrente,codintermedaux;
int oper, numquadcorrente;
operando opnd1, opnd2, result, opndaux;
int numtemp;
const operando opndidle = {IDLEOPND, 0};


void Empilha(int n);
int Desempilha();
void InicTabSimb();
void ImprimeTabSimb();
simbolo InsereSimb(char *cadeia, int tid, int tvar, simbolo escopo);
int hash (char *cadeia);
simbolo ProcuraSimb (char * cadeia, simbolo escopo);
void DeclaracaoRepetida (char *s);
void TipoInadequado (char *s);
void NaoDeclarado (char *s);
void ImprimeNaoUsados();
char * createScopeString(const char string[20]);
void ReturnInadequado ();
void ReturnVazio();
void DimensaoInvalida();
void TipoIncompativel();
int EhIntRealCarac(int s1, int s2);
int EhLogico(int s1);
void DimensoesFaltantesOuInvalidas();
void EscalarComSubs();
void IndexadaSemSubs();
void InsereParametro(simbolo modulo, simbolo param);
void ModuloComoArgumento();
void RecursaoNaoPermitida();
void ParametroAMais();
void ParametroIncompativel();
void ParametrosFaltantes();
void TestaCompatibilidade(int param, int arg);
void tabular();
void jumpLines();
void isRepeat();

void ImprimeQuadruplas(void);
void InicCodIntermed();
void InicCodIntermedMod(simbolo simb);
quadrupla GeraQuadrupla(int oper,operando opnd1,operando opnd2,operando result);
simbolo NovaTemp(int tip);
void RenumQuadruplas(quadrupla quad1, quadrupla quad2);
void TrataLeitura(infovariavel var);

void EmpilharOpnd(operando x, pilhaoperando *P);
void DesempilharOpnd(pilhaoperando *P);
operando TopoOpnd(pilhaoperando P);
void InicPilhaOpnd(pilhaoperando *P);
char VaziaOpnd(pilhaoperando P);

void EmpilharContexto(contexto x, pilhacontexto *P);
void DesempilharContexto(pilhacontexto *P);
contexto TopoContexto(pilhacontexto P);
void InicPilhaContexto(pilhacontexto *P);
char VaziaContexto(pilhacontexto P);


void ExecQuadCallop(quadrupla quad);

int tipocorrente;
int tab = 0;
int newLines = 0;
int repeat = 0;
int enquantoTabular = 0;
simbolo escopoAtual;
int ehDecl = 0;
int cmdAtual;
int subsc = 0;
int countParams =0;
simbolo atual;


void InterpCodIntermed(void);
void InterpCodIntermedSubProgramas(void);
void AlocaVariaveis(quadrupla quad);
%}
%union {
    char cadeia[50];
    int valint;
    float valreal;
    int atr;
    int dim;
    int nsubscr;
    infoexpressao infoexpr;
    infovariavel infovar;
    char carac;
    simbolo simb;
    quadrupla quad;
}

%type  <infovar>    Variavel
%type  <infoexpr>   Expressao ExprAux1 ExprAux2 ExprAux3 ExprAux4 Termo Fator ChamadaFunc
%token <cadeia> CARAC
%token <cadeia> FUNCAO
%token <cadeia> PROCEDIMENTO
%token <cadeia> SENAO
%token <cadeia> CHAMAR
%token <cadeia> INT
%token <cadeia> PROGRAMA
%token <cadeia> VAR
%token <cadeia> COMANDOS
%token <cadeia> LER
%token <cadeia> REAL
%token <cadeia> VERDADE
%token <cadeia> ENQUANTO
%token <cadeia> LOGIC
%token <cadeia> REPETIR
%token <cadeia> ESCREVER
%token <cadeia> PARA
%token <cadeia> RETORNAR
%token <cadeia> FALSO
%token <cadeia> PRINCIPAL
%token <cadeia> SE
%token <cadeia> ABTRIP
%token <cadeia> FTRIP
%token <cadeia> OR
%token <cadeia> AND
%token <atr>    OPREL
%token <atr>    OPAD
%token <atr>    OPMULT
%token <carac>  NOT
%token <carac>  NEG
%token <carac>  ATRIB
%token <carac>  ABPAR
%token <carac>  FPAR
%token <carac>  ABCOL
%token <carac>  FCOL
%token <carac>  ABCHAV
%token <carac>  FCHAV
%token <carac>  PVIRG
%token <carac>  VIRG
%token <cadeia> ID
%token <cadeia> CTINT
%token <cadeia> CTCARAC
%token <cadeia> CTREAL
%token <cadeia> CADEIA
%token <cadeia> OTHER
%%
Prog       :    PROGRAMA {InicTabSimb();printf("%s ", $1); InicCodIntermed(); pilhaTopo = NULL;} 
                ID {printf("%s ", $3);}
                ABTRIP {printf("%s\n\n", $5); 
                char * scope = createScopeString("##global");
                escopoAtual = InsereSimb(scope, NOTVAR, SCOPE, NULL);
                global = escopoAtual;
                simbolo simb = InsereSimb($3,IDPROG,NOTVAR, escopoAtual);
                InicCodIntermedMod(escopoAtual);
                opnd1.tipo = MODOPND;
                opnd1.atr.modulo = modcorrente;
                GeraQuadrupla(OPENMOD, opnd1, opndidle, opndidle);
                free(scope);
                ehDecl = 1;
                }
                Decls
                ListMod
                ModPrincipal {
                        modcorrente = codintermed->prox;
                        quadcorrente = codintermed->prox->listquad->prox;
                        opnd1.tipo = PROCPND;
                        ehDecl = 0;
                        simbolo simb = ProcuraSimb("principal", global);
                        opnd1.atr.simb = simb;
                        GeraQuadrupla(CALLOP, opnd1, opndidle, opndidle);
                        GeraQuadrupla(OPEXIT, opndidle, opndidle, opndidle);
                }
                FTRIP {printf("%s\n", $11);
                ImprimeNaoUsados();
                ImprimeTabSimb();
                ImprimeQuadruplas();
                InterpCodIntermed();
                }
                ;

Decls       :
            |   VAR {printf("%s ", $1);}
                ABCHAV {printf("%c\n", $3); tab++;}
                ListDecl
                FCHAV {printf("%c\n\n", $6); tab--; ehDecl = 0;}
            ;

ListDecl    :   Declaracao
            |   ListDecl
                Declaracao
            ;

Declaracao  :   Tipo
                ABPAR {printf("%c", $2);}
                ListElem
                FPAR {printf("%c\n", $5);}
            ;

Tipo        :
                INT {tabular(); printf("%s ", $1); tipocorrente = INTEGER;}
            |   REAL {tabular(); printf("%s ", $1);tipocorrente = FLOAT;}
            |   CARAC {tabular(); printf("%s ", $1);tipocorrente = CHAR;}
            |   LOGIC {tabular(); printf("%s ", $1);tipocorrente = LOGICAL;}
            ;

ListElem    :   Elem
            |   ListElem
                VIRG {printf("%c ", $2);}
                Elem
            ;

Elem        :   ID {
                    printf("%s", $1);
                    simbolo simb = NULL;
                    if(ProcuraSimb($1, escopoAtual) !=NULL) 
                        DeclaracaoRepetida($1); 
                    else 
                        simb = InsereSimb($1,IDVAR,tipocorrente, escopoAtual);
                    
                    atual = simb;
                }
                Dims {
                    if(atual != NULL)
                    {
                        atual->ndims = subsc;
                    }
                    subsc = 0;
                }
            ;

Dims        :
            |   ABCOL {printf("%c", $1);}
                ListDim
                FCOL {printf("%c", $4);}
            ;

ListDim    :    CTINT {printf("%s", $1); 
                if(atoi($1) <=0)
                {
                    DimensaoInvalida();
                }
                subsc++;
                atual->dims[subsc] = atoi($1);    
            }
            |   ListDim
                VIRG {printf("%c ", $2);}
                CTINT {printf("%s", $4);
                    if(atoi($4) <=0)
                    {
                        DimensaoInvalida();
                    }
                    subsc++;
                    atual->dims[subsc] = atoi($4);
                }
            ;

ListMod     :
            |   ListMod
                Modulo
            ;

Modulo      :   Cabecalho
                Corpo {
                    escopoAtual = escopoAtual->escopo;
                    if(quadcorrente->oper != OPRETURN)
                    {
                        GeraQuadrupla(OPRETURN, opndidle, opndidle, opndidle);
                    }
                }
            ;

Cabecalho   :   CabFunc
            |   CabProc
            ;

CabFunc     :   FUNCAO {printf("%s ", $1);}
                Tipo
                ID     {printf("%s ", $4);
                    ehDecl = 1; 
                    if(ProcuraSimb($4, escopoAtual) != NULL) 
                        DeclaracaoRepetida($4); 
                    else{
                        escopoAtual = InsereSimb($4,IDFUNC,tipocorrente, escopoAtual);
                        InicCodIntermedMod(escopoAtual);
                        opnd1.tipo = FUNCPND;
                        opnd1.atr.modulo = modcorrente;
                        GeraQuadrupla(OPENMOD,opnd1,opndidle,opndidle);
                    } 
                        
                    }
                ABPAR   {printf("%c", $6);}
                CabFPAux {ehDecl = 0;}
            ;

CabProc     :   PROCEDIMENTO {printf("%s ", $1);}
                ID      {printf("%s ", $3);
                        ehDecl = 1;
                        if(ProcuraSimb($3, escopoAtual)!=NULL) 
                            DeclaracaoRepetida($3); 
                        else{
                            escopoAtual = InsereSimb($3,IDPROC,NOTVAR, escopoAtual);
                            InicCodIntermedMod(escopoAtual);
                            opnd1.tipo = PROCPND;
                            opnd1.atr.modulo = modcorrente;
                            GeraQuadrupla(OPENMOD,opnd1,opndidle,opndidle);
                        } 
                    }
                ABPAR   {printf("%c", $5);}
                CabFPAux  {ehDecl = 0;}
            ;

/* Auxiliar para a impressao */
CabFPAux    :   ListParam
                FPAR  {printf("%c\n", $2);}
            |   FPAR  {printf("%c\n", $1);}
            ;

ListParam   :   Parametro
            |   ListParam
                VIRG    {printf("%c ", $2);}
                Parametro
            ;

Parametro   :   Tipo
                ID  {printf("%s", $2);
                if(ProcuraSimb($2, escopoAtual)!=NULL)
                    DeclaracaoRepetida($2); 
                else 
                {
                    simbolo par = InsereSimb($2,IDVAR,tipocorrente, escopoAtual);
                    par->inic = TRUE;
                    InsereParametro(escopoAtual, par);
                }
                }
            ;

Corpo       :   {ehDecl = 1;} Decls {ehDecl = 0;}
                Comandos
            ;

ModPrincipal    :   PRINCIPAL {printf("%s\n", $1);
                        escopoAtual = InsereSimb($1, IDPROC, NOTVAR, escopoAtual);
                        InicCodIntermedMod(escopoAtual);
                        opnd1.tipo = MODOPND;
                        opnd1.atr.modulo = modcorrente;
                        GeraQuadrupla(OPENMOD, opnd1, opndidle, opndidle);
                        }
                    Corpo
                    {
                        GeraQuadrupla(OPRETURN,opndidle,opndidle,opndidle);
                    }
                ;

Comandos    :   COMANDOS {printf("%s ", $1); tab++;}
                CmdComp {tab--; printf("\n");}
            ;

CmdComp     :   ABCHAV  {printf("%c\n", $1); newLines = 0;}
                ListCmd
                FCHAV   {tab--; tabular(); printf("%c", $4); isRepeat(); tab++; enquantoTabular = 0;}
            ;

ListCmd     :
            |   ListCmd
                Comando
            ;

Comando     :   CmdComp
            |   CmdSe
            |   CmdEnquanto
            |   CmdRepetir
            |   CmdPara
            |   CmdLer
            |   CmdEscrever
            |   CmdAtrib
            |   ChamadaProc
            |   CmdRetornar
            |   PVIRG {printf("%c\n", $1);}
            ;

CmdSe       :   SE {jumpLines(); tabular(); printf("%s ", $1);}
                ABPAR {printf("%c", $3);}
                Expressao {
                    if($5.tipo != LOGICAL)
                    {
                        TipoIncompativel();
                    }
                    
                    opndaux.tipo = ROTOPND;
                    $<quad>$ = GeraQuadrupla(OPJF, $5.opnd, opndidle, opndaux);
                }
                FPAR {printf("%c ", $7); tab++; newLines=1;}
                Comando {
                    tab--; newLines=0;
                    $<quad>$ = quadcorrente;
                    $<quad>6->result.atr.rotulo = GeraQuadrupla(NOP,opndidle,opndidle,opndidle);    
                }
                CmdSenao {
                    if ($<quad>10->prox != quadcorrente) {
                  	    quadaux = $<quad>10->prox;
                        $<quad>10->prox = quadaux->prox;
                        quadaux->prox = $<quad>10->prox->prox;
                        $<quad>10->prox->prox = quadaux;
                        RenumQuadruplas ($<quad>10, quadcorrente);
                    }
                }
            ;

CmdSenao    :
            |   SENAO {
                    jumpLines(); 
                    tabular(); 
                    printf("%s ", $1); 
                    tab++;
                    newLines=1;
                    opndaux.tipo = ROTOPND;
                    $<quad>$ = GeraQuadrupla(OPJUMP, opndidle, opndidle, opndaux);    
                }
                Comando {
                    tab--; 
                    newLines=0;
                    $<quad>2->result.atr.rotulo = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                }
            ;

CmdEnquanto :   ENQUANTO {
                    jumpLines(); 
                    tabular(); 
                    printf("%s ", $1);
                    $<quad>$ = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                }
                ABPAR {printf("%c", $3);}
                Expressao {
                    if($5.tipo != LOGICAL)
                    {
                        TipoIncompativel();
                    }
                    opndaux.tipo = ROTOPND;
                    $<quad>$ = GeraQuadrupla(OPJF, $5.opnd, opndidle, opndaux);
    
                }
                FPAR    {printf("%c ", $7); tab++;}
                Comando {
                    tab--;

                    opndaux.tipo = ROTOPND;
                    opndaux.atr.rotulo = $<quad>2;
                    GeraQuadrupla(OPJUMP, opndidle, opndidle, opndaux);
                    $<quad>6->result.atr.rotulo = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                }
            ;

CmdRepetir  :   REPETIR {
                    jumpLines(); 
                    tabular(); 
                    printf("%s ", $1); 
                    tab++; 
                    repeat=1; 
                    newLines=1; 
                    enquantoTabular = 1;
                    $<quad>$ = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);    
                }
                Comando {tab--; newLines=0;}
                ENQUANTO {
                    if(enquantoTabular==1)
                    {
                        tabular();
                    }
                    else
                    {
                        printf(" ");
                    }
                    printf("%s ", $5);
                    repeat = 0;
                    }
                ABPAR   {printf("%c", $7);}
                Expressao {
                    if($9.tipo != LOGICAL)
                    {
                        TipoIncompativel();
                    }
                    opndaux.tipo = ROTOPND;
                    opndaux.atr.rotulo = $<quad>2;
                    GeraQuadrupla(OPJF, $9.opnd, opndidle, opndaux);
                }
                FPAR    {printf("%c", $11);}
                PVIRG   {printf("%c\n", $13);}
            ;

CmdPara     :   PARA {jumpLines(); tabular(); printf("%s ", $1); cmdAtual = CMDPARA;}
                Variavel {
                    printf(" ");
                    cmdAtual = 0;
                    if($3.simb == NULL)
                        TipoIncompativel();
                    else if($3.simb->tvar != INTEGER && $3.simb->tvar != CHAR)
                    {
                        TipoIncompativel();
                    }
                    
                }
                ABPAR       {printf("%c", $5);}
                ExprAux4    {
                    if($7.tipo != INTEGER && $7.tipo != CHAR)
                    {
                        TipoIncompativel();
                    }
                    GeraQuadrupla(OPATRIB, $7.opnd, opndidle, $3.opnd);
                }
                PVIRG       {
                    printf("%c ", $9);
                    $<quad>$ = GeraQuadrupla (NOP, opndidle, opndidle, opndidle);
                }
                Expressao   {
                    if($11.tipo != LOGICAL)
                    {
                        TipoIncompativel();
                    }
                    opndaux.tipo = ROTOPND;
	                $<quad>$ = GeraQuadrupla (OPJF, $11.opnd, opndidle, opndaux);
                }
                PVIRG       {
                    printf("%c ", $13);
                    $<quad>$ = GeraQuadrupla (NOP, opndidle, opndidle, opndidle);
                }
                ExprAux4    {
                    if($15.tipo != INTEGER && $15.tipo != CHAR)
                    {
                        TipoIncompativel();
                    }
                    GeraQuadrupla(OPATRIB, $15.opnd, opndidle, $3.opnd);
                    
                }
                FPAR   {
                    
                    printf("%c", $17); tab++; newLines=1;
                    $<quad>$ = quadcorrente; 
                
                }

                { $<quad>$ = GeraQuadrupla (NOP, opndidle, opndidle, opndidle); }

                Comando     {
                    tab--; newLines=0;
    
                    quadaux = quadcorrente;
                    opndaux.tipo = ROTOPND;  opndaux.atr.rotulo = $<quad>10;
                    quadrupla quadaux2 = GeraQuadrupla (OPJUMP, opndidle, opndidle, opndaux);
                    $<quad>12->result.atr.rotulo = GeraQuadrupla(NOP, opndidle, opndidle, opndidle); 

                    $<quad>12->prox = $<quad>19;
                    quadaux->prox = $<quad>14;
                    $<quad>18->prox = quadaux2;
                    
                    RenumQuadruplas ($<quad>12, quadcorrente);

                }
            ;

CmdLer      :   LER {jumpLines(); tabular(); printf("%s ", $1); cmdAtual = CMDLER;}
                ABPAR {printf("%c", $3);}
                ListLeit
                FPAR    {printf("%c", $6);}
                PVIRG   {
                    printf("%c\n", $8); 
                    cmdAtual = 0;
                    if(countParams > 0)
                    {
                        opnd1.tipo = INTOPND;
                        opnd1.atr.valint = countParams;
                        GeraQuadrupla(OPLER, opnd1, opndidle, opndidle);
                    }
                    countParams = 0;    
                }
            ;

ListLeit    :   Variavel {
                    TrataLeitura($1);
                }
            |   ListLeit
                VIRG {printf("%c ", $2);}
                Variavel {
                    TrataLeitura($4);
                }
            ;

CmdEscrever :   ESCREVER {jumpLines(); tabular(); printf("%s ", $1);}
                ABPAR   {printf("%c", $3);}
                ListEscr
                FPAR    {printf("%c", $6);}
                PVIRG   {
                    printf("%c\n", $8);
                    opnd1.tipo = INTOPND;
                    opnd1.atr.valint = countParams;
                    GeraQuadrupla(OPWRITE, opnd1, opndidle, opndidle);
                    countParams = 0;    
                }
            ;

ListEscr    :   ElemEscr
            |   ListEscr
                VIRG {printf("%c ", $2);}
                ElemEscr
            ;

ElemEscr    :   CADEIA  {
                    printf("%s", $1);
                    opnd1.tipo = CADOPND;
                    int len = strlen($1);
                    opnd1.atr.valcad = (char *) malloc(sizeof(char) * len);
                    memcpy(opnd1.atr.valcad, &$1[1], len-2);
                    GeraQuadrupla(PARAM, opnd1, opndidle, opndidle);
                    countParams++;
                }
            |   Expressao
                {
                    GeraQuadrupla(PARAM, $1.opnd, opndidle, opndidle);
                    countParams++;
                }
            ;

ChamadaProc :   CHAMAR {jumpLines(); tabular(); printf("%s ", $1);}
                ID  {printf("%s ", $3);
                    simbolo proc = ProcuraSimb($3, escopoAtual);
                    if(proc == NULL)
                    {
                        NaoDeclarado($3);
                    }
                    else if(proc->tid != IDPROC)
                    {
                        TipoInadequado($3);
                    }
                    else if(proc == escopoAtual)
                    {
                        RecursaoNaoPermitida();
                    }
                    else if(proc->tid == IDPROC)
                    {
                        moduloChamado = proc;
                        paramAtual = moduloChamado->listparamc;
                    }
                }
                ABPAR   {printf("%c", $5);}
                Argumentos
                FPAR    {printf("%c", $8);}
                PVIRG   {
                    printf("%c\n", $10);
                    moduloChamado = NULL;
                    paramAtual = NULL;
                    simbolo proc = ProcuraSimb($3, escopoAtual);

                    if(proc != NULL && proc->tid == IDPROC)
                    {
                        if(countParams < proc->nparams)
                        {
                            ParametrosFaltantes();
                        }
                        else if(countParams > proc->nparams)
                        {
                            ParametroAMais();
                        }
                        opnd1.tipo = PROCPND;
                        opnd1.atr.simb = proc;
                        GeraQuadrupla(CALLOP, opnd1, opndidle, opndidle);
                    }
                    countParams = 0;
                }
            ;

Argumentos  :
            |   ListExpr
            ;

CmdRetornar :   RETORNAR    {jumpLines(); tabular(); printf("%s ", $1);
                                if(escopoAtual->tid == IDFUNC)
                                {
                                    ReturnVazio();
                                }
                                GeraQuadrupla(OPRETURN, opndidle, opndidle, opndidle);
                            }
                PVIRG       {printf("%c\n", $3);}
            |   RETORNAR    {jumpLines(); tabular(); printf("%s ", $1);
                                if(escopoAtual->tid == IDPROC)
                                {
                                    ReturnInadequado();
                                }
                            }
                Expressao {
                    switch(escopoAtual->tvar)
                    {
                        case INTEGER:
                        case CHAR:
                            if($3.tipo != CHAR && $3.tipo != INTEGER)
                            {
                                TipoIncompativel();
                            }
                            break;
                        case REAL:
                            if($3.tipo != REAL && $3.tipo != INTEGER && $3.tipo != CHAR)
                            {
                                TipoIncompativel();
                            }
                            break;
                        case LOGICAL:
                            if($3.tipo != LOGICAL)
                            {
                                TipoIncompativel();
                            }
                    }
                }
                PVIRG  {
                    printf("%c\n", $5);
                    GeraQuadrupla(OPRETURN, $3.opnd, opndidle, opndidle);
                    }
            ;

CmdAtrib    :   {jumpLines(); tabular(); cmdAtual = CMDATRIB;} Variavel {cmdAtual = 0;}
                ATRIB   {printf(" %c ", $4);}
                Expressao {
                    if($2.simb == NULL)
                        TipoIncompativel();
                    else
                    {
                        switch($2.simb->tvar)
                        {
                            case INTEGER:
                            case CHAR:
                            {
                                if($6.tipo != INTEGER && $6.tipo != CHAR)
                                {
                                    TipoIncompativel();
                                }
                            }
                            break;
                            case FLOAT:
                            {
                                if($6.tipo != INTEGER && $6.tipo != FLOAT && $6.tipo != CHAR)
                                {
                                    TipoIncompativel();
                                }
                            }
                            break;
                            case LOGICAL:
                            {
                                if($6.tipo != LOGICAL)
                                {
                                    TipoIncompativel();
                                }
                            }
                        }
                        if($2.simb->ndims==0)
                        {
                            GeraQuadrupla(OPATRIB, $6.opnd, opndidle, $2.opnd);
                        }
                        else
                        {
                            GeraQuadrupla(ATRIBPONT, $6.opnd, opndidle, $2.opnd);
                        }
                        
                    }
                    
                }
                PVIRG   {printf("%c\n", $8);}
            ;

ListExpr    :   Expressao {
                    if(paramAtual != NULL)
                    {
                        TestaCompatibilidade(paramAtual->simb->tvar, $1.tipo);
                        paramAtual = paramAtual->prox;
                    }
                    GeraQuadrupla(PARAM, $1.opnd, opndidle, opndidle);
                    countParams++;
                }
            |   ListExpr
                VIRG {printf("%c ", $2);}
                Expressao {
                    if(paramAtual != NULL)
                    {
                        TestaCompatibilidade(paramAtual->simb->tvar, $4.tipo);
                        paramAtual = paramAtual->prox;
                    }
                    GeraQuadrupla(PARAM, $4.opnd, opndidle, opndidle);
                    countParams++;
                }
            ;

Expressao   :   ExprAux1 {$$.tipo = $1.tipo;}
            |   Expressao
                OR  {printf(" %s ", $2);}
                ExprAux1
                {
                    $$.tipo = EhLogico($1.tipo);
                    $$.tipo = EhLogico($4.tipo);

                    $$.opnd.tipo = VAROPND;
                    $$.opnd.atr.simb = NovaTemp($$.tipo);
                    GeraQuadrupla(OPOR, $1.opnd, $4.opnd, $$.opnd);
                }
            ;

ExprAux1    :   ExprAux2 {$$ = $1;}
            |   ExprAux1
                AND     {printf(" %s ", $2);}
                ExprAux2
                {
                    $$.tipo = EhLogico($1.tipo);
                    $$.tipo = EhLogico($4.tipo);

                    $$.opnd.tipo = VAROPND;
                    $$.opnd.atr.simb = NovaTemp($$.tipo);
                    GeraQuadrupla(OPAND, $1.opnd, $4.opnd, $$.opnd);
                }
            ;        

ExprAux2    :   ExprAux3 {$$ = $1;}
            |   NOT     {printf("%c", $1);}
                ExprAux3
                {
                    $$.tipo = EhLogico($3.tipo);
                    $$.opnd.tipo = VAROPND;
                    $$.opnd.atr.simb = NovaTemp($$.tipo);
                    GeraQuadrupla(OPNOT, $3.opnd, opndidle, $$.opnd);
                }
            ;

ExprAux3    :   ExprAux4 {$$ = $1;}
            |   ExprAux4
                OPREL   
                    {
                        switch($2)
                        {
                            case MENOR:
                                printf(" < ");
                                break;
                            case MAIOR:
                                printf(" > ");
                                break;
                            case MENIG:
                                printf(" <= ");
                                break;
                            case MAIG:
                                printf(" >= ");
                                break;
                            case IGUAL:
                                printf(" == ");
                                break;
                            case DIFERENTE:
                                    printf(" != ");
                                break;
                        }
                    }
                ExprAux4 {
                    if($2 == IGUAL || $2 == DIFERENTE)
                    {
                        if($1.tipo == NOTVAR || $4.tipo == NOTVAR)
                        {
                            TipoIncompativel();
                        }
                        if(($1.tipo == LOGICAL && $4.tipo != LOGICAL) || ($1.tipo != LOGICAL && $4.tipo == LOGICAL))
                        {
                            TipoIncompativel();
                        }
                    }
                    else
                    {
                        EhIntRealCarac($1.tipo, $4.tipo);
                    }
                    $$.tipo = LOGICAL;
                    $$.opnd.tipo = VAROPND;
                    $$.opnd.atr.simb = NovaTemp($$.tipo);
                    switch($2)
                    {
                        case MENOR:
                            GeraQuadrupla(OPLT, $1.opnd, $4.opnd, $$.opnd);
                            break;
                        case MAIOR:
                            GeraQuadrupla(OPGT, $1.opnd, $4.opnd, $$.opnd);
                            break;
                        case MENIG:
                            GeraQuadrupla(OPLE, $1.opnd, $4.opnd, $$.opnd);
                            break;
                        case MAIG:
                            GeraQuadrupla(OPGE, $1.opnd, $4.opnd, $$.opnd);
                            break;
                        case IGUAL:
                            GeraQuadrupla(OPIGUAL, $1.opnd, $4.opnd, $$.opnd);
                            break;
                        case DIFERENTE:
                            GeraQuadrupla(OPDIF, $1.opnd, $4.opnd, $$.opnd);
                            break;
                    }

                }
            ;

ExprAux4    :   Termo {$$ = $1;}
            |   ExprAux4
                OPAD    
                    {
                        switch($2)
                        {
                            case MAIS:
                                printf(" + ");
                                break;
                            case MENOS:
                                printf(" - ");
                                break;
                        }
                    }
                Termo
                {
                    $$.tipo = EhIntRealCarac($1.tipo, $4.tipo);
                    $$.opnd.tipo = VAROPND;
                    $$.opnd.atr.simb = NovaTemp($$.tipo);
                    if($2 == MAIS)
                        GeraQuadrupla(OPMAIS, $1.opnd, $4.opnd, $$.opnd);
                    else
                        GeraQuadrupla(OPMENOS, $1.opnd, $4.opnd, $$.opnd);
                }
            ;

Termo       :   Fator {$$ = $1;}
            |   Termo 
                OPMULT  
                    {
                        switch($2)
                        {
                            case VEZES:
                                printf(" * ");
                                break;
                            case DIV:
                                printf(" / ");
                                break;
                            case MODULO:
                                printf(" %% ");
                                break;
                        }
                    }
                Fator {
                    if($2 == MODULO)
                        {
                            if($1.tipo != INTEGER && $1.tipo != CHAR)
                                TipoIncompativel();
                            
                            if($4.tipo != INTEGER && $4.tipo != CHAR)
                                TipoIncompativel();
                            
                            if($1.tipo >= $4.tipo)
                            {
                                $$.tipo = $1.tipo;
                            }
                            else
                            {
                                $$.tipo = $4.tipo;
                            }
                            $$.opnd.tipo = VAROPND;
                            $$.opnd.atr.simb = NovaTemp($$.tipo);
                            GeraQuadrupla(OPMODULO, $1.opnd, $4.opnd, $$.opnd);
                        }
                        else
                        {
                            $$.tipo = EhIntRealCarac($1.tipo, $4.tipo);
                            $$.opnd.tipo = VAROPND;
                            $$.opnd.atr.simb = NovaTemp($$.tipo);
                            if($2 == VEZES)
                                GeraQuadrupla(OPVEZES, $1.opnd, $4.opnd, $$.opnd);
                            else
                                GeraQuadrupla(OPDIV, $1.opnd, $4.opnd, $$.opnd);
                        }
                }
            ;

Fator       :   Variavel {
                if($1.simb !=NULL)
                {
                    $$.tipo = $1.simb->tvar;
                    if($1.simb->ndims == 0)
                    {
                        $$.opnd = $1.opnd;
                    }
                    else
                    {
                        simbolo novaTmp = NovaTemp($$.tipo);
                        opnd2.tipo = VAROPND;
                        opnd2.atr.simb = novaTmp;
                        GeraQuadrupla(CONTPONT, $1.opnd, opndidle, opnd2);
                        $$.opnd = opnd2;
                    }
                    
                }
                else
                    $$.tipo = NOTVAR;
            }
            |   CTINT {printf("%s", $1); 
                    $$.tipo = INTEGER; 
                    $$.opnd.tipo = INTOPND;
                    $$.opnd.atr.valint = atoi($1);
                    }
            |   CTREAL {printf("%s", $1); 
                    $$.tipo = FLOAT;
                    $$.opnd.tipo = REALOPND;
                    $$.opnd.atr.valfloat = atof($1);
                    }
            |   CTCARAC {
                    printf("%s", $1); 
                    $$.tipo = CHAR;
                    $$.opnd.tipo = CHAROPND;
                    $$.opnd.atr.valchar = $1[0];
                    }
            |   VERDADE {
                    printf("%s", $1); 
                    $$.tipo = LOGICAL;
                    $$.opnd.tipo = LOGICOPND;
                    $$.opnd.atr.vallogic = 1;
                    }
            |   FALSO {
                    printf("%s", $1); 
                    $$.tipo = LOGICAL;
                    $$.opnd.tipo = LOGICOPND;
                    $$.opnd.atr.vallogic = 0;
                    }
            |   NEG {printf("%c", $1);}
                Fator {
                    if($3.tipo != INTEGER && $3.tipo != FLOAT && $3.tipo != CHAR)
                    {
                        TipoIncompativel();
                    }
                    $$.tipo = $3.tipo;
                    $$.opnd.tipo = VAROPND;
                    $$.opnd.atr.simb = NovaTemp($$.tipo);
                    GeraQuadrupla(OPNEG, $3.opnd, opndidle, $$.opnd);
                }
            |   ABPAR {printf("%c", $1);}
                Expressao
                FPAR {printf("%c", $4); $$.tipo = $3.tipo; $$.opnd = $3.opnd;}
            |   ChamadaFunc {$$ = $1;}
            ;

Variavel    :       ID {printf("%s", $1);
                    simbolo simb = ProcuraSimb($1, escopoAtual);
                    Empilha(subsc);
                    subsc = 0;
	                if (simb == NULL)
                    {
                        NaoDeclarado ($1);
                    }   
	                else if (simb->tid != IDVAR)   
                    {
                        TipoInadequado($1);
                    }

                    if (simb != NULL)
                    {
                        if(cmdAtual == CMDLER || cmdAtual == CMDPARA || cmdAtual == CMDATRIB)
                        {
                            simb->inic = TRUE;
                        }
                        simb->ref = TRUE;
                    }
                }
                Subscritos {
                    simbolo simb = ProcuraSimb($1, escopoAtual);
                    if(simb != NULL)
                    {
                        $$.simb = simb;
                        if(simb->ndims == 0 && subsc > 0)
                        {
                            EscalarComSubs();
                        }
                        else if(simb->ndims > 0 && subsc == 0)
                        {
                            IndexadaSemSubs();
                        }
                        else if(simb->ndims != subsc)
                        {
                            DimensoesFaltantesOuInvalidas();
                        }
                        $$.opnd.tipo = VAROPND;
                        if(simb->ndims ==0)
                        {
                            $$.opnd.atr.simb = $$.simb;
                        }
                        else
                        {
                            int tipoPVar;
                            switch($$.simb->tvar)
                            {
                                case LOGICAL:
                                    tipoPVar = PTRLOG;
                                    break;
                                case CHAR:
                                    tipoPVar = PTRCHAR;
                                    break;
                                case FLOAT:
                                    tipoPVar = PTRFLOAT;
                                    break;
                                case INTEGER:
                                    tipoPVar = PTRINT;
                                    break;
                                default:
                                    tipoPVar = $$.simb->tvar;
                                    break;                                    
                            }
                            simbolo novaTmp = NovaTemp(tipoPVar);
                            opnd1.tipo = VAROPND;
                            opnd1.atr.simb = simb;
                            opnd2.tipo = INTOPND;
                            opnd2.atr.valint = simb->ndims;
                            $$.opnd.atr.simb = novaTmp;
                            GeraQuadrupla(OPINDEX, opnd1, opnd2, $$.opnd);
                        }
                    }
                    else
                    {
                        $$.simb = NULL;
                    }               

                    subsc = Desempilha();                    
                }
            ;

Subscritos  :   
            |   ABCOL {printf("%c", $1);}
                ListSubscr
                FCOL  {printf("%c", $4);}
            ;

ListSubscr  :   ExprAux4 {
                    subsc++;
                    if($1.tipo != INTEGER && $1.tipo != CHAR)
                    {
                        TipoIncompativel();
                    }
                    GeraQuadrupla(OPIND, $1.opnd, opndidle, opndidle);
                }
            |   ListSubscr
                VIRG {printf("%c ", $2);}
                ExprAux4 {
                    subsc++;
                    if($4.tipo != INTEGER && $4.tipo != CHAR)
                    {
                        TipoIncompativel();
                    }
                    GeraQuadrupla(OPIND, $4.opnd, opndidle, opndidle);
                }
            ;

ChamadaFunc :   ID  {printf("%s ", $1);
                    simbolo idfu = ProcuraSimb($1, escopoAtual);
                    if(idfu == NULL)
                    {
                        NaoDeclarado($1);
                    }
                    else if(idfu->tid != IDFUNC)
                    {
                        TipoInadequado($1);
                    }
                    else if(idfu == escopoAtual)
                    {
                        RecursaoNaoPermitida();
                    }
                    else if(idfu->tid == IDFUNC)
                    {
                        moduloChamado = idfu;
                        paramAtual = idfu->listparamc;
                    }

                    
                }
                ABPAR {printf("%c", $3);}
                Argumentos
                FPAR {printf("%c", $6);
                    simbolo idfu = ProcuraSimb($1, escopoAtual);
                    if(idfu == NULL)
                    {
                        $$.tipo = NOTVAR;
                    }
                    else if(countParams < idfu->nparams)
                    {
                        ParametrosFaltantes();
                    }
                    else if(countParams > idfu->nparams)
                    {
                        ParametroAMais();
                    }

                    if(idfu != NULL)
                    {
                        $$.tipo = idfu->tvar;
                        simbolo novaTmp = NovaTemp($$.tipo);
                        $$.opnd.tipo = VAROPND;
                        $$.opnd.atr.simb = novaTmp;
                        opnd1.tipo = FUNCPND;
                        opnd1.atr.simb = idfu;
                        if(countParams > 0)
                        {
                            opnd2.tipo = INTOPND;
                            opnd2.atr.valint = countParams;
                            GeraQuadrupla(CALLOP, opnd1, opnd2, $$.opnd);
                        }
                        else
                        {
                            GeraQuadrupla(CALLOP, opnd1, opndidle, $$.opnd);
                        }
                    }
                    
                    moduloChamado = NULL;
                    paramAtual = NULL;
                    countParams = 0;
                }
            ;

%%
#include "lex.yy.c"
void tabular() {
    int i=0;
    for(; i<tab; i++)
        printf("\t");
}

void jumpLines()
{
    int i=0;
    for(; i<newLines; i++)
    {
        printf("\n");
    }
}

void isRepeat()
{
    if(repeat==0)
    {
        printf("\n");
    }
}

void InicTabSimb(){
    int i;
    for(i = 0; i< NCLASSHASH; i++)
        tabsimb[i] = NULL;
}

simbolo ProcuraSimb(char * cadeia, simbolo escopo)
{
    simbolo s;
    int i = hash(cadeia);
    if (ehDecl == 1)
    {
        for(s = tabsimb[i]; s!=NULL && (strcmp(cadeia, s->cadeia) != 0 || s->escopo != escopo); s = s->prox);
    }
    else
    {
        simbolo escopoProcura = escopo;
        while(escopoProcura != NULL)
        {
            for(s=tabsimb[i]; s!=NULL && (strcmp(cadeia, s->cadeia) != 0 || s->escopo != escopoProcura); s = s->prox);
            if(s != NULL)
            {
                return s;
            }
            escopoProcura = escopoProcura->escopo;
        }
    }
    
    return s;
}

void ImprimeNaoUsados()
{
    int i;
    for(i=0; i<NCLASSHASH; i++)
    {
        if(tabsimb[i] != NULL)
        {
            simbolo s = tabsimb[i];
            while(s != NULL)
            {
                if(s->tid == IDVAR)
                {
                    if(s->inic == FALSE && s->ref == FALSE)
                    {
                        printf("\nSimbolo %s no escopo %s nao foi inicializado nem referenciado.", s->cadeia, s->escopo->cadeia);
                    }
                    else if(s->inic == FALSE)
                    {
                        printf("\nSimbolo %s no escopo %s nao foi inicializado.", s->cadeia, s->escopo->cadeia);
                    }
                    else if(s->ref == FALSE)
                    {
                        printf("\nSimbolo %s no escopo %s nao foi referenciado.", s->cadeia, s->escopo->cadeia);
                    }
                }

                s = s->prox;
            }
        }
    }
}

simbolo InsereSimb(char *cadeia, int tid, int tvar, simbolo escopo){
    int i; simbolo aux, s;
	i = hash (cadeia); aux = tabsimb[i];
	s = tabsimb[i] = (simbolo) malloc (sizeof (celsimb));
	s->cadeia = (char*) malloc ((strlen(cadeia)+1) * sizeof(char));
	strcpy (s->cadeia, cadeia);
	s->tid = tid;		
    s->tvar = tvar;
	s->inic = FALSE;	
    s->ref = FALSE;
	s->prox = aux;
    s->ndims = 0;
    s->escopo = escopo;
    s->listparamc = NULL;
    s->listparamf = NULL;
    s->nparams = 0;	
    return s;
}

void InsereParametro(simbolo modulo, simbolo param)
{
    if(modulo->listparamc == NULL)
    {
        modulo->listparamc = (elemlistsimb *) malloc(sizeof(elemlistsimb));
        modulo->listparamc->simb = param;
        modulo->listparamc->prox = NULL;
        modulo->listparamf = modulo->listparamc;
    }
    else
    {
        modulo->listparamf->prox = (elemlistsimb *) malloc(sizeof(elemlistsimb));
        modulo->listparamf = modulo->listparamf->prox;
        modulo->listparamf->prox = NULL;
        modulo->listparamf->simb = param;
    }
    modulo->nparams++;
}

int hash(char *cadeia) {
	int h = 0;
    int i;
	for (i = 0; cadeia[i]; i++) {h += cadeia[i];}
	h = h % NCLASSHASH;
	return h;
}

void ImprimeTabSimb(){
	simbolo s;
	printf ("\n\n   TABELA  DE  SIMBOLOS:\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("|Hash|       Cadeia     |Tipo de ID|Tipo de variavel|     Escopo    |#param|#dim |Inic |Ref  |\n");
    printf("----------------------------------------------------------------------------------------------\n");
    int i;
	for(i = 0; i < NCLASSHASH; i++)
		if(tabsimb[i]){
			for(s = tabsimb[i]; s!=NULL; s = s->prox){
                printf("|%4d|%18s|%10s|%16s|%15s|%6d|%5d|", 
                i,
                s->cadeia, 
                nometipid[s->tid], 
                (s->tid==IDVAR)? nometipvar[s->tvar]: "    -    ", 
                (s->escopo==NULL)? "NULL": s->escopo->cadeia,
                s->nparams,
                s->ndims);
                if(s->tid==IDVAR)
                {
                    printf("%5s|%5s|\n", (s->inic==TRUE)?"TRUE": "FALSE",
                (s->ref==TRUE)?"TRUE": "FALSE");
                }
                else
                {
                    printf("  -  |  -  |\n");
                }
			}
		}
    printf("----------------------------------------------------------------------------------------------\n");
}

char * createScopeString(const char string[20])
{
    int size = strlen(string);
    char * name = (char *) malloc((size + 1) * sizeof(char));
    strcpy(name, string);
    return name;
}

void DeclaracaoRepetida (char *s) {
	printf ("\n\n***** Declaracao Repetida: %s *****\n\n", s);
}

void NaoDeclarado (char *s) {
printf ("\n\n***** Identificador Nao Declarado: %s *****\n\n", s);
}

void TipoInadequado (char *s) {
printf ("\n\n***** Identificador de Tipo Inadequado: %s *****\n\n", s);
}

void ReturnInadequado ()
{
    printf("\n\n**** Procedimento nao deve retornar nada *****\n\n");
}

void ReturnVazio()
{
    printf("\n\n**** Funcao com retorno vazio ****\n\n");
}

void DimensaoInvalida()
{
    printf("\n\n**** Dimensao deve ser maior que zero ***\n\n");
}

void TipoIncompativel()
{
    printf("\n\n**** Tipo incompativel com a operacao. ***\n\n");
}

int EhIntRealCarac(int s1, int s2)
{
    if(s1 != INTEGER && s1 != CHAR && s1 != FLOAT)
    {
        TipoIncompativel();
    }
    
    if(s2 != INTEGER && s2 != CHAR && s2 != FLOAT)
    {
        TipoIncompativel();
    }   

    if(s1 >= s2)
    {
        return s1;
    }
    else
    {
        return s2;
    }
}

int EhLogico(int s1)
{
    if(s1 != LOGICAL)
    {
        TipoIncompativel();
    }

    return LOGICAL;
}

void DimensoesFaltantesOuInvalidas()
{
    printf("\n\n**** Dimensoes a menos ou a mais do que deveria ***\n\n");
}

void EscalarComSubs()
{
    printf("\n\n**** Escalar nao pode ter subscritos ****\n\n");
}

void IndexadaSemSubs()
{
    printf("\n\n**** Variavel indexada deve ter subscritos ****\n\n");
}

void ModuloComoArgumento()
{
    printf("\n\n**** Modulo nao pode ser argumento ****\n\n");
}

void RecursaoNaoPermitida()
{
    printf("\n\n**** Recursao nao permitida ****\n\n");
}

void ParametroAMais()
{
    printf("\n\n**** Parametros a mais na chamada do modulo ***\n\n");
}

void ParametroIncompativel()
{
    printf("\n\n*** Parametro incompativel com a assinatura do modulo ***\n\n");
}

void ParametrosFaltantes()
{
    printf("\n\n**** Ha parametros faltantes na chamada do modulo ***\n\n");
}

void TestaCompatibilidade(int param, int arg)
{
    switch(param)
    {
        case INTEGER:
        case CHAR:
            if(arg != INTEGER && arg != CHAR)
            {
                ParametroIncompativel();
            }
            break;
        case REAL:
            if(arg != INTEGER && arg != CHAR && arg != REAL)
            {
                ParametroIncompativel();
            }
            break;
        case LOGICAL:
            if(arg != LOGICAL)
            {
                ParametroIncompativel();
            }
            break;
    }
}

void Empilha(int n)
{
    pilhaPtr novo = (pilhaPtr) malloc(sizeof(nohPilha));
    novo->prox = pilhaTopo;
    pilhaTopo = novo;
    novo->num = n;
}

int Desempilha()
{
    int n;
    if(pilhaTopo == NULL)
    {
        n = 0;
    }
    else
    {
        n = pilhaTopo->num;
        pilhaPtr velho = pilhaTopo;
        pilhaTopo = pilhaTopo->prox;
        free(velho);
    }

    return n;
}

/*Funcoes para o codigo intermediario */

void InicCodIntermed () {
    modcorrente = codintermed = malloc (sizeof (celmodhead));
    modcorrente->listquad = NULL;
	modcorrente->prox = NULL;
}

void InicCodIntermedMod (simbolo simb) {
	modcorrente->prox = malloc (sizeof (celmodhead));
	modcorrente = modcorrente->prox;
	modcorrente->prox = NULL;
	modcorrente->modname = simb;
	modcorrente->listquad = malloc (sizeof (celquad));
	quadcorrente = modcorrente->listquad;
	quadcorrente->prox = NULL;
	numquadcorrente = 0;
	quadcorrente->num = 0;
}

quadrupla GeraQuadrupla (int oper, operando opnd1, operando opnd2, operando result) {
	quadcorrente->prox = malloc (sizeof (celquad));
	quadcorrente->prox->oper = oper;
	quadcorrente->prox->opnd1 = opnd1;
	quadcorrente->prox->opnd2 = opnd2;
	quadcorrente->prox->result = result;
	quadcorrente->prox->prox = NULL;
    numquadcorrente = quadcorrente->num + 1;
   	quadcorrente->prox->num = numquadcorrente;
    quadcorrente = quadcorrente->prox;
   	return quadcorrente;
}

simbolo NovaTemp (int tip) {
	simbolo simb; int temp, i, j;
	char nometemp[10] = "##", s[10] = {0};
	numtemp ++; temp = numtemp;
	for (i = 0; temp > 0; temp /= 10, i++)
		s[i] = temp % 10 + '0';
	i --;
	for (j = 0; j <= i; j++)
		nometemp[2+i-j] = s[j];
	simb = InsereSimb (nometemp, IDVAR, tip, escopoAtual);
	simb->inic = simb->ref = TRUE;
    return simb;
}

void ImprimeQuadruplas()
{
    modhead p;
    quadrupla q;
    for(p = codintermed->prox; p !=NULL; p = p->prox)
    {
        printf("\n\nQuadruplas do modulo %s:\n", p->modname->cadeia);
        for(q=p->listquad->prox; q != NULL; q = q->prox)
        {
            printf("\n\t%4d) %s", q->num, nomeoperquad[q->oper]);
            printf(", (%s", nometipoopndquad[q->opnd1.tipo]);
            	switch (q->opnd1.tipo) {
				case IDLEOPND: break;
				case VAROPND: printf (", %s", q->opnd1.atr.simb->cadeia); break;
				case INTOPND: printf (", %d", q->opnd1.atr.valint); break;
				case REALOPND: printf (", %g", q->opnd1.atr.valfloat); break;
				case CHAROPND: printf (", %c", q->opnd1.atr.valchar); break;
				case LOGICOPND: printf (", %d", q->opnd1.atr.vallogic); break;
				case CADOPND: printf (", %s", q->opnd1.atr.valcad); break;
				case ROTOPND: printf (", %d", q->opnd1.atr.rotulo->num); break;
				case MODOPND: 
                    printf(", %s", q->opnd1.atr.modulo->modname->cadeia);
					break;
                case FUNCPND:
                case PROCPND:
                    switch(q->oper)
                    {
                        case OPENMOD:
                            printf(", %s", q->opnd1.atr.modulo->modname->cadeia);
                        break;
                        case CALLOP:
                            printf(", %s", q->opnd1.atr.simb->cadeia);
                            break;
                    }
                break;
			}
            printf (")");
			printf (", (%s", nometipoopndquad[q->opnd2.tipo]);
			switch (q->opnd2.tipo) {
				case IDLEOPND: break;
				case VAROPND: printf (", %s", q->opnd2.atr.simb->cadeia); break;
				case INTOPND: printf (", %d", q->opnd2.atr.valint); break;
				case REALOPND: printf (", %g", q->opnd2.atr.valfloat); break;
				case CHAROPND: printf (", %c", q->opnd2.atr.valchar); break;
				case LOGICOPND: printf (", %d", q->opnd2.atr.vallogic); break;
				case CADOPND: printf (", %s", q->opnd2.atr.valcad); break;
				case ROTOPND: printf (", %d", q->opnd2.atr.rotulo->num); break;
				case MODOPND: printf(", %s", q->opnd2.atr.modulo->modname->cadeia);
					break;
                case FUNCPND:
                case PROCPND:
                     switch(q->oper)
                    {
                        case OPENMOD:
                            printf(", %s", q->opnd1.atr.modulo->modname->cadeia);
                        break;
                        case CALLOP:
                            printf(", %s", q->opnd1.atr.simb->cadeia);
                            break;
                    }
                    break;
			}
            printf (")");
			printf (", (%s", nometipoopndquad[q->result.tipo]);
			switch (q->result.tipo) {
				case IDLEOPND: break;
				case VAROPND: printf (", %s", q->result.atr.simb->cadeia); break;
				case INTOPND: printf (", %d", q->result.atr.valint); break;
				case REALOPND: printf (", %g", q->result.atr.valfloat); break;
				case CHAROPND: printf (", %c", q->result.atr.valchar); break;
				case LOGICOPND: printf (", %d", q->result.atr.vallogic); break;
				case CADOPND: printf (", %s", q->result.atr.valcad); break;
				case ROTOPND: printf (", %d", q->result.atr.rotulo->num); break;
				case MODOPND: printf(", %s", q->result.atr.modulo->modname->cadeia);
					break;
			}
			printf (")");
        }
    }
    printf("\n");
}

void RenumQuadruplas(quadrupla quad1, quadrupla quad2)
{
    quadrupla q;
    int nquad;
    for(q= quad1->prox, nquad = quad1->num; q != quad2; q = q->prox)
    {
        nquad++;
        q->num = nquad;
    }
}

void TrataLeitura(infovariavel var)
{
    countParams++;
    if(var.simb->ndims == 0)
    {
        opnd1.tipo = VAROPND;
        opnd1.atr.simb = var.simb;
        GeraQuadrupla(PARAM, opnd1, opndidle, opndidle);
    }
    else
    {
        simbolo novaTmp = NovaTemp(var.simb->tvar);
        opnd1.tipo = VAROPND;
        opnd1.atr.simb = novaTmp;
        GeraQuadrupla(PARAM, opnd1, opndidle, opndidle);
        opnd2.tipo = INTOPND;
        opnd2.atr.valint = countParams;
        GeraQuadrupla(OPLER, opnd2, opndidle, opndidle);
        GeraQuadrupla(ATRIBPONT, opnd1, opndidle, var.opnd);
        countParams=0;
    }
}

/* Funções do Interpretador*/

void InterpCodIntermed()
{
    printf("\n\nINTERPRETADOR:\n");
    codintermedaux = codintermed->prox;
    InicPilhaOpnd(&pilhaopnd);
    InicPilhaContexto(&pilhacontext);
    InterpCodIntermedSubProgramas();

}

void InterpCodIntermedSubProgramas()
{

    quadrupla quad, quadprox;
    char encerra;
    contexto ctx;
    encerra = FALSE;
    quad = codintermedaux->listquad->prox;
    
    while(!encerra)
    {
        printf("\n%4d)%s", quad->num, nomeoperquad[quad->oper]);
        quadprox = quad->prox;
        switch(quad->oper)
        {
            case OPEXIT:
                encerra = TRUE;
                break;
            case OPENMOD:
                AlocaVariaveis(quad);
                break;
            case PARAM:
                EmpilharOpnd(quad->opnd1,&pilhaopnd);
                break;
            case CALLOP:
                ctx = (contexto){codintermedaux, quad ,opndidle};    
                EmpilharContexto(ctx,&pilhacontext);
                ExecQuadCallop(quad);
                ctx = TopoContexto(pilhacontext);
                codintermedaux = ctx.moduloAtual;
                quad = ctx.quadruplaAtual;
                DesempilharContexto(&pilhacontext);
                break;
            
            case OPRETURN:
                encerra = TRUE;
        }
        if(!encerra)
            quad = quadprox;
    }
    printf("\n");
}

void AlocaVariaveis(quadrupla quad)
{
    simbolo s;
    int nelemaloc, i, j;
    printf("\n\tAlocando as variaveis:");
    for(i=0; i < NCLASSHASH; i++)
    {
        if(tabsimb[i])
        {
            for(s = tabsimb[i]; s != NULL; s = s->prox)
            {
                if(s->escopo == quad->opnd1.atr.modulo->modname && s->tid == IDVAR)
                {
                    nelemaloc = 1;
                    if(s->ndims > 0)
                        for(j=1; j<= s->ndims; j++)
                        {
                            nelemaloc *= s->dims[j];
                        }
                    switch(s->tvar)
                    {
                        case INTEGER:
                            s->valint = malloc(nelemaloc*sizeof(int));
                            break;
                        case FLOAT:
                            s->valfloat = malloc(nelemaloc*sizeof(float));
                            break;
                        case CHAR:
                            s->valfloat = malloc(nelemaloc*sizeof(char));
                            break;
                        case LOGICAL:
                            s->vallogic = malloc(nelemaloc * sizeof(char));
                            break;
                    }
                    printf("\n\t\t\t%s: %d elemento(s) alocado(s)", s->cadeia, nelemaloc);
                }
            }
        }
    }
}

void EmpilharOpnd (operando x, pilhaoperando *P) {
	nohopnd *temp;
	temp = *P;   
	*P = (nohopnd *) malloc (sizeof (nohopnd));
	(*P)->opnd = x; (*P)->prox = temp;
}

void DesempilharOpnd (pilhaoperando *P) {
	nohopnd *temp;
	if (! VaziaOpnd (*P)) {
		temp = *P;  *P = (*P)->prox; free (temp);
	}
	else  printf ("\n\tDelecao em pilha vazia\n");
}

operando TopoOpnd (pilhaoperando P) {
	if (! VaziaOpnd (P))  return P->opnd;
	else  printf ("\n\tTopo de pilha vazia\n");
}

void InicPilhaOpnd (pilhaoperando *P) { 
	*P = NULL;
}

char VaziaOpnd (pilhaoperando P) {
	if  (P == NULL)  return 1;  
	else return 0; 
}

void EmpilharContexto (contexto x, pilhacontexto *P) {
	nohcontexto *temp;
	temp = *P;   
	*P = (nohcontexto *) malloc (sizeof (nohcontexto));
	(*P)->context = x; (*P)->prox = temp;
}

void DesempilharContexto (pilhacontexto *P) {
	nohcontexto *temp;
	if (! VaziaContexto (*P)) {
		temp = *P;  *P = (*P)->prox; free (temp);
	}
	else  printf ("\n\tDelecao em pilha vazia\n");
}

contexto TopoContexto (pilhacontexto P) {
	if (! VaziaContexto(P))  return P->context;
	else  printf ("\n\tTopo de pilha vazia\n");
}

void InicPilhaContexto (pilhacontexto *P) { 
	*P = NULL;
}

char VaziaContexto (pilhacontexto P) {
	if  (P == NULL)  return 1;  
	else return 0; 
}



void ExecQuadCallop(quadrupla quad){
    int i;
    operando opendAux;
    pilhaoperando pilhaopndaux;
    codintermedaux = codintermed->prox;
    if(VaziaContexto(pilhacontext)){
        printf("\nErro : Sem contexto durante execução de ExecQuadCallop");
    }
    else{
        char *modname = quad->opnd1.atr.simb->cadeia;   

        while(strcmp(modname,codintermedaux->modname->cadeia)!=0 && codintermedaux!=NULL){
            codintermedaux = codintermedaux->prox;
        }
        
        if(codintermedaux == NULL){
            printf("\n Não encontrou o modulo com o nome: %s",modname);
        }
        else{

            if(quad->opnd2.tipo!=IDLEOPND){

                InicPilhaOpnd(&pilhaopndaux);
                for(i=1; i<= quad->opnd2.atr.valint;i++){
                    EmpilharOpnd(TopoOpnd(pilhaopnd),&pilhaopndaux);
                    DesempilharOpnd(&pilhaopnd);
                }

            }
            InterpCodIntermedSubProgramas();
        }
    }
}