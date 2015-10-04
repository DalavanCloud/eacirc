#include "CaesarInterface.h"
#include "EACglobals.h"
#include "aead/aead.h"

CaesarInterface::CaesarInterface(int a, int nr, int kl, int smnl, int pmnl, int co)
    : m_algorithm(a), m_numRounds(nr) {
    pCaesarSettings->keyLength = kl;
    pCaesarSettings->smnLength = smnl;
    pCaesarSettings->pmnLength = pmnl;
    pCaesarSettings->cipertextOverhead = co;
}

CaesarInterface::~CaesarInterface() { }

CaesarInterface* CaesarInterface::getCaesarFunction(int algorithm, int numRounds) {
    switch (algorithm) {
        case CAESAR_ACORN128: { return new Acorn128(numRounds); };
        case CAESAR_AEGIS128: { return new Aegis128(numRounds); };
        case CAESAR_AEGIS128L: { return new Aegis128l(numRounds); };
        case CAESAR_AEGIS256: { return new Aegis256(numRounds); };
//        case CAESAR_AES128AVALANCHEV1: { return new Aes128avalanchev1(numRounds); };
//        case CAESAR_AES192AVALANCHEV1: { return new Aes192avalanchev1(numRounds); };
//        case CAESAR_AES256AVALANCHEV1: { return new Aes256avalanchev1(numRounds); };
//        case CAESAR_AES128CPFBV1: { return new Aes128cpfbv1(numRounds); };
        case CAESAR_AES128GCMV1: { return new Aes128gcmv1(numRounds); };
        case CAESAR_AES256GCMV1: { return new Aes256gcmv1(numRounds); };
        case CAESAR_AES128MARBLE4RV1: { return new Aes128marble4rv1(numRounds); };
        case CAESAR_AES128N12CLOCV1: { return new Aes128n12clocv1(numRounds); };
        case CAESAR_AES128N8CLOCV1: { return new Aes128n8clocv1(numRounds); };
//        case CAESAR_AES128N12SILCV1: { return new Aes128n12silcv1(numRounds); };
//        case CAESAR_AES128N8SILCV1: { return new Aes128n8silcv1(numRounds); };
//        case CAESAR_LED80N6SILCV1: { return new Led80n6silcv1(numRounds); };
//        case CAESAR_PRESENT80N6SILCV1: { return new Present80n6silcv1(numRounds); };
        case CAESAR_AES128OTRPV1: { return new Aes128otrpv1(numRounds); };
        case CAESAR_AES128OTRSV1: { return new Aes128otrsv1(numRounds); };
        case CAESAR_AES256OTRPV1: { return new Aes256otrpv1(numRounds); };
        case CAESAR_AES256OTRSV1: { return new Aes256otrsv1(numRounds); };
        case CAESAR_AES128POETV1AES128: { return new Aes128poetv1aes128(numRounds); };
        case CAESAR_AES128POETV1AES4: { return new Aes128poetv1aes4(numRounds); };
//        case CAESAR_AES256CPFBV1: { return new Aes256cpfbv1(numRounds); };
        case CAESAR_AESCOPAV1: { return new Aescopav1(numRounds); };
        case CAESAR_AESJAMBUV1: { return new Aesjambuv1(numRounds); };
        case CAESAR_AEZV1: { return new Aezv1(numRounds); };
        case CAESAR_AEZV3: { return new Aezv3(numRounds); };
        case CAESAR_ARTEMIA128V1: { return new Artemia128v1(numRounds); };
        case CAESAR_ARTEMIA256V1: { return new Artemia256v1(numRounds); };
        case CAESAR_ASCON128V1: { return new Ascon128v1(numRounds); };
        case CAESAR_ASCON96V1: { return new Ascon96v1(numRounds); };
        case CAESAR_CALICOV8: { return new Calicov8(numRounds); };
        case CAESAR_CMCC22V1: { return new Cmcc22v1(numRounds); };
        case CAESAR_CMCC24V1: { return new Cmcc24v1(numRounds); };
        case CAESAR_CMCC42V1: { return new Cmcc42v1(numRounds); };
        case CAESAR_CMCC44V1: { return new Cmcc44v1(numRounds); };
        case CAESAR_CMCC84V1: { return new Cmcc84v1(numRounds); };
        case CAESAR_DEOXYSEQ128128V1: { return new Deoxyseq128128v1(numRounds); };
        case CAESAR_DEOXYSEQ256128V1: { return new Deoxyseq256128v1(numRounds); };
        case CAESAR_DEOXYSNEQ128128V1: { return new Deoxysneq128128v1(numRounds); };
        case CAESAR_DEOXYSNEQ256128V1: { return new Deoxysneq256128v1(numRounds); };
        case CAESAR_ENCHILADA128V1: { return new Enchilada128v1(numRounds); };
//        case CAESAR_ENCHILADA256V1: { return new Enchilada256v1(numRounds); };
        case CAESAR_HS1SIVHIV1: { return new Hs1sivhiv1(numRounds); };
        case CAESAR_HS1SIVLOV1: { return new Hs1sivlov1(numRounds); };
        case CAESAR_HS1SIVV1: { return new Hs1sivv1(numRounds); };
        case CAESAR_ICEPOLE128AV1: { return new Icepole128av1(numRounds); };
        case CAESAR_ICEPOLE128V1: { return new Icepole128v1(numRounds); };
        case CAESAR_ICEPOLE256AV1: { return new Icepole256av1(numRounds); };
        case CAESAR_IFEEDAES128N104V1: { return new Ifeedaes128n104v1(numRounds); };
        case CAESAR_IFEEDAES128N96V1: { return new Ifeedaes128n96v1(numRounds); };
        case CAESAR_ISCREAM12V1: { return new Iscream12v1(numRounds); };
        case CAESAR_ISCREAM12V2: { return new Iscream12v2(numRounds); };
        case CAESAR_ISCREAM14V1: { return new Iscream14v1(numRounds); };
        case CAESAR_ISCREAM14V2: { return new Iscream14v2(numRounds); };
        case CAESAR_SCREAM10V1: { return new Scream10v1(numRounds); };
        case CAESAR_SCREAM10V2: { return new Scream10v2(numRounds); };
        case CAESAR_SCREAM12V1: { return new Scream12v1(numRounds); };
        case CAESAR_SCREAM12V2: { return new Scream12v2(numRounds); };
        case CAESAR_JOLTIKEQ12864V1: { return new Joltikeq12864v1(numRounds); };
        case CAESAR_JOLTIKEQ6464V1: { return new Joltikeq6464v1(numRounds); };
        case CAESAR_JOLTIKEQ8048V1: { return new Joltikeq8048v1(numRounds); };
        case CAESAR_JOLTIKEQ9696V1: { return new Joltikeq9696v1(numRounds); };
        case CAESAR_JOLTIKNEQ12864V1: { return new Joltikneq12864v1(numRounds); };
        case CAESAR_JOLTIKNEQ6464V1: { return new Joltikneq6464v1(numRounds); };
        case CAESAR_JOLTIKNEQ8048V1: { return new Joltikneq8048v1(numRounds); };
        case CAESAR_JOLTIKNEQ9696V1: { return new Joltikneq9696v1(numRounds); };
//        case CAESAR_JULIUSV1DRAFT: { return new Juliusv1draft(numRounds); };
        case CAESAR_KETJEJRV1: { return new Ketjejrv1(numRounds); };
        case CAESAR_KETJESRV1: { return new Ketjesrv1(numRounds); };
        case CAESAR_KIASUEQ128V1: { return new Kiasueq128v1(numRounds); };
        case CAESAR_KIASUNEQ128V1: { return new Kiasuneq128v1(numRounds); };
        case CAESAR_LACV1: { return new Lacv1(numRounds); };
        case CAESAR_LAKEKEYAKV1: { return new Lakekeyakv1(numRounds); };
        case CAESAR_OCEANKEYAKV1: { return new Oceankeyakv1(numRounds); };
        case CAESAR_RIVERKEYAKV1: { return new Riverkeyakv1(numRounds); };
        case CAESAR_SEAKEYAKV1: { return new Seakeyakv1(numRounds); };
        case CAESAR_MINALPHERV1: { return new Minalpherv1(numRounds); };
        case CAESAR_MORUS1280128V1: { return new Morus1280128v1(numRounds); };
        case CAESAR_MORUS1280256V1: { return new Morus1280256v1(numRounds); };
        case CAESAR_MORUS640128V1: { return new Morus640128v1(numRounds); };
        case CAESAR_NORX3241V1: { return new Norx3241v1(numRounds); };
        case CAESAR_NORX3261V1: { return new Norx3261v1(numRounds); };
        case CAESAR_NORX6441V1: { return new Norx6441v1(numRounds); };
        case CAESAR_NORX6444V1: { return new Norx6444v1(numRounds); };
        case CAESAR_NORX6461V1: { return new Norx6461v1(numRounds); };
        case CAESAR_OMDSHA256K128N96TAU128V1: { return new Omdsha256k128n96tau128v1(numRounds); };
        case CAESAR_OMDSHA256K128N96TAU64V1: { return new Omdsha256k128n96tau64v1(numRounds); };
        case CAESAR_OMDSHA256K128N96TAU96V1: { return new Omdsha256k128n96tau96v1(numRounds); };
        case CAESAR_OMDSHA256K192N104TAU128V1: { return new Omdsha256k192n104tau128v1(numRounds); };
        case CAESAR_OMDSHA256K256N104TAU160V1: { return new Omdsha256k256n104tau160v1(numRounds); };
        case CAESAR_OMDSHA256K256N248TAU256V1: { return new Omdsha256k256n248tau256v1(numRounds); };
        case CAESAR_OMDSHA512K128N128TAU128V1: { return new Omdsha512k128n128tau128v1(numRounds); };
        case CAESAR_OMDSHA512K256N256TAU256V1: { return new Omdsha512k256n256tau256v1(numRounds); };
        case CAESAR_OMDSHA512K512N256TAU256V1: { return new Omdsha512k512n256tau256v1(numRounds); };
        case CAESAR_PAEQ128: { return new Paeq128(numRounds); };
        case CAESAR_PAEQ128T: { return new Paeq128t(numRounds); };
        case CAESAR_PAEQ128TNM: { return new Paeq128tnm(numRounds); };
        case CAESAR_PAEQ160: { return new Paeq160(numRounds); };
        case CAESAR_PAEQ64: { return new Paeq64(numRounds); };
        case CAESAR_PAEQ80: { return new Paeq80(numRounds); };
        case CAESAR_PI16CIPHER096V1: { return new Pi16cipher096v1(numRounds); };
        case CAESAR_PI16CIPHER128V1: { return new Pi16cipher128v1(numRounds); };
        case CAESAR_PI32CIPHER128V1: { return new Pi32cipher128v1(numRounds); };
        case CAESAR_PI32CIPHER256V1: { return new Pi32cipher256v1(numRounds); };
        case CAESAR_PI64CIPHER128V1: { return new Pi64cipher128v1(numRounds); };
        case CAESAR_PI64CIPHER256V1: { return new Pi64cipher256v1(numRounds); };
        case CAESAR_PI64CIPHER256V1ONEROUND: { return new Pi64cipher256v1oneround(numRounds); };
        case CAESAR_PI64CIPHER256V1TWOROUNDS: { return new Pi64cipher256v1tworounds(numRounds); };
//        case CAESAR_POLAWISV1: { return new Polawisv1(numRounds); };
        case CAESAR_PPAEV11: { return new Ppaev11(numRounds); };
        case CAESAR_PRIMATESV1APE120: { return new Primatesv1ape120(numRounds); };
        case CAESAR_PRIMATESV1APE80: { return new Primatesv1ape80(numRounds); };
        case CAESAR_PRIMATESV1GIBBON120: { return new Primatesv1gibbon120(numRounds); };
        case CAESAR_PRIMATESV1GIBBON80: { return new Primatesv1gibbon80(numRounds); };
        case CAESAR_PRIMATESV1HANUMAN120: { return new Primatesv1hanuman120(numRounds); };
        case CAESAR_PRIMATESV1HANUMAN80: { return new Primatesv1hanuman80(numRounds); };
        case CAESAR_PROEST128APEV1: { return new Proest128apev1(numRounds); };
        case CAESAR_PROEST128COPAV1: { return new Proest128copav1(numRounds); };
        case CAESAR_PROEST128OTRV1: { return new Proest128otrv1(numRounds); };
        case CAESAR_PROEST256APEV1: { return new Proest256apev1(numRounds); };
        case CAESAR_PROEST256COPAV1: { return new Proest256copav1(numRounds); };
        case CAESAR_PROEST256OTRV1: { return new Proest256otrv1(numRounds); };
        case CAESAR_RAVIYOYLAV1: { return new Raviyoylav1(numRounds); };
        case CAESAR_SABLIERV1: { return new Sablierv1(numRounds); };
//        case CAESAR_SHELLAES128V1D4N64: { return new Shellaes128v1d4n64(numRounds); };
//        case CAESAR_SHELLAES128V1D4N80: { return new Shellaes128v1d4n80(numRounds); };
//        case CAESAR_SHELLAES128V1D5N64: { return new Shellaes128v1d5n64(numRounds); };
//        case CAESAR_SHELLAES128V1D5N80: { return new Shellaes128v1d5n80(numRounds); };
//        case CAESAR_SHELLAES128V1D6N64: { return new Shellaes128v1d6n64(numRounds); };
//        case CAESAR_SHELLAES128V1D6N80: { return new Shellaes128v1d6n80(numRounds); };
//        case CAESAR_SHELLAES128V1D7N64: { return new Shellaes128v1d7n64(numRounds); };
//        case CAESAR_SHELLAES128V1D7N80: { return new Shellaes128v1d7n80(numRounds); };
//        case CAESAR_SHELLAES128V1D8N64: { return new Shellaes128v1d8n64(numRounds); };
//        case CAESAR_SHELLAES128V1D8N80: { return new Shellaes128v1d8n80(numRounds); };
//        case CAESAR_SILVERV1: { return new Silverv1(numRounds); };
//        case CAESAR_STRIBOB192R1: { return new Stribob192r1(numRounds); };
//        case CAESAR_TIAOXINV1: { return new Tiaoxinv1(numRounds); };
//        case CAESAR_TRIVIA0V1: { return new Trivia0v1(numRounds); };
//        case CAESAR_TRIVIA128V1: { return new Trivia128v1(numRounds); };
//        case CAESAR_TWINE80N6CLOCV1: { return new Twine80n6clocv1(numRounds); };
//        case CAESAR_WHEESHTV1MR3FR1T128: { return new Wheeshtv1mr3fr1t128(numRounds); };
//        case CAESAR_WHEESHTV1MR3FR1T256: { return new Wheeshtv1mr3fr1t256(numRounds); };
//        case CAESAR_WHEESHTV1MR3FR3T256: { return new Wheeshtv1mr3fr3t256(numRounds); };
//        case CAESAR_WHEESHTV1MR5FR7T256: { return new Wheeshtv1mr5fr7t256(numRounds); };
//        case CAESAR_YAES128V2: { return new Yaes128v2(numRounds); };
#ifdef WITH_OPENSSL
        case CAESAR_AEADAES128OCBTAGLEN128V1: { return new Aeadaes128ocbtaglen128v1(numRounds); };
        case CAESAR_AEADAES128OCBTAGLEN64V1: { return new Aeadaes128ocbtaglen64v1(numRounds); };
        case CAESAR_AEADAES128OCBTAGLEN96V1: { return new Aeadaes128ocbtaglen96v1(numRounds); };
        case CAESAR_AEADAES192OCBTAGLEN128V1: { return new Aeadaes192ocbtaglen128v1(numRounds); };
        case CAESAR_AEADAES192OCBTAGLEN64V1: { return new Aeadaes192ocbtaglen64v1(numRounds); };
        case CAESAR_AEADAES192OCBTAGLEN96V1: { return new Aeadaes192ocbtaglen96v1(numRounds); };
        case CAESAR_AEADAES256OCBTAGLEN128V1: { return new Aeadaes256ocbtaglen128v1(numRounds); };
        case CAESAR_AEADAES256OCBTAGLEN64V1: { return new Aeadaes256ocbtaglen64v1(numRounds); };
        case CAESAR_AEADAES256OCBTAGLEN96V1: { return new Aeadaes256ocbtaglen96v1(numRounds); };
        case CAESAR_CBA1: { return new Cba1(numRounds); };
        case CAESAR_CBA10: { return new Cba10(numRounds); };
        case CAESAR_CBA2: { return new Cba2(numRounds); };
        case CAESAR_CBA3: { return new Cba3(numRounds); };
        case CAESAR_CBA4: { return new Cba4(numRounds); };
        case CAESAR_CBA5: { return new Cba5(numRounds); };
        case CAESAR_CBA6: { return new Cba6(numRounds); };
        case CAESAR_CBA7: { return new Cba7(numRounds); };
        case CAESAR_CBA8: { return new Cba8(numRounds); };
        case CAESAR_CBA9: { return new Cba9(numRounds); };
        case CAESAR_ELMD1000V1: { return new Elmd1000v1(numRounds); };
        case CAESAR_ELMD1001V1: { return new Elmd1001v1(numRounds); };
        case CAESAR_ELMD101270V1: { return new Elmd101270v1(numRounds); };
        case CAESAR_ELMD101271V1: { return new Elmd101271v1(numRounds); };
        case CAESAR_ELMD500V1: { return new Elmd500v1(numRounds); };
        case CAESAR_ELMD501V1: { return new Elmd501v1(numRounds); };
        case CAESAR_ELMD51270V1: { return new Elmd51270v1(numRounds); };
        case CAESAR_ELMD51271V1: { return new Elmd51271v1(numRounds); };
#endif
     default:
         mainLogger.out(LOGGER_ERROR) << "Unknown CAESAR algorithm (" << algorithm << ")." << endl;
         return NULL;
     }
}
