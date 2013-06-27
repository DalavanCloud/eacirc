#ifndef EACCONSTANTS_H
#define EACCONSTANTS_H

#include <limits.h>

typedef unsigned long DWORD;

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#ifndef ULONG_MAX
#define ULONG_MAX     0xffffffffUL
#endif

#ifndef UCHAR_MAX
#define UCHAR_MAX     255
#endif

#ifndef INT_MAX
#define INT_MAX       2147483647
#endif

#ifndef BITS_IN_UCHAR
#define BITS_IN_UCHAR 8
#endif

#ifdef _MSC_VER
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif

// PROJECTS
#define PROJECT_PREGENERATED_TV     0
#define PROJECT_ESTREAM             100
#define PROJECT_SHA3                200
#define PROJECT_TEA                 300
#define PROJECT_FILE_DISTINGUISHER  400

// FILENAMES
#define FILE_CONFIG                 "config.xml"
#define FILE_STATE                  "state.xml"
#define FILE_STATE_INITIAL          "state_initial.xml"
#define FILE_POPULATION             "population.xml"
#define FILE_POPULATION_INITIAL     "population_initial.xml"
#define FILE_FITNESS_PROGRESS       "fitness_progress.txt"
#define FILE_BEST_FITNESS           "bestfit_graph.txt"
#define FILE_AVG_FITNESS            "avgfit_graph.txt"
#define FILE_GALIB_SCORES           "scores.log"
#define FILE_BOINC_FRACTION_DONE    "fraction_done.txt"
#define FILE_TEST_VECTORS           "test_vectors.bin"
#define FILE_TEST_VECTORS_HR        "test_vectors_hr.txt"
#define FILE_CIRCUIT                "circuit_"          // folloved by fitness (.bin, .txt, .dot, .c)
#define FILE_BEST_CIRCUIT           "EAC_circuit"       // .bin, .txt, .dot, .c
#define FILE_LOGFILE                "eacirc.log"

// QRNG DATA
// filename = $PREFIX$INDEX$DUFFIX
// index starts from 0 to maximal value save in main settings
// index number should be prefixed by zeroes (to equal length as max index)
#define FILE_QRNG_DATA_PREFIX       "Random"
#define FILE_QRNG_DATA_SUFFIX       ".bin"
// separator berween more paths
#define FILE_PATH_SEPARATOR         ";"
// maximum number of bits used from random data file
// don't set too big, this size is read into memory
// currently 10MB
#define RANDOM_DATA_FILE_SIZE		10485760

// COMMAND LINE OPTIONS
#define CMD_OPT_LOGGING             "-log"
#define CMD_OPT_LOGGING_TO_FILE     "-log2file"
#define CMD_OPT_SELF_TEST           "-test"
#define CMD_OPT_CUSTOM_CONFIG       "-c"

// CIRCUIT LIMITS
#define MAX_LAYER_SIZE              32
//#define NUM_OUTPUT_CATEGORIES		256
#define NUM_OUTPUT_CATEGORIES		10
//#define ENABLE_SLIDING_WINDOW			// if enabled, input data are shifted only per one byte, not pGlobals->settings->circuit.sizeInputLayer. Note - fitness results are then not directly comparable with version without sliding window

// EVALUATORS
#define EVALUATOR_HAMMING_WEIGHT    24
#define EVALUATOR_TOP_BIT           25
#define EVALUATOR_CATEGORIES        26
// note: all project specific evaluators must have constant above this
#define EVALUATOR_PROJECT_SPECIFIC_MINIMUM PROJECT_ESTREAM
/* OLD BEGIN
#define EVALUATOR_BIT               20
#define EVALUATOR_BITGROUP_PARITY   21
#define EVALUATOR_BYTES_PARITY      22
#define EVALUATOR_HAMMING_WEIGHT    23
#define EVALUATOR_BYTE              24
#define EVALUATOR_DISTINGUISH       25
#define EVALUATOR_OUTPUT_CATEGORIES	26
// OLD END
*/

