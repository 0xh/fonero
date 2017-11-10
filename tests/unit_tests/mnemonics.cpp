// Copyright (c) 2017-2018, The Fonero Project.
// Copyright (c) 2014-2017 The Fonero Project.
// Portions Copyright (c) 2012-2013 The Cryptonote developers.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "gtest/gtest.h"
#include "mnemonics/electrum-words.h"
#include "crypto/crypto.h"
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "mnemonics/chinese_simplified.h"
#include "mnemonics/english.h"
#include "mnemonics/spanish.h"
#include "mnemonics/portuguese.h"
#include "mnemonics/japanese.h"
#include "mnemonics/german.h"
#include "mnemonics/italian.h"
#include "mnemonics/russian.h"
#include "mnemonics/french.h"
#include "mnemonics/dutch.h"
#include "mnemonics/esperanto.h"
#include "mnemonics/english_old.h"
#include "mnemonics/language_base.h"
#include "mnemonics/singleton.h"

namespace
{
  /*!
   * \brief Compares vectors for equality
   * \param expected expected vector
   * \param present  current vector
   */
  void compare_vectors(const std::vector<std::string> &expected, const std::vector<std::string> &present)
  {
    std::vector<std::string>::const_iterator it1, it2;
    for (it1 = expected.begin(), it2 = present.begin(); it1 != expected.end() && it2 != present.end();
      it1++, it2++)
    {
      ASSERT_STREQ(it1->c_str(), it2->c_str());
    }
  }

  /*!
   * \brief Tests the given language mnemonics.
   * \param language A Language instance to test
   */
  void test_language(const Language::Base &language)
  {
    const std::vector<std::string> &word_list = language.get_word_list();
    std::string seed = "", return_seed = "";
    // Generate a random seed without checksum
    crypto::secret_key randkey;
    for (size_t ii = 0; ii < sizeof(randkey); ++ii)
    {
      randkey.data[ii] = rand();
    }
    crypto::ElectrumWords::bytes_to_words(randkey, seed, language.get_language_name());
    // remove the checksum word
    const char *space = strrchr(seed.c_str(), ' ');
    ASSERT_TRUE(space != NULL);
    seed = std::string(seed.c_str(), space-seed.c_str());

    std::cout << "Test seed without checksum:\n";
    std::cout << seed << std::endl;

    crypto::secret_key key;
    std::string language_name;
    bool res;
    std::vector<std::string> seed_vector, return_seed_vector;
    std::string checksum_word;

    // Convert it to secret key
    res = crypto::ElectrumWords::words_to_bytes(seed, key, language_name);
    ASSERT_EQ(true, res);
    std::cout << "Detected language: " << language_name << std::endl;
    ASSERT_STREQ(language.get_language_name().c_str(), language_name.c_str());

    // Convert the secret key back to seed
    crypto::ElectrumWords::bytes_to_words(key, return_seed, language.get_language_name());
    ASSERT_EQ(true, res);
    std::cout << "Returned seed:\n";
    std::cout << return_seed << std::endl;
    boost::split(seed_vector, seed, boost::is_any_of(" "));
    boost::split(return_seed_vector, return_seed, boost::is_any_of(" "));

    // Extract the checksum word
    checksum_word = return_seed_vector.back();
    return_seed_vector.pop_back();
    ASSERT_EQ(seed_vector.size(), return_seed_vector.size());
    // Ensure that the rest of it is same
    compare_vectors(seed_vector, return_seed_vector);

    // Append the checksum word to repeat the entire process with a seed with checksum
    seed += (" " + checksum_word);
    std::cout << "Test seed with checksum:\n";
    std::cout << seed << std::endl;
    res = crypto::ElectrumWords::words_to_bytes(seed, key, language_name);
    ASSERT_EQ(true, res);
    std::cout << "Detected language: " << language_name << std::endl;
    ASSERT_STREQ(language.get_language_name().c_str(), language_name.c_str());

    return_seed = "";
    crypto::ElectrumWords::bytes_to_words(key, return_seed, language.get_language_name());
    ASSERT_EQ(true, res);
    std::cout << "Returned seed:\n";
    std::cout << return_seed << std::endl;

    seed_vector.clear();
    return_seed_vector.clear();
    boost::split(seed_vector, seed, boost::is_any_of(" "));
    boost::split(return_seed_vector, return_seed, boost::is_any_of(" "));
    ASSERT_EQ(seed_vector.size(), return_seed_vector.size());
    compare_vectors(seed_vector, return_seed_vector);
  }
}

TEST(mnemonics, consistency)
{
  try {
    std::vector<std::string> language_list;
    crypto::ElectrumWords::get_language_list(language_list);
  }
  catch(const std::exception &e)
  {
    std::cout << "Error initializing mnemonics: " << e.what() << std::endl;
    ASSERT_TRUE(false);
  }
}

TEST(mnemonics, all_languages)
{
  srand(time(NULL));
  std::vector<Language::Base*> languages({
    Language::Singleton<Language::Chinese_Simplified>::instance(),
    Language::Singleton<Language::English>::instance(),
    Language::Singleton<Language::Spanish>::instance(),
    Language::Singleton<Language::Portuguese>::instance(),
    Language::Singleton<Language::Japanese>::instance(),
    Language::Singleton<Language::German>::instance(),
    Language::Singleton<Language::Italian>::instance(),
    Language::Singleton<Language::Russian>::instance(),
    Language::Singleton<Language::French>::instance(),
    Language::Singleton<Language::Dutch>::instance(),
    Language::Singleton<Language::Esperanto>::instance()
  });

  for (std::vector<Language::Base*>::iterator it = languages.begin(); it != languages.end(); it++)
  {
    try {
      test_language(*(*it));
    }
    catch (const std::exception &e) {
      std::cout << "Error testing " << (*it)->get_language_name() << " language: " << e.what() << std::endl;
      ASSERT_TRUE(false);
    }
  }
}

TEST(mnemonics, language_detection_with_bad_checksum)
{
    crypto::secret_key key;
    std::string language_name;
    bool res;

    // This Portuguese (4-prefix) seed has all its words with 3-prefix that's also present in English
    const std::string base_seed = "cinzento luxuriante leonardo gnostico digressao cupula fifa broxar iniquo louvor ovario dorsal ideologo besuntar decurso rosto susto lemure unheiro pagodeiro nitroglicerina eclusa mazurca bigorna";
    const std::string real_checksum = "gnostico";

    res = crypto::ElectrumWords::words_to_bytes(base_seed, key, language_name);
    ASSERT_EQ(true, res);
    ASSERT_STREQ(language_name.c_str(), "Português");

    res = crypto::ElectrumWords::words_to_bytes(base_seed + " " + real_checksum, key, language_name);
    ASSERT_EQ(true, res);
    ASSERT_STREQ(language_name.c_str(), "Português");
}
