/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Lab6.y" /* yacc.c:339  */

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
#define     OPJT          31

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
char *nomeoperquad[32] = {"",
    "OPOR", "OPAND", "OPNOT", "OPLT", "OPLE", "OPGT", "OPGE", "OPMAIS", "OPMENOS", 
    "OPVEZES", "OPDIV", "OPMODULO", "OPNEG", "OPATRIB", "PARAM", "CALLOP", 
    "OPENMOD", "OPRETURN", "OPREAD", "OPWRITE", "OPJUMP", "OPJF", "OPEXIT",
    "INDEX", "ATRIBPONT", "CONTPONT", "NOP", "OPIGUAL", "OPDIF", "IND",
    "OPJT"
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
    simbolo chamado;
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
//void Indentar();

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
void ExecQuadMais(quadrupla quad);
void ExecQuadMenos(quadrupla quad);
void ExecQuadVezes(quadrupla quad);
void ExecQuadDiv(quadrupla quad);
void ExecQuadModulo(quadrupla quad);
void ExecQuadAtrib(quadrupla quad);
void ExecQuadLT(quadrupla quad);
void ExecQuadLE(quadrupla quad);
void ExecQuadGT(quadrupla quad);
void ExecQuadGE(quadrupla quad);
void ExecQuadIgual(quadrupla quad);
void ExecQuadDif(quadrupla quad);
void ExecQuadWrite(quadrupla quad);
void ExecQuadRead(quadrupla quad);
void ExecQuadOR(quadrupla quad);
void ExecQuadAND(quadrupla quad);
void ExecQuadNOT(quadrupla quad);
void ExecQuadNEG(quadrupla quad);
void ExecQuadINDEX(quadrupla quad);
void ExecQuadAtribpont(quadrupla quad);
void ExecQuadContpont(quadrupla quad);

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
void DesalocaVariaveis(simbolo modulo);
void ImprimeCadeia(char * cadeia);

#line 386 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CARAC = 258,
    FUNCAO = 259,
    PROCEDIMENTO = 260,
    SENAO = 261,
    CHAMAR = 262,
    INT = 263,
    PROGRAMA = 264,
    VAR = 265,
    COMANDOS = 266,
    LER = 267,
    REAL = 268,
    VERDADE = 269,
    ENQUANTO = 270,
    LOGIC = 271,
    REPETIR = 272,
    ESCREVER = 273,
    PARA = 274,
    RETORNAR = 275,
    FALSO = 276,
    PRINCIPAL = 277,
    SE = 278,
    ABTRIP = 279,
    FTRIP = 280,
    OR = 281,
    AND = 282,
    OPREL = 283,
    OPAD = 284,
    OPMULT = 285,
    NOT = 286,
    NEG = 287,
    ATRIB = 288,
    ABPAR = 289,
    FPAR = 290,
    ABCOL = 291,
    FCOL = 292,
    ABCHAV = 293,
    FCHAV = 294,
    PVIRG = 295,
    VIRG = 296,
    ID = 297,
    CTINT = 298,
    CTCARAC = 299,
    CTREAL = 300,
    CADEIA = 301,
    OTHER = 302
  };
#endif
/* Tokens.  */
#define CARAC 258
#define FUNCAO 259
#define PROCEDIMENTO 260
#define SENAO 261
#define CHAMAR 262
#define INT 263
#define PROGRAMA 264
#define VAR 265
#define COMANDOS 266
#define LER 267
#define REAL 268
#define VERDADE 269
#define ENQUANTO 270
#define LOGIC 271
#define REPETIR 272
#define ESCREVER 273
#define PARA 274
#define RETORNAR 275
#define FALSO 276
#define PRINCIPAL 277
#define SE 278
#define ABTRIP 279
#define FTRIP 280
#define OR 281
#define AND 282
#define OPREL 283
#define OPAD 284
#define OPMULT 285
#define NOT 286
#define NEG 287
#define ATRIB 288
#define ABPAR 289
#define FPAR 290
#define ABCOL 291
#define FCOL 292
#define ABCHAV 293
#define FCHAV 294
#define PVIRG 295
#define VIRG 296
#define ID 297
#define CTINT 298
#define CTCARAC 299
#define CTREAL 300
#define CADEIA 301
#define OTHER 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 320 "Lab6.y" /* yacc.c:355  */

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

#line 531 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 548 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  132
/* YYNRULES -- Number of rules.  */
#define YYNRULES  178
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  268

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   382,   382,   383,   384,   398,   382,   416,   417,   418,
     417,   423,   424,   429,   428,   435,   436,   437,   438,   441,
     443,   442,   447,   447,   466,   467,   467,   472,   481,   480,
     492,   493,   497,   507,   508,   511,   513,   526,   511,   530,
     531,   543,   530,   548,   550,   553,   555,   554,   559,   572,
     572,   572,   576,   576,   589,   589,   593,   593,   598,   599,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   616,   617,   618,   627,   628,   616,   644,   645,   645,
     661,   667,   668,   677,   661,   688,   698,   699,   711,   712,
     721,   688,   725,   726,   737,   738,   745,   749,   757,   761,
     769,   776,   725,   795,   796,   798,   795,   812,   816,   815,
     822,   823,   825,   822,   835,   837,   836,   841,   851,   858,
     859,   879,   881,   858,   915,   916,   919,   919,   927,   933,
     927,   962,   962,   963,   964,   962,  1011,  1021,  1020,  1033,
    1035,  1034,  1047,  1049,  1048,  1061,  1062,  1062,  1072,  1075,
    1073,  1142,  1145,  1143,  1168,  1171,  1169,  1219,  1240,  1245,
    1250,  1256,  1262,  1268,  1268,  1279,  1279,  1282,  1285,  1285,
    1368,  1369,  1369,  1374,  1383,  1382,  1394,  1416,  1394
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CARAC", "FUNCAO", "PROCEDIMENTO",
  "SENAO", "CHAMAR", "INT", "PROGRAMA", "VAR", "COMANDOS", "LER", "REAL",
  "VERDADE", "ENQUANTO", "LOGIC", "REPETIR", "ESCREVER", "PARA",
  "RETORNAR", "FALSO", "PRINCIPAL", "SE", "ABTRIP", "FTRIP", "OR", "AND",
  "OPREL", "OPAD", "OPMULT", "NOT", "NEG", "ATRIB", "ABPAR", "FPAR",
  "ABCOL", "FCOL", "ABCHAV", "FCHAV", "PVIRG", "VIRG", "ID", "CTINT",
  "CTCARAC", "CTREAL", "CADEIA", "OTHER", "$accept", "Prog", "$@1", "$@2",
  "$@3", "$@4", "Decls", "$@5", "$@6", "ListDecl", "Declaracao", "$@7",
  "Tipo", "ListElem", "$@8", "Elem", "$@9", "Dims", "$@10", "ListDim",
  "$@11", "ListMod", "Modulo", "Cabecalho", "CabFunc", "$@12", "$@13",
  "$@14", "CabProc", "$@15", "$@16", "$@17", "CabFPAux", "ListParam",
  "$@18", "Parametro", "Corpo", "$@19", "$@20", "ModPrincipal", "$@21",
  "Comandos", "$@22", "CmdComp", "$@23", "ListCmd", "Comando", "CmdSe",
  "$@24", "$@25", "@26", "$@27", "@28", "CmdSenao", "@29", "CmdEnquanto",
  "@30", "$@31", "@32", "$@33", "CmdRepetir", "@34", "$@35", "$@36",
  "$@37", "$@38", "$@39", "CmdPara", "$@40", "$@41", "$@42", "$@43", "@44",
  "@45", "@46", "$@47", "@48", "@49", "CmdLer", "$@50", "$@51", "$@52",
  "ListLeit", "$@53", "CmdEscrever", "$@54", "$@55", "$@56", "ListEscr",
  "$@57", "ElemEscr", "ChamadaProc", "$@58", "$@59", "$@60", "$@61",
  "Argumentos", "CmdRetornar", "$@62", "$@63", "$@64", "CmdAtrib", "$@65",
  "$@66", "$@67", "$@68", "ListExpr", "$@69", "Expressao", "$@70",
  "ExprAux1", "$@71", "ExprAux2", "$@72", "ExprAux3", "$@73", "ExprAux4",
  "$@74", "Termo", "$@75", "Fator", "$@76", "$@77", "Variavel", "$@78",
  "Subscritos", "$@79", "ListSubscr", "$@80", "ChamadaFunc", "$@81",
  "$@82", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -183

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-183)))

#define YYTABLE_NINF -177

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,  -183,    12,   -22,  -183,  -183,    32,  -183,    24,  -183,
    -183,   -11,    10,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,    25,    25,    30,  -183,  -183,    24,    28,  -183,
    -183,  -183,  -183,     3,  -183,    33,    39,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,    40,    65,    49,    67,  -183,
    -183,  -183,  -183,    -5,  -183,  -183,    55,    66,    70,  -183,
    -183,    55,  -183,    68,  -183,    29,  -183,  -183,  -183,  -183,
    -183,    49,  -183,  -183,  -183,  -183,  -183,    78,  -183,    25,
       6,  -183,   -32,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
      69,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,    80,  -183,  -183,    81,    74,
      77,    42,    90,    80,    87,    71,    98,  -183,  -183,    91,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,    99,  -183,  -183,  -183,   110,   111,  -183,  -183,
      60,   107,  -183,  -183,  -183,  -183,   103,   108,  -183,   106,
      80,    71,   127,    52,   109,    86,    86,    71,   113,  -183,
     104,  -183,  -183,  -183,  -183,    71,  -183,  -183,  -183,  -183,
      34,  -183,   110,  -183,  -183,    58,  -183,   110,  -183,  -183,
    -183,    -4,  -183,    71,  -183,    71,    86,    86,    86,   110,
      86,    71,    71,  -183,  -183,   114,   116,  -183,  -183,    86,
    -183,    71,   111,  -183,   119,   107,  -183,   117,   119,    11,
     110,   118,   115,   110,   105,    80,  -183,  -183,   120,    52,
     119,   122,  -183,  -183,  -183,   121,  -183,  -183,  -183,  -183,
      42,    71,  -183,  -183,   123,  -183,    42,    86,  -183,   124,
      71,  -183,   110,  -183,  -183,   119,  -183,   110,   130,    71,
     145,  -183,   110,  -183,  -183,   126,   128,    42,  -183,  -183,
    -183,    86,   119,   132,  -183,  -183,    42,  -183
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     3,     0,     4,     7,     8,
      30,     0,     0,     9,    35,    39,    52,    31,    49,    33,
      34,     5,     0,     0,     0,    49,    32,     7,     0,    17,
      15,    16,    18,     0,    11,     0,     0,    40,    53,    50,
       6,    10,    12,    13,    36,     0,     0,     0,     0,    41,
      54,    51,    22,     0,    19,    37,     0,     0,    24,    14,
      20,     0,    44,     0,    42,     0,    45,    56,    55,    25,
      23,     0,    38,    48,    43,    46,    58,     0,    21,     0,
     131,    27,     0,    47,   119,   103,    80,    85,   110,    92,
     128,    71,    57,    70,    60,    59,    61,    62,    63,    64,
      65,    66,    68,    69,    67,     0,    26,    28,     0,     0,
       0,   131,     0,     0,     0,     0,     0,   168,   132,     0,
     120,   104,    81,    86,   111,    93,   127,   161,   162,   146,
     163,   165,   168,   158,   160,   159,   129,   139,   142,   145,
     148,   151,   154,   157,   167,    72,   170,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   140,
       0,   143,   149,   152,   155,     0,   171,   169,   133,   121,
       0,   107,    82,    87,   117,     0,   114,   118,    94,   147,
     164,     0,   177,     0,   130,     0,     0,     0,     0,    73,
       0,     0,   124,   105,   108,     0,     0,   112,   115,     0,
     166,   124,   141,   144,   150,   153,   156,     0,   173,     0,
     134,     0,   125,   136,     0,     0,    83,    88,     0,     0,
      95,     0,    74,   172,   174,     0,   122,   137,   106,   109,
     131,     0,   113,   116,     0,   178,   131,     0,   135,     0,
       0,    84,    89,    96,    75,   175,   123,   138,     0,     0,
      77,    90,    97,    78,    76,     0,     0,   131,    91,    98,
      79,     0,    99,     0,   100,   101,   131,   102
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,  -183,  -183,  -183,  -183,   131,  -183,  -183,  -183,
     129,  -183,    17,  -183,  -183,    83,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,   112,  -183,  -183,    92,   134,  -183,  -183,  -183,
    -183,  -183,  -183,   125,  -183,  -183,  -111,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
     -50,  -183,  -183,  -183,  -183,  -183,   -31,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -114,  -183,
      -9,  -183,   -13,  -183,    20,  -183,  -182,  -183,   -10,  -183,
    -153,  -183,  -183,  -103,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     8,    28,    10,    11,    22,    33,
      34,    47,    63,    53,    71,    54,    58,    70,    77,    82,
     119,    12,    17,    18,    19,    23,    48,    61,    20,    24,
      45,    56,    64,    65,    79,    66,    26,    27,    46,    21,
      25,    51,    57,    94,    76,    80,    95,    96,   116,   165,
     207,   236,   250,   254,   257,    97,   110,   151,   195,   230,
      98,   111,   152,   196,   231,   248,   255,    99,   113,   154,
     199,   234,   249,   256,   261,   263,   265,   266,   100,   109,
     150,   214,   170,   215,   101,   112,   153,   218,   175,   219,
     176,   102,   108,   149,   192,   239,   211,   103,   114,   115,
     160,   104,   105,   147,   191,   225,   212,   240,   177,   183,
     137,   185,   138,   155,   139,   186,   140,   187,   141,   188,
     142,   156,   157,   143,   146,   167,   190,   209,   237,   144,
     158,   201
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     123,   136,   118,   180,   204,   106,    29,     1,   208,   107,
     125,    30,     4,    84,    14,    15,    31,   220,    85,    32,
       5,    86,   159,    87,    88,    89,    90,    13,    29,    91,
      59,   200,    16,    30,     9,   206,    60,   172,    31,    35,
      36,    32,    41,   181,    67,    92,    93,   171,   223,    84,
      35,   189,   224,    40,    85,   245,     7,    86,    29,    87,
      88,    89,    90,    30,    74,    91,   127,    43,    31,   193,
      75,    32,    37,   128,    49,   194,    50,   210,   213,   262,
      67,    44,    93,   129,   130,   127,   131,   213,   162,   163,
      62,    52,   128,   197,   132,   133,   134,   135,   174,   198,
     127,    55,   129,   130,    67,   131,    69,   128,   121,  -126,
      73,   122,   229,   132,   133,   134,   135,   242,   130,   241,
     131,    81,   117,   120,   124,   244,   247,   126,   132,   133,
     134,   135,   145,  -176,   148,   252,   159,   164,   161,   166,
     169,   168,   173,   178,   184,   228,   260,   182,   163,   216,
     217,   253,   222,   226,    78,   267,   227,   235,    39,    38,
     232,   238,    42,   243,   246,   251,   258,   264,   259,   233,
     221,    83,   203,    72,   202,   179,     0,   205,     0,     0,
       0,     0,    68
};

