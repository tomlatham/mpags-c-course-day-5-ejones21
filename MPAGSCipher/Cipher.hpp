#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

// Standard library includes
#include <string>

// Our project headers 
#include "CipherMode.hpp"

/** \file Cipher.hpp
 * \brief Contains the pABC for the type Cipher
 */

/**
 * \class Cipher
 * \brief Specifies the interface the type must provide and implement
 */
class Cipher { 
  public:
    /// Default constructor
    Cipher() = default;
    /// Copy constructor
    Cipher(const Cipher& rhs) = default;
    /// Move constructor
    Cipher(Cipher&& rhs) = default; 
    /// Copy assignment operator
    Cipher& operator=(const Cipher& rhs) = default;
    /// Move assignment operator
    Cipher& operator=(Cipher&& rhs) = default; 
    /// Destructor
    virtual ~Cipher() = default;


   /**
    * Apply the selected cipher to the input text
    * 
    * \param input the text to encrypt or decrypt
    * \param mode whether to encrypt or decrypt the input text
    * \return the result of applying the cipher to the input text
    */
  virtual std::string applyCipher( const std::string& input, const CipherMode mode ) const = 0;
};

#endif
