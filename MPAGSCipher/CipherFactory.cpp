#include <memory>
#include "CipherFactory.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

std::unique_ptr<Cipher> cipherFactory ( const CipherType type, std::string applyCipher ) {
  switch (type) {
    case CipherType::Caesar : 
      return std::make_unique<CaesarCipher>( applyCipher );
      
    case CipherType::Playfair :
      return std::make_unique<PlayfairCipher>( applyCipher );

    case CipherType::Vigenere :
      return std::make_unique<VigenereCipher>( applyCipher );

    default : throw std::runtime_error("No such cipher") ;
      return nullptr;
  }
}
    