static const yytype_int16 yycheck[] =
{
     111,   115,   105,   156,   186,    37,     3,     9,   190,    41,
     113,     8,     0,     7,     4,     5,    13,   199,    12,    16,
      42,    15,    26,    17,    18,    19,    20,    38,     3,    23,
      35,    35,    22,     8,    10,   188,    41,   151,    13,    22,
      23,    16,    39,   157,    38,    39,    40,   150,    37,     7,
      33,   165,    41,    25,    12,   237,    24,    15,     3,    17,
      18,    19,    20,     8,    35,    23,    14,    34,    13,    35,
      41,    16,    42,    21,    34,    41,    11,   191,   192,   261,
      38,    42,    40,    31,    32,    14,    34,   201,    28,    29,
      35,    42,    21,    35,    42,    43,    44,    45,    46,    41,
      14,    34,    31,    32,    38,    34,    36,    21,    34,    40,
      42,    34,   215,    42,    43,    44,    45,   231,    32,   230,
      34,    43,    42,    42,    34,   236,   240,    40,    42,    43,
      44,    45,    34,    34,    43,   249,    26,    30,    27,    36,
      34,    33,    15,    34,    40,    40,   257,    34,    29,    35,
      34,     6,    35,    35,    71,   266,    41,    35,    27,    25,
      40,    40,    33,    40,    40,    35,    40,    35,    40,   219,
     201,    79,   185,    61,   183,   155,    -1,   187,    -1,    -1,
      -1,    -1,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    49,    50,     0,    42,    51,    24,    52,    10,
      54,    55,    69,    38,     4,     5,    22,    70,    71,    72,
      76,    87,    56,    73,    77,    88,    84,    85,    53,     3,
       8,    13,    16,    57,    58,    60,    60,    42,    84,    54,
      25,    39,    58,    34,    42,    78,    86,    59,    74,    34,
      11,    89,    42,    61,    63,    34,    79,    90,    64,    35,
      41,    75,    35,    60,    80,    81,    83,    38,    91,    36,
      65,    62,    80,    42,    35,    41,    92,    66,    63,    82,
      93,    43,    67,    83,     7,    12,    15,    17,    18,    19,
      20,    23,    39,    40,    91,    94,    95,   103,   108,   115,
     126,   132,   139,   145,   149,   150,    37,    41,   140,   127,
     104,   109,   133,   116,   146,   147,    96,    42,   171,    68,
      42,    34,    34,    94,    34,   171,    40,    14,    21,    31,
      32,    34,    42,    43,    44,    45,   156,   158,   160,   162,
     164,   166,   168,   171,   177,    34,   172,   151,    43,   141,
     128,   105,   110,   134,   117,   161,   169,   170,   178,    26,
     148,    27,    28,    29,    30,    97,    36,   173,    33,    34,
     130,   171,   156,    15,    46,   136,   138,   156,    34,   162,
     168,   156,    34,   157,    40,   159,   163,   165,   167,   156,
     174,   152,   142,    35,    41,   106,   111,    35,    41,   118,
      35,   179,   158,   160,   164,   166,   168,    98,   164,   175,
     156,   144,   154,   156,   129,   131,    35,    34,   135,   137,
     164,   144,    35,    37,    41,   153,    35,    41,    40,   171,
     107,   112,    40,   138,   119,    35,    99,   176,    40,   143,
     155,    94,   156,    40,    94,   164,    40,   156,   113,   120,
     100,    35,   156,     6,   101,   114,   121,   102,    40,    40,
      94,   122,   164,   123,    35,   124,   125,    94
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    50,    51,    52,    53,    49,    54,    55,    56,
      54,    57,    57,    59,    58,    60,    60,    60,    60,    61,
      62,    61,    64,    63,    65,    66,    65,    67,    68,    67,
      69,    69,    70,    71,    71,    73,    74,    75,    72,    77,
      78,    79,    76,    80,    80,    81,    82,    81,    83,    85,
      86,    84,    88,    87,    90,    89,    92,    91,    93,    93,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    96,    97,    98,    99,   100,    95,   101,   102,   101,
     104,   105,   106,   107,   103,   109,   110,   111,   112,   113,
     114,   108,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   115,   127,   128,   129,   126,   130,   131,   130,
     133,   134,   135,   132,   136,   137,   136,   138,   138,   140,
     141,   142,   143,   139,   144,   144,   146,   145,   147,   148,
     145,   150,   151,   152,   153,   149,   154,   155,   154,   156,
     157,   156,   158,   159,   158,   160,   161,   160,   162,   163,
     162,   164,   165,   164,   166,   167,   166,   168,   168,   168,
     168,   168,   168,   169,   168,   170,   168,   168,   172,   171,
     173,   174,   173,   175,   176,   175,   178,   179,   177
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,    11,     0,     0,     0,
       6,     1,     2,     0,     5,     1,     1,     1,     1,     1,
       0,     4,     0,     3,     0,     0,     4,     1,     0,     4,
       0,     2,     2,     1,     1,     0,     0,     0,     8,     0,
       0,     0,     7,     2,     1,     1,     0,     4,     2,     0,
       0,     4,     0,     3,     0,     3,     0,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     0,     0,     0,     0,    11,     0,     0,     3,
       0,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,     0,     0,     0,     8,     1,     0,     4,
       0,     0,     0,     8,     1,     0,     4,     1,     1,     0,
       0,     0,     0,    10,     0,     1,     0,     3,     0,     0,
       5,     0,     0,     0,     0,     8,     1,     0,     4,     1,
       0,     4,     1,     0,     4,     1,     0,     3,     1,     0,
       4,     1,     0,     4,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     0,     3,     0,     4,     1,     0,     3,
       0,     0,     4,     1,     0,     4,     0,     0,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 382 "Lab6.y" /* yacc.c:1646  */
    {InicTabSimb();printf("%s ", (yyvsp[0].cadeia)); InicCodIntermed(); pilhaTopo = NULL;}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 383 "Lab6.y" /* yacc.c:1646  */
    {printf("%s ", (yyvsp[0].cadeia));}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 384 "Lab6.y" /* yacc.c:1646  */
    {printf("%s\n\n", (yyvsp[0].cadeia)); 
                char * scope = createScopeString("##global");
                escopoAtual = InsereSimb(scope, NOTVAR, SCOPE, NULL);
                global = escopoAtual;
                simbolo simb = InsereSimb((yyvsp[-2].cadeia),IDPROG,NOTVAR, escopoAtual);
                InicCodIntermedMod(escopoAtual);
                opnd1.tipo = MODOPND;
                opnd1.atr.modulo = modcorrente;
                GeraQuadrupla(OPENMOD, opnd1, opndidle, opndidle);
                free(scope);
                ehDecl = 1;
                }
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 398 "Lab6.y" /* yacc.c:1646  */
    {
                        modcorrente = codintermed->prox;
                        quadcorrente = codintermed->prox->listquad->prox;
                        opnd1.tipo = PROCPND;
                        ehDecl = 0;
                        simbolo simb = ProcuraSimb("principal", global);
                        opnd1.atr.simb = simb;
                        GeraQuadrupla(CALLOP, opnd1, opndidle, opndidle);
                        GeraQuadrupla(OPEXIT, opndidle, opndidle, opndidle);
                }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 408 "Lab6.y" /* yacc.c:1646  */
    {printf("%s\n", (yyvsp[0].cadeia));
                //ImprimeNaoUsados();
                //ImprimeTabSimb();
                //ImprimeQuadruplas();
                InterpCodIntermed();
                }
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 417 "Lab6.y" /* yacc.c:1646  */
    {printf("%s ", (yyvsp[0].cadeia));}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 418 "Lab6.y" /* yacc.c:1646  */
    {printf("%c\n", (yyvsp[0].carac)); tab++;}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 420 "Lab6.y" /* yacc.c:1646  */
    {printf("%c\n\n", (yyvsp[0].carac)); tab--; ehDecl = 0;}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 429 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 431 "Lab6.y" /* yacc.c:1646  */
    {printf("%c\n", (yyvsp[0].carac));}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 435 "Lab6.y" /* yacc.c:1646  */
    {tabular(); printf("%s ", (yyvsp[0].cadeia)); tipocorrente = INTEGER;}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 436 "Lab6.y" /* yacc.c:1646  */
    {tabular(); printf("%s ", (yyvsp[0].cadeia));tipocorrente = FLOAT;}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 437 "Lab6.y" /* yacc.c:1646  */
    {tabular(); printf("%s ", (yyvsp[0].cadeia));tipocorrente = CHAR;}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 438 "Lab6.y" /* yacc.c:1646  */
    {tabular(); printf("%s ", (yyvsp[0].cadeia));tipocorrente = LOGICAL;}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 443 "Lab6.y" /* yacc.c:1646  */
    {printf("%c ", (yyvsp[0].carac));}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 447 "Lab6.y" /* yacc.c:1646  */
    {
                    printf("%s", (yyvsp[0].cadeia));
                    simbolo simb = NULL;
                    if(ProcuraSimb((yyvsp[0].cadeia), escopoAtual) !=NULL) 
                        DeclaracaoRepetida((yyvsp[0].cadeia)); 
                    else 
                        simb = InsereSimb((yyvsp[0].cadeia),IDVAR,tipocorrente, escopoAtual);
                    
                    atual = simb;
                }
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 457 "Lab6.y" /* yacc.c:1646  */
    {
                    if(atual != NULL)
                    {
                        atual->ndims = subsc;
                    }
                    subsc = 0;
                }
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 467 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 469 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 472 "Lab6.y" /* yacc.c:1646  */
    {printf("%s", (yyvsp[0].cadeia)); 
                if(atoi((yyvsp[0].cadeia)) <=0)
                {
                    DimensaoInvalida();
                }
                subsc++;
                atual->dims[subsc] = atoi((yyvsp[0].cadeia));    
            }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 481 "Lab6.y" /* yacc.c:1646  */
    {printf("%c ", (yyvsp[0].carac));}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 482 "Lab6.y" /* yacc.c:1646  */
    {printf("%s", (yyvsp[0].cadeia));
                    if(atoi((yyvsp[0].cadeia)) <=0)
                    {
                        DimensaoInvalida();
                    }
                    subsc++;
                    atual->dims[subsc] = atoi((yyvsp[0].cadeia));
                }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 498 "Lab6.y" /* yacc.c:1646  */
    {
                    escopoAtual = escopoAtual->escopo;
                    if(quadcorrente->oper != OPRETURN)
                    {
                        GeraQuadrupla(OPRETURN, opndidle, opndidle, opndidle);
                    }
                }
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 511 "Lab6.y" /* yacc.c:1646  */
    {printf("%s ", (yyvsp[0].cadeia));}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 513 "Lab6.y" /* yacc.c:1646  */
    {printf("%s ", (yyvsp[0].cadeia));
                    ehDecl = 1; 
                    if(ProcuraSimb((yyvsp[0].cadeia), escopoAtual) != NULL) 
                        DeclaracaoRepetida((yyvsp[0].cadeia)); 
                    else{
                        escopoAtual = InsereSimb((yyvsp[0].cadeia),IDFUNC,tipocorrente, escopoAtual);
                        InicCodIntermedMod(escopoAtual);
                        opnd1.tipo = FUNCPND;
                        opnd1.atr.modulo = modcorrente;
                        GeraQuadrupla(OPENMOD,opnd1,opndidle,opndidle);
                    } 
                        
                    }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 526 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 527 "Lab6.y" /* yacc.c:1646  */
    {ehDecl = 0;}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 530 "Lab6.y" /* yacc.c:1646  */
    {printf("%s ", (yyvsp[0].cadeia));}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 531 "Lab6.y" /* yacc.c:1646  */
    {printf("%s ", (yyvsp[0].cadeia));
                        ehDecl = 1;
                        if(ProcuraSimb((yyvsp[0].cadeia), escopoAtual)!=NULL) 
                            DeclaracaoRepetida((yyvsp[0].cadeia)); 
                        else{
                            escopoAtual = InsereSimb((yyvsp[0].cadeia),IDPROC,NOTVAR, escopoAtual);
                            InicCodIntermedMod(escopoAtual);
                            opnd1.tipo = PROCPND;
                            opnd1.atr.modulo = modcorrente;
                            GeraQuadrupla(OPENMOD,opnd1,opndidle,opndidle);
                        } 
                    }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 543 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 544 "Lab6.y" /* yacc.c:1646  */
    {ehDecl = 0;}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 549 "Lab6.y" /* yacc.c:1646  */
    {printf("%c\n", (yyvsp[0].carac));}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 550 "Lab6.y" /* yacc.c:1646  */
    {printf("%c\n", (yyvsp[0].carac));}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 555 "Lab6.y" /* yacc.c:1646  */
    {printf("%c ", (yyvsp[0].carac));}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 560 "Lab6.y" /* yacc.c:1646  */
    {printf("%s", (yyvsp[0].cadeia));
                if(ProcuraSimb((yyvsp[0].cadeia), escopoAtual)!=NULL)
                    DeclaracaoRepetida((yyvsp[0].cadeia)); 
                else 
                {
                    simbolo par = InsereSimb((yyvsp[0].cadeia),IDVAR,tipocorrente, escopoAtual);
                    par->inic = TRUE;
                    InsereParametro(escopoAtual, par);
                }
                }
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 572 "Lab6.y" /* yacc.c:1646  */
    {ehDecl = 1;}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 572 "Lab6.y" /* yacc.c:1646  */
    {ehDecl = 0;}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 576 "Lab6.y" /* yacc.c:1646  */
    {printf("%s\n", (yyvsp[0].cadeia));
                        escopoAtual = InsereSimb((yyvsp[0].cadeia), IDPROC, NOTVAR, escopoAtual);
                        InicCodIntermedMod(escopoAtual);
                        opnd1.tipo = MODOPND;
                        opnd1.atr.modulo = modcorrente;
                        GeraQuadrupla(OPENMOD, opnd1, opndidle, opndidle);
                        }
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 584 "Lab6.y" /* yacc.c:1646  */
    {
                        GeraQuadrupla(OPRETURN,opndidle,opndidle,opndidle);
                    }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 589 "Lab6.y" /* yacc.c:1646  */
    {printf("%s ", (yyvsp[0].cadeia)); tab++;}
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 590 "Lab6.y" /* yacc.c:1646  */
    {tab--; printf("\n");}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 593 "Lab6.y" /* yacc.c:1646  */
    {printf("%c\n", (yyvsp[0].carac)); newLines = 0;}
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 595 "Lab6.y" /* yacc.c:1646  */
    {tab--; tabular(); printf("%c", (yyvsp[0].carac)); isRepeat(); tab++; enquantoTabular = 0;}
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 613 "Lab6.y" /* yacc.c:1646  */
    {printf("%c\n", (yyvsp[0].carac));}
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 616 "Lab6.y" /* yacc.c:1646  */
    {jumpLines(); tabular(); printf("%s ", (yyvsp[0].cadeia));}
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 617 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 618 "Lab6.y" /* yacc.c:1646  */
    {
                    if((yyvsp[0].infoexpr).tipo != LOGICAL)
                    {
                        TipoIncompativel();
                    }
                    
                    opndaux.tipo = ROTOPND;
                    (yyval.quad) = GeraQuadrupla(OPJF, (yyvsp[0].infoexpr).opnd, opndidle, opndaux);
                }
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 627 "Lab6.y" /* yacc.c:1646  */
    {printf("%c ", (yyvsp[0].carac)); tab++; newLines=1;}
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 628 "Lab6.y" /* yacc.c:1646  */
    {
                    tab--; newLines=0;
                    (yyval.quad) = quadcorrente;
                    (yyvsp[-3].quad)->result.atr.rotulo = GeraQuadrupla(NOP,opndidle,opndidle,opndidle);    
                }
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 633 "Lab6.y" /* yacc.c:1646  */
    {
                    if ((yyvsp[-1].quad)->prox != quadcorrente) {
                  	    quadaux = (yyvsp[-1].quad)->prox;
                        (yyvsp[-1].quad)->prox = quadaux->prox;
                        quadaux->prox = (yyvsp[-1].quad)->prox->prox;
                        (yyvsp[-1].quad)->prox->prox = quadaux;
                        RenumQuadruplas ((yyvsp[-1].quad), quadcorrente);
                    }
                }
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 645 "Lab6.y" /* yacc.c:1646  */
    {
                    jumpLines(); 
                    tabular(); 
                    printf("%s ", (yyvsp[0].cadeia)); 
                    tab++;
                    newLines=1;
                    opndaux.tipo = ROTOPND;
                    (yyval.quad) = GeraQuadrupla(OPJUMP, opndidle, opndidle, opndaux);    
                }
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 654 "Lab6.y" /* yacc.c:1646  */
    {
                    tab--; 
                    newLines=0;
                    (yyvsp[-1].quad)->result.atr.rotulo = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                }
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 661 "Lab6.y" /* yacc.c:1646  */
    {
                    jumpLines(); 
                    tabular(); 
                    printf("%s ", (yyvsp[0].cadeia));
                    (yyval.quad) = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                }
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 667 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 668 "Lab6.y" /* yacc.c:1646  */
    {
                    if((yyvsp[0].infoexpr).tipo != LOGICAL)
                    {
                        TipoIncompativel();
                    }
                    opndaux.tipo = ROTOPND;
                    (yyval.quad) = GeraQuadrupla(OPJF, (yyvsp[0].infoexpr).opnd, opndidle, opndaux);
    
                }
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 677 "Lab6.y" /* yacc.c:1646  */
    {printf("%c ", (yyvsp[0].carac)); tab++;}
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 678 "Lab6.y" /* yacc.c:1646  */
    {
                    tab--;

                    opndaux.tipo = ROTOPND;
                    opndaux.atr.rotulo = (yyvsp[-7].quad);
                    GeraQuadrupla(OPJUMP, opndidle, opndidle, opndaux);
                    (yyvsp[-3].quad)->result.atr.rotulo = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);
                }
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 688 "Lab6.y" /* yacc.c:1646  */
    {
                    jumpLines(); 
                    tabular(); 
                    printf("%s ", (yyvsp[0].cadeia)); 
                    tab++; 
                    repeat=1; 
                    newLines=1; 
                    enquantoTabular = 1;
                    (yyval.quad) = GeraQuadrupla(NOP, opndidle, opndidle, opndidle);    
                }
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 698 "Lab6.y" /* yacc.c:1646  */
    {tab--; newLines=0;}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 699 "Lab6.y" /* yacc.c:1646  */
    {
                    if(enquantoTabular==1)
                    {
                        tabular();
                    }
                    else
                    {
                        printf(" ");
                    }
                    printf("%s ", (yyvsp[0].cadeia));
                    repeat = 0;
                    }
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 711 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 712 "Lab6.y" /* yacc.c:1646  */
    {
                    if((yyvsp[0].infoexpr).tipo != LOGICAL)
                    {
                        TipoIncompativel();
                    }
                    opndaux.tipo = ROTOPND;
                    opndaux.atr.rotulo = (yyvsp[-7].quad);
                    GeraQuadrupla(OPJT, (yyvsp[0].infoexpr).opnd, opndidle, opndaux);
                }
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 721 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 722 "Lab6.y" /* yacc.c:1646  */
    {printf("%c\n", (yyvsp[0].carac));}
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 725 "Lab6.y" /* yacc.c:1646  */
    {jumpLines(); tabular(); printf("%s ", (yyvsp[0].cadeia)); cmdAtual = CMDPARA;}
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 726 "Lab6.y" /* yacc.c:1646  */
    {
                    printf(" ");
                    cmdAtual = 0;
                    if((yyvsp[0].infovar).simb == NULL)
                        TipoIncompativel();
                    else if((yyvsp[0].infovar).simb->tvar != INTEGER && (yyvsp[0].infovar).simb->tvar != CHAR)
                    {
                        TipoIncompativel();
                    }
                    
                }
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 737 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 738 "Lab6.y" /* yacc.c:1646  */
    {
                    if((yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo != CHAR)
                    {
                        TipoIncompativel();
                    }
                    GeraQuadrupla(OPATRIB, (yyvsp[0].infoexpr).opnd, opndidle, (yyvsp[-4].infovar).opnd);
                }
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 745 "Lab6.y" /* yacc.c:1646  */
    {
                    printf("%c ", (yyvsp[0].carac));
                    (yyval.quad) = GeraQuadrupla (NOP, opndidle, opndidle, opndidle);
                }
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 749 "Lab6.y" /* yacc.c:1646  */
    {
                    if((yyvsp[0].infoexpr).tipo != LOGICAL)
                    {
                        TipoIncompativel();
                    }
                    opndaux.tipo = ROTOPND;
	                (yyval.quad) = GeraQuadrupla (OPJF, (yyvsp[0].infoexpr).opnd, opndidle, opndaux);
                }
#line 2456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 757 "Lab6.y" /* yacc.c:1646  */
    {
                    printf("%c ", (yyvsp[0].carac));
                    (yyval.quad) = GeraQuadrupla (NOP, opndidle, opndidle, opndidle);
                }
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 761 "Lab6.y" /* yacc.c:1646  */
    {
                    if((yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo != CHAR)
                    {
                        TipoIncompativel();
                    }
                    GeraQuadrupla(OPATRIB, (yyvsp[0].infoexpr).opnd, opndidle, (yyvsp[-12].infovar).opnd);
                    
                }
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 769 "Lab6.y" /* yacc.c:1646  */
    {
                    
                    printf("%c", (yyvsp[0].carac)); tab++; newLines=1;
                    (yyval.quad) = quadcorrente; 
                
                }
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 776 "Lab6.y" /* yacc.c:1646  */
    { (yyval.quad) = GeraQuadrupla (NOP, opndidle, opndidle, opndidle); }
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 778 "Lab6.y" /* yacc.c:1646  */
    {
                    tab--; newLines=0;
    
                    quadaux = quadcorrente;
                    opndaux.tipo = ROTOPND;  opndaux.atr.rotulo = (yyvsp[-10].quad);
                    quadrupla quadaux2 = GeraQuadrupla (OPJUMP, opndidle, opndidle, opndaux);
                    (yyvsp[-8].quad)->result.atr.rotulo = GeraQuadrupla(NOP, opndidle, opndidle, opndidle); 

                    (yyvsp[-8].quad)->prox = (yyvsp[-1].quad);
                    quadaux->prox = (yyvsp[-6].quad);
                    (yyvsp[-2].quad)->prox = quadaux2;
                    
                    RenumQuadruplas ((yyvsp[-8].quad), quadcorrente);

                }
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 795 "Lab6.y" /* yacc.c:1646  */
    {jumpLines(); tabular(); printf("%s ", (yyvsp[0].cadeia)); cmdAtual = CMDLER;}
#line 2521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 796 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 2527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 798 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 2533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 799 "Lab6.y" /* yacc.c:1646  */
    {
                    printf("%c\n", (yyvsp[0].carac)); 
                    cmdAtual = 0;
                    if(countParams > 0)
                    {
                        opnd1.tipo = INTOPND;
                        opnd1.atr.valint = countParams;
                        GeraQuadrupla(OPLER, opnd1, opndidle, opndidle);
                    }
                    countParams = 0;    
                }
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 812 "Lab6.y" /* yacc.c:1646  */
    {
                    TrataLeitura((yyvsp[0].infovar));
                }
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 816 "Lab6.y" /* yacc.c:1646  */
    {printf("%c ", (yyvsp[0].carac));}
#line 2563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 817 "Lab6.y" /* yacc.c:1646  */
    {
                    TrataLeitura((yyvsp[0].infovar));
                }
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 822 "Lab6.y" /* yacc.c:1646  */
    {jumpLines(); tabular(); printf("%s ", (yyvsp[0].cadeia));}
#line 2577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 823 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 825 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 2589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 826 "Lab6.y" /* yacc.c:1646  */
    {
                    printf("%c\n", (yyvsp[0].carac));
                    opnd1.tipo = INTOPND;
                    opnd1.atr.valint = countParams;
                    GeraQuadrupla(OPWRITE, opnd1, opndidle, opndidle);
                    countParams = 0;    
                }
#line 2601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 837 "Lab6.y" /* yacc.c:1646  */
    {printf("%c ", (yyvsp[0].carac));}
#line 2607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 841 "Lab6.y" /* yacc.c:1646  */
    {
                    printf("%s", (yyvsp[0].cadeia));
                    opnd1.tipo = CADOPND;
                    int len = strlen((yyvsp[0].cadeia));
                    opnd1.atr.valcad = (char *) malloc(sizeof(char) * len);
                    memcpy(opnd1.atr.valcad, &(yyvsp[0].cadeia)[1], len-2);
                    opnd1.atr.valcad[len-2]= '\0';
                    GeraQuadrupla(PARAM, opnd1, opndidle, opndidle);
                    countParams++;
                }
#line 2622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 852 "Lab6.y" /* yacc.c:1646  */
    {
                    GeraQuadrupla(PARAM, (yyvsp[0].infoexpr).opnd, opndidle, opndidle);
                    countParams++;
                }
#line 2631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 858 "Lab6.y" /* yacc.c:1646  */
    {jumpLines(); tabular(); printf("%s ", (yyvsp[0].cadeia));}
#line 2637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 859 "Lab6.y" /* yacc.c:1646  */
    {printf("%s ", (yyvsp[0].cadeia));
                    simbolo proc = ProcuraSimb((yyvsp[0].cadeia), escopoAtual);
                    if(proc == NULL)
                    {
                        NaoDeclarado((yyvsp[0].cadeia));
                    }
                    else if(proc->tid != IDPROC)
                    {
                        TipoInadequado((yyvsp[0].cadeia));
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
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 879 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 2668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 881 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 2674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 882 "Lab6.y" /* yacc.c:1646  */
    {
                    printf("%c\n", (yyvsp[0].carac));
                    moduloChamado = NULL;
                    paramAtual = NULL;
                    simbolo proc = ProcuraSimb((yyvsp[-7].cadeia), escopoAtual);

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
                        if(countParams > 0)
                        {
                            opnd2.tipo = INTOPND;
                            opnd2.atr.valint = countParams;
                            GeraQuadrupla(CALLOP, opnd1, opnd2, opndidle);
                        }
                        else
                        {
                            GeraQuadrupla(CALLOP, opnd1, opndidle, opndidle);
                        }                    
                    }
                    countParams = 0;
                }
#line 2710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 919 "Lab6.y" /* yacc.c:1646  */
    {jumpLines(); tabular(); printf("%s ", (yyvsp[0].cadeia));
                                if(escopoAtual->tid == IDFUNC)
                                {
                                    ReturnVazio();
                                }
                                GeraQuadrupla(OPRETURN, opndidle, opndidle, opndidle);
                            }
#line 2722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 926 "Lab6.y" /* yacc.c:1646  */
    {printf("%c\n", (yyvsp[0].carac));}
#line 2728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 927 "Lab6.y" /* yacc.c:1646  */
    {jumpLines(); tabular(); printf("%s ", (yyvsp[0].cadeia));
                                if(escopoAtual->tid == IDPROC)
                                {
                                    ReturnInadequado();
                                }
                            }
#line 2739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 933 "Lab6.y" /* yacc.c:1646  */
    {
                    switch(escopoAtual->tvar)
                    {
                        case INTEGER:
                        case CHAR:
                            if((yyvsp[0].infoexpr).tipo != CHAR && (yyvsp[0].infoexpr).tipo != INTEGER)
                            {
                                TipoIncompativel();
                            }
                            break;
                        case REAL:
                            if((yyvsp[0].infoexpr).tipo != REAL && (yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo != CHAR)
                            {
                                TipoIncompativel();
                            }
                            break;
                        case LOGICAL:
                            if((yyvsp[0].infoexpr).tipo != LOGICAL)
                            {
                                TipoIncompativel();
                            }
                    }
                }
#line 2767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 956 "Lab6.y" /* yacc.c:1646  */
    {
                    printf("%c\n", (yyvsp[0].carac));
                    GeraQuadrupla(OPRETURN, (yyvsp[-2].infoexpr).opnd, opndidle, opndidle);
                    }
#line 2776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 962 "Lab6.y" /* yacc.c:1646  */
    {jumpLines(); tabular(); cmdAtual = CMDATRIB;}
#line 2782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 962 "Lab6.y" /* yacc.c:1646  */
    {cmdAtual = 0;}
#line 2788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 963 "Lab6.y" /* yacc.c:1646  */
    {printf(" %c ", (yyvsp[0].carac));}
#line 2794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 964 "Lab6.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-4].infovar).simb == NULL)
                        TipoIncompativel();
                    else
                    {
                        switch((yyvsp[-4].infovar).simb->tvar)
                        {
                            case INTEGER:
                            case CHAR:
                            {
                                if((yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo != CHAR)
                                {
                                    TipoIncompativel();
                                }
                            }
                            break;
                            case FLOAT:
                            {
                                if((yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo != FLOAT && (yyvsp[0].infoexpr).tipo != CHAR)
                                {
                                    TipoIncompativel();
                                }
                            }
                            break;
                            case LOGICAL:
                            {
                                if((yyvsp[0].infoexpr).tipo != LOGICAL)
                                {
                                    TipoIncompativel();
                                }
                            }
                        }
                        if((yyvsp[-4].infovar).simb->ndims==0)
                        {
                            GeraQuadrupla(OPATRIB, (yyvsp[0].infoexpr).opnd, opndidle, (yyvsp[-4].infovar).opnd);
                        }
                        else
                        {
                            GeraQuadrupla(ATRIBPONT, (yyvsp[0].infoexpr).opnd, opndidle, (yyvsp[-4].infovar).opnd);
                        }
                        
                    }
                    
                }
#line 2843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1008 "Lab6.y" /* yacc.c:1646  */
    {printf("%c\n", (yyvsp[0].carac));}
#line 2849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1011 "Lab6.y" /* yacc.c:1646  */
    {
                    if(paramAtual != NULL)
                    {
                        TestaCompatibilidade(paramAtual->simb->tvar, (yyvsp[0].infoexpr).tipo);
                        paramAtual = paramAtual->prox;
                    }
                    GeraQuadrupla(PARAM, (yyvsp[0].infoexpr).opnd, opndidle, opndidle);
                    countParams++;
                }
#line 2863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1021 "Lab6.y" /* yacc.c:1646  */
    {printf("%c ", (yyvsp[0].carac));}
#line 2869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1022 "Lab6.y" /* yacc.c:1646  */
    {
                    if(paramAtual != NULL)
                    {
                        TestaCompatibilidade(paramAtual->simb->tvar, (yyvsp[0].infoexpr).tipo);
                        paramAtual = paramAtual->prox;
                    }
                    GeraQuadrupla(PARAM, (yyvsp[0].infoexpr).opnd, opndidle, opndidle);
                    countParams++;
                }
#line 2883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1033 "Lab6.y" /* yacc.c:1646  */
    {(yyval.infoexpr).tipo = (yyvsp[0].infoexpr).tipo;}
#line 2889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1035 "Lab6.y" /* yacc.c:1646  */
    {printf(" %s ", (yyvsp[0].cadeia));}
#line 2895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1037 "Lab6.y" /* yacc.c:1646  */
    {
                    (yyval.infoexpr).tipo = EhLogico((yyvsp[-3].infoexpr).tipo);
                    (yyval.infoexpr).tipo = EhLogico((yyvsp[0].infoexpr).tipo);

                    (yyval.infoexpr).opnd.tipo = VAROPND;
                    (yyval.infoexpr).opnd.atr.simb = NovaTemp((yyval.infoexpr).tipo);
                    GeraQuadrupla(OPOR, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                }
#line 2908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1047 "Lab6.y" /* yacc.c:1646  */
    {(yyval.infoexpr) = (yyvsp[0].infoexpr);}
#line 2914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1049 "Lab6.y" /* yacc.c:1646  */
    {printf(" %s ", (yyvsp[0].cadeia));}
#line 2920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1051 "Lab6.y" /* yacc.c:1646  */
    {
                    (yyval.infoexpr).tipo = EhLogico((yyvsp[-3].infoexpr).tipo);
                    (yyval.infoexpr).tipo = EhLogico((yyvsp[0].infoexpr).tipo);

                    (yyval.infoexpr).opnd.tipo = VAROPND;
                    (yyval.infoexpr).opnd.atr.simb = NovaTemp((yyval.infoexpr).tipo);
                    GeraQuadrupla(OPAND, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                }
#line 2933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1061 "Lab6.y" /* yacc.c:1646  */
    {(yyval.infoexpr) = (yyvsp[0].infoexpr);}
#line 2939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1062 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 2945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1064 "Lab6.y" /* yacc.c:1646  */
    {
                    (yyval.infoexpr).tipo = EhLogico((yyvsp[0].infoexpr).tipo);
                    (yyval.infoexpr).opnd.tipo = VAROPND;
                    (yyval.infoexpr).opnd.atr.simb = NovaTemp((yyval.infoexpr).tipo);
                    GeraQuadrupla(OPNOT, (yyvsp[0].infoexpr).opnd, opndidle, (yyval.infoexpr).opnd);
                }
#line 2956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1072 "Lab6.y" /* yacc.c:1646  */
    {(yyval.infoexpr) = (yyvsp[0].infoexpr);}
#line 2962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1075 "Lab6.y" /* yacc.c:1646  */
    {
                        switch((yyvsp[0].atr))
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
#line 2990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1098 "Lab6.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-2].atr) == IGUAL || (yyvsp[-2].atr) == DIFERENTE)
                    {
                        if((yyvsp[-3].infoexpr).tipo == NOTVAR || (yyvsp[0].infoexpr).tipo == NOTVAR)
                        {
                            TipoIncompativel();
                        }
                        if(((yyvsp[-3].infoexpr).tipo == LOGICAL && (yyvsp[0].infoexpr).tipo != LOGICAL) || ((yyvsp[-3].infoexpr).tipo != LOGICAL && (yyvsp[0].infoexpr).tipo == LOGICAL))
                        {
                            TipoIncompativel();
                        }
                    }
                    else
                    {
                        EhIntRealCarac((yyvsp[-3].infoexpr).tipo, (yyvsp[0].infoexpr).tipo);
                    }
                    (yyval.infoexpr).tipo = LOGICAL;
                    (yyval.infoexpr).opnd.tipo = VAROPND;
                    (yyval.infoexpr).opnd.atr.simb = NovaTemp((yyval.infoexpr).tipo);
                    switch((yyvsp[-2].atr))
                    {
                        case MENOR:
                            GeraQuadrupla(OPLT, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                            break;
                        case MAIOR:
                            GeraQuadrupla(OPGT, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                            break;
                        case MENIG:
                            GeraQuadrupla(OPLE, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                            break;
                        case MAIG:
                            GeraQuadrupla(OPGE, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                            break;
                        case IGUAL:
                            GeraQuadrupla(OPIGUAL, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                            break;
                        case DIFERENTE:
                            GeraQuadrupla(OPDIF, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                            break;
                    }

                }
#line 3037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1142 "Lab6.y" /* yacc.c:1646  */
    {(yyval.infoexpr) = (yyvsp[0].infoexpr);}
#line 3043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1145 "Lab6.y" /* yacc.c:1646  */
    {
                        switch((yyvsp[0].atr))
                        {
                            case MAIS:
                                printf(" + ");
                                break;
                            case MENOS:
                                printf(" - ");
                                break;
                        }
                    }
#line 3059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1157 "Lab6.y" /* yacc.c:1646  */
    {
                    (yyval.infoexpr).tipo = EhIntRealCarac((yyvsp[-3].infoexpr).tipo, (yyvsp[0].infoexpr).tipo);
                    (yyval.infoexpr).opnd.tipo = VAROPND;
                    (yyval.infoexpr).opnd.atr.simb = NovaTemp((yyval.infoexpr).tipo);
                    if((yyvsp[-2].atr) == MAIS)
                        GeraQuadrupla(OPMAIS, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                    else
                        GeraQuadrupla(OPMENOS, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                }
#line 3073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1168 "Lab6.y" /* yacc.c:1646  */
    {(yyval.infoexpr) = (yyvsp[0].infoexpr);}
#line 3079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1171 "Lab6.y" /* yacc.c:1646  */
    {
                        switch((yyvsp[0].atr))
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
#line 3098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1185 "Lab6.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-2].atr) == MODULO)
                        {
                            if((yyvsp[-3].infoexpr).tipo != INTEGER && (yyvsp[-3].infoexpr).tipo != CHAR)
                                TipoIncompativel();
                            
                            if((yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo != CHAR)
                                TipoIncompativel();
                            
                            if((yyvsp[-3].infoexpr).tipo >= (yyvsp[0].infoexpr).tipo)
                            {
                                (yyval.infoexpr).tipo = (yyvsp[-3].infoexpr).tipo;
                            }
                            else
                            {
                                (yyval.infoexpr).tipo = (yyvsp[0].infoexpr).tipo;
                            }
                            (yyval.infoexpr).opnd.tipo = VAROPND;
                            (yyval.infoexpr).opnd.atr.simb = NovaTemp((yyval.infoexpr).tipo);
                            GeraQuadrupla(OPMODULO, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                        }
                        else
                        {
                            (yyval.infoexpr).tipo = EhIntRealCarac((yyvsp[-3].infoexpr).tipo, (yyvsp[0].infoexpr).tipo);
                            (yyval.infoexpr).opnd.tipo = VAROPND;
                            (yyval.infoexpr).opnd.atr.simb = NovaTemp((yyval.infoexpr).tipo);
                            if((yyvsp[-2].atr) == VEZES)
                                GeraQuadrupla(OPVEZES, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                            else
                                GeraQuadrupla(OPDIV, (yyvsp[-3].infoexpr).opnd, (yyvsp[0].infoexpr).opnd, (yyval.infoexpr).opnd);
                        }
                }
#line 3135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1219 "Lab6.y" /* yacc.c:1646  */
    {
                if((yyvsp[0].infovar).simb !=NULL)
                {
                    (yyval.infoexpr).tipo = (yyvsp[0].infovar).simb->tvar;
                    if((yyvsp[0].infovar).simb->ndims == 0)
                    {
                        (yyval.infoexpr).opnd = (yyvsp[0].infovar).opnd;
                    }
                    else
                    {
                        simbolo novaTmp = NovaTemp((yyval.infoexpr).tipo);
                        opnd2.tipo = VAROPND;
                        opnd2.atr.simb = novaTmp;
                        GeraQuadrupla(CONTPONT, (yyvsp[0].infovar).opnd, opndidle, opnd2);
                        (yyval.infoexpr).opnd = opnd2;
                    }
                    
                }
                else
                    (yyval.infoexpr).tipo = NOTVAR;
            }
#line 3161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1240 "Lab6.y" /* yacc.c:1646  */
    {printf("%s", (yyvsp[0].cadeia)); 
                    (yyval.infoexpr).tipo = INTEGER; 
                    (yyval.infoexpr).opnd.tipo = INTOPND;
                    (yyval.infoexpr).opnd.atr.valint = atoi((yyvsp[0].cadeia));
                    }
#line 3171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1245 "Lab6.y" /* yacc.c:1646  */
    {printf("%s", (yyvsp[0].cadeia)); 
                    (yyval.infoexpr).tipo = FLOAT;
                    (yyval.infoexpr).opnd.tipo = REALOPND;
                    (yyval.infoexpr).opnd.atr.valfloat = atof((yyvsp[0].cadeia));
                    }
#line 3181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1250 "Lab6.y" /* yacc.c:1646  */
    {
                    printf("%s", (yyvsp[0].cadeia)); 
                    (yyval.infoexpr).tipo = CHAR;
                    (yyval.infoexpr).opnd.tipo = CHAROPND;
                    (yyval.infoexpr).opnd.atr.valchar = (yyvsp[0].cadeia)[1];
                    }
#line 3192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1256 "Lab6.y" /* yacc.c:1646  */
    {
                    printf("%s", (yyvsp[0].cadeia)); 
                    (yyval.infoexpr).tipo = LOGICAL;
                    (yyval.infoexpr).opnd.tipo = LOGICOPND;
                    (yyval.infoexpr).opnd.atr.vallogic = 1;
                    }
#line 3203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1262 "Lab6.y" /* yacc.c:1646  */
    {
                    printf("%s", (yyvsp[0].cadeia)); 
                    (yyval.infoexpr).tipo = LOGICAL;
                    (yyval.infoexpr).opnd.tipo = LOGICOPND;
                    (yyval.infoexpr).opnd.atr.vallogic = 0;
                    }
#line 3214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1268 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 3220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1269 "Lab6.y" /* yacc.c:1646  */
    {
                    if((yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo != FLOAT && (yyvsp[0].infoexpr).tipo != CHAR)
                    {
                        TipoIncompativel();
                    }
                    (yyval.infoexpr).tipo = (yyvsp[0].infoexpr).tipo;
                    (yyval.infoexpr).opnd.tipo = VAROPND;
                    (yyval.infoexpr).opnd.atr.simb = NovaTemp((yyval.infoexpr).tipo);
                    GeraQuadrupla(OPNEG, (yyvsp[0].infoexpr).opnd, opndidle, (yyval.infoexpr).opnd);
                }
#line 3235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1279 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 3241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1281 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac)); (yyval.infoexpr).tipo = (yyvsp[-1].infoexpr).tipo; (yyval.infoexpr).opnd = (yyvsp[-1].infoexpr).opnd;}
#line 3247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1282 "Lab6.y" /* yacc.c:1646  */
    {(yyval.infoexpr) = (yyvsp[0].infoexpr);}
#line 3253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1285 "Lab6.y" /* yacc.c:1646  */
    {printf("%s", (yyvsp[0].cadeia));
                    simbolo simb = ProcuraSimb((yyvsp[0].cadeia), escopoAtual);
                    Empilha(subsc);
                    subsc = 0;
	                if (simb == NULL)
                    {
                        NaoDeclarado ((yyvsp[0].cadeia));
                    }   
	                else if (simb->tid != IDVAR)   
                    {
                        TipoInadequado((yyvsp[0].cadeia));
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
#line 3280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1307 "Lab6.y" /* yacc.c:1646  */
    {
                    simbolo simb = ProcuraSimb((yyvsp[-2].cadeia), escopoAtual);
                    if(simb != NULL)
                    {
                        (yyval.infovar).simb = simb;
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
                        (yyval.infovar).opnd.tipo = VAROPND;
                        if(simb->ndims ==0)
                        {
                            (yyval.infovar).opnd.atr.simb = (yyval.infovar).simb;
                        }
                        else
                        {
                            int tipoPVar;
                            switch((yyval.infovar).simb->tvar)
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
                                    tipoPVar = (yyval.infovar).simb->tvar;
                                    break;                                    
                            }
                            simbolo novaTmp = NovaTemp(tipoPVar);
                            opnd1.tipo = VAROPND;
                            opnd1.atr.simb = simb;
                            opnd2.tipo = INTOPND;
                            opnd2.atr.valint = simb->ndims;
                            (yyval.infovar).opnd.atr.simb = novaTmp;
                            GeraQuadrupla(OPINDEX, opnd1, opnd2, (yyval.infovar).opnd);
                        }
                    }
                    else
                    {
                        (yyval.infovar).simb = NULL;
                    }               

                    subsc = Desempilha();                    
                }
#line 3344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1369 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 3350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1371 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 3356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1374 "Lab6.y" /* yacc.c:1646  */
    {
                    subsc++;
                    if((yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo != CHAR)
                    {
                        TipoIncompativel();
                    }
                    GeraQuadrupla(OPIND, (yyvsp[0].infoexpr).opnd, opndidle, opndidle);
                }
#line 3369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1383 "Lab6.y" /* yacc.c:1646  */
    {printf("%c ", (yyvsp[0].carac));}
#line 3375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1384 "Lab6.y" /* yacc.c:1646  */
    {
                    subsc++;
                    if((yyvsp[0].infoexpr).tipo != INTEGER && (yyvsp[0].infoexpr).tipo != CHAR)
                    {
                        TipoIncompativel();
                    }
                    GeraQuadrupla(OPIND, (yyvsp[0].infoexpr).opnd, opndidle, opndidle);
                }
#line 3388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1394 "Lab6.y" /* yacc.c:1646  */
    {printf("%s ", (yyvsp[0].cadeia));
                    simbolo idfu = ProcuraSimb((yyvsp[0].cadeia), escopoAtual);
                    if(idfu == NULL)
                    {
                        NaoDeclarado((yyvsp[0].cadeia));
                    }
                    else if(idfu->tid != IDFUNC)
                    {
                        TipoInadequado((yyvsp[0].cadeia));
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
#line 3415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1416 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));}
#line 3421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1418 "Lab6.y" /* yacc.c:1646  */
    {printf("%c", (yyvsp[0].carac));
                    simbolo idfu = ProcuraSimb((yyvsp[-5].cadeia), escopoAtual);
                    if(idfu == NULL)
                    {
                        (yyval.infoexpr).tipo = NOTVAR;
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
                        (yyval.infoexpr).tipo = idfu->tvar;
                        simbolo novaTmp = NovaTemp((yyval.infoexpr).tipo);
                        (yyval.infoexpr).opnd.tipo = VAROPND;
                        (yyval.infoexpr).opnd.atr.simb = novaTmp;
                        opnd1.tipo = FUNCPND;
                        opnd1.atr.simb = idfu;
                        if(countParams > 0)
                        {
                            opnd2.tipo = INTOPND;
                            opnd2.atr.valint = countParams;
                            GeraQuadrupla(CALLOP, opnd1, opnd2, (yyval.infoexpr).opnd);
                        }
                        else
                        {
                            GeraQuadrupla(CALLOP, opnd1, opndidle, (yyval.infoexpr).opnd);
                        }
                    }
                    
                    moduloChamado = NULL;
                    paramAtual = NULL;
                    countParams = 0;
                }
#line 3465 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3469 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1459 "Lab6.y" /* yacc.c:1906  */

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
    s->valint = NULL;
    s->valfloat = NULL;
    s->vallogic = NULL;
    s->valchar = NULL;
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
    finput = fopen("entrada.txt", "r");
    printf("\n\nINTERPRETADOR:\n");
    codintermedaux = codintermed->prox;
    InicPilhaOpnd(&pilhaopnd);
    InicPilhaContexto(&pilhacontext);
    InterpCodIntermedSubProgramas();
}

void InterpCodIntermedSubProgramas()
{
    tab=0;
    quadrupla quad, quadprox;
    char encerra;
    char condicao;
    contexto ctx;
    simbolo moduloChamado = NULL;
    encerra = FALSE;
    quad = codintermedaux->listquad->prox;
    
    while(!encerra)
    {
        //Indentar();
        //printf("%4d)%s", quad->num, nomeoperquad[quad->oper]);
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

            case OPIND:
                EmpilharOpnd(quad->opnd1, &pilhaopnd);
                break;
            
            case OPJUMP:
                quadprox = quad->result.atr.rotulo;  
                break;
            
            case OPINDEX:
                ExecQuadINDEX(quad);
                break;

            case OPJF:
		        if (quad->opnd1.tipo == LOGICOPND)
			        condicao = quad->opnd1.atr.vallogic;
		        if (quad->opnd1.tipo == VAROPND)
			        condicao = *(quad->opnd1.atr.simb->vallogic);
		        if (! condicao)
			        quadprox = quad->result.atr.rotulo;
		        
                break;
            
            case OPJT:
		        if (quad->opnd1.tipo == LOGICOPND)
			        condicao = quad->opnd1.atr.vallogic;
		        if (quad->opnd1.tipo == VAROPND)
			        condicao = *(quad->opnd1.atr.simb->vallogic);
		        if (condicao)
			        quadprox = quad->result.atr.rotulo;
		        
                break;
            
            case CALLOP:
                tab++;
                ctx = (contexto){codintermedaux, quad, moduloChamado};    
                EmpilharContexto(ctx,&pilhacontext);
                ExecQuadCallop(quad);
                moduloChamado = quad->opnd1.atr.simb;
                quadprox = codintermedaux->listquad->prox;
                break;
            
            case OPRETURN:
                tab--;
                ctx = TopoContexto(pilhacontext);
                if(quad->opnd1.tipo != IDLEOPND)
                {
                    int tipo, valint;
                    char valchar, vallogic;
                    float valfloat;
                    switch(quad->opnd1.tipo)
                    {
                        case INTOPND:
                            tipo = INTOPND;
                            valint = quad->opnd1.atr.valint;
                            break;
                        case CHAROPND:
                            tipo = CHAROPND;
                            valchar = quad->opnd1.atr.valchar;
                            break;
                        case REALOPND:
                            tipo = REALOPND;
                            valfloat = quad->opnd1.atr.valfloat;
                            break;
                        case LOGICOPND:
                            tipo = LOGICOPND;
                            vallogic = quad->opnd1.atr.vallogic;
                            break;
                        case VAROPND:
                            switch(quad->opnd1.atr.simb->tvar)
                            {
                                case INTEGER:
                                    tipo = INTOPND;
                                    valint = *(quad->opnd1.atr.simb->valint);
                                    break;
                                case CHAR:
                                    tipo = CHAROPND;
                                    valchar = *(quad->opnd1.atr.simb->valchar);
                                    break;
                                case FLOAT:
                                    tipo = REALOPND;
                                    valfloat = *(quad->opnd1.atr.simb->valfloat);
                                    break;
                                case LOGICAL:
                                    tipo = LOGICOPND;
                                    vallogic = *(quad->opnd1.atr.simb->vallogic);
                                    break;
                            }
                    }
                    switch(ctx.quadruplaAtual->result.atr.simb->tvar)
                    {
                        case INTEGER:
                            if(tipo == INTOPND)
                                *(ctx.quadruplaAtual->result.atr.simb->valint) = valint;
                            else if(tipo == CHAROPND)
                                *(ctx.quadruplaAtual->result.atr.simb->valint) = valchar;
                            break;
                        case CHAR:
                            if(tipo == INTOPND)
                                *(ctx.quadruplaAtual->result.atr.simb->valchar) = valint;
                            else if(tipo == CHAROPND)
                                *(ctx.quadruplaAtual->result.atr.simb->valchar) = valchar;
                            break;
                        case LOGICAL:
                            *(ctx.quadruplaAtual->result.atr.simb->valchar) = vallogic;
                            break;
                        case FLOAT:
                            if(tipo == INTOPND)
                                *(ctx.quadruplaAtual->result.atr.simb->valfloat) = valint;
                            else if(tipo == REALOPND)
                                *(ctx.quadruplaAtual->result.atr.simb->valfloat) = valfloat;
                            else if(tipo == CHAROPND)
                                *(ctx.quadruplaAtual->result.atr.simb->valfloat) = valchar;
                            break;
                    }
                }
                DesalocaVariaveis(moduloChamado);
                codintermedaux = ctx.moduloAtual;
                quadprox = ctx.quadruplaAtual->prox;
                moduloChamado = ctx.chamado;
                DesempilharContexto(&pilhacontext);
                break;

            case OPMAIS:
                ExecQuadMais(quad);
                break;
            
            case OPMENOS:
                ExecQuadMenos(quad);
                break;
            
            case NOP:
                break;

            case OPMODULO:
                ExecQuadModulo(quad);
                break;

            case OPDIV:
                ExecQuadDiv(quad);
                break;
            
            case OPVEZES:
                ExecQuadVezes(quad);
                break;

            case OPATRIB:
                ExecQuadAtrib(quad);
                break;
            
            case OPNEG:
                ExecQuadNEG(quad);
                break;
            
            case OPNOT:
                ExecQuadNOT(quad);
                break;
            
            case OPAND:
                ExecQuadAND(quad);
                break;
            
            case OPGT:
                ExecQuadGT(quad);
                break;

            case OPGE:
                ExecQuadGE(quad);
                break;
            
            case OPLT:
                ExecQuadLT(quad);
                break;
            
            case OPLE:
                ExecQuadLE(quad);
                break;

            case OPIGUAL:
                ExecQuadIgual(quad);
                break;

            case OPDIF:
                ExecQuadDif(quad);
                break;
            
            case OPOR:
                ExecQuadOR(quad);
                break;

            case OPWRITE:
                ExecQuadWrite(quad);
                break;

            case OPLER:
                ExecQuadRead(quad);
                break;

            case ATRIBPONT:
                ExecQuadAtribpont(quad);
                break;
            
            case CONTPONT:
                ExecQuadContpont(quad);
                break;

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
    //Indentar();
    //printf("\tAlocando as variaveis:");
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
                            if(s->valint == NULL)
                                s->valint = malloc(nelemaloc*sizeof(int));
                            break;
                        case FLOAT:
                            if(s->valfloat == NULL)
                                s->valfloat = malloc(nelemaloc*sizeof(float));
                            break;
                        case CHAR:
                            if(s->valchar == NULL)
                                s->valchar = malloc(nelemaloc*sizeof(char));
                            break;
                        case LOGICAL:
                            if(s->vallogic == NULL)
                                s->vallogic = malloc(nelemaloc * sizeof(char));
                            break;
                    }
                    //Indentar();
                    //printf("\t\t\t%s: %d elemento(s) alocado(s)", s->cadeia, nelemaloc);
                }
            }
        }
    }
}

void ExecQuadDif (quadrupla quad) {
	int tipo1, tipo2, valint1, valint2;
	float valfloat1, valfloat2;
    switch (quad->opnd1.tipo) {
		case LOGICOPND:
            tipo1 = INTOPND; valint1 = quad->opnd1.atr.vallogic;break;
        case INTOPND:
			tipo1 = INTOPND;  valint1 = quad->opnd1.atr.valint;  break;
		case REALOPND:
			tipo1 = REALOPND; valfloat1=quad->opnd1.atr.valfloat;break;
		case CHAROPND:
			tipo1 = INTOPND; valint1 = quad->opnd1.atr.valchar; break;
		case VAROPND:
			switch (quad->opnd1.atr.simb->tvar) {
				case INTEGER:  tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valint);
					break;
				case FLOAT:  tipo1 = REALOPND;
					valfloat1 = *(quad->opnd1.atr.simb->valfloat);
					break;
				case CHAR:  tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valchar);
					break;
                case LOGICAL: tipo1 = INTOPND;
                    valint1 = *(quad->opnd1.atr.simb->vallogic);
			}
			break;
	}
    switch (quad->opnd2.tipo) {
        case LOGICOPND:
            tipo2 = INTOPND; valint2 = quad->opnd2.atr.vallogic;break;
		case INTOPND:
			tipo2 = INTOPND;  valint2 = quad->opnd2.atr.valint;  break;
		case REALOPND:
			tipo2=REALOPND;valfloat2 = quad->opnd2.atr.valfloat;break;
		case CHAROPND:
			tipo2 = INTOPND;valint2 = quad->opnd2.atr.valchar; break;
		case VAROPND:
			switch (quad->opnd2.atr.simb->tvar) {
				case INTEGER:  tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valint);
					break;
				case FLOAT:  tipo2 = REALOPND;
					valfloat2 = *(quad->opnd2.atr.simb->valfloat);
					break;
				case CHAR:  tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valchar);
					break;
                case LOGICAL: tipo2 = INTOPND;
                    valint2 = *(quad->opnd2.atr.simb->vallogic);
				}
			break;
	}
    if (tipo1 == INTOPND && tipo2 == INTOPND)
		*(quad->result.atr.simb->vallogic) = valint1 != valint2;
	if (tipo1 == INTOPND && tipo2 == REALOPND)
		*(quad->result.atr.simb->vallogic) = valint1 != valfloat2;
	if (tipo1 == REALOPND && tipo2 == INTOPND)
		*(quad->result.atr.simb->vallogic) = valfloat1 != valint2;
	if (tipo1 == REALOPND && tipo2 == REALOPND)
		*(quad->result.atr.simb->vallogic) = valfloat1 != valfloat2;
}

void ExecQuadNEG (quadrupla quad) {

    switch (quad->opnd1.tipo) {
		case INTOPND:
            *(quad->result.atr.simb->valint) = -quad->opnd1.atr.valint;
            break;
        case CHAROPND:
            *(quad->result.atr.simb->valchar) = -quad->opnd1.atr.valchar;
            break;
        case REALOPND:
            *(quad->result.atr.simb->valfloat) = -quad->opnd1.atr.valfloat;
            break;
        case VAROPND:
            switch (quad->opnd1.atr.simb->tvar)
            {
                case INTEGER:
                    *(quad->result.atr.simb->valint) = -(*(quad->opnd1.atr.simb->valint));
                    break;
                case CHAR:
                    *(quad->result.atr.simb->valchar) = -(*(quad->opnd1.atr.simb->valchar));
                    break;
                case FLOAT:
                    *(quad->result.atr.simb->valfloat) = -(*(quad->opnd1.atr.simb->valfloat));
                    break;
            }            
	}
	
}


void ExecQuadNOT (quadrupla quad) {
	char tipo1, valint1;
    tipo1 = -1;
	
    switch (quad->opnd1.tipo) {
		case LOGICOPND:
            tipo1 = CHAROPND; valint1 = quad->opnd1.atr.vallogic;break;
		case VAROPND:
			switch (quad->opnd1.atr.simb->tvar) {
                case LOGICAL: tipo1 = CHAROPND;
                    valint1 = *(quad->opnd1.atr.simb->vallogic);
                    break;
			}
			break;
	}
    if (tipo1 == CHAROPND)
		*(quad->result.atr.simb->vallogic) = !(valint1);
	
}


void ExecQuadAND (quadrupla quad) {
	char tipo1, tipo2, valint1, valint2;
    tipo1 = -1;
    tipo2 = -2;
	
    switch (quad->opnd1.tipo) {
		case LOGICOPND:
            tipo1 = CHAROPND; valint1 = quad->opnd1.atr.vallogic;break;
		case VAROPND:
			switch (quad->opnd1.atr.simb->tvar) {
                case LOGICAL: tipo1 = CHAROPND;
                    valint1 = *(quad->opnd1.atr.simb->vallogic);
                    break;
			}
			break;
	}
    switch (quad->opnd2.tipo) {
        case LOGICOPND:
            tipo2 = CHAROPND; valint2 = quad->opnd2.atr.vallogic;break;
		case VAROPND:
			switch (quad->opnd2.atr.simb->tvar) {
                case LOGICAL: tipo2 = CHAROPND;
                    valint2 = *(quad->opnd2.atr.simb->vallogic);
                    break;
				}
			break;
	}
    if (tipo1 == CHAROPND && tipo2 == CHAROPND)
		*(quad->result.atr.simb->vallogic) = (valint1 && valint2);
	
}



void ExecQuadOR (quadrupla quad) {
	char tipo1, tipo2, valint1, valint2;
	
    switch (quad->opnd1.tipo) {
		case LOGICOPND:
            tipo1 = CHAROPND; valint1 = quad->opnd1.atr.vallogic;break;
		case VAROPND:
			switch (quad->opnd1.atr.simb->tvar) {
                case LOGICAL: tipo1 = CHAROPND;
                    valint1 = *(quad->opnd1.atr.simb->vallogic);
                    break;
			}
			break;
	}
    switch (quad->opnd2.tipo) {
        case LOGICOPND:
            tipo2 = CHAROPND; valint2 = quad->opnd2.atr.vallogic;break;
		case VAROPND:
			switch (quad->opnd2.atr.simb->tvar) {
                case LOGICAL: tipo2 = CHAROPND;
                    valint2 = *(quad->opnd2.atr.simb->vallogic);
                    break;
				}
			break;
	}
    if (tipo1 == CHAROPND && tipo2 == CHAROPND)
		*(quad->result.atr.simb->vallogic) = (valint1 || valint2);
	
}


void ExecQuadIgual (quadrupla quad) {
	int tipo1, tipo2, valint1, valint2;
	float valfloat1, valfloat2;
    switch (quad->opnd1.tipo) {
		case LOGICOPND:
            tipo1 = INTOPND; valint1 = quad->opnd1.atr.vallogic;break;
        case INTOPND:
			tipo1 = INTOPND;  valint1 = quad->opnd1.atr.valint;  break;
		case REALOPND:
			tipo1 = REALOPND; valfloat1=quad->opnd1.atr.valfloat;break;
		case CHAROPND:
			tipo1 = INTOPND; valint1 = quad->opnd1.atr.valchar; break;
		case VAROPND:
			switch (quad->opnd1.atr.simb->tvar) {
				case INTEGER:  tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valint);
					break;
				case FLOAT:  tipo1 = REALOPND;
					valfloat1 = *(quad->opnd1.atr.simb->valfloat);
					break;
				case CHAR:  tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valchar);
					break;
                case LOGICAL: tipo1 = INTOPND;
                    valint1 = *(quad->opnd1.atr.simb->vallogic);
                    break;
			}
			break;
	}
    switch (quad->opnd2.tipo) {
        case LOGICOPND:
            tipo2 = INTOPND; valint2 = quad->opnd2.atr.vallogic;break;
		case INTOPND:
			tipo2 = INTOPND;  valint2 = quad->opnd2.atr.valint;  break;
		case REALOPND:
			tipo2=REALOPND;valfloat2 = quad->opnd2.atr.valfloat;break;
		case CHAROPND:
			tipo2 = INTOPND;valint2 = quad->opnd2.atr.valchar; break;
		case VAROPND:
			switch (quad->opnd2.atr.simb->tvar) {
				case INTEGER:  tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valint);
					break;
				case FLOAT:  tipo2 = REALOPND;
					valfloat2 = *(quad->opnd2.atr.simb->valfloat);
					break;
				case CHAR:  tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valchar);
					break;
                case LOGICAL: tipo2 = INTOPND;
                    valint2 = *(quad->opnd2.atr.simb->vallogic);
                    break;
				}
			break;
	}
    if (tipo1 == INTOPND && tipo2 == INTOPND)
		*(quad->result.atr.simb->vallogic) = valint1 == valint2;
	if (tipo1 == INTOPND && tipo2 == REALOPND)
		*(quad->result.atr.simb->vallogic) = valint1 == valfloat2;
	if (tipo1 == REALOPND && tipo2 == INTOPND)
		*(quad->result.atr.simb->vallogic) = valfloat1 == valint2;
	if (tipo1 == REALOPND && tipo2 == REALOPND)
		*(quad->result.atr.simb->vallogic) = valfloat1 == valfloat2;
}


void ExecQuadGE (quadrupla quad) {
	int tipo1, tipo2, valint1, valint2;
	float valfloat1, valfloat2;
    switch (quad->opnd1.tipo) {
		case INTOPND:
			tipo1 = INTOPND;  valint1 = quad->opnd1.atr.valint;  break;
		case REALOPND:
			tipo1 = REALOPND; valfloat1=quad->opnd1.atr.valfloat;break;
		case CHAROPND:
			tipo1 = INTOPND; valint1 = quad->opnd1.atr.valchar; break;
		case VAROPND:
			switch (quad->opnd1.atr.simb->tvar) {
				case INTEGER:  tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valint);
					break;
				case FLOAT:  tipo1 = REALOPND;
					valfloat1 = *(quad->opnd1.atr.simb->valfloat);
					break;
				case CHAR:  tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valchar);
					break;
			}
			break;
	}
    switch (quad->opnd2.tipo) {
		case INTOPND:
			tipo2 = INTOPND;  valint2 = quad->opnd2.atr.valint;  break;
		case REALOPND:
			tipo2=REALOPND;valfloat2 = quad->opnd2.atr.valfloat;break;
		case CHAROPND:
			tipo2 = INTOPND;valint2 = quad->opnd2.atr.valchar; break;
		case VAROPND:
			switch (quad->opnd2.atr.simb->tvar) {
				case INTEGER:  tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valint);
					break;
				case FLOAT:  tipo2 = REALOPND;
					valfloat2 = *(quad->opnd2.atr.simb->valfloat);
					break;
				case CHAR:  tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valchar);
					break;
				}
			break;
	}
    if (tipo1 == INTOPND && tipo2 == INTOPND)
		*(quad->result.atr.simb->vallogic) = valint1 >= valint2;
	if (tipo1 == INTOPND && tipo2 == REALOPND)
		*(quad->result.atr.simb->vallogic) = valint1 >= valfloat2;
	if (tipo1 == REALOPND && tipo2 == INTOPND)
		*(quad->result.atr.simb->vallogic) = valfloat1 >= valint2;
	if (tipo1 == REALOPND && tipo2 == REALOPND)
		*(quad->result.atr.simb->vallogic) = valfloat1 >= valfloat2;
}



void ExecQuadGT (quadrupla quad) {
	int tipo1, tipo2, valint1, valint2;
	float valfloat1, valfloat2;
    switch (quad->opnd1.tipo) {
		case INTOPND:
			tipo1 = INTOPND;  valint1 = quad->opnd1.atr.valint;  break;
		case REALOPND:
			tipo1 = REALOPND; valfloat1=quad->opnd1.atr.valfloat;break;
		case CHAROPND:
			tipo1 = INTOPND; valint1 = quad->opnd1.atr.valchar; break;
		case VAROPND:
			switch (quad->opnd1.atr.simb->tvar) {
				case INTEGER:  tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valint);
					break;
				case FLOAT:  tipo1 = REALOPND;
					valfloat1 = *(quad->opnd1.atr.simb->valfloat);
					break;
				case CHAR:  tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valchar);
					break;
			}
			break;
	}
    switch (quad->opnd2.tipo) {
		case INTOPND:
			tipo2 = INTOPND;  valint2 = quad->opnd2.atr.valint;  break;
		case REALOPND:
			tipo2=REALOPND;valfloat2 = quad->opnd2.atr.valfloat;break;
		case CHAROPND:
			tipo2 = INTOPND;valint2 = quad->opnd2.atr.valchar; break;
		case VAROPND:
			switch (quad->opnd2.atr.simb->tvar) {
				case INTEGER:  tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valint);
					break;
				case FLOAT:  tipo2 = REALOPND;
					valfloat2 = *(quad->opnd2.atr.simb->valfloat);
					break;
				case CHAR:  tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valchar);
					break;
				}
			break;
	}
    if (tipo1 == INTOPND && tipo2 == INTOPND)
		*(quad->result.atr.simb->vallogic) = valint1 > valint2;
	if (tipo1 == INTOPND && tipo2 == REALOPND)
		*(quad->result.atr.simb->vallogic) = valint1 > valfloat2;
	if (tipo1 == REALOPND && tipo2 == INTOPND)
		*(quad->result.atr.simb->vallogic) = valfloat1 > valint2;
	if (tipo1 == REALOPND && tipo2 == REALOPND)
		*(quad->result.atr.simb->vallogic) = valfloat1 > valfloat2;
}

void ExecQuadLE (quadrupla quad) {
	int tipo1, tipo2, valint1, valint2;
	float valfloat1, valfloat2;
    switch (quad->opnd1.tipo) {
		case INTOPND:
			tipo1 = INTOPND;  valint1 = quad->opnd1.atr.valint;  break;
		case REALOPND:
			tipo1 = REALOPND; valfloat1=quad->opnd1.atr.valfloat;break;
		case CHAROPND:
			tipo1 = INTOPND; valint1 = quad->opnd1.atr.valchar; break;
		case VAROPND:
			switch (quad->opnd1.atr.simb->tvar) {
				case INTEGER:  tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valint);
					break;
				case FLOAT:  tipo1 = REALOPND;
					valfloat1 = *(quad->opnd1.atr.simb->valfloat);
					break;
				case CHAR:  tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valchar);
					break;
			}
			break;
	}
    switch (quad->opnd2.tipo) {
		case INTOPND:
			tipo2 = INTOPND;  valint2 = quad->opnd2.atr.valint;  break;
		case REALOPND:
			tipo2=REALOPND;valfloat2 = quad->opnd2.atr.valfloat;break;
		case CHAROPND:
			tipo2 = INTOPND;valint2 = quad->opnd2.atr.valchar; break;
		case VAROPND:
			switch (quad->opnd2.atr.simb->tvar) {
				case INTEGER:  tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valint);
					break;
				case FLOAT:  tipo2 = REALOPND;
					valfloat2 = *(quad->opnd2.atr.simb->valfloat);
					break;
				case CHAR:  tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valchar);
					break;
				}
			break;
	}
    if (tipo1 == INTOPND && tipo2 == INTOPND)
		*(quad->result.atr.simb->vallogic) = valint1 <= valint2;
	if (tipo1 == INTOPND && tipo2 == REALOPND)
		*(quad->result.atr.simb->vallogic) = valint1 <= valfloat2;
	if (tipo1 == REALOPND && tipo2 == INTOPND)
		*(quad->result.atr.simb->vallogic) = valfloat1 <= valint2;
	if (tipo1 == REALOPND && tipo2 == REALOPND)
		*(quad->result.atr.simb->vallogic) = valfloat1 <= valfloat2;
}

