#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

// Custom comparison function for sorting pairs by frequency
bool comparePairs(const std::pair<char, int>& a, const std::pair<char, int>& b) {
    return a.second > b.second;
}

// Custom comparison function for sorting trigram pairs by frequency
bool compareStringPairs(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    return a.second > b.second;
}

int main() {
    // The ciphertext to decode
    std::string ciphertext = "UZOSOVUOHXMOPVGPOZPEVSGZWSZOPFPESXUDBMETSXAIZVUEPHZHMDZSHZOWSFPAPPDISVPQUZWYMXUZUHSXEPYEPOPDZSZUFPOMBZWPFUPZHMDJUDTMOHMQ";
    
    // Count letter frequencies in the ciphertext
    std::map<char, int> frequency;
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        char c = ciphertext[i];
        frequency[c]++;
    }
    
    // Convert map to vector for sorting by frequency
    std::vector<std::pair<char, int> > freq_vec;
    std::map<char, int>::iterator it;
    for (it = frequency.begin(); it != frequency.end(); ++it) {
        freq_vec.push_back(std::make_pair(it->first, it->second));
    }
    
    // Sort by frequency (descending)
    std::sort(freq_vec.begin(), freq_vec.end(), comparePairs);
    
    // Display letter frequencies
    std::cout << "Letter frequencies in the ciphertext:" << std::endl;
    for (size_t i = 0; i < freq_vec.size(); ++i) {
        std::cout << freq_vec[i].first << ": " << freq_vec[i].second << std::endl;
    }
    
    // Count trigrams (3-letter sequences)
    std::map<std::string, int> trigrams;
    for (size_t i = 0; i < ciphertext.length() - 2; ++i) {
        std::string trigram = ciphertext.substr(i, 3);
        trigrams[trigram]++;
    }
    
    // Convert trigram map to vector for sorting
    std::vector<std::pair<std::string, int> > trigram_vec;
    std::map<std::string, int>::iterator trigram_it;
    for (trigram_it = trigrams.begin(); trigram_it != trigrams.end(); ++trigram_it) {
        trigram_vec.push_back(std::make_pair(trigram_it->first, trigram_it->second));
    }
    
    // Sort trigrams by frequency
    std::sort(trigram_vec.begin(), trigram_vec.end(), compareStringPairs);
    
    // Display most common trigrams
    std::cout << "\nMost common 3-letter sequences:" << std::endl;
    size_t trigram_display_count = trigram_vec.size() < 10 ? trigram_vec.size() : 10;
    for (size_t i = 0; i < trigram_display_count; ++i) {
        std::cout << trigram_vec[i].first << ": " << trigram_vec[i].second << std::endl;
    }
    
    // Based on frequency analysis and pattern matching, create a decryption key
    std::map<char, char> decryption_key;
    decryption_key['P'] = 'e';
    decryption_key['Z'] = 't';
    decryption_key['S'] = 'h';
    decryption_key['O'] = 's';
    decryption_key['U'] = 'c';
    decryption_key['H'] = 'a';
    decryption_key['M'] = 'o';
    decryption_key['D'] = 'n';
    decryption_key['F'] = 'i';
    decryption_key['V'] = 'r';
    decryption_key['E'] = 'l';
    decryption_key['W'] = 'w';
    decryption_key['X'] = 'd';
    decryption_key['G'] = 'f';
    decryption_key['B'] = 'g';
    decryption_key['A'] = 'y';
    decryption_key['J'] = 'k';
    decryption_key['Q'] = 'x';
    decryption_key['Y'] = 'p';
    decryption_key['I'] = 'v';
    decryption_key['T'] = 'm';
    decryption_key['C'] = 'u';
    decryption_key['N'] = 'j';
    decryption_key['K'] = 'q';
    decryption_key['L'] = 'z';
    decryption_key['R'] = 'b';
    
    // Decrypt the message
    std::string decrypted_text;
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        char c = ciphertext[i];
        std::map<char, char>::iterator key_it = decryption_key.find(c);
        if (key_it != decryption_key.end()) {
            decrypted_text += key_it->second;
        } else {
            decrypted_text += c;
        }
    }
    
    // Output the decrypted message
    std::cout << "\nDecrypted text:" << std::endl;
    std::cout << decrypted_text << std::endl;
    
    return 0;
}