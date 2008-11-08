/*************************************************
* OpenSSL Engine Header File                     *
* (C) 1999-2007 Jack Lloyd                       *
*************************************************/

#ifndef BOTAN_ENGINE_OPENSSL_H__
#define BOTAN_ENGINE_OPENSSL_H__

#include <botan/engine.h>

namespace Botan {

/*************************************************
* OpenSSL Engine                                 *
*************************************************/
class BOTAN_DLL OpenSSL_Engine : public Engine
   {
   public:
#if defined(BOTAN_HAS_IF_PUBLIC_KEY_FAMILY)
      IF_Operation* if_op(const BigInt&, const BigInt&, const BigInt&,
                          const BigInt&, const BigInt&, const BigInt&,
                          const BigInt&, const BigInt&) const;
#endif

#if defined(BOTAN_HAS_DSA)
      DSA_Operation* dsa_op(const DL_Group&, const BigInt&,
                            const BigInt&) const;
#endif

#if defined(BOTAN_HAS_NYBERG_RUEPPEL)
      NR_Operation* nr_op(const DL_Group&, const BigInt&, const BigInt&) const;
#endif

#if defined(BOTAN_HAS_ELGAMAL)
      ELG_Operation* elg_op(const DL_Group&, const BigInt&,
                            const BigInt&) const;
#endif

#if defined(BOTAN_HAS_DIFFIE_HELLMAN)
      DH_Operation* dh_op(const DL_Group&, const BigInt&) const;
#endif

      Modular_Exponentiator* mod_exp(const BigInt&,
                                     Power_Mod::Usage_Hints) const;
   private:
      BlockCipher* find_block_cipher(const std::string&) const;
      StreamCipher* find_stream_cipher(const std::string&) const;
      HashFunction* find_hash(const std::string&) const;
   };

}

#endif
