namespace Ketjejrv1_raw {

/*
The Keccak sponge function, designed by Guido Bertoni, Joan Daemen,
Michaël Peeters and Gilles Van Assche. For more information, feedback or
questions, please refer to our website: http://keccak.noekeon.org/

Implementation by the designers and Ronny Van Keer,
hereby denoted as "the implementer".

To the extent possible under law, the implementer has waived all copyright
and related or neighboring rights to the source code in this file.
http://creativecommons.org/publicdomain/zero/1.0/
*/

#ifndef _KeccakP_Interface_h_
#define _KeccakP_Interface_h_

#include "KeccakP-200-interface.h"


/** Macro to map KeccakP_StatePermute() to KeccakP200_StatePermute().
 */
#define KeccakP_StatePermute KeccakP200_StatePermute

#endif

} // namespace Ketjejrv1_raw