void ExecQuadLT (quadrupla quad) {
	int tipo1, tipo2, valint1, valint2;
	float valfloat1, valfloat2;
    switch (quad->opnd1.tipo) {
		case INTOPND:
			tipo1 = INTOPND;  valint1 = quad->opnd1.atr.valint;  break;
		case REALOPND:
			tipo1 = REALOPND; valfloat1=quad->opnd1.atr.valfloat;break;
		case CHAROPND:
			tipo1 = INTOPND; valint1 = quad->opnd1.atr.valchar; break;
		case VAROPND:
			switch (quad->opnd1.atr.simb->tvar) {
				case INTEGER:  tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valint);
					break;
				case FLOAT:  tipo1 = REALOPND;
					valfloat1 = *(quad->opnd1.atr.simb->valfloat);
					break;
				case CHAR:  tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valchar);
					break;
			}
			break;
	}
    switch (quad->opnd2.tipo) {
		case INTOPND:
			tipo2 = INTOPND;  valint2 = quad->opnd2.atr.valint;  break;
		case REALOPND:
			tipo2=REALOPND;valfloat2 = quad->opnd2.atr.valfloat;break;
		case CHAROPND:
			tipo2 = INTOPND;valint2 = quad->opnd2.atr.valchar; break;
		case VAROPND:
			switch (quad->opnd2.atr.simb->tvar) {
				case INTEGER:  tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valint);
					break;
				case FLOAT:  tipo2 = REALOPND;
					valfloat2 = *(quad->opnd2.atr.simb->valfloat);
					break;
				case CHAR:  tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valchar);
					break;
				}
			break;
	}
    if (tipo1 == INTOPND && tipo2 == INTOPND)
		*(quad->result.atr.simb->vallogic) = valint1 < valint2;
	if (tipo1 == INTOPND && tipo2 == REALOPND)
		*(quad->result.atr.simb->vallogic) = valint1 < valfloat2;
	if (tipo1 == REALOPND && tipo2 == INTOPND)
		*(quad->result.atr.simb->vallogic) = valfloat1 < valint2;
	if (tipo1 == REALOPND && tipo2 == REALOPND)
		*(quad->result.atr.simb->vallogic) = valfloat1 < valfloat2;
}