#define TESTVECT_MD5INV             0
#define TESTVECT_SHA1INV            1
#define TESTVECT_DESPLAINTEXT       2
#define TESTVECT_TEST               3
#define TESTVECT_MD5SHA_DISTINGUISH		4
#define TESTVECT_MD5_RAND_DISTINGUISH   5
#define TESTVECT_SHA1_RAND_DISTINGUISH  6

// RANDOM GENERATORS
#define GENERATOR_QRNG				1
#define	GENERATOR_BIAS				2
#define GENERATOR_MD5               3

// CIRCUIT FUNCTIONS
#define FNC_NOP                     0
#define FNC_OR                      1
#define FNC_AND                     2
#define FNC_CONST                   3
#define FNC_XOR                     4
#define FNC_NOR                     5
#define FNC_NAND                    6
#define FNC_ROTL                    7
#define FNC_ROTR                    8
#define FNC_BITSELECTOR             9
#define FNC_SUM                     10
#define FNC_SUBS                    11
#define FNC_ADD                     12
#define FNC_MULT                    13
#define FNC_DIV                     14
#define FNC_READX                   15
#define FNC_EQUAL                   16
#define FNC_MAX                     FNC_EQUAL

// BYTECODE OPS CODES - used for emulation of internode program (not all at the moment, see list below)
#define AALOAD      0x32
#define AASTORE     0x53
#define ALOAD       0x19
#define	ALOAD_0     0x2a
#define	ALOAD_1     0x2b
#define	ALOAD_2     0x2c
#define	ALOAD_3     0x2d
#define	ARETURN     0xb0
#define	ARRAYLENGTH	0xbe
#define	ASTORE      0x3a
#define	ASTORE_0	0x4b
#define	ASTORE_1	0x4c
#define	ASTORE_2	0x4d
#define	ASTORE_3	0x4e
#define	BALOAD      0x33
#define	BASTORE     0x54
#define	BIPUSH      0x10
#define	DUP         0x59
#define	GETSTATIC	0xb2
#define	GOTO        0xa7
#define	I2B         0x91
#define	IADD        0x60
#define	IAND        0x7e
#define IALOAD      0x2e
#define	IASTORE     0x4f
#define	ICONST_M1	0x2
#define ICONST_0	0x3
#define	ICONST_1	0x4
#define	ICONST_2	0x5
#define	ICONST_3	0x6
#define	ICONST_4	0x7
#define	ICONST_5	0x8
#define	IDIV		0x6c
#define	IFEQ		0x99
#define IFNE		0x9a
#define	IF_ICMPGE	0xa2
#define	IF_ICMPLE	0xa4
#define	IF_ICMPNE	0xa0
#define IINC		0x84
#define ILOAD		0x15
#define	ILOAD_0		0x1a
#define	ILOAD_1		0x1b
#define	ILOAD_2		0x1c
#define	ILOAD_3		0x1d
#define	IMUL		0x68
#define INVOKESPECIAL	0xb7
#define INVOKESTATIC	0xb8
#define IREM			0x70
#define IRETURN			0xac
#define ISHL			0x78
#define ISHR			0x7a
#define	ISTORE			0x36
#define	ISTORE_0		0x3b
#define	ISTORE_1		0x3c
#define	ISTORE_2		0x3d
#define	ISTORE_3		0x3e
#define ISUB			0x64
#define	IXOR			0x82
#define	MULTIANEWARRAY	0xc5
#define	NEWARRAY		0xbc
#define	PUTSTATIC		0xb3
#define	RETURN			0xb1
#define	SIPUSH			0x11
#define	POP				0x57

/* already implemented
IADD
ISUB
IAND
IXOR
ICONST_M1
ICONST_0
ICONST_1
ICONST_2
ICONST_3
ICONST_4
ICONST_5
I2B
IDIV
IMUL
IREM
ISHL
ISHR
BIPUSH
SIPUSH
DUP
*/
#endif                                                       
