// Standard library includes
#include <string>
#include <algorithm>
#include <iostream>

// Our project headers
#include "VigenereCipher.hpp"
#include "Alphabet.hpp"

VigenereCipher::VigenereCipher ( const std::string& key )
{
  setKey(key);
}

void VigenereCipher::setKey( const std::string& key ) 
{
  // Store the key
  key_ = key;

  // Make sure the key is uppercase
  std::transform( std::begin(key_), std::end(key_), std::begin(key_), ::toupper );

  // Remove non-alphabet characters
  key_.erase( std::remove_if( std::begin(key_), std::end(key_), [](char c){ return !std::isalpha(c); } ), std::end(key_) ); 

  // Check if the key is empty and replace with default if so
  if ( key_.empty() ) {
    key_ = "DEFAULT";
    std::cout << "No key was provided. Key set to " << key_ << "." << std::endl; 
  }  

  // Loop over the key
  for ( std::string::size_type i{0}; i<key_.size(); ++i) {
 
    // Find the letter position in the alphabet
    size_t position{0};
    position = Alphabet::alphabet.find(key_[i]);

    // Create a CaesarCipher using this position as a key
    CaesarCipher vcipher { position };

    // Insert a std::pair of the letter and CaesarCipher into the lookup
    auto chtoCC = std::make_pair( key_[i], vcipher );
    charLookup_.insert(chtoCC);
  }
}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode cipherMode ) const
{
  std::string outputText {""};
  // For each letter in input:
  for ( std::string::size_type i{0}; i<inputText.size(); ++i){
    
    // Find the corresponding letter in the key,
    // repeating/truncating as required
    char keyletter {'a'};
    keyletter = key_[i % key_.size()];

    // Find the Caesar cipher from the lookup
    auto vcipheriter = charLookup_.find(keyletter);

    // Run the encryption/decryption
    std::string input{ inputText[i] };
    // Add the result to the output
    outputText += ((*vcipheriter).second).applyCipher( input, cipherMode);

  }
  return outputText;
}