void ExecQuadAtrib(quadrupla quad){
    int tipo1, valint1;
	float valfloat1;
	char valchar1, vallogic1;

    switch (quad->opnd1.tipo) {
		case INTOPND:
			tipo1 = INTOPND;
			valint1 = quad->opnd1.atr.valint; break;
		case REALOPND:
			tipo1 = REALOPND;
			valfloat1 = quad->opnd1.atr.valfloat; break;
		case CHAROPND:
			tipo1 = CHAROPND;
			valchar1 = quad->opnd1.atr.valchar; break;
		case LOGICOPND:
			tipo1 = LOGICOPND;
			vallogic1 = quad->opnd1.atr.vallogic; break;
    
        case VAROPND:
			switch (quad->opnd1.atr.simb->tvar) {
				case INTEGER:
					tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valint); break;
				case FLOAT:
					tipo1 = REALOPND;
					valfloat1=*(quad->opnd1.atr.simb->valfloat);break;
				case CHAR:
					tipo1 = CHAROPND;
					valchar1=*(quad->opnd1.atr.simb->valchar);break;
				case LOGICAL:
					tipo1 = LOGICOPND;
					vallogic1 = *(quad->opnd1.atr.simb->vallogic);
					break;
			}
			break;
	}
    
    switch (quad->result.atr.simb->tvar) {
		case INTEGER:
			if (tipo1 == INTOPND)  *(quad->result.atr.simb->valint) = valint1;
			if (tipo1 == CHAROPND)*(quad->result.atr.simb->valint)=valchar1;
			break;
		case CHAR:
			if (tipo1 == INTOPND) *(quad->result.atr.simb->valchar) = valint1;
			if (tipo1==CHAROPND)*(quad->result.atr.simb->valchar)=valchar1;
			break;
		case LOGICAL:  *(quad->result.atr.simb->vallogic) = vallogic1; break;
		case FLOAT:
			if (tipo1 == INTOPND)
				*(quad->result.atr.simb->valfloat) = valint1;
			if (tipo1 == REALOPND)
				*(quad->result.atr.simb->valfloat) = valfloat1;
			if (tipo1 == CHAROPND)
				*(quad->result.atr.simb->valfloat) = valchar1;
			break;
	}
}

