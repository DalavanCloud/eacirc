#include "aes128marble4rv1_encrypt.h"
#include <string.h>
#include "aes128marble4rv1_api.h"
#include "aes128marble4rv1_marble.h"

// CHANGE namespace moved due to includes
namespace Aes128marble4rv1_raw {
int numRounds = -1;

int crypto_aead_encrypt(
        unsigned char *c, unsigned long long *clen,
        const unsigned char *m, unsigned long long mlen,
        const unsigned char *ad, unsigned long long adlen,
        const unsigned char *nsec,
        const unsigned char *npub,
        const unsigned char *k
        )
{
    if(mlen == 0 && adlen == 0) return RETURN_UNSUPPORTED;
    /* set ciphertext length */
    *clen = mlen + CRYPTO_ABYTES;

    unsigned char tag[CRYPTO_ABYTES];
    ae_cxt* cxt = ae_allocate();
    if(!cxt)
        return RETURN_MEMORY_FAIL;

    /* set key and compute round keys */
    if(ae_init(cxt, k, CRYPTO_KEYBYTES))
        return RETURN_KEYSIZE_ERR;

    /* process the associated data */
    process_ad(cxt, ad, adlen, npub, CRYPTO_NPUBBYTES);

    /* encrypt message */
    ae_encrypt(cxt, (unsigned char*)m, mlen, c);

    return RETURN_SUCCESS;
}

int crypto_aead_decrypt(
        unsigned char *m,unsigned long long *mlen,
        unsigned char *nsec,
        const unsigned char *c,unsigned long long clen,
        const unsigned char *ad,unsigned long long adlen,
        const unsigned char *npub,
        const unsigned char *k
        )
{
    /* set plaintext length */
    *mlen = clen - CRYPTO_ABYTES;
    if(mlen == 0 && adlen == 0) return RETURN_UNSUPPORTED;

    unsigned char tag[CRYPTO_ABYTES*2];
    ae_cxt* cxt = ae_allocate();
    if(!cxt)
        return RETURN_MEMORY_FAIL;

    /* set key and compute round keys */
    if(ae_init(cxt, k, CRYPTO_KEYBYTES))
        return RETURN_KEYSIZE_ERR;

    /* process the associated data */
    process_ad(cxt, ad, adlen, npub, CRYPTO_NPUBBYTES);

    /* decrypt ciphertext */
    ae_decrypt(cxt, m, clen, (unsigned char*)c, tag);

    /* compare the tag */
    int i;
    if((*mlen) > SLEN && (*mlen % SLEN))
    {
        for(i = 0; i < CRYPTO_ABYTES; i++)
            if(tag[i] != tag[SLEN + i]){
                return RETURN_TAG_NO_MATCH;
            }
    }
    else
        for(i = 0; i < CRYPTO_ABYTES; i++)
            if(tag[i] != c[(*mlen) + i]){
                return RETURN_TAG_NO_MATCH;
            }

    return RETURN_SUCCESS;
}


} // namespace Aes128marble4rv1_raw