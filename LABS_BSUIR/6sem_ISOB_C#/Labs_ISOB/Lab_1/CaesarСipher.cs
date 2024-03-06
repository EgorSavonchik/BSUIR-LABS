using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_1
{
    public class CaesarСipher
    {
        public int Step { get; set; }
        private const int ALPHABET_LENGTH = 26;

        public CaesarСipher(int step)
        {
            Step = step;
        }

        public string Encrypt(string source)
        {
            StringBuilder result = new StringBuilder();

            foreach (char letter in source) 
            {
                if(char.IsLetter(letter) && char.IsUpper(letter))
                {
                    result.Append((char)((letter + Step - 'A') % ALPHABET_LENGTH + 'A'));
                }
                else if(char.IsLetter(letter))
                {
                    result.Append((char)((letter + Step - 'a') % ALPHABET_LENGTH + 'a'));
                }
                else
                {
                    result.Append(letter);
                }
                
            }

            return result.ToString();
        }

        public string Decrypt(string source) 
        {
            StringBuilder result = new StringBuilder();

            foreach (char letter in source)
            {
                if (char.IsLetter(letter) && char.IsUpper(letter))
                {
                    result.Append((char)((letter - Step + ALPHABET_LENGTH - 'A') % ALPHABET_LENGTH + 'A'));
                }
                else if (char.IsLetter(letter))
                {
                    result.Append((char)((letter - Step + ALPHABET_LENGTH - 'a') % ALPHABET_LENGTH + 'a'));
                }
                else
                {
                    result.Append(letter);
                }
            }

            return result.ToString();
        }
    }
}