void ExecQuadVezes (quadrupla quad) {
	int tipo1, tipo2, valint1, valint2;
	float valfloat1, valfloat2;

    switch (quad->opnd1.tipo) {
		case INTOPND:
			tipo1 = INTOPND;  valint1 = quad->opnd1.atr.valint;  break;
		case REALOPND:
			tipo1 = REALOPND;  valfloat1 = quad->opnd1.atr.valfloat; break;
		case CHAROPND:
			tipo1 = INTOPND;  valint1 = quad->opnd1.atr.valchar;  break;
		case VAROPND:
			switch (quad->opnd1.atr.simb->tvar) {
				case INTEGER:
					tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valint);  break;
				case FLOAT:
					tipo1 = REALOPND;
					valfloat1=*(quad->opnd1.atr.simb->valfloat);break;
				case CHAR:
					tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valchar); break;
			}
			break;
	}
    switch (quad->opnd2.tipo) {
		case INTOPND:
			tipo2 = INTOPND;  valint2 = quad->opnd2.atr.valint;  break;
		case REALOPND:
			tipo2 = REALOPND;  valfloat2 = quad->opnd2.atr.valfloat;  break;
		case CHAROPND:
			tipo2 = INTOPND;  valint2 = quad->opnd2.atr.valchar;  break;
		case VAROPND:
			switch (quad->opnd2.atr.simb->tvar) {
				case INTEGER:
					tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valint);  break;
				case FLOAT:
					tipo2 = REALOPND;
					valfloat2=*(quad->opnd2.atr.simb->valfloat);break;
				case CHAR:
					tipo2 = INTOPND;
					valint2=*(quad->opnd2.atr.simb->valchar);break;
			}
			break;
	}
    switch (quad->result.atr.simb->tvar){
		case INTEGER:
			*(quad->result.atr.simb->valint) = valint1 * valint2;
			break;
		case FLOAT:
			if (tipo1 == INTOPND && tipo2 == INTOPND)
				*(quad->result.atr.simb->valfloat) = valint1 * valint2;
			if (tipo1 == INTOPND && tipo2 == REALOPND)
				*(quad->result.atr.simb->valfloat) = valint1 * valfloat2;
			if (tipo1 == REALOPND && tipo2 == INTOPND)
				*(quad->result.atr.simb->valfloat) = valfloat1 * valint2;
			if (tipo1 == REALOPND && tipo2 == REALOPND)
				*(quad->result.atr.simb->valfloat) = valfloat1 * valfloat2;
			break;
	}
}

