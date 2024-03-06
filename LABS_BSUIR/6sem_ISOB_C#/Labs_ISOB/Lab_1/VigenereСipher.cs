using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_1
{
    public class VigenereСipher
    {
        private string _key;

        public string Key
        {
            get => _key;
            set
            {
                if (value != null)
                    _key = value.ToLower();
            }
        }

        private const int ALPHABET_LENGTH = 26;

        public VigenereСipher(string key)
        {
            Key = key;
        }

        public string Encrypt(string source)
        {
            StringBuilder result = new StringBuilder();

            for (int i = 0; i < source.Length; i++)
            {
                int letOffset = char.IsUpper(source[i]) ? 'A' : 'a';

                if (char.IsLetter(source[i]))
                {
                    result.Append((char)(((source[i] + Key[i % Key.Length] - letOffset - 'a') % ALPHABET_LENGTH) + letOffset));
                }
            }

            return result.ToString();
        }

        public string Decrypt(string source)
        {
            StringBuilder result = new StringBuilder();

            for (int i = 0; i < source.Length; i++)
            {
                int letOffset = char.IsUpper(source[i]) ? 'A' : 'a';

                if (char.IsLetter(source[i]))
                {
                    result.Append((char)(((source[i] - Key[i % Key.Length] + ALPHABET_LENGTH - letOffset + 'a') % ALPHABET_LENGTH) + letOffset));
                }
            }

            return result.ToString();
        }
    }
}
