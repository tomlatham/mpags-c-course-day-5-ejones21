//! Unit Tests for MPAGSCipher Cipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Cipher.hpp"
#include "CipherType.hpp"
#include "CipherFactory.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

bool testCipher( const std::vector<std::unique_ptr<Cipher>>& cipher, const CipherMode mode, const std::string& inputText, const std::vector<std::string>& outputText) {

  std::vector<std::string> actual_vec {};  

  for ( const auto& c : cipher) { 
    std::string actual = c->applyCipher( inputText, mode);
    (actual_vec).push_back(actual);
  }
  
  if (actual_vec == outputText) {
    return true;
  }
  else {
    return false;
  }
}

TEST_CASE("Cipher encryptions", "[cipher]") { 
  std::vector<std::unique_ptr<Cipher>> cipherlist;
  cipherlist.push_back( cipherFactory( CipherType::Caesar, "10" ) );
  cipherlist.push_back( cipherFactory( CipherType::Playfair, "hello" ) );
  cipherlist.push_back( cipherFactory( CipherType::Vigenere, "key" ) );

  std::vector<std::string> output {"ROVVYGYBVN","ELDLOAYESEGX","RIJVSUYVJN"};
  REQUIRE( testCipher( cipherlist, CipherMode::Encrypt, "HELLOWORLD", output) == true );
}

TEST_CASE("Cipher decryptions", "[cipher]") { 
  std::vector<std::unique_ptr<Cipher>> cipherlist;
  cipherlist.push_back( cipherFactory( CipherType::Caesar, "10" ) );
  cipherlist.push_back( cipherFactory( CipherType::Playfair, "hello" ) );
  cipherlist.push_back( cipherFactory( CipherType::Vigenere, "key" ) );

  std::vector<std::string> output {"XUBBEMEHBT","AHXSELYESEGX","XANBKYENNT"};
  REQUIRE( testCipher( cipherlist, CipherMode::Decrypt, "HELLOWORLD", output) == true );
}




// bool testCipher( const Cipher& cipher, const CipherMode mode, const std::string& inputText, const std::string& outputText) {

//   std::string actual = cipher.applyCipher( inputText, mode);
  
//   if (actual == outputText) { 
//     return true;
//   }
//   else {
//     return false;
//   }
// }


  
// TEST_CASE("Caesar Cipher encryption", "[caesar]") { 
//   CaesarCipher cc {10};
//   REQUIRE( testCipher( cc, CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN") == true );
// }

// TEST_CASE("Caesar Cipher decryption", "[caesar]") {
//   CaesarCipher cc {10};
//   REQUIRE( testCipher( cc, CipherMode::Decrypt, "ROVVYGYBVN", "HELLOWORLD") == true );
// }

// TEST_CASE("Playfair Cipher encryption", "[playfair]") {
//   PlayfairCipher pc{"hello"};
//   REQUIRE( testCipher( pc, CipherMode::Encrypt, "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA") == true );
// }

// TEST_CASE("Playfair Cipher decryption", "[playfair]") {
//   PlayfairCipher pc{"hello"};
//   REQUIRE( testCipher( pc, CipherMode::Decrypt, "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ") == true );
// }

// TEST_CASE("Vigenere Cipher encryption", "[vigenere]") { 
//   VigenereCipher vc {"key"};
//   REQUIRE( testCipher( vc, CipherMode::Encrypt, "HELLOWORLD", "RIJVSUYVJN") == true );
// }

// TEST_CASE("Vigenere Cipher decryption", "[vigenere]") {
//   VigenereCipher vc {"key"};
//   REQUIRE( testCipher( vc, CipherMode::Decrypt, "RIJVSUYVJN", "HELLOWORLD") == true );
// }