void ExecQuadModulo (quadrupla quad) {
	int tipo1, tipo2, valint1, valint2;
	float valfloat1, valfloat2;

    switch (quad->opnd1.tipo) {
		case INTOPND:
			tipo1 = INTOPND;  valint1 = quad->opnd1.atr.valint;  break;
		case REALOPND:
			tipo1 = REALOPND;  valfloat1 = quad->opnd1.atr.valfloat; break;
		case CHAROPND:
			tipo1 = INTOPND;  valint1 = quad->opnd1.atr.valchar;  break;
		case VAROPND:
			switch (quad->opnd1.atr.simb->tvar) {
				case INTEGER:
					tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valint);  break;
				case FLOAT:
					tipo1 = REALOPND;
					valfloat1=*(quad->opnd1.atr.simb->valfloat);break;
				case CHAR:
					tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valchar); break;
			}
			break;
	}
    switch (quad->opnd2.tipo) {
		case INTOPND:
			tipo2 = INTOPND;  valint2 = quad->opnd2.atr.valint;  break;
		case CHAROPND:
			tipo2 = INTOPND;  valint2 = quad->opnd2.atr.valchar;  break;
		case VAROPND:
			switch (quad->opnd2.atr.simb->tvar) {
				case INTEGER:
					tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valint);  break;
				case CHAR:
					tipo2 = INTOPND;
					valint2=*(quad->opnd2.atr.simb->valchar);break;
			}
			break;
	}
    switch (quad->result.atr.simb->tvar){
		case INTEGER:
			*(quad->result.atr.simb->valint) = valint1 % valint2;
			break;
	}
}


void ExecQuadDiv (quadrupla quad) {
	int tipo1, tipo2, valint1, valint2;
	float valfloat1, valfloat2;

    switch (quad->opnd1.tipo) {
		case INTOPND:
			tipo1 = INTOPND;  valint1 = quad->opnd1.atr.valint;  break;
		case REALOPND:
			tipo1 = REALOPND;  valfloat1 = quad->opnd1.atr.valfloat; break;
		case CHAROPND:
			tipo1 = INTOPND;  valint1 = quad->opnd1.atr.valchar;  break;
		case VAROPND:
			switch (quad->opnd1.atr.simb->tvar) {
				case INTEGER:
					tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valint);  break;
				case FLOAT:
					tipo1 = REALOPND;
					valfloat1=*(quad->opnd1.atr.simb->valfloat);break;
				case CHAR:
					tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valchar); break;
			}
			break;
	}
    switch (quad->opnd2.tipo) {
		case INTOPND:
			tipo2 = INTOPND;  valint2 = quad->opnd2.atr.valint;  break;
		case REALOPND:
			tipo2 = REALOPND;  valfloat2 = quad->opnd2.atr.valfloat;  break;
		case CHAROPND:
			tipo2 = INTOPND;  valint2 = quad->opnd2.atr.valchar;  break;
		case VAROPND:
			switch (quad->opnd2.atr.simb->tvar) {
				case INTEGER:
					tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valint);  break;
				case FLOAT:
					tipo2 = REALOPND;
					valfloat2=*(quad->opnd2.atr.simb->valfloat);break;
				case CHAR:
					tipo2 = INTOPND;
					valint2=*(quad->opnd2.atr.simb->valchar);break;
			}
			break;
	}
    switch (quad->result.atr.simb->tvar){
		case INTEGER:
			*(quad->result.atr.simb->valint) = valint1 / valint2;
			break;
		case FLOAT:
			if (tipo1 == INTOPND && tipo2 == INTOPND)
				*(quad->result.atr.simb->valfloat) = valint1 / valint2;
			if (tipo1 == INTOPND && tipo2 == REALOPND)
				*(quad->result.atr.simb->valfloat) = valint1 / valfloat2;
			if (tipo1 == REALOPND && tipo2 == INTOPND)
				*(quad->result.atr.simb->valfloat) = valfloat1 / valint2;
			if (tipo1 == REALOPND && tipo2 == REALOPND)
				*(quad->result.atr.simb->valfloat) = valfloat1 / valfloat2;
			break;
	}
}



void ExecQuadMenos (quadrupla quad) {
	int tipo1, tipo2, valint1, valint2;
	float valfloat1, valfloat2;

    switch (quad->opnd1.tipo) {
		case INTOPND:
			tipo1 = INTOPND;  valint1 = quad->opnd1.atr.valint;  break;
		case REALOPND:
			tipo1 = REALOPND;  valfloat1 = quad->opnd1.atr.valfloat; break;
		case CHAROPND:
			tipo1 = INTOPND;  valint1 = quad->opnd1.atr.valchar;  break;
		case VAROPND:
			switch (quad->opnd1.atr.simb->tvar) {
				case INTEGER:
					tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valint);  break;
				case FLOAT:
					tipo1 = REALOPND;
					valfloat1=*(quad->opnd1.atr.simb->valfloat);break;
				case CHAR:
					tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valchar); break;
			}
			break;
	}
    switch (quad->opnd2.tipo) {
		case INTOPND:
			tipo2 = INTOPND;  valint2 = quad->opnd2.atr.valint;  break;
		case REALOPND:
			tipo2 = REALOPND;  valfloat2 = quad->opnd2.atr.valfloat;  break;
		case CHAROPND:
			tipo2 = INTOPND;  valint2 = quad->opnd2.atr.valchar;  break;
		case VAROPND:
			switch (quad->opnd2.atr.simb->tvar) {
				case INTEGER:
					tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valint);  break;
				case FLOAT:
					tipo2 = REALOPND;
					valfloat2=*(quad->opnd2.atr.simb->valfloat);break;
				case CHAR:
					tipo2 = INTOPND;
					valint2=*(quad->opnd2.atr.simb->valchar);break;
			}
			break;
	}
    switch (quad->result.atr.simb->tvar){
		case INTEGER:
			*(quad->result.atr.simb->valint) = valint1 - valint2;
			break;
		case FLOAT:
			if (tipo1 == INTOPND && tipo2 == INTOPND)
				*(quad->result.atr.simb->valfloat) = valint1 - valint2;
			if (tipo1 == INTOPND && tipo2 == REALOPND)
				*(quad->result.atr.simb->valfloat) = valint1 - valfloat2;
			if (tipo1 == REALOPND && tipo2 == INTOPND)
				*(quad->result.atr.simb->valfloat) = valfloat1 - valint2;
			if (tipo1 == REALOPND && tipo2 == REALOPND)
				*(quad->result.atr.simb->valfloat) = valfloat1 - valfloat2;
			break;
	}
}


void ExecQuadMais (quadrupla quad) {
	int tipo1, tipo2, valint1, valint2;
	float valfloat1, valfloat2;

    switch (quad->opnd1.tipo) {
		case INTOPND:
			tipo1 = INTOPND;  valint1 = quad->opnd1.atr.valint;  break;
		case REALOPND:
			tipo1 = REALOPND;  valfloat1 = quad->opnd1.atr.valfloat; break;
		case CHAROPND:
			tipo1 = INTOPND;  valint1 = quad->opnd1.atr.valchar;  break;
		case VAROPND:
			switch (quad->opnd1.atr.simb->tvar) {
				case INTEGER:
					tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valint);  break;
				case FLOAT:
					tipo1 = REALOPND;
					valfloat1=*(quad->opnd1.atr.simb->valfloat);break;
				case CHAR:
					tipo1 = INTOPND;
					valint1 = *(quad->opnd1.atr.simb->valchar); break;
			}
			break;
	}
    switch (quad->opnd2.tipo) {
		case INTOPND:
			tipo2 = INTOPND;  valint2 = quad->opnd2.atr.valint;  break;
		case REALOPND:
			tipo2 = REALOPND;  valfloat2 = quad->opnd2.atr.valfloat;  break;
		case CHAROPND:
			tipo2 = INTOPND;  valint2 = quad->opnd2.atr.valchar;  break;
		case VAROPND:
			switch (quad->opnd2.atr.simb->tvar) {
				case INTEGER:
					tipo2 = INTOPND;
					valint2 = *(quad->opnd2.atr.simb->valint);  break;
				case FLOAT:
					tipo2 = REALOPND;
					valfloat2=*(quad->opnd2.atr.simb->valfloat);break;
				case CHAR:
					tipo2 = INTOPND;
					valint2=*(quad->opnd2.atr.simb->valchar);break;
			}
			break;
	}
    switch (quad->result.atr.simb->tvar){
		case INTEGER:
			*(quad->result.atr.simb->valint) = valint1 + valint2;
			break;
		case FLOAT:
			if (tipo1 == INTOPND && tipo2 == INTOPND)
				*(quad->result.atr.simb->valfloat) = valint1 + valint2;
			if (tipo1 == INTOPND && tipo2 == REALOPND)
				*(quad->result.atr.simb->valfloat) = valint1 + valfloat2;
			if (tipo1 == REALOPND && tipo2 == INTOPND)
				*(quad->result.atr.simb->valfloat) = valfloat1 + valint2;
			if (tipo1 == REALOPND && tipo2 == REALOPND)
				*(quad->result.atr.simb->valfloat) = valfloat1 + valfloat2;
			break;
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
    pontelemlistsimb listPtr;
    if(VaziaContexto(pilhacontext)){
        printf("\nErro : Sem contexto durante execução de ExecQuadCallop");
    }
    else{
        char *modname = quad->opnd1.atr.simb->cadeia;   

        while(strcmp(modname,codintermedaux->modname->cadeia)!=0 && codintermedaux!=NULL){
            codintermedaux = codintermedaux->prox;
        }
        
        if(codintermedaux == NULL){
            printf("\n Não se encontrou o modulo com o nome: %s",modname);
        }
        else{

            if(quad->opnd2.tipo!=IDLEOPND){

                InicPilhaOpnd(&pilhaopndaux);
                for(i=1; i<= quad->opnd2.atr.valint;i++){
                    EmpilharOpnd(TopoOpnd(pilhaopnd),&pilhaopndaux);
                    DesempilharOpnd(&pilhaopnd);
                }
                int tipoaux, valint;
                char valchar, vallogic;
                float valfloat;
                listPtr = quad->opnd1.atr.simb->listparamc;
                for(i=1; i<=quad->opnd2.atr.valint; i++)
                {
                    opndaux = TopoOpnd(pilhaopndaux);
                    DesempilharOpnd(&pilhaopndaux);
                    switch(opndaux.tipo)
                    {
                        case INTOPND:
                            tipoaux = INTOPND;
                            valint = opndaux.atr.valint;
                            break;
                        case CHAROPND:
                            tipoaux = CHAROPND;
                            valchar = opndaux.atr.valchar;
                            break;
                        case REALOPND:
                            tipoaux = REALOPND;
                            valfloat = opndaux.atr.valfloat;
                            break;
                        case LOGICOPND:
                            tipoaux = LOGICOPND;
                            vallogic = opndaux.atr.vallogic;
                            break;
                        case VAROPND:
                            switch(opndaux.atr.simb->tvar)
                            {
                                case INTEGER:
                                    tipoaux = INTOPND;
                                    valint = *(opndaux.atr.simb->valint);
                                    break;
                                case CHAR:
                                    tipoaux = CHAROPND;
                                    valchar = *(opndaux.atr.simb->valchar);
                                    break;
                                case FLOAT:
                                    tipoaux = REALOPND;
                                    valfloat = *(opndaux.atr.simb->valfloat);
                                    break;
                                case LOGICAL:
                                    tipoaux = LOGICOPND;
                                    vallogic = *(opndaux.atr.simb->vallogic);
                                    break;
                            }
                    }

                    switch(listPtr->simb->tvar)
                    {
                        case INTEGER:
                            listPtr->simb->valint = (int*) malloc(sizeof(int));
                            if(tipoaux == INTOPND)
                                *(listPtr->simb->valint) = valint;
                            else if(tipoaux == CHAROPND)
                                *(listPtr->simb->valint) = valchar;
                            break;
                        case CHAR:
                            listPtr->simb->valchar = (char*) malloc(sizeof(char));
                            if(tipoaux == INTOPND)
                                *(listPtr->simb->valchar) = valint;
                            else if(tipoaux == CHAROPND)
                                *(listPtr->simb->valchar) = valchar;
                            break;
                        case LOGICAL:
                            listPtr->simb->vallogic = (char*) malloc(sizeof(char));
                            *(listPtr->simb->vallogic) = vallogic;
                            break;
                        case FLOAT:
                            listPtr->simb->valfloat = (float *) malloc(sizeof(float));
                            if(tipoaux == INTOPND)
                                *(listPtr->simb->valfloat) = valint;
                            else if(tipoaux == REALOPND)
                                *(listPtr->simb->valfloat) = valfloat;
                            else if(tipoaux == CHAROPND)
                                *(listPtr->simb->valfloat) = valchar;
                            break;
                    }

                    listPtr = listPtr->prox;
                }

            }
        }
    }
}

void ExecQuadWrite(quadrupla quad)
{
    int i;
    operando opndaux;
    pilhaoperando pilhaopndaux;

    //printf("\n\t\t(INTEPRETADOR)Escrevendo: \n\n");
    InicPilhaOpnd(&pilhaopndaux);
    for(i = 1; i<=quad->opnd1.atr.valint; i++)
    {
        EmpilharOpnd(TopoOpnd(pilhaopnd), &pilhaopndaux);
        DesempilharOpnd(&pilhaopnd);
    }
    
    //printf("\t\t");

    for(i=1; i<=quad->opnd1.atr.valint; i++)
    {
        opndaux = TopoOpnd(pilhaopndaux);
        DesempilharOpnd(&pilhaopndaux);
        switch(opndaux.tipo)
        {
            case INTOPND:
                printf("%d ", opndaux.atr.valint);
                break;
            case REALOPND:
                printf("%g ", opndaux.atr.valfloat);
                break;
            case CHAROPND:
                printf("%c ", opndaux.atr.valchar);
                break;
            case LOGICOPND:
                if(opndaux.atr.vallogic == 1)
                    printf("VERDADE ");
                else
                    printf("FALSO ");
                break;
            case CADOPND:
                ImprimeCadeia(opndaux.atr.valcad);
                break;
            case VAROPND:
                switch(opndaux.atr.simb->tvar)
                {
                    case INTEGER:
                        printf("%d", *(opndaux.atr.simb->valint));
                        break;
                    case FLOAT:
                        printf("%g", *(opndaux.atr.simb->valfloat));
                        break;
                    case LOGICAL:
                        if(*(opndaux.atr.simb->vallogic)==1)
                            printf("VERDADE");
                        else
                            printf("FALSO");
                        break;
                    case CHAR:
                        printf("%c", *(opndaux.atr.simb->valchar));
                        break;
                }
                break; 
        }
        //printf(" ");
    }
    //printf("\n");
}

void ImprimeCadeia(char * cadeia)
{
    int len = strlen(cadeia);
    enum {CHARACTER, ESCAPE} state = CHARACTER;
    int i;
    for(i=0; i<len; i++)
    {
        switch(state)
        {
            case CHARACTER:
                if(cadeia[i] == '\\') {
                    state = ESCAPE;
                }
                else
                {
                    printf("%c", cadeia[i]);
                }
                break;
            case ESCAPE:
                switch(cadeia[i])
                {
                    case 'n':
                        printf("\n");
                        break;
                    case 't':
                        printf("\t");
                        break;
                }
                state = CHARACTER;
                break;
        }
    }
}

void ExecQuadRead(quadrupla quad)
{
    int i;
    operando opndaux;
    pilhaoperando pilhaopndaux;

    printf("\n\t\t(INTERPRETADOR)");
    InicPilhaOpnd(&pilhaopndaux);
    for(i=1; i<=quad->opnd1.atr.valint; i++)
    {
        EmpilharOpnd(TopoOpnd(pilhaopnd), &pilhaopndaux);
        DesempilharOpnd(&pilhaopnd);
    }
    for(i=1; i<=quad->opnd1.atr.valint; i++)
    {
        opndaux = TopoOpnd(pilhaopndaux);
        DesempilharOpnd(&pilhaopndaux);
        switch(opndaux.atr.simb->tvar)
        {
            case INTEGER:
                fscanf(finput, "%d ", opndaux.atr.simb->valint);
                printf("Lido %d", *(opndaux.atr.simb->valint));
                break;
            case FLOAT:
                fscanf(finput, "%g ", opndaux.atr.simb->valfloat);
                printf("Lido %g", *(opndaux.atr.simb->valfloat));
                break;
            case LOGICAL:
                fscanf(finput, "%d ", opndaux.atr.simb->vallogic);
                printf("Lido %d",*(opndaux.atr.simb->vallogic));
                break;
            case CHAR:
                fscanf(finput, "%c ", opndaux.atr.simb->valchar);
                printf("Lido %c", *(opndaux.atr.simb->valchar));
                break;   
        }
        printf("\n");
    }
}

void ExecQuadINDEX(quadrupla quad)
{
    int i;
    operando opndaux;
    pilhaoperando pilhaopndaux;

    InicPilhaOpnd(&pilhaopndaux);
    for(i=1; i<=quad->opnd2.atr.valint; i++)
    {
        EmpilharOpnd(TopoOpnd(pilhaopnd), &pilhaopndaux);
        DesempilharOpnd(&pilhaopnd);
    }
    
    int dim;
    
    int pos = 0;
    for(i = 1; i<=quad->opnd1.atr.simb->ndims; i++)
    {
        pos *= quad->opnd1.atr.simb->dims[i];
        opndaux = TopoOpnd(pilhaopndaux);
        DesempilharOpnd(&pilhaopndaux);
        switch(opndaux.tipo)
        {
        case INTOPND:
            dim = opndaux.atr.valint;
            break;
        case CHAROPND:
            dim = opndaux.atr.valchar;
            break;
        case VAROPND:
            switch(opndaux.atr.simb->tvar)
            {
                case INTEGER:
                    dim = *(opndaux.atr.simb->valint);
                    break;
                case CHAR:
                    dim = *(opndaux.atr.simb->valchar);
                    break;
            }
            break;
        }
        pos += dim;
    }

    switch(quad->opnd1.atr.simb->tvar)
    {
        case INTEGER:
            quad->result.atr.simb->valint = &(quad->opnd1.atr.simb->valint[pos]);
            break;
        case FLOAT:
            quad->result.atr.simb->valfloat = &(quad->opnd1.atr.simb->valfloat[pos]);
            break;
        case CHAR:
            quad->result.atr.simb->valchar = &(quad->opnd1.atr.simb->valchar[pos]);
            break;
        case LOGICAL:
            quad->result.atr.simb->vallogic = &(quad->opnd1.atr.simb->vallogic[pos]);
            break;
    }
}

void ExecQuadContpont(quadrupla quad)
{
    switch(quad->opnd1.atr.simb->tvar)
    {
        case PTRINT:
            *(quad->result.atr.simb->valint) = *(quad->opnd1.atr.simb->valint);
            break;
        case PTRFLOAT:
            *(quad->result.atr.simb->valfloat) = *(quad->opnd1.atr.simb->valfloat);
            break;
        case PTRCHAR:
            *(quad->result.atr.simb->valchar) = *(quad->opnd1.atr.simb->valchar);
            break;
        case PTRLOG:
            *(quad->result.atr.simb->vallogic) = *(quad->opnd1.atr.simb->vallogic);        
    }
}

void ExecQuadAtribpont(quadrupla quad)
{
    int tipo1, valint1;
    float valfloat1;
    char valchar1, vallogic1;
    switch (quad->opnd1.tipo) 
    {
        case INTOPND:
            tipo1 = INTOPND;
            valint1 = quad->opnd1.atr.valint; break;
        case REALOPND:
            tipo1 = REALOPND;
            valfloat1 = quad->opnd1.atr.valfloat; break;
        case CHAROPND:
            tipo1 = CHAROPND;
            valchar1 = quad->opnd1.atr.valchar; break;
        case LOGICOPND:
            tipo1 = LOGICOPND;
            vallogic1 = quad->opnd1.atr.vallogic; break;
        case VAROPND:
            switch (quad->opnd1.atr.simb->tvar) {
                case INTEGER:
                    tipo1 = INTOPND;
                    valint1 = *(quad->opnd1.atr.simb->valint); break;
                case FLOAT:
                    tipo1 = REALOPND;
                    valfloat1=*(quad->opnd1.atr.simb->valfloat);break;
                case CHAR:
                    tipo1 = CHAROPND;
                    valchar1=*(quad->opnd1.atr.simb->valchar);break;
                case LOGICAL:
                    tipo1 = LOGICOPND;
                    vallogic1 = *(quad->opnd1.atr.simb->vallogic);
                    break;
            }
            break;
	}

    switch(quad->result.atr.simb->tvar)
    {
        case PTRINT:
            if(tipo1 == INTOPND)
                *(quad->result.atr.simb->valint) = valint1;
            else if(tipo1 == CHAROPND)
                *(quad->result.atr.simb->valint) = valchar1;
            break;
        case PTRCHAR:
            if(tipo1 == INTOPND)
                *(quad->result.atr.simb->valchar) = valint1;
            else if(tipo1 == CHAROPND)
                *(quad->result.atr.simb->valchar) = valchar1;
            break;
        case PTRLOG:
            *(quad->result.atr.simb->vallogic) = vallogic1;
            break;
        case PTRFLOAT:
        if(tipo1 == INTOPND)
            *(quad->result.atr.simb->valfloat) = valint1;
        else if(tipo1 == REALOPND)
            *(quad->result.atr.simb->valfloat) = valfloat1;
        else if(tipo1 == CHAROPND)
            *(quad->result.atr.simb->valfloat) = valchar1;
        break;
    }

}

void DesalocaVariaveis(simbolo modulo)
{
    simbolo s;
    int nelemaloc, i, j;
    for(i=0; i < NCLASSHASH; i++)
    {
        if(tabsimb[i])
        {
            for(s = tabsimb[i]; s != NULL; s = s->prox)
            {
                if(s->escopo == modulo && s->tid == IDVAR)
                {
                    switch(s->tvar)
                    {
                        case INTEGER:
                            if(s->valint != NULL)
                            {
                                free(s->valint);
                                s->valint = NULL;
                            }
                            break;
                        case FLOAT:
                            if(s->valfloat != NULL)
                            {
                                free(s->valfloat);
                                s->valfloat = NULL;
                            }
                            break;
                        case CHAR:
                            if(s->valchar != NULL)
                            {
                                free(s->valchar);
                                s->valchar = NULL;
                            }
                                
                            break;
                        case LOGICAL:
                            if(s->vallogic != NULL)
                            {
                                free(s->vallogic);
                                s->vallogic = NULL;

                            }
                            break;
                        case PTRINT:
                            s->valint = NULL;
                            break;
                        case PTRFLOAT:
                            s->valfloat = NULL;
                            break;
                        case PTRCHAR:
                            s->valchar = NULL;
                            break;
                        case PTRLOG:
                            s->vallogic = NULL;
                            break;
                    }
                
                }
            }
        }
    }
}

/*void Indentar()
{
    printf("\n");
    int i;
    for(i=0; i<tab; i++)
    {
        printf("\t");
    }
}*/
